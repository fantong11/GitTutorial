#pragma once
namespace game_framework {
	class SwordGas{
	public:
		SwordGas();
		void LoadBitmap();		// ���J�ϧ�
		void SetSwordGas(int,int,bool);			// ����
		void OnMove();
		void OnShow();			// �N�ϧζK��e��
		bool Collision(int, int, int);
		bool show;
	private:
		int x, y, z;				// �ϧήy��
		CAnimation charactor_special_right;
		CAnimation charactor_special_left;
		int direction_right;
		int distance;
		bool hit;
		int now_pic;

	};
}