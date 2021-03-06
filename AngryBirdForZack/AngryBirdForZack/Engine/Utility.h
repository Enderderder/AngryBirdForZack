#ifndef UTILITY_H
#define UTILITY_H

// OpenGL Include ------------------------------------------------------------------------------
#include <glew.h>
#include <freeglut.h>
#include <SOIL.h>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
#include <fmod.hpp>
#include <Box2D.h>
#include <glm/common.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H

// Library Include -----------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <strstream>
#include <Windows.h>
#include <cassert>
#include <thread>
#include <memory>
#include <sstream>

//#include <vld.h> // Memory Leak Detector

//----------------------------------------------------------------------------------------------

namespace util
{
	// Define the screen size
	static int SCR_WIDTH = 1366;
	static int SCR_HEIGHT = 768;

	// Define the Pixel Per Unit
	static int PIXELUNIT = 50;

	// Useful Functions
	static float ToRad(float _degree)
	{
		return (_degree / 180) * b2_pi;
	}

	static float ToDeg(float _radian)
	{
		return _radian * (180 / b2_pi);
	}

	template<typename T>
	static std::string ToString(const T& _value)
	{
		std::strstream theStream;
		theStream << _value << std::ends;
		return (theStream.str());
	}

}

// Define Struct -------------------------------------------------------------------------------

struct DebugTimer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	DebugTimer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	
	~DebugTimer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		

		float ms = duration.count();
		std::cout << "Debug Timer took " << ms << " ms \n";
	}

};

struct Transform
{
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	//glm::vec3 direction = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
};

enum Tag
{
	Default,
	Player,
	UI,
	Bird,
	Pig,
	Ground,
	Plank,
	Slingshot,
};

enum InputState 
{
	INPUT_FIRST_RELEASE,	// First frame of Up state 
	INPUT_RELEASED,			// Default State (Up) 
	INPUT_FIRST_PRESS,		// First frame of Down state 
	INPUT_HOLD,				// Key is held Down 
};

enum InputMouse 
{ 
	MOUSE_LEFT = 0, 
	MOUSE_MIDDLE, 
	MOUSE_RIGHT 
};

//----------------------------------------------------------------------------------------------

#endif // !_UTILITY_H
