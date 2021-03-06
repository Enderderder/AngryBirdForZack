
// Engine Include
#include "Engine.h"

// Static Variable
CAssetMgr* CAssetMgr::s_pAssetMgr = nullptr;

CAssetMgr* CAssetMgr::GetInstance()
{
	if (s_pAssetMgr == nullptr)
	{
		s_pAssetMgr = new CAssetMgr();
	}

	return s_pAssetMgr;
}

void CAssetMgr::DestroyInstance()
{
	delete s_pAssetMgr;
	s_pAssetMgr = nullptr;
}

CAssetMgr::CAssetMgr() {}

CAssetMgr::~CAssetMgr() 
{
	// Clean all the Sprite inside the map
	for (const auto &iter : m_spriteMap)
	{
		delete (iter.second);
	}
	// Clear the sprite map
	m_spriteMap.clear();

	// Clear the program map
	m_programMap.clear();
}

void CAssetMgr::InitializeAssets()
{
	/** Initialize Programs */
	CreateProgram("DefaultSpriteProgram", "Engine/Shaders/Sprite.vs", "Engine/Shaders/Sprite.fs");

	/** Initialize Sprites */
	CreateSprite("DefaultSprite", "Resources/Sprites/DefaultSprite.png");
	CreateSprite("RedBird_Normal", "Resources/Sprites/Birds/RedBird_Normal.png");
	CreateSprite("Pig_Normal", "Resources/Sprites/Pigs/Pig_Normal.png");
	CreateSprite("Ground", "Resources/Sprites/Ground/Ground.png");
	CreateSprite("WoodPlank", "Resources/Sprites/Planks/WoodPlank.png");
	CreateSprite("Slingshot", "Resources/Sprites/Slingshot/Slingshot.png");
	CreateSprite("AngryBirdBG", "Resources/Sprites/Background/AngryBirdBG.png");

	CreateSprite("Triangle", "Resources/Sprites/Player2.png");
	CreateSprite("Block", "Resources/Sprites/10Block.png");
	CreateSprite("Player", "Resources/Sprites/spaceship.png");
	CreateSprite("Gate", "Resources/Sprites/gate.png");
	CreateSprite("Collectable", "Resources/Sprites/collectable.png");
	
}


CSprite* CAssetMgr::GetSprite(std::string _name) const
{
	for (auto iter = m_spriteMap.begin(); iter != m_spriteMap.end(); ++iter)
	{
		if (iter->first == _name)
		{
			return iter->second;
		}
	}

	CDebug::Log("Unable to grab sprite from name.");
	return nullptr;
}

GLuint CAssetMgr::GetProgramID(std::string _name) const
{
	for (auto iter = m_programMap.begin(); iter != m_programMap.end(); ++iter)
	{
		if (iter->first == _name)
		{
			return iter->second;
		}
	}

	CDebug::Log("Unable to grab program ID from name.");
	return NULL;
}

void CAssetMgr::CreateProgram(std::string _name, const char* _vertexPath, const char* _fragmentPath)
{
	GLuint newProgram = ShaderLoader::CreateProgram(_vertexPath, _fragmentPath);

	m_programMap.insert(std::pair<std::string, GLuint>(_name, newProgram));
}

void CAssetMgr::CreateSprite(std::string _name, const char* _pathName)
{
	CSprite* newSprite = new CSprite();
	newSprite->CreateSprite(_pathName);

	m_spriteMap.insert(std::pair<std::string, CSprite*>(_name, newSprite));
}
