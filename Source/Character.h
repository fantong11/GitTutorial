#ifndef CHARACTER_H
#define CHARACTER_H
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供可以用鍵盤或滑鼠控制的擦子
	// 看懂就可以改寫成自己的程式了
	/////////////////////////////////////////////////////////////////////////////

	class ChooseCharactor
	{
	public:
		ChooseCharactor();
		void Initialize();				// 設定擦子為初始值
		void LoadBitmap();				// 載入圖形
		void OnMove();					// 移動擦子
		void OnShow(int,int,int);					// 將擦子圖形貼到畫面
		//void RoleSelect(int);
		//void SetMovingLeft(bool flag);	// 設定是否正在往左移動
		//void SetMovingRight(bool flag); // 設定是否正在往右移動
		//void SetXY(int nx, int ny);		// 設定擦子左上角座標
		//void Attack(UINT);
	protected:
		CAnimation animation;		// 擦子的動畫
		//CAnimation animation;		// 擦子的動畫
		//bool isMovingLeft;			// 是否正在往左移動
		//bool isMovingRight;			// 是否正在往右移動
	private:
		int roleSel;
		CMovingBitmap role1;
		CMovingBitmap role2;
		CMovingBitmap role3;
		CMovingBitmap player1;
		CMovingBitmap player2;
		CMovingBitmap rolename1;
		CMovingBitmap rolename2;
		CMovingBitmap rolename3;
		CMovingBitmap rolename4;
		CMovingBitmap rolename5;
		CMovingBitmap rolename6;
		CMovingBitmap team;
		int control;
	};
}
#endif