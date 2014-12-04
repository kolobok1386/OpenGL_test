#ifndef _COMMON_INC
#define _COMMON_INC

// Включаем GLEW. Всегда включайте его ДО gl.h и glfw.h
#include <windows.h>

#include <GL/glew.h>
#include <btBulletDynamicsCommon.h>
#include <memory>
#include <vector>
#include <map>
#include <unordered_map>
//#include "DefTypes.h"

#if defined(OPENGL)
//#include "GL/gl3w.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtx/simd_mat4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/matrix_inverse.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/core/func_trigonometric.hpp"

#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL
#endif

typedef std::string componentID;

#include "RTTI.h"

#define DELETE_PTR(ptr)\
	if(ptr) \
	{ \
		delete ptr; \
		ptr = 0; \
	};
	


#endif