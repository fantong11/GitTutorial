#pragma once
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的選角頁面，主要的遊戲程式都在這裡
// 每個Member function的Implementation都要弄懂
/////////////////////////////////////////////////////////////////////////////
	class CGameStateChoose : public CGameState {
	public:
		CGameStateChoose(CGame *g);
		void OnInit();  								// 遊戲的初值及圖形設定
	//	void OnBeginState();							// 設定每次重玩所需的變數
	protected:
		void OnShow();									// 顯示這個狀態的遊戲畫面
		void OnKeyUp(UINT, UINT, UINT);
		void OnLButtonDown(UINT, CPoint);
	private:
		CMovingBitmap CHO;
	};
	

}