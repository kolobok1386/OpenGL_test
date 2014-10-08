#include "BulletPhysics.h"

void BulletPhysics::initObjects() 
{
	m_collisionConfiguration = std::shared_ptr<btDefaultCollisionConfiguration>(new btDefaultCollisionConfiguration());
	m_dispatcher = std::shared_ptr<btCollisionDispatcher>(new btCollisionDispatcher(m_collisionConfiguration.get()));
	m_overlappingPairCache = std::shared_ptr<btDbvtBroadphase>(new btDbvtBroadphase());
	m_solver = std::shared_ptr<btSequentialImpulseConstraintSolver>(new btSequentialImpulseConstraintSolver());
	m_dynamicsWorld = std::shared_ptr<btDiscreteDynamicsWorld>(new btDiscreteDynamicsWorld(m_dispatcher.get(), m_overlappingPairCache.get(), m_solver.get(), m_collisionConfiguration.get()));

	m_dynamicsWorld->setGravity(btVector3(0, -10, 0));
}

btRigidBody* BulletPhysics::addFallingSphere()
{
	btCollisionShape* fallShape = new btSphereShape(1);//(btVector3(1, 1, 1));
	btDefaultMotionState* fallMotionState =
		new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 5, 0)));
	btScalar mass = 1;
	btVector3 fallInertia(0, 0, 0);
	fallShape->calculateLocalInertia(mass, fallInertia);
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, fallMotionState, fallShape, fallInertia);
	fallRigidBodyCI.m_restitution = 0.9f;
	//fallRigidBodyCI.m_friction = 1.5f;
	btRigidBody* fallRigidBody = new btRigidBody(fallRigidBodyCI);
	m_dynamicsWorld->addRigidBody(fallRigidBody);

	return fallRigidBody;
}
