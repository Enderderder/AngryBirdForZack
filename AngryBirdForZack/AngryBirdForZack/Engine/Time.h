#pragma once

// Global Include
#include "Utility.h"

class CTime
{

#pragma region Singleton

public:
	static CTime* GetInstance();
	static void DestroyInstance();

private:
	CTime() {}
	~CTime() {}

	// Non-copyable
	CTime(const CTime& _kr) = delete;
	CTime& operator= (const CTime& _kr) = delete;

protected:
	// Singleton Instance
	static CTime* s_pTime;

#pragma endregion Singleton

private:

	float deltaTime;
	float oldTime, newTime;
	float deltaTimeTick;
	float tickTime;
	float timeScale;

public:

	void Initialize();
	void Update();

	float GetDeltaTime() const;
	float GetTick() const;
	
	void SetTimeScale(float _timeScale);
	float GetTimeScale() const;

};