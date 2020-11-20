#include "PLayer.h"
#include "Cannon.h"

PLayer::PLayer(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture)
	: Sprite2D(model, shader, texture)
{	
	//Gia tri cong them
	x_value = PLAYER_WIDTH;
	y_value = PLAYER_HEIGHT;
	//x_pos = PLAYER_BEGIN_x;
	//y_pos = PLAYER_BEGIN_y;
	model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("wall");
	m_player = std::make_shared<SpriteAnimation>(model, shader, texture, 1, 0.0f);
	m_player->SetSize(52, 52);
}

PLayer::~PLayer()
{
}


void PLayer::HandleKeyEvents(GLbyte key, bool bIsPressed)
{
	
}



void PLayer::Update(GLfloat deltatime)
{
	
}
