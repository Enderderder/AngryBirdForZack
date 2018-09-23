#pragma once

// Inherite Include
#include "Engine/GameObject.h"

// Forward Declare
class CSpriteRender;
class CRigiBody2D;

class CBird : public CGameObject
{
public:
	CBird();
	~CBird();

	virtual void BeginPlay() override;
	virtual void Update(float _tick) override;
	virtual void OnCollisionEnd(CGameObject* _other) override;
	virtual void OnCollisionEnter(CGameObject* _other) override;

	/**
	 * The active ability of the bird that can be use 
	 * after shoot out by he slingshot
	 */
	virtual void ActiveAbility() = 0;

protected:

	/** Components */
	CSpriteRender* m_spriteRender;
	CRigiBody2D* m_rigidBody;
};