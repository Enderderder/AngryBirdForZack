#pragma once

// Inherited Include
#include "Pig.h"

class CNormalPig : public CPig
{
public:
	
	CNormalPig();
	~CNormalPig();

	virtual void BeginPlay() override;
	virtual void Update(float _tick) override;
	virtual void LateUpdate(float _tick) override;
	virtual void OnCollisionEnter(CGameObject* _other) override;
	virtual void OnCollisionEnd(CGameObject* _other) override;

private:

	

};
