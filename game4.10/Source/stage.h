#pragma once
namespace game_framework {
	// �o�� class �w�q�F���d���Ѽ�
	// ���������~ �I�� �ĤH���ͦ���m ���a���ͦ���m

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