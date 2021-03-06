#pragma once

// Global Include
#include "Utility.h"

struct Character
{
	GLuint      TextureID;	// Texture ID 
	glm::ivec2	Size;		// Size of glyph
	glm::ivec2  Bearing;	// Positon of glyph 
	GLuint      Advance;	// How far to move for the next character
};

class Text {
public:
	Text(std::string font);
	~Text();

	void Render();
	void SetText(std::string newText) { text = newText; };
	void SetColor(glm::vec3 newColor) { color = newColor; };
	void SetScale(GLfloat newScale) { scale = newScale; };
	void SetPosition(glm::vec2 newPosition) { position = newPosition; };

private:
	std::string text;
	GLfloat scale;
	glm::vec3 color;
	glm::vec2 position;

	GLuint m_VAO, m_VBO, m_Program;
	std::map<GLchar, Character> Characters;
};
