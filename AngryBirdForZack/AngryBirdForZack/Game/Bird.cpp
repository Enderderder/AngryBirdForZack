
// This Include
#include "Bird.h"

// Engine Include
#include "Engine/Engine.h"

CBird::CBird()
{
	// Set the bird to not process so its not affect by any input
	m_isProcessing = false;

	// Set the maximun distance the bird can drag back from the slingshot
	m_slingShotRadius = 2.0f;

	m_spriteRender = CreateComponent<CSpriteRender>();
	m_rigidBody = CreateComponent<CRigidBody2D>();
}

CBird::~CBird()
{}

void CBird::BeginPlay()
{
	__super::BeginPlay();
	
	ProcessBird();
}

void CBird::Update(float _tick)
{
	__super::Update(_tick);
	
	if (m_isFollowingMouse)
	{
		ProcessMouseDrag();
	}
}

void CBird::OnCollisionEnd(CGameObject* _other)
{
	__super::OnCollisionEnd(_other);
	

}

void CBird::OnCollisionEnter(CGameObject* _other)
{
	__super::OnCollisionEnter(_other);
	


}

void CBird::OnMouseDown()
{
	__super::OnMouseDown();
	
	if (m_isProcessing)
	{
		m_isFollowingMouse = true;
	}
}

void CBird::ProcessBird()
{
	m_isProcessing = true;
}

void CBird::UnProcessBird()
{
	m_isProcessing = false;
}

void CBird::ProcessMouseDrag()
{
	if (CInput::GetInstance()->g_cMouseState[0] != INPUT_RELEASED)
	{
		// Get the Scene
		CScene* scene =
			CSceneMgr::GetInstance()->GetRunningScene();

		// Get the mouse world position
		b2Vec2 mousPosition =
			CInput::GetInstance()->g_mousePosition;
		mousPosition = scene->ConvertToWorldPosition(mousPosition);
		b2Vec2 mouseWorldPosition =
			b2Vec2(mousPosition.x, mousPosition.y);

		// Get the direction from slingshot to the mouse
		//b2Vec2 b2SlingShotPos = 
		//	b2Vec2(slingShot->m_transform.position.x, slingShot->m_transform.position.y);
		//b2Vec2 b2BirdPos = b2Vec2(m_transform.position.x, m_transform.position.y);
		//b2Vec2 slingShotToMouse = (b2SlingShotPos - b2BirdPos); 
		
		m_transform.position.x = mouseWorldPosition.x;
		m_transform.position.y = mouseWorldPosition.y;

		// If its within the max slingshot radius
		//if (slingShotToMouse.Length() <= m_slingShotRadius)
		//{
		//	// Move the bird to where ever mouse is
		//	m_transform.position.x = mouseWorldPosition.x;
		//	m_transform.position.y = mouseWorldPosition.y;
		//}
// 		else
// 		{
// 			// Get the direction normalized
// 			b2Vec2 dirSlingShotToMouse = slingShotToMouse;
// 			dirSlingShotToMouse *= (b2SlingShotPos - b2BirdPos).Normalize();
// 			
// 			// Times with the max length
// 			b2Vec2 birdPosition = dirSlingShotToMouse;
// 			birdPosition *= m_slingShotRadius;
// 
// 			// Move the bird
// 			m_transform.position.x = birdPosition.x;
// 			m_transform.position.y = birdPosition.y;
// 		}
	}
	else // When player release the mouse
	{
		m_isFollowingMouse = false;
	}
}