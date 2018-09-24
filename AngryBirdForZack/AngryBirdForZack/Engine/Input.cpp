
// Engine Include
#include "Engine.h"

// Static Variable
CInput* CInput::s_pInput = nullptr;

CInput::CInput()
{}

CInput::~CInput()
{}

CInput* CInput::GetInstance()
{
	if (s_pInput == nullptr)
	{
		s_pInput = new CInput();
	}
	return s_pInput;
}

void CInput::DestroyInstance()
{
	delete s_pInput;
	s_pInput = nullptr;
}


void CInput::InitializeInput()
{
	for (unsigned char i = 0; i < 255; i++)
	{
		g_cKeyState[i] = INPUT_RELEASED;
	}
	for (unsigned char i = 0; i < 3; i++)
	{
		g_cMouseState[i] = INPUT_RELEASED;
	}

	glutKeyboardFunc(InitKeyDown);
	glutKeyboardUpFunc(InitKeyUp);
	glutMouseFunc(InitMouse);

	Players.push_back(new XBOXController(1));
	Players.push_back(new XBOXController(2));
	Players.push_back(new XBOXController(3));
	Players.push_back(new XBOXController(4));
}

void CInput::Keyboard_Down(unsigned char key, int x, int y)
{
	if (g_cKeyState[key] != INPUT_HOLD && g_cKeyState[key] != INPUT_FIRST_PRESS)
	{
		g_cKeyState[key] = INPUT_FIRST_PRESS;
		return;
	}
	else g_cKeyState[key] = INPUT_HOLD;
}

void CInput::Keyboard_Up(unsigned char key, int x, int y)
{
	g_cKeyState[key] = INPUT_RELEASED;
}

void CInput::Mouse(int button, int glutState, int x, int y)
{
	// Set the mouse position
	g_mousePosition = b2Vec2((float32)x, (float32)y);

	// If one of the button fire
	if (button < 3)
	{
		if (glutState == GLUT_DOWN && g_cMouseState[button] == INPUT_RELEASED)
		{
			g_cMouseState[button] = INPUT_FIRST_PRESS;
		}
		else if (glutState == GLUT_DOWN && g_cMouseState[button] == INPUT_FIRST_PRESS)
		{
			g_cMouseState[button] = INPUT_HOLD;
		}
		else if (glutState == GLUT_UP)
		{
			g_cMouseState[button] = INPUT_RELEASED;
		}
	}
}

void CInput::InitKeyDown(unsigned char key, int x, int y)
{
		CInput::GetInstance()->Keyboard_Down(key, x, y);
}

void CInput::InitKeyUp(unsigned char key, int x, int y)
{
	CInput::GetInstance()->Keyboard_Up(key, x, y);
}

void CInput::InitMouse(int button, int glutState, int x, int y)
{
	CInput::GetInstance()->Mouse(button, glutState, x, y);
}

void CInput::Update(float _tick)
{
	for (auto& player : Players)
	{
		player->Update();
	}

	RefreshKeys();
}

void CInput::RefreshKeys()
{
	for (unsigned char i = 0; i < 255; i++)
	{
		if (g_cKeyState[i] == INPUT_FIRST_PRESS)
		{
			g_cKeyState[i] = INPUT_HOLD;
		}
	}
	for (unsigned char i = 0; i < 3; i++)
	{
		if (g_cMouseState[i] == INPUT_FIRST_PRESS)
		{
			g_cMouseState[i] = INPUT_HOLD;
		}
	}
}

