
// Game Class Include
#include "GameClasses.h"

// Engine Include
#include "Engine/Engine.h"


CNormalPig::CNormalPig()
{
	// Set name and tag
	m_name = "Pig_Normal";
	m_tag = Tag::Pig;

	// Set the scale down
	m_transform.scale = glm::vec3(0.2f, 0.2f, 1.0f);

	// Set the health of normal pig
	m_health = 2;

	// Set the Sprite to the Pig
	m_spriteRender->SetSprite("Pig_Normal");

	// Define the shape of the body
	b2CircleShape circleShape;
	circleShape.m_radius =
		(m_spriteRender->GetSprite()->GetWidth() * m_transform.scale.x / 2.0f) / util::PIXELUNIT;

	// Define the fixture using the shape
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &circleShape;
	fixtureDef.isSensor = false;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.1f;

	// Create the fixture in the body
	m_rigidBody->GetBody()->CreateFixture(&fixtureDef);
}

CNormalPig::~CNormalPig()
{}

void CNormalPig::BeginPlay()
{
	__super::BeginPlay();
	
}

void CNormalPig::Update(float _tick)
{
	__super::Update(_tick);
	

}

void CNormalPig::LateUpdate(float _tick)
{
	__super::LateUpdate(_tick);


}

void CNormalPig::OnCollisionEnter(CGameObject* _other)
{
	__super::OnCollisionEnter(_other);
	
	
}

void CNormalPig::OnCollisionEnd(CGameObject* _other)
{
	__super::OnCollisionEnd(_other);
	

}

