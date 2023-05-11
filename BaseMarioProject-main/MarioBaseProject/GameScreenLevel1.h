#pragma once
#ifndef _GAMESCREENLEVEL1_H
#define _GAMESCREENLEVEL1_H
#include "GameScreen.h"
#include "Commons.h"
#include "Character.h"
#include "CharacterMario.h"
#include"CharacterLuigi.h"
#include "LevelMap.h"

#include <iostream>

class Character;
class CharacterMario;
class Texture2D;

class GameScreenLevel1 : GameScreen
{
	public:
		GameScreenLevel1(SDL_Renderer* renderer);
		~GameScreenLevel1();

		void Render();
		void Update(float deltaTime, SDL_Event e) override;

	private:
		Texture2D* m_background_texture;
		bool SetUpLevel();
		Character* mario;
		Character* luigi;
		void SetLevelMap();
		LevelMap* m_level_map;

};
#endif
