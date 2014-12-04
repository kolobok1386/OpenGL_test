#ifndef _SHADER_PROGRAM
#define _SHADER_PROGRAM

#include "CommonInc.h"
#include "DefTypes.h"

class AKShaderProgram;
class AKShaderVariable;

class AKShaderVariable : public RTTI
{
	RTTI_DECLARATIONS(AKShaderVariable, RTTI)
public:
	AKShaderVariable(AKShaderProgram& shaderProgram, std::string& name);
	~AKShaderVariable();

	GLuint getLocation();
	void setValue(const glm::mat4& value);
	void setValue(const glm::vec4& value);
	void setValue(const glm::vec3& value);
	void setValue(const glm::vec2& value);
	void setValue(float value);
	void setValue(int value);

private:
	std::string m_name;
	GLuint m_location;
	AKShaderProgram& m_shaderProgram;
};

class AKShaderProgram : public RTTI
{
	RTTI_DECLARATIONS(AKShaderProgram, RTTI)
public:
	AKShaderProgram();
	~AKShaderProgram();

	void link();
	void use();
	GLuint getHandle();
	void addShaderEffect(GLuint shaderEffectId);

private:
	GLuint m_programId;
	std::vector<std::shared_ptr<AKShaderVariable> > m_variables;
	std::map<std::string, std::shared_ptr<AKShaderVariable> > m_variablesWithNames;
};

#endif