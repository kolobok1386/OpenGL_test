#ifndef _DEFTYPES
#define _DEFTYPES

#include "CommonInc.h"

#define declare_type(SELF)\
	typedef std::shared_ptr<SELF> S##SELF;

declare_type(btDefaultCollisionConfiguration)
declare_type(btCollisionDispatcher)
declare_type(btDbvtBroadphase)
declare_type(btSequentialImpulseConstraintSolver)
declare_type(btDiscreteDynamicsWorld)
declare_type(btBroadphaseInterface)
declare_type(btCollisionShape)
declare_type(btRigidBody)

#endif