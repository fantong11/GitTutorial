#pragma once
namespace game_framework {
	// 這個 class 定義了關卡的參數
	// 掉落的物品 背景 敵人的生成位置 玩家的生成位置

	class CGameStateStage : public CGameState {
	public:
		CGameStateStage(CGame *g);
		void OnInit();
	protected:
		void OnShow();
	private:
		CMovingBitmap stageOneBackground;
		CMovingBitmap stageTwoBackground;
		CMovingBitmap StageThreeBackground;
	};
}