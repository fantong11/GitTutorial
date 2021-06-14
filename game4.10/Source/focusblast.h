#pragma once
namespace game_framework {
	class Focusblast {
	public:
		Focusblast();
		void LoadBitmap();		// ���J�ϧ�
		void SetFocusblast(int, int, bool);			// ����
		void OnMove();
		void OnShow();			// �N�ϧζK��e��
		bool Collision(int, int,int);
	private:
		int x, y, z;				// �ϧήy��
		CAnimation charactor_special_right;
		CAnimation charactor_special_left;
		int direction_right;
		int distance;
		bool hit;
		bool show;
		int now_pic;

	};
}