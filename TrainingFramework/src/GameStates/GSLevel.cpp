#include "GSLevel.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSLevel::GSLevel()
{

}


GSLevel::~GSLevel()
{
}



void GSLevel::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("background-play");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	//button lv1
	texture = ResourceManagers::GetInstance()->GetTexture("play-now");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, 200);
	button->SetSize(200, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Play);
		});
	m_listButton.push_back(button);

	// button lv2
	texture = ResourceManagers::GetInstance()->GetTexture("credit");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, 300);
	button->SetSize(200, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Credit);
		});
	m_listButton.push_back(button);

	//button back
	texture = ResourceManagers::GetInstance()->GetTexture("exit");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, 400);
	button->SetSize(200, 50);
	button->SetOnClick([]() {
		exit(0);
		});
	m_listButton.push_back(button);



	//text game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	m_Text_gameName = std::make_shared< Text>(shader, font, "CATCH BOOM", TEXT_COLOR::GREEN, 1.0);
	m_Text_gameName->Set2DPosition(Vector2(screenWidth / 2 - 80, 120));
}

void GSLevel::Exit()
{
}


void GSLevel::Pause()
{

}

void GSLevel::Resume()
{

}


void GSLevel::HandleEvents()
{

}

void GSLevel::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSLevel::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSLevel::Update(float deltaTime)
{
	m_BackGround->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSLevel::Draw()
{
	m_BackGround->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_Text_gameName->Draw();
}


