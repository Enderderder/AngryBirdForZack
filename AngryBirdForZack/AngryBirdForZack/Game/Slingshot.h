#pragma once

// Inherited Include
#include "Engine/GameObject.h"

// Forward Declare
class CSpriteRender;
class CRigidBody2D;
class CBird;

class CSlingShot : public CGameObject
{
public:

	CSlingShot();
	virtual ~CSlingShot();

	virtual void BeginPlay() override;
	virtual void Update(float _tick) override;
	virtual void OnCollisionEnd(CGameObject* _other) override;
	virtual void OnCollisionEnter(CGameObject* _other) override;
	virtual void OnMouseDown() override;

public:

	CBird* birdOnSlingshot;
	std::vector<CBird*> birdsOnField;

private:

	// Component
	CSpriteRender* m_spriteRender;



};
