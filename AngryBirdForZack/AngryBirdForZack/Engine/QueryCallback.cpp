
// Engine Include
#include "Engine.h"

bool CQueryCallback::ReportFixture(b2Fixture* _fixture)
{
	m_vFoundedBodies.push_back(_fixture->GetBody());

	return true;
}
