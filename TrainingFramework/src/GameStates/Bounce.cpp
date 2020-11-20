#include "Bounce.h"

extern int screenWidth;
extern int screenHeight;

Bounce::Bounce(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture)
	: Sprite2D(model, shader, texture)
{
	
	model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("bounce");
	m_bounce = std::make_shared<SpriteAnimation>(model, shader, texture, 1, 0.0f);
	m_bounce->SetSize(70, 20);
}

Bounce::~Bounce()
{
}

void Bounce::Update(GLfloat deltatime)
{
}
