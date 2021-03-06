
// Engine Include
#include "Engine.h"

// Static Variable
CTime* CTime::s_pTime = nullptr;

CTime* CTime::GetInstance()
{
	if (s_pTime == nullptr)
	{
		s_pTime = new CTime();
	}
	
	return s_pTime;
}

void CTime::DestroyInstance()
{
	delete s_pTime;
	s_pTime = nullptr;
}

void CTime::Initialize()
{
	timeScale = 1.0f;
	oldTime = (float)glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	tickTime = 0.01666666f;
	deltaTimeTick = 0.0f;
}

void CTime::Update()
{
	newTime = (float)glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	deltaTime = newTime - oldTime;
	oldTime = newTime;
	deltaTimeTick += deltaTime;
	if (deltaTimeTick >= tickTime)
	{
		deltaTimeTick = 0.0f;
	}
}

float CTime::GetDeltaTime() const
{
	return deltaTime;
}

float CTime::GetTick() const
{
	return deltaTimeTick;
}

void CTime::SetTimeScale(float _timeScale)
{
	timeScale = _timeScale;
}

float CTime::GetTimeScale() const
{
	return timeScale;
}