#ifndef _BULLET_PHYSICS
#define _BULLET_PHYSICS

#include "CommonInc.h"
#include "DefTypes.h"

class BulletPhysics : public RTTI
{
	RTTI_DECLARATIONS(BulletPhysics, RTTI)
public:
	void initObjects();
	SbtDiscreteDynamicsWorld getDynamicsWorld() { return m_dynamicsWorld; };
	btRigidBody* addFallingSphere();
private:
	SbtDefaultCollisionConfiguration m_collisionConfiguration;
	SbtCollisionDispatcher m_dispatcher;
	SbtBroadphaseInterface m_overlappingPairCache;
	SbtSequentialImpulseConstraintSolver m_solver;
	SbtDiscreteDynamicsWorld m_dynamicsWorld;
	std::vector<SbtCollisionShape> m_collisionShapes;
	std::map<std::string, SbtRigidBody> m_physicsAccessors;

};

#endif