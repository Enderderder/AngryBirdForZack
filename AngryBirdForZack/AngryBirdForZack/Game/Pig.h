#pragma once

// Inherited Include
#include "Engine/GameObject.h"

// Forward Declare
class CSpriteRender;
class CRigidBody2D;

class CPig : public CGameObject
{
public:

	CPig();
	virtual ~CPig();

	virtual void BeginPlay() override;
	virtual void LateUpdate(float _tick) override;
	virtual void OnCollisionEnd(CGameObject* _other) override;
	virtual void OnCollisionEnter(CGameObject* _other) override;
	virtual void Update(float _tick) override;

	void TakeDamage(int _damage);
	bool ShouldDie();
	void Die();


protected:

	/** Components */
	CSpriteRender* m_spriteRender;
	CRigidBody2D* m_rigidBody;

	// The health of the pig
	int m_health;
	float m_velocityToTakeDmg;

};