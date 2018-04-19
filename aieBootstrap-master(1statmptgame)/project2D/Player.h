#pragma once
#include "Texture.h"
#include "Renderer2D.h"
#include "Application2D.h"
#include "Input.h" 

class Player
{
public:
	Player();
	~Player();

	void Draw(aie::Renderer2D* Renderer2D);
	void update(float deltaTime);

private:

	int m_nHealth;

	aie::Texture*		m_Player;
	float x;
	float y;
};