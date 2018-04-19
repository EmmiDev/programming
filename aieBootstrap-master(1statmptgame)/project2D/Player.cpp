#include "Player.h"
#include "Renderer2D.h"
#include "Application2D.h"
#include "Input.h"

Player::Player()
{
	m_Player = new aie::Texture("./Textures/Amber-1.png");
	x = 300;
	y = 300;
}

Player::~Player()
{
	delete m_Player;
}

void Player::Draw(aie::Renderer2D* Renderer2D)
{
	Renderer2D->drawSprite(m_Player, x, y);
}

void Player::update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	//arrow keys to move the player
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		y += 150.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		y -= 150.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		x -= 150.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		x += 150.0f * deltaTime;
}