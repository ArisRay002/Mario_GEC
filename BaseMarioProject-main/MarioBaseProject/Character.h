#pragma once
#include "SDL.h"
#include "Commons.h"
#include"LevelMap.h"
#include <iostream>

using namespace std;

class Texture2D;

class Character
{
public:
	Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap*map);
	~Character();

	//polymorphism 
	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void SetPosition(Vector2D new_position);
	Vector2D GetPosition();
	void AddGravity(float deltaTime);
	void Jump();
	float GetCollisionRadius();
	bool IsJumping() { return m_jumping; }
	void CancelJump() { m_jumping = false; }
	Rect2D GetCollisionBox();

		
protected:
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;
	bool m_moving_left;
	bool m_moving_right;
	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);
	bool m_jumping;
	bool m_can_jump;
	float m_jump_force;
	FACING m_facing_direction;
	float m_collision_radius;

private:
	LevelMap* m_current_level_map;
};

