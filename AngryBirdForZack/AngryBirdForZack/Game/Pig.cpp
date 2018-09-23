
// This Include
#include "Pig.h"

// Engine Include
#include "Engine/Engine.h"

CPig::CPig()
{
	m_spriteRener = CreateComponent<CSpriteRender>();
	m_rigidBody = CreateComponent<CRigiBody2D>();
}

CPig::~CPig()
{}

void CPig::BeginPlay()
{
	__super::BeginPlay();
	
}

void CPig::LateUpdate(float _tick)
{
	__super::LateUpdate(_tick);
	
}

void CPig::OnCollisionEnd(CGameObject* _other)
{
	__super::OnCollisionEnd(_other);
	
}

void CPig::OnCollisionEnter(CGameObject* _other)
{
	__super::OnCollisionEnter(_other);
	

	b2Vec2 vec2Velocity = m_rigidBody->GetBody()->GetLinearVelocity();
	float velocity = (float)vec2Velocity.Length();



}

void CPig::Update(float _tick)
{
	__super::Update(_tick);
	
}
