#pragma once
#include "Sprite2D.h"
#include "ResourceManagers.h"
#include "SpriteAnimation.h";


class PLayer : public Sprite2D
{

public:
	PLayer(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture);
	~PLayer();

	void	HandleKeyEvents(GLbyte key, bool bIsPressed);
	void Update(GLfloat deltatime);
	std::shared_ptr<SpriteAnimation> GetAnimation() {
		return m_player;
	}
	//void CheckCollision(std::shared_ptr<Cannon> cannon);
private:
	const int PLAYER_WIDTH = 151;
	const int PLAYER_HEIGHT = 55;
	const int PLAYER_BEGIN_x = 200;
	const int PLAYER_BEGIN_y = 1800;
	GLint x_value; //Gia tri cong them
	GLint y_value;
	GLint x_pos; //Vi tri hien tai
	GLint y_pos;
	std::shared_ptr<SpriteAnimation> m_player;
};

