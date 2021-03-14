#pragma once
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的選角頁面，主要的遊戲程式都在這裡
// 每個Member function的Implementation都要弄懂
/////////////////////////////////////////////////////////////////////////////
	class CharactorChoose
	{
	public:
		CharactorChoose();
		void LoadBitmap();										// 載入圖形
		void OnShow();											// 將圖形貼到畫面
		void SetXY(int nx, int ny);								// 設定圖片的座標
		void Initialize();				// 設定選角為初始值
		void LoadBitmap();				// 載入圖形
		void IsLeft(bool flag);     	// 設定是否左
		void IsRight(bool flag);       // 設定是否右
	protected:
		//CMovingBitmap bmp;			// 球的圖		
	private:
		//bool HitRectangle(int tx1, int ty1, int tx2, int ty2);	// 是否碰到參數範圍的矩形
	};


}
#pragma once
