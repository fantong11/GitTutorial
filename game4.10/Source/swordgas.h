#pragma once
namespace game_framework {
	class SwordGas{
	public:
		SwordGas();
		void LoadBitmap();		// 載入圖形
		void SetSwordGas(int,int,bool);			// 移動
		void OnMove();
		void OnShow();			// 將圖形貼到畫面
	private:
		int x, y;				// 圖形座標
		CAnimation charactor_special_right;
		CAnimation charactor_special_left;
		int direction_right;
		int distance;

	};
}