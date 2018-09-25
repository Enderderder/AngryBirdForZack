
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

	// Configure Gameobjects

#pragma region Object: BackGround

	CGameObject* backGround = new CGameObject();
	m_vGameObj.push_back(backGround);
	backGround->m_name = "BackGround";
	backGround->m_tag = Tag::Default;
	// Create Sprite Renderer
	CSpriteRender* spriteRender = backGround->CreateComponent<CSpriteRender>();
	spriteRender->SetSprite("AngryBirdBG");

#pragma endregion Object: BackGround

#pragma region Object: Ground

	CGameObject* ground = new CGameObject();
	m_vGameObj.push_back(ground);
	ground->m_name = "Ground";
	ground->m_tag = Tag::Ground;
	ground->m_transform.position = glm::vec3(2.0f, -6.0f, 0.0f);
	// Create Sprite Renderer
	CSpriteRender* groundRenderer = ground->CreateComponent<CSpriteRender>();
	groundRenderer->SetSprite("Ground");
	// Create RigidBody
	CRigidBody2D* rigidBody = ground->CreateComponent<CRigidBody2D>();
	rigidBody->SetBodyType(b2BodyType::b2_staticBody);
	rigidBody->SetCanRotate(false);
	// Define the shape of the body
	b2PolygonShape polygonShape;
	float32 halfWidth =
		(groundRenderer->GetSprite()->GetWidth() * ground->m_transform.scale.x) / 2.0f / util::PIXELUNIT;
	float32 halfHeight =
		((groundRenderer->GetSprite()->GetHeight() - 30) * ground->m_transform.scale.y) / 2.0f / util::PIXELUNIT;
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

#pragma region Object: Slingshot

	CGameObject* slingshot = new CSlingShot();
	slingshot->m_transform.position = glm::vec3(-10.0f, -2.75f, 0.0f);
	m_vGameObj.push_back(slingshot);

#pragma endregion Object: Slingshot

#pragma region Object: RedBird

	CGameObject* redBird = new CRedBird();
	redBird->m_transform.position = glm::vec3(-4.0f, 3.0f, 0.0f);
	m_vGameObj.push_back(redBird);

#pragma endregion Object: RedBird
	
#pragma region Object: NormalPig

	CGameObject* normalPig = new CNormalPig();
	normalPig->m_transform.position = glm::vec3(3.0f, 1.0f, 0.0f);
	m_vGameObj.push_back(normalPig);

#pragma endregion Object: NormalPig

#pragma region Object: WoodPlank1

	CGameObject* woodPlank1 = new CPlank();
	woodPlank1->m_transform.position = glm::vec3(2.0f, -3.0f, 0.0f);
	m_vGameObj.push_back(woodPlank1);

#pragma endregion Object: WoodPlank1

#pragma region Object: WoodPlank2

	CGameObject* WoodPlank2 = new CPlank();
	WoodPlank2->m_transform.position = glm::vec3(4.0f, -3.0f, 0.0f);
	m_vGameObj.push_back(WoodPlank2);

#pragma endregion Object: WoodPlank2

#pragma region Object: WoodPlank3

	CGameObject* WoodPlank3 = new CPlank();
	WoodPlank3->m_transform.position = glm::vec3(3.0f, 0.0f, 0.0f);
	WoodPlank3->m_transform.rotation.z = 90.0f;
	WoodPlank3->m_transform.scale.y = 1.3f;
	m_vGameObj.push_back(WoodPlank3);

#pragma endregion Object: WoodPlank3

#pragma region Object: WoodPlank4

	CGameObject* WoodPlank4 = new CPlank();
	WoodPlank4->m_transform.position = glm::vec3(3.0f, -0.0f, 0.0f);
	WoodPlank4->m_transform.rotation.z = 90.0f;
	WoodPlank4->m_transform.scale.y = 1.3f;
	m_vGameObj.push_back(WoodPlank4);

#pragma endregion Object: WoodPlank4
	

