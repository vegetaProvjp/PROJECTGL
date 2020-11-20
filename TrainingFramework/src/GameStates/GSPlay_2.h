#pragma once
#include "gamestatebase.h"
#include "GameButton.h"
#include <GameObject/PLayer.h>
#include <GameObject/Cannon.h>
#include <GameStates/Bounce.h>
class Sprite2D;
class Sprite3D;
class Text;
class PLayer;
class SpriteAnimation;
class Cannon;

class GSPlay_2 :
	public GameStateBase
{
public:
	GSPlay_2();
	~GSPlay_2();

	void Init();
	void Exit();

	void Pause();
	void Resume();

	void HandleEvents();
	void HandleKeyEvents(int key, bool bIsPressed);

	void HandleTouchEvents(int x, int y, bool bIsPressed);
	void Update(float deltaTime);
	void Draw();
	void SetCannon(std::shared_ptr<Models> model);


private:
	const int PLAYER_WIDTH = 151;
	const int PLAYER_HEIGHT = 55;
	std::shared_ptr<Sprite2D> m_BackGround;
	std::shared_ptr<PLayer> mp_Player;
	std::shared_ptr<Cannon> m_Cannon;
	std::shared_ptr <Bounce> ma_Bounce;

	std::vector < std::shared_ptr<Sprite2D>> m_listSprite2D;
	std::shared_ptr<SpriteAnimation> m_Boom;
	std::shared_ptr<GameButton> btn_pause, btn_resume, btn_start;
	std::list<std::shared_ptr<GameButton>> m_listButton;
	std::list< std::shared_ptr<Cannon>> m_listCannon;
	std::list< std::shared_ptr<Bounce>> m_listBounce;
	GLint x_value = 10; //Gia tri cong them
	GLint y_value;

	//std::vector < std::shared_ptr<SpriteAnimation>> m_listSpriteAnimations;

};

