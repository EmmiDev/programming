#include "Player.h"
#include "Renderer2D.h"
#include "Application2D.h"
#include "Input.h"
#include <assert.h>

Player::Player()
{
	m_Player = new aie::Texture("./Textures/Amber-1.png");
	x = 300;
	y = 300;
	assert(m_Player);
}

Player::~Player()
{
	delete m_Player;
}

// getting x as it is a privite varible and making it more accessable
float Player::GetX()
{
	return x;
}
// with this function enables the code to set the x position a lot easier
void Player::SetX(float newX)
{
	x = newX;
}

float Player::GetY()
{
	return y;
}

void Player::SetY(float newY)
{
	y = newY;
}

// Drawing the Player
void Player::Draw(aie::Renderer2D* Renderer2D)
{
	Renderer2D->drawSprite(m_Player, x, y);
}

// creates the player controls
void Player::update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	//arrow keys to move the player
	if (input->isKeyDown(aie::INPUT_KEY_W))
		y += 170.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_S))
		y -= 170.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_A))
		x -= 170.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_D))
		x += 170.0f * deltaTime;
}