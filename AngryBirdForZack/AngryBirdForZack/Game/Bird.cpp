
// This Include
#include "Bird.h"

// Engine Include
#include "Engine/Engine.h"

CBird::CBird()
{
	m_spriteRender = CreateComponent<CSpriteRender>();
	m_rigidBody = CreateComponent<CRigidBody2D>();
}

CBird::~CBird()
{}

void CBird::BeginPlay()
{
	__super::BeginPlay();

	// Set the bird to not process so its not affect by any input
	m_isProcessing = false;
	
}

void CBird::Update(float _tick)
{
	__super::Update(_tick);
	

}

void CBird::OnCollisionEnd(CGameObject* _other)
{
	__super::OnCollisionEnd(_other);
	

}

void CBird::OnCollisionEnter(CGameObject* _other)
{
	__super::OnCollisionEnter(_other);
	


}

void CBird::ProcessBird()
{
	m_isProcessing = true;
}

void CBird::UnProcessBird()
{
	m_isProcessing = false;
}

