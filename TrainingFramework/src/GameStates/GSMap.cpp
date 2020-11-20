#include "GSMap.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine
extern bool isStart;
GSMap::GSMap()
{

}


GSMap::~GSMap()
{
}



void GSMap::Init()
{


	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("map");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	//button lv1
	texture = ResourceManagers::GetInstance()->GetTexture("trans");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(60, 440);
	button->SetSize(30, 30);
	button->SetOnClick([]() {
		ResourceManagers::GetInstance()->PauseSound("menu");
		ResourceManagers::GetInstance()->PlaySound("lv1", true);
		ResourceManagers::GetInstance()->PlaySound("click", false);
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Play);
		});
	m_listButton.push_back(button);

	// button lv2
	texture = ResourceManagers::GetInstance()->GetTexture("trans");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(225, 250);
	button->SetSize(30, 30);
	button->SetOnClick([]() {
		ResourceManagers::GetInstance()->PauseSound("menu");
		ResourceManagers::GetInstance()->PlaySound("click", false);
		ResourceManagers::GetInstance()->PlaySound("lv2", true);
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Play_2);
		});
	m_listButton.push_back(button);
	//button back
	texture = ResourceManagers::GetInstance()->GetTexture("button_back_2");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, 50);
	button->SetSize(125, 55);
	button->SetOnClick([]() {
		ResourceManagers::GetInstance()->PlaySound("click", false);
		GameStateMachine::GetInstance()->PopState();
		//GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);
}

void GSMap::Exit()
{
}


void GSMap::Pause()
{

}

void GSMap::Resume()
{

}


void GSMap::HandleEvents()
{

}

void GSMap::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSMap::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSMap::Update(float deltaTime)
{
	m_BackGround->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSMap::Draw()
{
	m_BackGround->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
}
