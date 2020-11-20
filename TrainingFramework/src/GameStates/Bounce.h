#pragma once
#include "Sprite2D.h"
#include "SpriteAnimation.h"
#include "ResourceManagers.h"

class Bounce : public Sprite2D
{

public:
	Bounce(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture);
	~Bounce();

	void Update(GLfloat deltatime);
	std::shared_ptr<SpriteAnimation> GetAnimation() {
		return m_bounce;
	}

private:

	std::shared_ptr<SpriteAnimation> m_bounce;
	Vector2 pos;
};

