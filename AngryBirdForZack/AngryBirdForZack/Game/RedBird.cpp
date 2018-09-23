
// Game Class Include
#include "GameClasses.h"

// Engine Include
#include "Engine/Engine.h"

CRedBird::CRedBird()
{
	m_name = "Red_Bird";
	m_tag = "Bird";

	// Sprite and Body Component has been created inside the base class

	// Set the sprite to the Red Bird
	m_spriteRender->SetSprite("RedBird_Normal");

	// Define the shape of the body
	b2CircleShape circleShape;
	circleShape.m_radius = 
		m_spriteRender->GetSprite()->GetWidth() / 2.0f;

	// Define the fixture using the shape
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &circleShape;
	fixtureDef.isSensor = false;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.1f;

	// Create the fixture in the body
	m_rigidBody->GetBody()->CreateFixture(&fixtureDef);
}

CRedBird::~CRedBird()
{}

void CRedBird::ActiveAbility()
{
	// The red bird has no active abiility
}

void CRedBird::BeginPlay()
{
	__super::BeginPlay();

	// Set the scale down
	m_transform.scale = glm::vec3(0.2f, 0.2f, 1.0f);

	//m_rigidBody->GetBody()->m_mass = 1.0f;
}

void CRedBird::OnCollisionEnter(CGameObject* _other)
{
	__super::OnCollisionEnter(_other);
	
}

void CRedBird::Update(float _tick)
{
	__super::Update(_tick);

	b2Vec2 position = m_rigidBody->GetBody()->GetTransform().p;
	float x = position.x;
	float y = position.y;

	std::cout << "Transform: " << x << ", " << y << "\n";
	//m_rigidBody->GetBody()->GetTransform();
}
