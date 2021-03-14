#pragma once
#include "StdAfx.h"
#include "gamelib.h"
#include "Resource.h"


namespace game_framework {
	// �o�� class �w�q�F���d���Ѽ�
	// ���������~ �I�� �ĤH���ͦ���m ���a���ͦ���m

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