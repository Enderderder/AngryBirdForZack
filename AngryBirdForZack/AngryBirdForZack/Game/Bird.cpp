
// This Include
#include "Bird.h"

// Engine Include
#include "Engine/Engine.h"

CBird::CBird()
{
	m_spriteRender = CreateComponent<CSpriteRender>();
	//m_spriteRender->SetSprite("Bird");

	m_rigidBody = CreateComponent<CRigiBody2D>();

	b2CircleShape circleShape;
	//circleShape.m_radius = 

	//b2FixtureDef fixtureDef;

}

CBird::~CBird()
{}

void CBird::BeginPlay()
{
	__super::BeginPlay();
	
	
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
