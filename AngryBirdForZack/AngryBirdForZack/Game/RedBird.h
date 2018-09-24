#pragma once

// Inherited Include
#include "Bird.h"

class CRedBird : public CBird
{
public:

	CRedBird();
	virtual ~CRedBird();

	/** Derived from CBird Class */
	virtual void ActiveAbility() override;

	/** Derived from CGameObject Class */
	virtual void BeginPlay() override;
	virtual void OnCollisionEnter(CGameObject* _other) override;
	virtual void Update(float _tick) override;

private:

	

};