#include "GameScreenLevel1.h"
#include "Texture2D.h"
#include <iostream>
class Texture2D;
class GameScreenLevel1 : GameScreen
{
	
};

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel();
}

GameScreenLevel1::~GameScreenLevel1()
{
	delete Texture2D*;
}

void GameScreenLevel1::Render()
{

}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{

}

bool GameScreenLevel1::SetUpLevel()
{
	return false;
}
