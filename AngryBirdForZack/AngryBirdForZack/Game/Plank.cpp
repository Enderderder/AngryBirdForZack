
// Game Class Include
#include "GameClasses.h"

// Engine Include
#include "Engine/Engine.h"


CPlank::CPlank()
{
	// Set name and tag
	m_name = "WoodPlank";
	m_tag = Tag::Plank;

	// Set the velocity of object to destroy
	m_velocityToDestroy = 5.0f;

	m_velocityToTakeDmg = 10.0f;
	m_Health = 2;

	// Create Component
	m_spriteRender = CreateComponent<CSpriteRender>();
	m_rigidBody = CreateComponent<CRigidBody2D>();

	// Set the sprite
	m_spriteRender->SetSprite("WoodPlank");

	// Define the shape of the body
	b2PolygonShape polygonShape;
	float32 halfWidth =
		(m_spriteRender->GetSprite()->GetWidth() * m_transform.scale.x) / 2.0f / util::PIXELUNIT;
	float32 halfHeight =
		(m_spriteRender->GetSprite()->GetHeight() * m_transform.scale.y) / 2.0f / util::PIXELUNIT;
	polygonShape.SetAsBox(halfWidth, halfHeight);
	// Define the fixture using the shape
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygonShape;
	fixtureDef.isSensor = false;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.1f;
	// Create the fixture in the body
	m_rigidBody->GetBody()->CreateFixture(&fixtureDef);
}

CPlank::~CPlank()
{
	
}

void CPlank::BeginPlay()
{
	__super::BeginPlay();
	
}

void CPlank::Update(float _tick)
{
	__super::Update(_tick);
	
}

void CPlank::LateUpdate(float _tick)
{
	__super::LateUpdate(_tick);
	
}

void CPlank::OnCollisionEnter(CGameObject* _other)
{
	__super::OnCollisionEnter(_other);
	
	if (m_rigidBody->GetBody()->GetLinearVelocity().Length() > m_velocityToDestroy)
	{
		DestroyObject();
		return;
	}

	if (CBird* birdObj = dynamic_cast<CBird*>(_other))
	{
		float birdVelocity = 
			(float)birdObj->GetComponent<CRigidBody2D>()->GetBody()->GetLinearVelocity().Length();

		// Calculate the damage taken base on the velocity of the bird
		// Base damage no matter what uppon collide
		int damageTake = (int)(birdVelocity / m_velocityToTakeDmg) + 1;
		TakeDamage(damageTake);

		CDebug::Log("Plank Got hit. Object velovity: " + util::ToString(birdVelocity));
	}

}

void CPlank::OnCollisionEnd(CGameObject* _other)
{
	__super::OnCollisionEnd(_other);
	
}

void CPlank::TakeDamage(int _damage)
{
	m_Health -= _damage;
	if (m_Health <= 0)
	{
		DestroyObject();
	}
}

