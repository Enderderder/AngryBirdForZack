#pragma once

// Global Include
#include "Utility.h"

class CQueryCallback : public b2QueryCallback
{
public:

	std::vector<b2Body*> m_vFoundedBodies;

	virtual bool ReportFixture(b2Fixture* _fixture) override;

};