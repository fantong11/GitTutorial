#pragma once
#include "StdAfx.h"
#include "gamelib.h"
#include "Resource.h"


namespace game_framework {
	// 這個 class 定義了關卡的參數
	// 掉落的物品 背景 敵人的生成位置 玩家的生成位置

	class CGameStateStage : public CGameState {
	public:
		void LoadBitmap();
		void OnShow();
	private:
		CAnimation stageOneBackground;
		CAnimation stageTwoBackground;
		CAnimation StageThreeBackground;
	};
}