#include "Source/StdAfx.h"
#include "Source/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "Source/audio.h"
#include "Source/gamelib.h"
#include "Source/CEraser.h"
#include "Source/choose.h"
#include "Source/CBall.h"
#include "Source/Character.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的選擇狀態(Game Choose)
/////////////////////////////////////////////////////////////////////////////

	CharactorChoose::CharactorChoose()
	{

	}
	bool IsLeft() {
		if
	}
	bool IsRight() {

	}
	void CharactorChoose::Initialize()
	{
		const int X_POS = 280;
		const int Y_POS = 400;
		x = X_POS;
		y = Y_POS;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
	}

	void CharactorChoose::LoadBitmap()
	{
		bmp.LoadBitmap(IDB_BALL, RGB(0, 0, 0));			// 載入球的圖形
		bmp_center.LoadBitmap(IDB_CENTER, RGB(0, 0, 0));	// 載入球圓心的圖形
	}

	void CharactorChoose::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void CharactorChoose::OnShow()
	{
		if (is_alive) {
			bmp.SetTopLeft(x + dx, y + dy);
			bmp.ShowBitmap();
			bmp_center.SetTopLeft(x, y);
			bmp_center.ShowBitmap();
		}
	}
}