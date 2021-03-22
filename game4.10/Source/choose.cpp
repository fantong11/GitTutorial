#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CEraser.h"
#include "choose.h"
#include "CBall.h"


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
// �o��class���C������ܪ��A(Game Choose)
/////////////////////////////////////////////////////////////////////////////
	CGameStateChoose::CGameStateChoose(CGame *g)
		: CGameState(g)
	{
		control = 0;
		attack = 0;
		select = 0;
		role.Initialize();
		
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
		character3.LoadBitmap(IDB_JOIN1, RGB(255, 255, 255));
		character4.LoadBitmap(IDB_JOIN2, RGB(255, 255, 255));
		character5.LoadBitmap(IDB_JOIN1, RGB(255, 255, 255));
		character6.LoadBitmap(IDB_JOIN2, RGB(255, 255, 255));
		character7.LoadBitmap(IDB_JOIN1, RGB(255, 255, 255));
		character8.LoadBitmap(IDB_JOIN2, RGB(255, 255, 255));
		character9.LoadBitmap(IDB_JOIN1, RGB(255, 255, 255));
		character10.LoadBitmap(IDB_JOIN2, RGB(255, 255, 255));
		character11.LoadBitmap(IDB_JOIN1, RGB(255, 255, 255));
		character12.LoadBitmap(IDB_JOIN2, RGB(255, 255, 255));
		character13.LoadBitmap(IDB_JOIN1, RGB(255, 255, 255));
		character14.LoadBitmap(IDB_JOIN2, RGB(255, 255, 255));
		character15.LoadBitmap(IDB_JOIN1, RGB(255, 255, 255));
		character16.LoadBitmap(IDB_JOIN2, RGB(255, 255, 255));
		initialplayer1.LoadBitmap(IDB_INIJOINWHITE);
		initialplayer2.LoadBitmap(IDB_INIJOINBLUE);
		initialplayer3.LoadBitmap(IDB_INIJOINWHITE);
		initialplayer4.LoadBitmap(IDB_INIJOINBLUE);
		initialplayer5.LoadBitmap(IDB_INIJOINWHITE);
		initialplayer6.LoadBitmap(IDB_INIJOINBLUE);
		initialplayer7.LoadBitmap(IDB_INIJOINWHITE);
		initialplayer8.LoadBitmap(IDB_INIJOINBLUE);
		initialplayer9.LoadBitmap(IDB_INIJOINWHITE);
		initialplayer10.LoadBitmap(IDB_INIJOINBLUE);
		initialplayer11.LoadBitmap(IDB_INIJOINWHITE);
		initialplayer12.LoadBitmap(IDB_INIJOINBLUE);
		initialplayer13.LoadBitmap(IDB_INIJOINWHITE);
		initialplayer14.LoadBitmap(IDB_INIJOINBLUE);
		initialplayer15.LoadBitmap(IDB_INIJOINWHITE);
		initialplayer16.LoadBitmap(IDB_INIJOINBLUE);

		//Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
		//
		// ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
		//
	}
	void CGameStateChoose::OnMove()							// ���ʹC������
	{
		//
		// �p�G�Ʊ�ק�cursor���˦��A�h�N�U���{����commment�����Y�i
		//
		// SetCursor(AfxGetApp()->LoadCursor(IDC_GAMECURSOR));
		//
		// ���ʭI���Ϫ��y��
		//
		control += 1;
		//role.Initialize();
		
	}
	/*
	bool CGameStateChoose::PressAttack(int a){
		if (a == 1) {
			return true;
		}
		return false;
	}
	*/
	void CGameStateChoose::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard���b�Y
		const char KEY_UP = 0x26; // keyboard�W�b�Y
		const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
		const char KEY_DOWN = 0x28; // keyboard�U�b�Y
		if (nChar == KEY_UP) {
			role.LoadBitmap();
			attack++;
			select++;
		}
		if (nChar == KEY_LEFT && attack>0) {
			select--;
		}
		if (nChar == KEY_RIGHT && attack > 0) {
			select++;
		}
				
	}
	void CGameStateChoose::OnShow()
	{
		CHO.SetTopLeft(0, 0);
		CHO.ShowBitmap();
		character1.SetTopLeft(120, 90);
		character2.SetTopLeft(120, 90);
		character3.SetTopLeft(260, 90);
		character4.SetTopLeft(260, 90);
		character5.SetTopLeft(400, 90);
		character6.SetTopLeft(400, 90);
		character7.SetTopLeft(540, 90);
		character8.SetTopLeft(540, 90);
		character9.SetTopLeft(120, 320);
		character10.SetTopLeft(120, 320);
		character11.SetTopLeft(260, 320);
		character12.SetTopLeft(260, 320);
		character13.SetTopLeft(400, 320);
		character14.SetTopLeft(400, 320);
		character15.SetTopLeft(540, 320);
		character16.SetTopLeft(540, 320);
		initialplayer1.SetTopLeft(97, 180);
		initialplayer2.SetTopLeft(97, 180);
		initialplayer3.SetTopLeft(240, 180);
		initialplayer4.SetTopLeft(240, 180);
		initialplayer5.SetTopLeft(375, 180);
		initialplayer6.SetTopLeft(375, 180);
		initialplayer7.SetTopLeft(515, 180);
		initialplayer8.SetTopLeft(515, 180);
		initialplayer9.SetTopLeft(97, 400);
		initialplayer10.SetTopLeft(97, 400);
		initialplayer11.SetTopLeft(240, 400);
		initialplayer12.SetTopLeft(240, 400);
		initialplayer13.SetTopLeft(375, 400);
		initialplayer14.SetTopLeft(375, 400);
		initialplayer15.SetTopLeft(515, 400);
		initialplayer16.SetTopLeft(515, 400);
		
	
		if (control % 2 == 1) {
			character1.ShowBitmap();
			character3.ShowBitmap();
			character5.ShowBitmap();
			character7.ShowBitmap();
			character9.ShowBitmap();
			character11.ShowBitmap();
			character13.ShowBitmap();
			character15.ShowBitmap();
			initialplayer1.ShowBitmap();
			initialplayer3.ShowBitmap();
			initialplayer5.ShowBitmap();
			initialplayer7.ShowBitmap();
			initialplayer9.ShowBitmap();
			initialplayer11.ShowBitmap();
			initialplayer13.ShowBitmap();
			initialplayer15.ShowBitmap();
		}
		else {
			character2.ShowBitmap();
			character4.ShowBitmap();
			character6.ShowBitmap();
			character8.ShowBitmap();
			character10.ShowBitmap();
			character12.ShowBitmap();
			character14.ShowBitmap();
			character16.ShowBitmap();
			initialplayer2.ShowBitmap();
			initialplayer4.ShowBitmap();
			initialplayer6.ShowBitmap();
			initialplayer8.ShowBitmap();
			initialplayer10.ShowBitmap();
			initialplayer12.ShowBitmap();
			initialplayer14.ShowBitmap();
			initialplayer16.ShowBitmap();
		}
		if (attack > 0) {
			role.OnShow(select,control,attack);
		}
		
		
		
	}
}
/*
void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT = 0x25; // keyboard���b�Y
	const char KEY_UP = 0x26; // keyboard�W�b�Y
	const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
	const char KEY_DOWN = 0x28; // keyboard�U�b�Y
	if (nChar == KEY_LEFT)
		eraser.SetMovingLeft(true);
	if (nChar == KEY_RIGHT)
		eraser.SetMovingRight(true);
	if (nChar == KEY_UP)
		eraser.SetMovingUp(true);
	if (nChar == KEY_DOWN)
		eraser.SetMovingDown(true);
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT = 0x25; // keyboard���b�Y
	const char KEY_UP = 0x26; // keyboard�W�b�Y
	const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
	const char KEY_DOWN = 0x28; // keyboard�U�b�Y
	if (nChar == KEY_LEFT)
		eraser.SetMovingLeft(false);
	if (nChar == KEY_RIGHT)
		eraser.SetMovingRight(false);
	if (nChar == KEY_UP)
		eraser.SetMovingUp(false);
	if (nChar == KEY_DOWN)
		eraser.SetMovingDown(false);
}
*/