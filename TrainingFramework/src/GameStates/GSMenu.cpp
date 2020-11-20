#include "GSMenu.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine
extern bool isStart;
GSMenu::GSMenu()
{

}


GSMenu::~GSMenu()
{
}



void GSMenu::Init()
{


	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("background-play");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	//BackGround
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	//catch boom
	texture = ResourceManagers::GetInstance()->GetTexture("catch_boom");
	m_GameName = std::make_shared<Sprite2D>(model, shader, texture);
	m_GameName->Set2DPosition(screenWidth / 2, 100);
	m_GameName->SetSize(200, 100);

	//play button
	texture = ResourceManagers::GetInstance()->GetTexture("button_play_3");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, 220);
	button->SetSize(120, 55);
	button->SetOnClick([]() {
		
		ResourceManagers::GetInstance()->PlaySound("click", false);
		isStart = false;
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Map);
		});
	m_listButton.push_back(button);

	// button credit
	texture = ResourceManagers::GetInstance()->GetTexture("button_credit_2");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, 300);
	button->SetSize(120, 55);
	button->SetOnClick([]() {
		ResourceManagers::GetInstance()->PlaySound("click", false);
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Credit);
		});
	m_listButton.push_back(button);
	
	//exit button
	texture = ResourceManagers::GetInstance()->GetTexture("button_quit_2");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, 380);
	button->SetSize(120, 55);
	button->SetOnClick([]() {
		ResourceManagers::GetInstance()->PlaySound("click", false);
		exit(0);
		});
	m_listButton.push_back(button);

	//text game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	m_Text_gameName = std::make_shared< Text>(shader, font, "", TEXT_COLOR::GREEN, 1.0);
	m_Text_gameName->Set2DPosition(Vector2(screenWidth / 2 - 80, 120));


}

void GSMenu::Exit()
{
}


void GSMenu::Pause()
{

}

void GSMenu::Resume()
{

}


void GSMenu::HandleEvents()
{

}

void GSMenu::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSMenu::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSMenu::Update(float deltaTime)
{
	m_BackGround->Update(deltaTime);
	m_GameName->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSMenu::Draw()
{
	m_BackGround->Draw();
	m_GameName->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_Text_gameName->Draw();
}
