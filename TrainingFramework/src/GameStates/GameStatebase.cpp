/*
#include "GSIntro.h"
#include "GSMenu.h"
*/
#include "GSPlay.h"
#include "GSPlay_2.h"
#include "GSIntro.h"
#include "GSMenu.h"
#include "GSCredit.h"
#include "GSLevel.h"
#include "GameStatebase.h"
#include "GSMap.h"
#include "GSEnd.h"
#include "GSSuccess.h"
std::shared_ptr<GameStateBase> GameStateBase::CreateState(StateTypes stt)
{
	std::shared_ptr<GameStateBase> gs = nullptr;
	switch (stt)
	{
	case STATE_INVALID:
		break;
	case STATE_Intro:
		gs = std::make_shared<GSIntro>();
		break;
	case STATE_Menu:
		gs = std::make_shared<GSMenu>();
		break;
	case STATE_Play:
		gs = std::make_shared<GSPlay>();
		break;
	case STATE_Credit:
		gs = std::make_shared<GSCredit>();
		break;
	case STATE_Level:
		gs = std::make_shared<GSLevel>();
		break;
	case STATE_Play_2:
		gs = std::make_shared<GSPlay_2>();
		break;
	case STATE_Map:
		gs = std::make_shared<GSMap>();
		break;
	case STATE_End:
		gs = std::make_shared<GSEnd>();
		break;
	case STATE_Success:
		gs = std::make_shared<GSSuccess>();
		break;
	default:
		break;
	}
	return gs;
}