
// Game Classes Include
#include "GameClasses.h"

// Engine Include
#include "Engine/Engine.h"

CSlingShot::CSlingShot()
{
	// Set name and tag
	m_name = "Slingshot";
	m_tag = Tag::Slingshot;

	// Create the component for the object
	m_spriteRender = CreateComponent<CSpriteRender>();
	m_spriteRender->SetSprite("Slingshot");

}

CSlingShot::~CSlingShot()
{
	// Clean up
	birdOnSlingshot = nullptr;
	birdsOnField.clear();
}

void CSlingShot::BeginPlay()
{
	__super::BeginPlay();
	
}

void CSlingShot::Update(float _tick)
{
	__super::Update(_tick);
	
}

void CSlingShot::OnCollisionEnd(CGameObject* _other)
{
	__super::OnCollisionEnd(_other);
	
}

void CSlingShot::OnCollisionEnter(CGameObject* _other)
{
	__super::OnCollisionEnter(_other);
	
}

void CSlingShot::OnMouseDown()
{
	__super::OnMouseDown();
	
}