#pragma region Object: JointHolderPlank

	// Create the first joint object
	CGameObject* jointHolder = new CGameObject();
	m_vGameObj.push_back(jointHolder);
	jointHolder->m_transform.position = glm::vec3(-5.0f, 6.0f, 0.0f);
	jointHolder->m_transform.rotation.z = 90.0f;
	CSpriteRender* jointSprite = jointHolder->CreateComponent<CSpriteRender>();
	jointSprite->SetSprite("WoodPlank");
	CRigidBody2D* jointBody = jointHolder->CreateComponent<CRigidBody2D>();
	jointBody->SetBodyType(b2BodyType::b2_staticBody);
	// Create Fixture
	b2PolygonShape jointPolygonShape;
	float32 jointHalfWidth =
		(jointSprite->GetSprite()->GetWidth() * jointHolder->m_transform.scale.x) / 2.0f / util::PIXELUNIT;
	float32 jointHalfHeight =
		(jointSprite->GetSprite()->GetHeight() * jointHolder->m_transform.scale.y) / 2.0f / util::PIXELUNIT;
	jointPolygonShape.SetAsBox(jointHalfWidth, jointHalfHeight);
	// Define the fixture using the shape
	b2FixtureDef jointFixtureDef;
	jointFixtureDef.shape = &jointPolygonShape;
	jointFixtureDef.isSensor = false;
	jointFixtureDef.density = 1.0f;
	jointFixtureDef.friction = 0.1f;
	// Create the fixture in the body
	jointBody->GetBody()->CreateFixture(&jointFixtureDef);

	// Create the second join object
	CGameObject* jointHanger = new CGameObject();
	m_vGameObj.push_back(jointHanger);
	jointHanger->m_transform.position = glm::vec3(-5.0f, 5.0f, 0.0f);
	CSpriteRender* hangerSprite = jointHanger->CreateComponent<CSpriteRender>();
	CRigidBody2D* hangerBody = jointHanger->CreateComponent<CRigidBody2D>();
	// Set Sprite
	hangerSprite->SetSprite("WoodPlank");
	// Create Fixture
	b2PolygonShape hangerPolygonShape;
	float32 hangerHalfWidth =
		(hangerSprite->GetSprite()->GetWidth() * jointHanger->m_transform.scale.x) / 2.0f / util::PIXELUNIT;
	float32 hangerHalfHeight =
		(hangerSprite->GetSprite()->GetHeight() * jointHanger->m_transform.scale.y) / 2.0f / util::PIXELUNIT;
	hangerPolygonShape.SetAsBox(hangerHalfWidth, hangerHalfHeight);
	// Define the fixture using the shape
	b2FixtureDef hangerFixtureDef;
	hangerFixtureDef.shape = &hangerPolygonShape;
	hangerFixtureDef.isSensor = false;
	hangerFixtureDef.density = 1.0f;
	hangerFixtureDef.friction = 0.1f;
	// Create the fixture in the body
	hangerBody->GetBody()->CreateFixture(&hangerFixtureDef);

	// Create a joint
	b2RevoluteJointDef revoluteDef;
	revoluteDef.bodyA = jointBody->GetBody();
	revoluteDef.bodyB = hangerBody->GetBody();
	revoluteDef.collideConnected = false;
	revoluteDef.localAnchorA.Set(0, 0);//center of the box
	revoluteDef.localAnchorB.Set(0, 0.8f);//top of the box
	revoluteDef.enableMotor = true;
	revoluteDef.maxMotorTorque = 20.0f;
	revoluteDef.motorSpeed = util::ToRad(360.0f);
	m_box2DWorld->CreateJoint(&revoluteDef);

#pragma endregion Object: JointHolderPlank

