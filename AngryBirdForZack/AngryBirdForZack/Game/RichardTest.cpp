
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
	// Configure Camera
	m_mainCamera = new CCamera();

	// 


	CGameObject* redBird = new CRedBird();
	redBird->m_transform.position = glm::vec3(1.0f, 1.0f, 0.0f);
	m_vGameObj.push_back(redBird);
}

void CRichardTest::BeginPlay()
{
	__super::BeginPlay();
	

}

void CRichardTest::UpdateScene(float _tick)
{
	__super::UpdateScene(_tick);
	

}
