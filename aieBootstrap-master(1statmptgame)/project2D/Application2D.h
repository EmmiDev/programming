#pragma once
#include "Application.h"
#include "Renderer2D.h"

class Player;
class roomBase;
class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;

	roomBase*			m_Level;
	roomBase*			m_Level2;
	roomBase*			m_Level3;
	roomBase*			m_Level4;
	roomBase*			m_Level5;

	roomBase*			m_currentRoom;

	aie::Texture*		m_DmFloor;
	aie::Texture*		m_Key;
	Player*				m_Player;

	float m_cameraX, m_cameraY;
	float m_timer;
};