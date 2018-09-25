#pragma once

// Global Include
#include "Utility.h"

class CInput
{
public:

	// Singletom Functions
	static CInput* GetInstance();
	static void DestroyInstance();

	// Member Functions
	void InitializeInput();

	static void InitKeyDown(unsigned char key, int x, int y);
	static void InitKeyUp(unsigned char key, int x, int y);
	static void InitMouse(int button, int glutState, int x, int y);
	static void InitMouseMotion(int x, int y);

	void Update(float _tick);
	void RefreshKeys();

	std::vector<class XBOXController*> Players;

private:
	// Make Singleton
	CInput();
	~CInput();

	void Keyboard_Down(unsigned char key, int x, int y);
	void Keyboard_Up(unsigned char key, int x, int y);
	void Mouse(int button, int glutState, int x, int y);
	void MouseMotion(int x, int y);

	// Make this Instance Non-copyable
	CInput(const CInput& _kr) = delete;
	CInput& operator= (const CInput& _kr) = delete;

protected:
	static CInput* s_pInput;

private: // Private Member Variables


public: // Public Variables

	unsigned int g_cKeyState[255];
	unsigned int g_cMouseState[3];
	b2Vec2 g_mousePosition;

};