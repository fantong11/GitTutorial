#pragma once
namespace game_framework {
	// �o�� class �w�q�F���d���Ѽ�
	// ���������~ �I�� �ĤH���ͦ���m ���a���ͦ���m

	class Stage {
	public:
		Stage();
		void LoadBitmap();
		void OnShow();
	private:
		CMovingBitmap background;
	};
}