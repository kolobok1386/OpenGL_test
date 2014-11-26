#include "ShaderProgram.h"

AKShaderVariable::AKShaderVariable(AKShaderProgram& shaderProgram, std::string& name)
: m_shaderProgram(shaderProgram),
m_name(name)
{
	m_location = glGetUniformLocation(m_shaderProgram.getHandle(), name.c_str());
};

AKShaderVariable::~AKShaderVariable()
{

};

GLuint AKShaderVariable::getLocation()
{
	return m_location;
};

void AKShaderVariable::setValue(const glm::mat4& value)
{
	glUniformMatrix4fv(m_location, 1, GL_FALSE, &value[0][0]);
};

void AKShaderVariable::setValue(const glm::vec4& value)
{
	glUniform4fv(m_location, 1, &value[0]);
};

void AKShaderVariable::setValue(const glm::vec3& value)
{
	glUniform3fv(m_location, 1, &value[0]);
};

void AKShaderVariable::setValue(const glm::vec2& value)
{
	glUniform2fv(m_location, 1, &value[0]);
};

void AKShaderVariable::setValue(float value)
{
	glUniform1f(m_location, value);
};

void AKShaderVariable::setValue(int value)
{
	glUniform1i(m_location, value);
};

//////////////////////////////

AKShaderProgram::AKShaderProgram()
: m_variables(),
m_variablesWithNames()
{
	m_programId = glCreateProgram();
}

AKShaderProgram::~AKShaderProgram()
{
	if(m_programId)
		glDeleteProgram(m_programId);
}

void AKShaderProgram::link()
{
	if(m_programId)
		glLinkProgram(m_programId);
}

void AKShaderProgram::use()
{
	if(m_programId)
		glUseProgram(m_programId);
}

GLuint AKShaderProgram::getHandle()
{
	return m_programId;
}

void AKShaderProgram::addShaderEffect(GLuint shaderEffectId)
{
	if(m_programId)
	{
		glAttachShader(m_programId, shaderEffectId);
	}	
	else
	{
		m_programId = glCreateProgram();
		glAttachShader(m_programId, shaderEffectId);
	}
}
