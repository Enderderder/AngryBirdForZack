#pragma once

// Inherited Include
#include "Engine/GameObject.h"

class CPlank : public CGameObject
{

public:

	CPlank();
	virtual ~CPlank();

	virtual void BeginPlay() override;
	virtual void Update(float _tick) override;
	virtual void LateUpdate(float _tick) override;
	virtual void OnCollisionEnter(CGameObject* _other) override;
	virtual void OnCollisionEnd(CGameObject* _other) override;

	void TakeDamage(int _damage);

private:

	/** Component */
	CSpriteRender* m_spriteRender;
	CRigidBody2D* m_rigidBody;


	float m_velocityToDestroy;
	float m_velocityToTakeDmg;

	int m_Health;
};