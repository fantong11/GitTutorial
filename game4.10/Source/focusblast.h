#pragma once
namespace game_framework {
	class Focusblast {
	public:
		Focusblast();
		void LoadBitmap();		// ���J�ϧ�
		void SetFocusblast(int, int, bool);			// ����
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