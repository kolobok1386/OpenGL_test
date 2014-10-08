#include "BulletPhysics.h"

// Включаем стандартные заголовки
#include <stdio.h>
#include <stdlib.h>

// Включаем GLEW. Всегда включайте его ДО gl.h и glfw.h
#include <GL/glew.h>

// Включаем GLFW
#include <GL/glfw3.h>

// Включаем GLM
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include "common/shader.hpp"
#include "common/texture.hpp"
#include "common/controls.hpp"
#include <string>
#include <fstream>

#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/OpenGL/GLRenderer.h>
using namespace CEGUI;


