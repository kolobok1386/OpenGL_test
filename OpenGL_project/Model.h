#ifndef _MODEL
#define _MODEL

#include "CommonInc.h"
#include "DefTypes.h"

class AKModel
{
public:
	AKModel();
	~AKModel();

private:
	std::vector<std::shared_ptr<AKMesh> > m_meshes;

};

#endif