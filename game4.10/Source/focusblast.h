#pragma once
namespace game_framework {
	class Focusblast {
	public:
		Focusblast();
		void LoadBitmap();		// 載入圖形
		void SetFocusblast(int, int, bool);			// 移動
		void OnMove();
		void OnShow();			// 將圖形貼到畫面
		bool Collision(int, int,int);
	private:
		int x, y, z;				// 圖形座標
		CAnimation charactor_special_right;
		CAnimation charactor_special_left;
		int direction_right;
		int distance;
		bool hit;
		bool show;
		int now_pic;

	};
}