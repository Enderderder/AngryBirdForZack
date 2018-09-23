#pragma once

// Inherited Include
#include "Engine/GameObject.h"

// Forward Declare
class CSpriteRender;
class CRigiBody2D;

class CPig : public CGameObject
{
public:

	CPig();
	~CPig();

	virtual void BeginPlay() override;
	virtual void LateUpdate(float _tick) override;
	virtual void OnCollisionEnd(CGameObject* _other) override;
	virtual void OnCollisionEnter(CGameObject* _other) override;
	virtual void Update(float _tick) override;



protected:

	/** Components */
	CSpriteRender* m_spriteRener;
	CRigiBody2D* m_rigidBody;

	


};