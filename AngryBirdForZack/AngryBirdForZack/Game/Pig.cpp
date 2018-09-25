
// This Include
#include "GameClasses.h"

// Engine Include
#include "Engine/Engine.h"

CPig::CPig()
{
	// The velocity of the other object when hit will cuz dmg
	m_velocityToTakeDmg = 6.0f;

	// Create the component for the object
	m_spriteRender = CreateComponent<CSpriteRender>();
	m_rigidBody = CreateComponent<CRigidBody2D>();
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

	if (CBird* birdObj = dynamic_cast<CBird*>(_other))
	{
		b2Vec2 birdVelocityVec = birdObj->GetComponent<CRigidBody2D>()->GetBody()->GetLinearVelocity();
		float fBirdVelocity = (float)birdVelocityVec.Length();

		// Calculate the damage taken base on the velocity of the bird
		// Base damage no matter what uppon collide
		int damageTake = (int)(fBirdVelocity / m_velocityToTakeDmg) + 1;
		TakeDamage(damageTake);

		CDebug::Log("Pig Got hit. Object velovity: " + util::ToString(fBirdVelocity));
	}
}

void CPig::Update(float _tick)
{
	__super::Update(_tick);


}

void CPig::Die()
{
	CDebug::Log("A Pig Dies");
	DestroyObject();
}

void CPig::TakeDamage(int _damage)
{
	m_health -= _damage;
	if (ShouldDie())
	{
		Die();
	}
}

bool CPig::ShouldDie()
{
	if (m_health <= 0)
	{
		return true;
	}
	return false;
}
