#pragma once
#include "Sprite2D.h"
#include "ResourceManagers.h"
#include "SpriteAnimation.h";
#include "GameStates/GSPlay.h"
#include "Shaders.h"
#include "Texture.h"
#include "Models.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite3D.h"
#include "Text.h"
#include "PLayer.h"
#include "GameStates/Bounce.h"
class Cannon : public Sprite2D
{

public:
	Cannon(std::shared_ptr<Models> model,GLint x, GLint y);
	~Cannon();
	void Cannon::Move1(GLfloat deltatime);
	void Cannon::Move2(GLfloat deltatime);
	void Cannon::Move3(GLfloat deltatime);
	void Cannon::Move4(GLfloat deltatime);
	void Update(GLfloat deltatime);
	void Move(GLfloat deltatime);
	void CheckCollision(std::shared_ptr<PLayer> player);
	void CollisionBounce(std::shared_ptr<Bounce> bounce);
	std::shared_ptr<SpriteAnimation> GetAnimation1() {
		return a_animation;
	}
	float GetTime() 
	{
		return m_time;
	}
	bool getCheck()
	{
		return check;
	}
	
private:
	std::shared_ptr<SpriteAnimation> m_pFeedback;
	GLint x_value;
	bool check;
	GLint y_value;
	std::shared_ptr<SpriteAnimation> a_animation;
	std::shared_ptr<SpriteAnimation> a_cannon;
	std::shared_ptr<SpriteAnimation> a_collision;
	Vector2 pos_now;
	Vector2 pos_coll;
	float m_time;
};