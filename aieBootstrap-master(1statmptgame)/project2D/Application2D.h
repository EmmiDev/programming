#pragma once
#include "Application.h"
#include "Renderer2D.h"

class Player;

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
	aie::Texture*		m_wall1;
	aie::Texture*		m_wall2;
	aie::Texture*		m_wall3;
	aie::Texture*		m_wall4;
	aie::Texture*		m_DmFloor;
	Player*				m_Player;

	float m_cameraX, m_cameraY;
	float m_timer;
};