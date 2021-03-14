#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CEraser.h"
#include "choose.h"
#include "CBall.h"
#include "Character.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的選擇狀態(Game Choose)
/////////////////////////////////////////////////////////////////////////////

	CGameStateChoose::CGameStateChoose(CGame *g)
		: CGameState(g)
	{
	}

	void CGameStateChoose::OnInit()
	{
		ShowInitProgress(0);	// 一開始的loading進度為0%
		//
		// 開始載入資料
		//
		CHO.LoadBitmap(IDB_CHOOSE);
		character1.LoadBitmap(IDB_JOIN1, RGB(255, 255, 255));
		character2.LoadBitmap(IDB_JOIN2, RGB(255, 255, 255));
		//Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
		//
		// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
		//
	}
	bool CGameStateChoose::PressAttack(int a){
		if (a == 1) {
			return true;
		}
		return false;
	}

	void CGameStateChoose::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard左箭頭
		const char KEY_UP = 0x26; // keyboard上箭頭
		const char KEY_RIGHT = 0x27; // keyboard右箭頭
		const char KEY_DOWN = 0x28; // keyboard下箭頭
		if (nChar == KEY_UP)
			PressAttack(1);

	}
	void CGameStateChoose::OnShow()
	{
		CHO.SetTopLeft(0, 0);
		CHO.ShowBitmap();
		character1.SetTopLeft(115, 90);
		character2.SetTopLeft(115, 90);
		character1.ShowBitmap();
		character2.ShowBitmap();
	}
}