#pragma region Object: PrismaticJointPlank

	// Create the first joint object
	CGameObject* prisJointHolder = new CGameObject();
	m_vGameObj.push_back(prisJointHolder);
	prisJointHolder->m_transform.position = glm::vec3(5.0f, 6.0f, 0.0f);
	prisJointHolder->m_transform.rotation.z = 90.0f;
	CSpriteRender* prisJointSprite = prisJointHolder->CreateComponent<CSpriteRender>();
	prisJointSprite->SetSprite("WoodPlank");
	CRigidBody2D* prisJointBody = prisJointHolder->CreateComponent<CRigidBody2D>();
	prisJointBody->SetBodyType(b2BodyType::b2_staticBody);
	// Create Fixture
	b2PolygonShape prisJointPolygonShape;
	float32 prisJointHalfWidth =
		(prisJointSprite->GetSprite()->GetWidth() * prisJointHolder->m_transform.scale.x) / 2.0f / util::PIXELUNIT;
	float32 prisJointHalfHeight =
		(prisJointSprite->GetSprite()->GetHeight() * prisJointHolder->m_transform.scale.y) / 2.0f / util::PIXELUNIT;
	prisJointPolygonShape.SetAsBox(prisJointHalfWidth, prisJointHalfHeight);
	// Define the fixture using the shape
	b2FixtureDef prisJointFixtureDef;
	prisJointFixtureDef.shape = &prisJointPolygonShape;
	prisJointFixtureDef.isSensor = false;
	prisJointFixtureDef.density = 1.0f;
	prisJointFixtureDef.friction = 0.1f;
	// Create the fixture in the body
	prisJointBody->GetBody()->CreateFixture(&prisJointFixtureDef);

	// Create the second join object
	CGameObject* prisJointHanger = new CGameObject();
	m_vGameObj.push_back(prisJointHanger);
	prisJointHanger->m_transform.position = glm::vec3(8.0f, 5.0f, 0.0f);
	CSpriteRender* prisHangerSprite = prisJointHanger->CreateComponent<CSpriteRender>();
	CRigidBody2D* prisHangerBody = prisJointHanger->CreateComponent<CRigidBody2D>();
	// Set Sprite
	prisHangerSprite->SetSprite("WoodPlank");
	// Create Fixture
	b2PolygonShape prisHangerPolygonShape;
	float32 prisHangerHalfWidth =
		(prisHangerSprite->GetSprite()->GetWidth() * prisJointHanger->m_transform.scale.x) / 2.0f / util::PIXELUNIT;
	float32 prisHangerHalfHeight =
		(prisHangerSprite->GetSprite()->GetHeight() * prisJointHanger->m_transform.scale.y) / 2.0f / util::PIXELUNIT;
	prisHangerPolygonShape.SetAsBox(prisHangerHalfWidth, prisHangerHalfHeight);
	// Define the fixture using the shape
	b2FixtureDef prisHangerFixtureDef;
	prisHangerFixtureDef.shape = &prisHangerPolygonShape;
	prisHangerFixtureDef.isSensor = false;
	prisHangerFixtureDef.density = 1.0f;
	prisHangerFixtureDef.friction = 0.1f;
	// Create the fixture in the body
	prisHangerBody->GetBody()->CreateFixture(&prisHangerFixtureDef);

	// Create a joint
	b2PrismaticJointDef prismaticDef;
	prismaticDef.bodyA = prisJointBody->GetBody();
	prismaticDef.bodyB = prisHangerBody->GetBody();
	prismaticDef.localAxisA.Set(0, 1);
	prismaticDef.collideConnected = false;
	prismaticDef.localAnchorA.Set(0, 0);//center of the box
	prismaticDef.localAnchorB.Set(0, 0.8f);//top of the box
	prismaticDef.enableMotor = true;
	prismaticDef.maxMotorForce = 500;//this is a powerful machine after all...
	prismaticDef.motorSpeed = 5;//5 units per second in positive axis direction
	m_box2DWorld->CreateJoint(&prismaticDef);

#pragma endregion Object: PrismaticJointPlank

}

void CRichardTest::BeginPlay()
{
	__super::BeginPlay();
	

}

void CRichardTest::UpdateScene(float _tick)
{
	__super::UpdateScene(_tick);
	

}
