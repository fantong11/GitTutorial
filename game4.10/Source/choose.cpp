#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CEraser.h"
#include "choose.h"
#include "CBall.h"
#include "choose.h"

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
		//Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
		//
		// ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
		//
	}

	void CGameStateChoose::OnShow()
	{
		CHO.SetTopLeft(0, 0);
		CHO.ShowBitmap();
	}
}