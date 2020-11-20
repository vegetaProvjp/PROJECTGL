#include "GSPlay.h"
#include "Shaders.h"
#include "Texture.h"
#include "Models.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "SpriteAnimation.h"
#include <PLayer.h>
#include "Cannon.h"
extern int m[3][2];
extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine
bool pause1 = false;
bool isStart = false;
GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{

}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("background-play");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	//BackGround
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);



	//button back


	texture = ResourceManagers::GetInstance()->GetTexture("back_play");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, 100);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		ResourceManagers::GetInstance()->PlaySound("click", false);
		ResourceManagers::GetInstance()->PauseSound("lv1");
		ResourceManagers::GetInstance()->PlaySound("menu", true);
		isStart = pause1 = false;
		m[0][0] = 1;
		m[0][1] = 0;
		m[1][0] = 0;
		m[1][1] = 0;
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);
	//Button pause
	texture = ResourceManagers::GetInstance()->GetTexture("button_start");
	btn_pause = std::make_shared<GameButton>(model, shader, texture);
	btn_pause->Set2DPosition(330, 50);
	btn_pause->SetSize(60, 60);
	btn_pause->SetOnClick([]() {
		ResourceManagers::GetInstance()->PlaySound("click", false);
		pause1 = true;
		});
	//Button resume
	texture = ResourceManagers::GetInstance()->GetTexture("button_resume_3");
	btn_resume = std::make_shared<GameButton>(model, shader, texture);
	btn_resume->Set2DPosition(330, 50);
	btn_resume->SetSize(60, 60);
	btn_resume->SetOnClick([]() {
		ResourceManagers::GetInstance()->m_Soloud.setPauseAll(true);
		pause1 = false;
		});
	// Button start
	texture = ResourceManagers::GetInstance()->GetTexture("set_play");
	btn_start = std::make_shared<GameButton>(model, shader, texture);
	btn_start->Set2DPosition(screenWidth / 2, 50);
	btn_start->SetSize(50, 50);
	btn_start->SetOnClick([]() {
		ResourceManagers::GetInstance()->PlaySound("click", false);
		isStart = true;
		});

	//text game title
	//shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	//std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	//m_score = std::make_shared< Text>(shader, font, "score: 10", TEXT_COLOR::RED, 1.0);
	//m_score->Set2DPosition(Vector2(5, 25));
	// player
	mp_Player = std::make_shared<PLayer>(model, shader, texture);
	mp_Player->GetAnimation()->Set2DPosition(180, 550);

	// cannon la boom
	//m_Cannon = std::make_shared<Cannon>(model, shader, texture);
	//m_Cannon->GetAnimation1()->Set2DPosition(297, 180);
	SetCannon(model);
	//boom la cannon
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("cannon");
	m_Boom = std::make_shared<SpriteAnimation>(model, shader, texture, 1, 0.0f);
	m_Boom->SetSize(70, 70);
	m_Boom->Set2DPosition(340, 205);
}

void GSPlay::Exit()
{

}


void GSPlay::Pause()
{

}

void GSPlay::Resume()
{

}


void GSPlay::HandleEvents()
{
	for (auto c : m_listCannon)
	{
		c->CheckCollision(mp_Player);
		if (c->getCheck())
		{
			GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Success);
		}

	}
}
void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{

	if (isStart == false)
	{ 
		if (bIsPressed)
		{
			Vector2 pos;
			pos = mp_Player->GetAnimation()->Get2DPosition();
			switch (key)
			{
			case KEY_RIGHT:
				pos.x += x_value;
				if (pos.x > MAP_WIDTH - 5)
				{
					pos.x -= x_value;
				}
				mp_Player->GetAnimation()->Set2DPosition(pos.x, pos.y);
				break;
			case KEY_LEFT:
				pos.x -= x_value;
				if (pos.x < 7)
				{
					pos.x += x_value;
				}
				mp_Player->GetAnimation()->Set2DPosition(pos.x, pos.y);
				break;
			}
		}
	}
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
	if (pause1)
	{
		btn_resume->HandleTouchEvents(x, y, bIsPressed);
	}
	else btn_pause->HandleTouchEvents(x, y, bIsPressed);
	if (isStart == false)
	{
		btn_start->HandleTouchEvents(x, y, bIsPressed);
	}
}

void GSPlay::Update(float deltaTime)
{

	if (!pause1)
	{
		if (isStart == false)
		{
			m_BackGround->Update(deltaTime);
			//for (auto obj : m_listSpriteAnimations)
			//{
			//	obj->Update(deltaTime);
			//}

			//Vector2 pos = mp_Player->Get2DPosition();
			//pos.x += 1000 * deltaTime;
			//mp_Player->Set2DPosition(pos);
			mp_Player->GetAnimation()->Update(deltaTime);
			m_Boom->Update(deltaTime);
		}
		else
		{
			m_BackGround->Update(deltaTime);
			m_Boom->Update(deltaTime);
			for (auto c : m_listCannon)
			{
				if (c -> GetTime() < 0.2)
				{
					c->Update(deltaTime);
				
				}
			}
		}
		HandleEvents();
	}

}

void GSPlay::Draw()
{
	
	m_BackGround->Draw();

	//for (auto obj : m_listSpriteAnimations)
	//{
	//	obj->Draw();
	//}
	mp_Player->GetAnimation()->Draw();
	for (auto c : m_listCannon)
	{
		if (c->GetTime() < 0.5)
		{
			c->GetAnimation1()->Draw();
			break;
		}
	}
	m_Boom->Draw();

	for (auto it : m_listButton)
	{
		it->Draw();
	}
	if (pause1)
	{
		btn_resume->Draw();
	}
	else btn_pause->Draw();
	if (isStart == false)
	{
		btn_start->Draw();
	}
}

void GSPlay::SetCannon(std::shared_ptr<Models> model) {
	std::shared_ptr <Cannon> m_Cannon = std::make_shared<Cannon>(model, 297, 180);
	m_listCannon.push_back(m_Cannon);
}