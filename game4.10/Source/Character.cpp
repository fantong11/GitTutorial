#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Character.h"
#include "cmath"


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////
	
	ChooseCharactor::ChooseCharactor()
	{
		Initialize();
		control = 0;
	}
	void ChooseCharactor::OnMove()							// 移動遊戲元素
	{
		//
		// 如果希望修改cursor的樣式，則將下面程式的commment取消即可
		//
		// SetCursor(AfxGetApp()->LoadCursor(IDC_GAMECURSOR));
		//
		// 移動背景圖的座標
		//
		

	}

	void ChooseCharactor::Initialize()
	{
		
		
	}

	void ChooseCharactor::LoadBitmap()
	{
		role1.LoadBitmap(IDB_TEMPLATE);
		role2.LoadBitmap(IDB_DEEP);
		role3.LoadBitmap(IDB_DAVID);
		player1.LoadBitmap(IDB_WHITEPLAYER);
		player2.LoadBitmap(IDB_BLUEPLAYER);
		rolename1.LoadBitmap(IDB_TEMPLATEWHITE);
		rolename2.LoadBitmap(IDB_TEMPLATEBLUE);
		rolename3.LoadBitmap(IDB_DEEPNAMEWHITE);
		rolename4.LoadBitmap(IDB_DEEPNAMEBLUE);
		rolename5.LoadBitmap(IDB_DAVIDNAMEWHITE);
		rolename6.LoadBitmap(IDB_DAVIDNAMEBLUE);
		team.LoadBitmap(IDB_TEAM);
	}
	void ChooseCharactor::OnShow(int select,int shine,int attack)
	{
		role1.SetTopLeft(97, 51);
		role2.SetTopLeft(97, 51);
		role3.SetTopLeft(97, 51);
		player1.SetTopLeft(97,180);
		player2.SetTopLeft(97,180);
		rolename1.SetTopLeft(97, 200);
		rolename2.SetTopLeft(97, 200);
		rolename3.SetTopLeft(97, 200);
		rolename4.SetTopLeft(97, 200);
		rolename5.SetTopLeft(97, 200);
		rolename6.SetTopLeft(97, 200);
		team.SetTopLeft(97, 225);
		if (attack == 1) {
			if (shine % 2 == 0)
				player1.ShowBitmap();
			else
				player2.ShowBitmap();
			if (abs(select+1) % 3 == 1) {
				role1.ShowBitmap();
				if (shine % 2 == 0)
					rolename1.ShowBitmap();
				else
					rolename2.ShowBitmap();
			}
			else if (abs(select+1) % 3 == 2) {
				role2.ShowBitmap();
				if (shine % 2 == 0)
					rolename3.ShowBitmap();
				else
					rolename4.ShowBitmap();
			}

			else {
				role3.ShowBitmap();
				if (shine % 2 == 0)
					rolename5.ShowBitmap();
				else
					rolename6.ShowBitmap();
			}
		}
		else if (attack>1) {
			team.ShowBitmap();
			player1.ShowBitmap();
			if (abs(select+1) % 3 == 1) {
				role1.ShowBitmap();
				rolename1.ShowBitmap();
			}
			else if (abs(select+1) % 3 == 2) {
				role2.ShowBitmap();
				rolename3.ShowBitmap();
			}
			else {
				role3.ShowBitmap();
				rolename5.ShowBitmap();
			}
			
			

		}
		
	}
}