#include "ShaderEffect.h"

AKShaderEffect::AKShaderEffect()
{
	m_shaderId = 0;
}

AKShaderEffect::~AKShaderEffect()
{
	if(m_shaderId)
		glDeleteShader(m_shaderId);
}

void AKShaderEffect::initFromSource(GLenum shaderType, const std::string& source)
{
	// Create the shaders
	GLuint m_shaderId = glCreateShader(shaderType);

	GLint Result = GL_FALSE;
	int InfoLogLength;

	char const * VertexSourcePointer = source.c_str();
	glShaderSource(m_shaderId, 1, &VertexSourcePointer, NULL);
	glCompileShader(m_shaderId);

	// Check Vertex Shader
	glGetShaderiv(m_shaderId, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(m_shaderId, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if(InfoLogLength > 0)
	{
		std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(m_shaderId, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}
}

void AKShaderEffect::initFromFile(GLenum shaderType, const std::string& filePath)
{
	// Create the shaders
	GLuint m_shaderId = glCreateShader(shaderType);

	// Read the Vertex Shader code from the file
	std::string VertexShaderCode;
	std::ifstream VertexShaderStream(filePath.c_str(), std::ios::in);
	if(VertexShaderStream.is_open())
	{
		std::string Line = "";
		while(getline(VertexShaderStream, Line))
			VertexShaderCode += "\n" + Line;
		VertexShaderStream.close();
	}
	else
	{
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", filePath.c_str());
		getchar();
		return;
	}

	GLint Result = GL_FALSE;
	int InfoLogLength;

	// Compile Vertex Shader
	printf("Compiling shader : %s\n", filePath);
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(m_shaderId, 1, &VertexSourcePointer, NULL);
	glCompileShader(m_shaderId);

	// Check Vertex Shader
	glGetShaderiv(m_shaderId, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(m_shaderId, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if(InfoLogLength > 0)
	{
		std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(m_shaderId, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}
}
