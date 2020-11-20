#include "GSCredit.h"


extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSCredit::GSCredit()
{

}


GSCredit::~GSCredit()
{
}



void GSCredit::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("2");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	//button back
	texture = ResourceManagers::GetInstance()->GetTexture("button_back_2");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth/2,100);
	button->SetSize(120, 55);
	button->SetOnClick([]() {
		ResourceManagers::GetInstance()->PlaySound("click", false);
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	// author text
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("ariblk");
	m_Text_gameName = std::make_shared<Text>(shader, font, "Nguyen Lam Sang", TEXT_COLOR::RED, 1.0);
	m_Text_gameName->Set2DPosition(Vector2(screenWidth / 2 - 100, 300));
}

void GSCredit::Exit()
{
}


void GSCredit::Pause()
{

}

void GSCredit::Resume()
{

}


void GSCredit::HandleEvents()
{

}

void GSCredit::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSCredit::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSCredit::Update(float deltaTime)
{

}

void GSCredit::Draw()
{
	m_BackGround->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_Text_gameName->Draw();
}
