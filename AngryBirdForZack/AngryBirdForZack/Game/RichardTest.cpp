
// This Include
#include "RichardTest.h"

// Engine Include
#include "Engine/Engine.h"
#include "GameClasses.h"

CRichardTest::CRichardTest()
{
}

CRichardTest::~CRichardTest()
{
}

void CRichardTest::ConfigurateScene()
{
	__super::ConfigurateScene();

	// Configure Camera
	m_mainCamera = new CCamera();

	// 

#pragma region Object: RedBird

	CGameObject* redBird = new CRedBird();
	redBird->m_transform.position = glm::vec3(0.0f, 3.0f, 0.0f);
	m_vGameObj.push_back(redBird);

#pragma endregion Object: RedBird
	
#pragma region Object: Ground

	CGameObject* ground = new CGameObject();
	m_vGameObj.push_back(ground);
	ground->m_name = "Ground";
	ground->m_tag = Tag::Ground;
	ground->m_transform.position = glm::vec3(2.0f, -6.0f, 0.0f);
	ground->m_transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
	// Create Sprite Renderer
	CSpriteRender* spriteRender = ground->CreateComponent<CSpriteRender>();
	spriteRender->SetSprite("Ground");
	// Create RigidBody
	CRigidBody2D* rigidBody = ground->CreateComponent<CRigidBody2D>();
	rigidBody->SetBodyType(b2BodyType::b2_staticBody);
	rigidBody->SetCanRotate(false);
	// Define the shape of the body
	b2PolygonShape polygonShape;
	float32 halfWidth = 
		(spriteRender->GetSprite()->GetWidth() * ground->m_transform.scale.x) / 2.0f / util::PIXELUNIT;
	float32 halfHeight = 
		(spriteRender->GetSprite()->GetHeight() * ground->m_transform.scale.y) / 2.0f / util::PIXELUNIT;
	polygonShape.SetAsBox(halfWidth, halfHeight);
	// Define the fixture using the shape
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygonShape;
	fixtureDef.isSensor = false;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.1f;
	// Create the fixture in the body
	rigidBody->GetBody()->CreateFixture(&fixtureDef);

#pragma endregion Object: Ground

	

}

void CRichardTest::BeginPlay()
{
	__super::BeginPlay();
	

}

void CRichardTest::UpdateScene(float _tick)
{
	__super::UpdateScene(_tick);
	

}
