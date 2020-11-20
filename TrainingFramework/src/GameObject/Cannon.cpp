#include <Cannon.h>
#include <math.h>
#define PI 3.14159
bool isCollision = false;
bool colBounce = false;

int m[2][2] = { {1,0 }, {0,0} };
Cannon::Cannon(std::shared_ptr<Models> model, GLint x, GLint y)
{
	 m_time = 0;
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("boom");
	a_cannon = std::make_shared<SpriteAnimation>(model, shader,texture, 1, 0.0f);
	a_cannon->SetSize(35, 35);
	check = false;

	texture = ResourceManagers::GetInstance()->GetTexture("explosion2");
	a_collision = std::make_shared<SpriteAnimation>(model, shader,texture,6, 0.1f);
	a_collision->SetSize(30, 30);
	a_animation = a_cannon;
	a_animation->Set2DPosition(x, y);
	
	x_value = 200;
	y_value = 200;
}
Cannon::~Cannon()
{
}


void Cannon::Update(GLfloat deltatime)
{
	
	pos_now = GetAnimation1()->Get2DPosition();
	Move(deltatime);

	//a_cannon->Set2DPosition(pos_now);
	if (isCollision == true)
	{
		a_animation = a_collision;
		m_time += deltatime;
		check = true;
	}

	if (colBounce == true)
	{
		do {
			pos_now.x += x_value * deltatime * cos(PI / 4) + 100;
				pos_now.y -= y_value * deltatime * cos(PI / 4) - 100;
			GetAnimation1()->Set2DPosition(pos_now);
			printf("%f\n", pos_now.x);
;			GetAnimation1()->Update(deltatime);
		} while (pos_now.x > 400);
	}
	GetAnimation1()->Set2DPosition(pos_now);
	GetAnimation1()->Update(deltatime);
}

// Bom va cham voi cac canh

void Cannon::Move(GLfloat deltatime)
{
	/*pos_now.x -= x_value * deltatime;
	if (pos_now.x < 0) {
		pos_now.x += x_value * deltatime
	}*/
	if (m[0][0] == 1) Move1(deltatime);
	else if (m[0][1] == 1) Move2(deltatime);
	else if (m[1][0] == 1) Move3(deltatime);
	else if (m[1][1] == 1) Move4(deltatime);

} 

void Cannon::Move1(GLfloat deltatime)
{
	pos_now.x -= x_value * deltatime * cos(PI / 4);
	pos_now.y -= y_value * deltatime * cos(PI / 4);
	if (pos_now.y < 10)
	{
		m[0][0] = 0;
		m[0][1] = 1;
		m[1][0] = 0;
		m[1][1] = 0;

	}
	else if (pos_now.x < 10)
	{
		m[0][0] = 0;
		m[0][1] = 0;
		m[1][0] = 1;
		m[1][1] = 0;

	}
	else if (pos_now.y > 600)
	{
		m[0][0] = 0;
		m[0][1] = 0;
		m[1][0] = 0;
		m[1][1] = 1;

	}
	else if (pos_now.x > 310)
	{
		m[0][0] = 1;
		m[0][1] = 0;
		m[1][0] = 0;
		m[1][1] = 0;

	}
}
void Cannon::Move2(GLfloat deltatime)
{
	pos_now.x -= x_value * deltatime * cos(PI / 4);
	pos_now.y += y_value * deltatime * cos(PI / 4);

	if (pos_now.x < 10)
	{
		m[0][0] = 0;
		m[0][1] = 0;
		m[1][0] = 1;
		m[1][1] = 0;

	}
}
void Cannon::Move3(GLfloat deltatime)
{
	pos_now.x += x_value * deltatime * cos(PI / 4);
	pos_now.y += y_value * deltatime * cos(PI / 4);
	if (pos_now.x > 350)
	{
		m[0][0] = 0;
		m[0][1] = 0;
		m[1][0] = 0;
		m[1][1] = 1;

	}
}
void Cannon::Move4(GLfloat deltatime)
{
	pos_now.x -= x_value * deltatime * cos(PI / 4);
	pos_now.y += y_value * deltatime * cos(PI / 4);

	if (pos_now.y > 650)
	{
		pos_now.x += x_value * deltatime * cos(PI / 4);
		pos_now.y += y_value * deltatime * cos(PI / 4);
	}
}
void Cannon::CheckCollision(std::shared_ptr<PLayer> player)
{
	Vector2 pos_cannon = GetAnimation1()->Get2DPosition();
	Vector2 pos_player = player->GetAnimation()->Get2DPosition();

	if (abs(pos_player.x - pos_cannon.x) <20 && abs(pos_player.y - pos_cannon.y) < 20)
	{		
		isCollision = true;
	}
	else
	{
		isCollision = false;
	}
}

//230.249023  348.291595
//200 360
//365 650
void Cannon::CollisionBounce(std::shared_ptr<Bounce> bounce)
{
	Vector2 pos_cannon = GetAnimation1()->Get2DPosition();
	Vector2 pos_bounce = bounce->GetAnimation()->Get2DPosition();
	
	if (abs(pos_bounce.x - pos_cannon.x) < 50 && abs(pos_bounce.y - pos_cannon.y) < 50)
	{
		colBounce = true;
	}
	else
	{
		colBounce = false;
	}
}

