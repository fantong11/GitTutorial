#pragma once
#include "Character.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的選角頁面，主要的遊戲程式都在這裡
// 每個Member function的Implementation都要弄懂
/////////////////////////////////////////////////////////////////////////////
	class CGameStateChoose : public CGameState {
	public:
		CGameStateChoose(CGame *g);
	//	void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();  								// 遊戲的初值及圖形設定
	//	bool PressAttack(int a);
	//	void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
	//	void OnBeginState();							// 設定每次重玩所需的變數
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMovingBitmap CHO;
		ChooseCharactor role;
		CMovingBitmap character1;
		CMovingBitmap character2;
		CMovingBitmap character3;
		CMovingBitmap character4;
		CMovingBitmap character5;
		CMovingBitmap character6;
		CMovingBitmap character7;
		CMovingBitmap character8;
		CMovingBitmap character9;
		CMovingBitmap character10;
		CMovingBitmap character11;
		CMovingBitmap character12;
		CMovingBitmap character13;
		CMovingBitmap character14;
		CMovingBitmap character15;
		CMovingBitmap character16;
		CMovingBitmap initialplayer1;
		CMovingBitmap initialplayer2;
		CMovingBitmap initialplayer3;
		CMovingBitmap initialplayer4;
		CMovingBitmap initialplayer5;
		CMovingBitmap initialplayer6;
		CMovingBitmap initialplayer7;
		CMovingBitmap initialplayer8;
		CMovingBitmap initialplayer9;
		CMovingBitmap initialplayer10;
		CMovingBitmap initialplayer11;
		CMovingBitmap initialplayer12;
		CMovingBitmap initialplayer13;
		CMovingBitmap initialplayer14;
		CMovingBitmap initialplayer15;
		CMovingBitmap initialplayer16;

		int control;
		int attack;
		int select;
	};	

}
