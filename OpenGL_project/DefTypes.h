#ifndef _DEFTYPES
#define _DEFTYPES

//#include "CommonInc.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"
#include "Mesh.h"

//class AKVertexBuffer;
class AKMesh;
class AKShaderVariable;


#define declare_types(SELF)\
	typedef std::shared_ptr<SELF> S##SELF;\
	typedef std::weak_ptr<SELF> W##SELF;\
	typedef std::unique_ptr<SELF> U##SELF;

declare_types(btDefaultCollisionConfiguration)
declare_types(btCollisionDispatcher)
declare_types(btDbvtBroadphase)
declare_types(btSequentialImpulseConstraintSolver)
declare_types(btDiscreteDynamicsWorld)
declare_types(btBroadphaseInterface)
declare_types(btCollisionShape)
declare_types(btRigidBody)
//declare_types(AKVertexBuffer)
//declare_types(AKMesh)
//declare_types(AKShaderVariable)

#endif