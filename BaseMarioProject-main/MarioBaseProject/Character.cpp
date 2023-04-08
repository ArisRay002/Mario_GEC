#include "Character.h"
#include "Texture2D.h"
using namespace std;

Character::Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position)
{
	SDL_Renderer* m_renderer = renderer;
	Vector2D m_position = start_position;
	Texture2D* m_texture = new Texture2D(m_renderer);
	if (!m_texture->LoadFromFile(imagePath))
	{
		std::cout << "Failed to load background texture!" << std::endl;	
	}
}

Character::~Character()
{
	m_renderer = nullptr;
}

void Character::Render()
{
	m_texture->Render(m_position, SDL_FLIP_NONE);
}

void Character::Update(float deltaTime, SDL_Event e)
{
	switch (e.type)
	{
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym)
			{
				case SDLK_LEFT:
					m_position.x -= 1;
				break;
				case SDLK_RIGHT:
					m_position.x += 1;
				break;
			}
			
		break;
	}
	
}

void Character::SetPosition(Vector2D new_position)
{
	m_position = new_position;
}

Vector2D Character::GetPosition()
{
	return Vector2D(m_position);
}
