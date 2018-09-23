
// Engine Include
#include "Engine.h"

CRigiBody2D::CRigiBody2D() :
	m_bodyType(b2_dynamicBody),
	m_bCanRotate(true)
{}

CRigiBody2D::~CRigiBody2D()
{

}

void CRigiBody2D::Update(float _tick)
{
	if (m_body) // If the body is created
	{
		// Sync the transform of the object with the body right after the Box2D Step
		GetOwner()->m_transform.position =
			glm::vec3(m_body->GetPosition().x, m_body->GetPosition().y, m_body->GetAngle());
	}
}

void CRigiBody2D::LateUpdate(float _tick)
{
	if (m_body) // If the body is created
	{
		// Get the obj posistion and rotation
		glm::vec3 objTransform = GetOwner()->m_transform.position;
		float objRotation = GetOwner()->m_transform.rotation.z;

		// Convert glmVec3 to b2Vec2
		b2Vec2 bodyTransform = b2Vec2(objTransform.x, objTransform.y);

		// Set the body to the position and rotation
		m_body->SetTransform(bodyTransform, objRotation);
	}
}

void CRigiBody2D::BeginPlay()
{
	//CreateBody();
	//CreateBody(CSceneMgr::GetInstance()->GetRunningScene()->GetWorld(), )
}

void CRigiBody2D::Awake()
{
	CreateBody();
}

void CRigiBody2D::OnDestroy()
{

}

b2Body* CRigiBody2D::GetBody()
{
	return m_body;
}

void CRigiBody2D::CreateBody()
{
	// Define the dynamic body. We set its position and call the body factory.
	b2BodyDef bodyDef;

	// Set the body type
	bodyDef.type = m_bodyType;

	// Set the initial transform position to the root current root position
	Transform rootTransform = GetOwner()->m_transform;
	bodyDef.position.Set(rootTransform.position.x, rootTransform.position.y);

	// Get the world of current scene and create the body in the world
	m_body = CSceneMgr::GetInstance()->GetRunningScene()->GetWorld()->CreateBody(&bodyDef);

	// Set the transform from the bodyDef to the body
	m_body->SetTransform ( bodyDef.position, (util::ToRad(rootTransform.rotation.z)) );

	// Set if the body can be rotate or not
	m_body->SetFixedRotation(!m_bCanRotate);

	// At the end, Set the body component into UserData for collision listening
	m_body->SetUserData(this);
}

/// Forbiden code
/*
void CRigiBody2D::CreateBody(b2World* _world, b2BodyType BodyType, bool bCanRotate, bool bHasFixture, float Density, float Friction, int fixtureType)
{
	//m_transform.position = glm::vec3(0.0f, 0.0f, 0.0f);
	// Define the dynamic body. We set its position and call the body factory.
	b2BodyDef bodyDef;
	bodyDef.type = BodyType;
	//bodyDef.position.Set(m_transform.position.x, m_transform.position.y);
	m_body = _world->CreateBody(&bodyDef);
	//m_body->SetTransform(bodyDef.position, (m_transform.direction.z / 180) * b2_pi);
	m_body->SetFixedRotation(!bCanRotate);
	// Define another box shape for our dynamic body.
	b2PolygonShape dynamicBox;
	if (GetOwner()->GetComponent<CSpriteRender>())
	{
		dynamicBox.SetAsBox(GetOwner()->GetComponent<CSpriteRender>()->GetSprite()->GetWidth() / 2.0f / util::PIXELUNIT,
			GetOwner()->GetComponent<CSpriteRender>()->GetSprite()->GetWidth() / 2.0f / util::PIXELUNIT);
		if (bHasFixture)
		{
			// Define the dynamic body fixture.
			b2FixtureDef fixtureDef;
			fixtureDef.shape = &dynamicBox;
			// Set the box density to be non-zero, so it will be dynamic.
			fixtureDef.density = Density;
			// Override the default friction.
			fixtureDef.friction = Friction;
			if (fixtureType == 0)
			{
				//fixtureDef.filter.categoryBits = 0x0004;
				//fixtureDef.filter.maskBits = 0x0002;
				fixtureDef.filter.groupIndex = -1;
			}
			else if (fixtureType == 1)
			{
				//fixtureDef.filter.categoryBits = 0x0002;
				//fixtureDef.filter.maskBits = 0x0004;
				fixtureDef.filter.groupIndex = -2;
			}
			// Add the shape to the body.
			m_body->CreateFixture(&fixtureDef);
		}
		else
		{
			m_body->CreateFixture(&dynamicBox, 0.0f);
		}
	}
	else
	{
		if (bHasFixture)
		{
			std::cout << "No sprite component Detected in: " << GetOwner()->m_name << std::endl;
		}
	}
}
*/

void CRigiBody2D::SetBodyType(b2BodyType _bodyType)
{
	m_bodyType = _bodyType;
	if (m_body)
	{
		m_body->SetType(_bodyType);
	}
}

b2BodyType CRigiBody2D::GetBodyType() const
{
	return m_bodyType;
}

void CRigiBody2D::SetCanRotate(bool _b)
{
	m_bCanRotate = _b;
	if (m_body)
	{
		m_body->SetFixedRotation(!_b);
	}
}

bool CRigiBody2D::GetCanRotate() const
{
	return m_bCanRotate;
}

/// Legacy Code
/*
void CRigiBody2D::SetHasFixture(bool _b)
{
	m_bHasFixture = _b;
	if (m_body)
	{
		if (m_body->GetFixtureList() != nullptr && _b == false)
		{
			m_body->DestroyFixture(m_body->GetFixtureList());
		}
		else if (m_body->GetFixtureList() == nullptr && _b == true)
		{

		}
	}
}
bool CRigiBody2D::GetHasFixture() const
{
	return m_bHasFixture;
}
*/