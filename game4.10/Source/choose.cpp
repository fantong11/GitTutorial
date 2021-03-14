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
// �o��class���C������ܪ��A(Game Choose)
/////////////////////////////////////////////////////////////////////////////

	CGameStateChoose::CGameStateChoose(CGame *g)
		: CGameState(g)
	{
	}

	void CGameStateChoose::OnInit()
	{
		ShowInitProgress(0);	// �@�}�l��loading�i�׬�0%
		//
		// �}�l���J���
		//
		CHO.LoadBitmap(IDB_CHOOSE);
		character1.LoadBitmap(IDB_JOIN1, RGB(255, 255, 255));
		character2.LoadBitmap(IDB_JOIN2, RGB(255, 255, 255));
		//Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
		//
		// ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
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
		const char KEY_LEFT = 0x25; // keyboard���b�Y
		const char KEY_UP = 0x26; // keyboard�W�b�Y
		const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
		const char KEY_DOWN = 0x28; // keyboard�U�b�Y
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