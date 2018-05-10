#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Player.h"
#include "Level.h"
#include "Level 2.h"
#include "Level 3.h"
#include "Level 4.h"
#include "Level 5.h"
#include <assert.h>

Application2D::Application2D() {
}

Application2D::~Application2D() {
}

bool Application2D::startup() {

	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");

	m_Level = new Level();
	m_Level2 = new Level2();
	m_Level3 = new Level3();
	m_Level4 = new Level4();
	m_Level5 = new Level5();

	assert(m_Level);
	assert(m_Level2);
	assert(m_Level3);
	assert(m_Level4);
	assert(m_Level5);

	m_Level->ConnectDoor(TOP, m_Level2); //connects the rooms one way
	m_Level2->ConnectDoor(BOTTOM, m_Level); // connects the rooms the other way

	m_Level->ConnectDoor(RIGHT, m_Level3);
	m_Level3->ConnectDoor(LEFT, m_Level);

	m_Level->ConnectDoor(BOTTOM, m_Level4);
	m_Level4->ConnectDoor(TOP, m_Level);

	m_Level->ConnectDoor(LEFT, m_Level5);
	m_Level5->ConnectDoor(RIGHT, m_Level);


 // detects the room your in, used so all the rooms aren't drawn all at once
	m_currentRoom = m_Level;
	//m_wall1 = new aie::Texture("./textures/wall-1.png");
	//m_wall2 = new aie::Texture("./textures/wall-2.png");
	//m_wall3 = new aie::Texture("./textures/wall-3.png");
	//m_wall4 = new aie::Texture("./textures/wall-4.png");
	//m_DmFloor = new aie::Texture("./textures/clean-floor.png");
	m_Key = new aie::Texture("./textures/Key.png");
	m_Player = new Player();

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown()
{
	delete m_font;
	delete m_Player;
	delete m_Level;
	delete m_Level2;
	delete m_Key;
	//delete m_wall1;
	//delete m_wall2;
	//delete m_wall3;
	//delete m_wall4;
	//delete m_DmFloor;
	delete m_shipTexture;
	delete m_texture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	//calling the player
	m_Player->update(deltaTime);

	//PLAYER walks beyond TOP wall, taken to TOP room
	if (m_Player->GetY() > 700 && m_currentRoom->GetDoor(TOP) != nullptr) // checking the room is valid
	{
		assert(m_Level);
		assert(m_Level2);
		m_currentRoom = m_currentRoom->GetDoor(TOP);
		//next room PLAYER position
		m_Player->SetY(064);
	}

	if (m_Player->GetX() > 940 && m_currentRoom->GetDoor(RIGHT) != nullptr)
	{
		assert(m_Level);
		assert(m_Level3);
		m_currentRoom = m_currentRoom->GetDoor(RIGHT);
		//next room PLAYER position
		m_Player->SetX(280);
	}

//_________________________________________________________________________________

	// PLAYER goes beyond BOTTOM wall, taken to BOTTOM room
	if (m_Player->GetY() < 10 && m_currentRoom->GetDoor(BOTTOM) != nullptr)
	{
		assert(m_Level);
		assert(m_Level4);
		m_currentRoom = m_currentRoom->GetDoor(BOTTOM);
		// next room PLAYER position
		m_Player->SetY(650);
	}

	if (m_Player->GetX() < 200 && m_currentRoom->GetDoor(LEFT) != nullptr)
	{
		assert(m_Level);
		assert(m_Level5);
		m_currentRoom = m_currentRoom->GetDoor(LEFT);
		// next room PLAYER position
		m_Player->SetX(690);
	}
	//_____________________________________________________________________________


	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	assert(m_2dRenderer);
	assert(m_Player);
	assert(m_currentRoom);

	// set the camera position before it begins rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	//detcts the current room your in and draws it
	m_currentRoom->Draw(m_2dRenderer);


	m_Player->Draw(m_2dRenderer);

	m_2dRenderer->drawSprite(m_Key, 500, 500);
	// draw a thin line
	//m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);

	// 60 second countdown
	int countDown = 60 - (int)m_timer;
	char count[10];
	sprintf_s(count, 10, "%i", countDown);
	m_2dRenderer->drawText(m_font, count, 0, 720 - 32);

	// done drawing sprites
	m_2dRenderer->end();
}