#pragma once
namespace game_framework {
	class SwordGas{
	public:
		SwordGas();
		void LoadBitmap();		// ���J�ϧ�
		void SetSwordGas(int,int,bool);			// ����
		void OnMove();
		void OnShow();			// �N�ϧζK��e��
	private:
		int x, y;				// �ϧήy��
		CAnimation charactor_special_right;
		CAnimation charactor_special_left;
		int direction_right;
		int distance;

	};
}