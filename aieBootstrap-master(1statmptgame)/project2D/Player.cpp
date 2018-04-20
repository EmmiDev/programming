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
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		y += 170.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		y -= 170.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		x -= 170.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		x += 170.0f * deltaTime;
}