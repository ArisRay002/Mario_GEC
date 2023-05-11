#pragma once
#include "SDL.h"
#include "Collisions.h"
#include "LevelMap.h"
#include "Texture2D.h"
#include <iostream>
#include "GameScreen.h"
#include "GameScreenLevel1.h"
class PowBlock 
{
	public:
		PowBlock(SDL_Renderer* LevelMap);
		~PowBlock();
		void Render();
		Rect2D GetCollisionBox();
		void TakeHit();
		bool IsAvailable();

	private:
		SDL_Renderer* m_renderer;
		Vector2D m_position;
		Texture2D* m_texture;
		LevelMap* m_level_map;

		float m_single_sprite_w;
		float m_single_sprite_h;
		int m_num_hits_left;


};

