#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Character.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	ChooseCharactor::ChooseCharactor()
	{
		Initialize();
	}

	void ChooseCharactor::Initialize()
	{
		const int X_POS = 10;
		const int Y_POS = 10;
		x = X_POS;
		y = Y_POS;
		isMovingLeft = isMovingRight = false;
	}

	void ChooseCharactor::LoadBitmap()
	{
		animation.AddBitmap(IDB_JOIN1, RGB(255, 255, 255));
		animation.AddBitmap(IDB_JOIN2, RGB(255, 255, 255));
	}

	void ChooseCharactor::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void ChooseCharactor::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void ChooseCharactor::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void ChooseCharactor::OnShow()
	{
		animation.SetTopLeft(x, y);
		animation.OnShow();
	}
}