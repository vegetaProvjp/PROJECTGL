#include "GSSuccess.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine
extern bool isStart;
GSSuccess::GSSuccess()
{

}


GSSuccess::~GSSuccess()
{
}



void GSSuccess::Init()
{


	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("2");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	//button back
	texture = ResourceManagers::GetInstance()->GetTexture("button_back_2");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, 50);
	button->SetSize(125, 55);
	button->SetOnClick([]() {
		ResourceManagers::GetInstance()->PlaySound("click", false);
		GameStateMachine::GetInstance()->PopState();
		GameStateMachine::GetInstance()->PopState();
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	m_text = std::make_shared<Text>(shader, font, "SUCCESS !!", TEXT_COLOR::RED, 2.0);
	m_text->Set2DPosition(screenWidth/2, screenHeight/2);
}

void GSSuccess::Exit()
{
}


void GSSuccess::Pause()
{

}

void GSSuccess::Resume()
{

}


void GSSuccess::HandleEvents()
{

}

void GSSuccess::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSSuccess::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSSuccess::Update(float deltaTime)
{
	m_BackGround->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSSuccess::Draw()
{
	m_BackGround->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_text->Draw();
}