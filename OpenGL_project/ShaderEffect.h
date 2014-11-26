#ifndef _SHADER_EFFECT
#define _SHADER_EFFECT

#include "CommonInc.h"
#include <iostream>
#include <fstream>
#include <string>

class AKShaderEffect
{
public:
	AKShaderEffect();
	~AKShaderEffect();

	void initFromSource(GLenum shaderType, const std::string& source);
	void initFromFile(GLenum shaderType, const std::string& filePath);
	GLuint getHandle();

protected:
	GLuint m_shaderId;
};

#endif