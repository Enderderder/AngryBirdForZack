#pragma once

// Inherited Include
#include "Engine\Scene.h"


class CRichardTest : public CScene
{
public:
	CRichardTest();
	~CRichardTest();

	virtual void ConfigurateScene() override;
	virtual void BeginPlay() override;
	virtual void UpdateScene(float _tick) override;

private:

	

};

