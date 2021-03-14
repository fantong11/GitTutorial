#include "stage.h"
#include "Source/StdAfx.h"
#include "Source/gamelib.h"

namespace game_framework {
	// stage class
	CGameStateStage::CGameStateStage(CGame *g) : CGameState(g) {

	}

	void CGameStateStage::OnInit() {
		ShowInitProgress(0);
		stageOneBackground.LoadBitmap();
	}
}