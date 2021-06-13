/*
 * mygame.cpp: 本檔案儲遊戲本身的class的implementation
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * History:
 *   2002-03-04 V3.1
 *          Add codes to demostrate the use of CMovingBitmap::ShowBitmap(CMovingBitmap &).
 *	 2004-03-02 V4.0
 *      1. Add 
 , CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *      2. Demo the use of CInteger in CGameStateRun.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *      1. Add codes to display IDC_GAMECURSOR in GameStateRun.
 *   2006-02-08 V4.2
 *      1. Revise sample screens to display in English only.
 *      2. Add code in CGameStateInit to demo the use of PostQuitMessage().
 *      3. Rename OnInitialUpdate() -> OnInit().
 *      4. Fix the bug that OnBeginState() of GameStateInit is not called.
 *      5. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      6. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2006-12-30
 *      1. Bug fix: fix a memory leak problem by replacing PostQuitMessage(0) as
 *         PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0).
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress. 
 *   2010-03-23 V4.6
 *      1. Demo MP3 support: use lake.mp3 to replace lake.wav.
*/

#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"
#include "cmath"
#include <iostream>
#include <fstream>


namespace game_framework {
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g)
: CGameState(g)
{
	

	
	

}

void CGameStateInit::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(0);	// 一開始的loading進度為0%
	//
	// 開始載入資料
	//
	TRACE("\n\n\n\n\n");
	logo.LoadBitmap(IDB_INIBG);
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
	menu.LoadBitmap(IDB_GAMEMENU);
	menu2.LoadBitmap(IDB_MENU2);
	menu3.LoadBitmap(IDB_MENU3);
	menu4.LoadBitmap(IDB_MENU4);
	menu5.LoadBitmap(IDB_MENU5);
	menu6.LoadBitmap(IDB_MENU6);
	role.LoadBitmap();
	int i = 0;
	for (i = 0; i < 35; i++) {
		if (i % 5 == 0)
			countdown[i].LoadBitmap(IDB_COUNTDOWN5);
		else if (i % 5 == 1)
			countdown[i].LoadBitmap(IDB_COUNTDOWN4);
		else if (i % 5 == 2)
			countdown[i].LoadBitmap(IDB_COUNTDOWN3);
		else if (i % 5 == 3)
			countdown[i].LoadBitmap(IDB_COUNTDOWN2);
		else if (i % 5 == 4)
			countdown[i].LoadBitmap(IDB_COUNTDOWN1);
	}
}

void CGameStateInit::OnBeginState()
{
	counter = 30 * 6;
	control = 0;
	attack = 0;
	select = 0;
	SelectMenu = 0;
	role.Initialize();
	section = 1;
}
void CGameStateInit::OnMove()
{
	control += 1;
	if (attack > 1) {
		counter--;
	}
		
	if (attack < 2) {
		SelectMenu = 0;
		counter = 30 * 6;
	}
}
void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_ESC = 27;
	const char KEY_SPACE = ' ';
	const char KEY_LEFT = 0x25; // keyboard左箭頭
	const char KEY_UP = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN = 0x28; // keyboard下箭頭
	const char KEY_ATTACK = 0x4A;
	const char KEY_DEF = 0x4C;
	const char KEY_JUMP = 0x4B;
	if (nChar == KEY_ATTACK) {
		TRACE("檔案I/O失敗\n");
		attack++;
		if (attack == 3) {
			
			if (SelectMenu >= 0) {
				if (((SelectMenu + 1) % 6) == 1) {
					if ((abs(SelectMenu) % 6) == 0) {
						ofstream fout("text1.txt");
						if (!fout)
						{
							TRACE("檔案I/O失敗");
						}
						if (select < 0) {
							if ((abs(select) % 3) == 1) {
								select = 3;
							}
							else if ((abs(select) % 3) == 2) {
								select = 2;
							}
							else {
								select = 1;
							}
						}
						else if (select >= 0) {
							if (abs(select + 1) % 3 == 1) {
								select = 1;
							}
							else if (abs(select + 1) % 3 == 2) {
								select = 2;
							}
							else {
								select = 3;
							}
						}
						fout << select << endl;
						fout.close();
						GotoGameState(GAME_STATE_RUN);
					}
						
				}
					
				if (((SelectMenu + 1) % 6) == 2)
					attack=1;
				if (((SelectMenu + 1) % 6) == 0)
					PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);
			}
			else {
				if ((abs(SelectMenu) % 6) == 0) {
					ofstream fout("text1.txt");
					if (!fout)
					{
						TRACE("檔案I/O失敗");
					}
					if (select < 0) {
						if ((abs(select) % 3) == 1) {
							select = 3;
						}
						else if ((abs(select) % 3) == 2) {
							select = 2;
						}
						else {
							select = 1;
						}
					}
					else if (select >= 0) {
						if (abs(select + 1) % 3 == 1) {
							select = 1;
						}
						else if (abs(select + 1) % 3 == 2) {
							select = 2;
						}
						else {
							select = 3;
						}
					}
					fout << select << endl;
					fout.close();
					GotoGameState(GAME_STATE_RUN);
				}
				if ((abs(SelectMenu) % 6) == 5)
					attack=1;
				if ((abs(SelectMenu) % 6) == 1)
					PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);
			}
			
		}
	}
	if (nChar == KEY_LEFT && attack == 1) {
		select--;	
	}
	if (nChar == KEY_RIGHT && attack == 1) {
		select++;
	}
	if (nChar == KEY_UP && attack == 2) {
		SelectMenu--;
	}
	if (nChar == KEY_DOWN && attack == 2) {
		SelectMenu++;
	}
	if (nChar == KEY_JUMP && attack > 0) {
		
		if (attack == 2 && counter > 0) {
			if (0 <= counter) {
				if (counter <= 180)
					counter -= 30;
			}
		}
		else {
			attack--;
		}
	}
	if (nChar == KEY_SPACE)
		section++;
	else if (nChar == KEY_ESC)								// Demo 關閉遊戲的方法
		PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0);	// 關閉遊戲
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	section++;
}
void CGameStateInit::OnShow()
{
	//
	// 貼上logo
	//
	//logo.SetTopLeft((SIZE_X - logo.Width())/2, SIZE_Y/8);
	logo.SetTopLeft(0, 0);
	logo.ShowBitmap();
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
	menu.SetTopLeft(0, 0);
	menu2.SetTopLeft(0, 0);
	menu3.SetTopLeft(0, 0);
	menu4.SetTopLeft(0, 0);
	menu5.SetTopLeft(0, 0);
	menu6.SetTopLeft(0, 0);
	int i = 0;
	for (int i = 0; i < 35; i++) {
		if (i / 5 == 0)
			countdown[i].SetTopLeft(234, 51);
		else if (i / 5 == 1)
			countdown[i].SetTopLeft(374, 51);
		else if (i / 5 == 2)
			countdown[i].SetTopLeft(514, 51);
		else if (i / 5 == 3)
			countdown[i].SetTopLeft(97, 273);
		else if (i / 5 == 4)
			countdown[i].SetTopLeft(234, 273);
		else if (i / 5 == 5)
			countdown[i].SetTopLeft(374, 273);
		else if (i / 5 == 6)
			countdown[i].SetTopLeft(514, 273);
	}
	if (section > 0) {
		CHO.SetTopLeft(0, 0);
		CHO.ShowBitmap();
		section++;
	}
	if (control % 2 == 1 && section >0 && attack <= 1) {
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
	else if (control % 2 == 0 && section > 0 && attack <= 1) {
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
	if (attack > 0 && section>1) {
		//id = select;
		role.OnShow(select, control,attack);
	}
	if (attack > 1 && section>1) {
		
		if (counter / 30 == 5) {
			for (i = 0; i < 35; i = i + 5) {
				countdown[i].ShowBitmap();
			}
		}
		if (counter / 30 == 4) {
			for (i = 1; i < 35; i = i + 5) {
				countdown[i].ShowBitmap();
			}
		}
		else if (counter / 30 == 3) {
			for (i = 2; i < 35; i = i + 5) {
				countdown[i].ShowBitmap();
			}
		}
		else if (counter / 30 == 2) {
			for (i = 3; i < 35; i = i + 5) {
				countdown[i].ShowBitmap();
			}
		}
		if (counter / 30 == 1) {
			for (i = 4; i < 35; i = i + 5) {
				countdown[i].ShowBitmap();
			}
		}
		

	}
	if (counter < 0 && attack==2) {
		if (SelectMenu >= 0) {
			if (((SelectMenu+1)%6)==1)
				menu.ShowBitmap();
			else if (((SelectMenu + 1) % 6) == 2)
				menu2.ShowBitmap();
			else if (((SelectMenu + 1) % 6) == 3)
				menu3.ShowBitmap();
			else if (((SelectMenu + 1) % 6) == 4)
				menu4.ShowBitmap();
			else if (((SelectMenu + 1) % 6) == 5)
				menu5.ShowBitmap();
			else
				menu6.ShowBitmap();
		}
		else {
			if ((abs(SelectMenu) % 6) == 1)
				menu6.ShowBitmap();
			else if ((abs(SelectMenu) % 6) == 2)
				menu5.ShowBitmap();
			else if ((abs(SelectMenu) % 6) == 3)
				menu4.ShowBitmap();
			else if ((abs(SelectMenu) % 6) == 4)
				menu3.ShowBitmap();
			else if ((abs(SelectMenu) % 6) == 5)
				menu2.ShowBitmap();
			else 
				menu.ShowBitmap();
		}
		if(SelectMenu==0)
			menu.ShowBitmap();
		else if (SelectMenu == 1)
			menu2.ShowBitmap();
		else if (SelectMenu == 2)
			menu3.ShowBitmap();
		else if (SelectMenu == 3)
			menu4.ShowBitmap();
	}
	
}								

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的結束狀態(Game Over)
/////////////////////////////////////////////////////////////////////////////

CGameStateOver::CGameStateOver(CGame *g)
: CGameState(g)
{
}

void CGameStateOver::OnMove()
{
	counter--;
	if (counter < 0)
		GotoGameState(GAME_STATE_INIT);
}
void CGameStateOver::OnBeginState()
{
	counter = 30 * 3; // 5 seconds
	lose.LoadBitmap(IDB_LOSE);
}

void CGameStateOver::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(66);	// 接個前一個狀態的進度，此處進度視為66%
	//
	// 開始載入資料
	//
	Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 最終進度為100%
	//
	ShowInitProgress(100);
}

void CGameStateOver::OnShow()
{
	lose.SetTopLeft(0, 0);
	lose.ShowBitmap();
}


//////////win//////////

CGameStateWin::CGameStateWin(CGame *g)
	: CGameState(g)
{
}

void CGameStateWin::OnMove()
{
	counter--;
	if (counter < 0)
		GotoGameState(GAME_STATE_INIT);
}
void CGameStateWin::OnBeginState()
{
	counter = 30 * 3; // 5 seconds
	win.LoadBitmap(IDB_WIN);
	
}

void CGameStateWin::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(66);	// 接個前一個狀態的進度，此處進度視為66%
	//
	// 開始載入資料
	//
	Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 最終進度為100%
	//
	ShowInitProgress(100);
	

}

void CGameStateWin::OnShow()
{
	win.SetTopLeft(0, 0);
	win.ShowBitmap();
}
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g)
: CGameState(g)//, NUMBALLS(28)
{

	//ball = new CBall [NUMBALLS];
}

CGameStateRun::~CGameStateRun()
{
	delete [] enemy;
	delete[] player;
	delete[] smallcharacter;
}

void CGameStateRun::OnBeginState()
{
	stage = 1;
	CAudio::Instance()->Play(AUDIO_BACK1, true);			// 撥放 WAVE
	smallstage = 1;
	ifstream fin("text1.txt", ios::in);
	int temp;
	fin >> temp;
	fin.close();
	player = new Player[1];
	player[0].LoadBitmap(temp);
	enemy = new Enemy[5];
	enemy_num = 0;
	int i = 0;
	for (i = 0; i < 5; i++) {
		enemy[i].LoadBitmap(temp);
		enemy[i].SetHP(50);
	}
	enemy[0].SetXY(400, 300);
	enemy[1].SetXY(400, 270);
	enemy[2].SetXY(400, 330);
	enemy[3].SetXY(400, 270);
	enemy[4].SetXY(400, 330);
	enemy_num = 1;
	player[0].SetXY(95, 300);
	if (smallstage == 1) {
		for (i = 1; i < 5; i++)
			enemy[i].enemy_now = false;
	}
	smallcharacter = new CMovingBitmap[1];
	if(temp==1)
		smallcharacter[0].LoadBitmap(IDB_SMALLTEMPLATE);
	else if(temp==2)
		smallcharacter[0].LoadBitmap(IDB_SMALLDEEP);
	else
		smallcharacter[0].LoadBitmap(IDB_SMALLDAVID);
	
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{	
	int i = 0;
	enemy_num = 0;
	for (i = 0; i < 5; i++) {
		if (enemy[i].enemy_now)
			enemy_num++;
	}
	if (enemy[0].IsDead()) {
		if (smallstage == 1 && enemy[0].is_alive) {
			//enemy_num--;
			smallstage++;
			enemy[1].enemy_now = true;
			enemy[2].enemy_now = true;
		}
		enemy[0].is_alive = false;
		enemy[0].SetAlive(false);
		enemy[0].isAttack = false;
		enemy[0].enemy_now = false;
	}
	if (enemy[1].IsDead()) {
		//if (enemy_num > 0 && smallstage == 2 && enemy[1].is_alive)
		//enemy_num = 1;
		enemy[1].is_alive = false;
		enemy[1].SetAlive(false);
		enemy[1].isAttack = false;
		enemy[1].enemy_now = false;
	}
	if (enemy[2].IsDead()) {
		//if (enemy_num > 0 && smallstage == 2 && enemy[2].is_alive)
		//enemy_num = 1;
	
		enemy[2].is_alive = false;
		enemy[2].SetAlive(false);
		enemy[2].isAttack = false;
		enemy[2].enemy_now = false;
	}
	if (smallstage == 2 && enemy[1].IsDead() && enemy[2].IsDead()) {
		smallstage += 1;
		enemy[3].enemy_now = true;
		enemy[4].enemy_now = true;
	}
	if (enemy[3].IsDead()) {
		//enemy_num = 1;
		enemy[3].is_alive = false;
		enemy[3].SetAlive(false);
		enemy[3].isAttack = false;
		enemy[3].enemy_now = false;
	}
	if (enemy[4].IsDead()) {
		//enemy_num = 1;
		enemy[4].is_alive = false;
		enemy[4].SetAlive(false);
		enemy[4].isAttack = false;
		enemy[4].enemy_now = false;
	}
	if (smallstage == 3 && enemy[3].IsDead() && enemy[4].IsDead()) {
		enemy_num = 0;
		ofstream fout("blood.txt");
		if (!fout)
		{
			TRACE("檔案I/O失敗");
		}
		
		fout << player[0].HP << endl;
		fout.close();
		ofstream fout2("magic.txt");
		if (!fout2)
		{
			TRACE("檔案I/O失敗");
		}

		fout2 << player[0].MAGIC << endl;
		fout2.close();
		CAudio::Instance()->Stop(AUDIO_BACK1);
		GotoGameState(GAME_STATE_STAGE2);
	}
	if (player[0].IsDead()) {
		CAudio::Instance()->Stop(AUDIO_BACK1);	
		GotoGameState(GAME_STATE_OVER);
	}

	int p_x = 0, p_y = 0, e_x = 0, e_y = 0;
	player[0].Decrease();
	for (i = 0; i < 5; i++) {
		if (enemy[i].enemy_now)
			enemy[i].getCloseToPlayer(player[0].x, player[0].y);
	}

	for (i = 0; i < 5; i++) {
		if (enemy[i].enemy_now) {
			if(player[0].isAttack)
				enemy[i].isUnderAttack(player[0].x, player[0].y, player[0].z, player[0].isAttack);
			else
				player[0].isUnderAttack(enemy[i].x, enemy[i].y, enemy[i].z, enemy[i].isAttack);
		}
	}


}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	
	stageone.LoadBitmap(IDB_STAGEONEWHOLE);
	up_block.LoadBitmap(IDB_UPBLOCK);
	CAudio::Instance()->Load(AUDIO_BACK1, "sounds\\stage1.mp3");	// 載入編號0的聲音ding.wav

}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	int i = 0;
	const char KEY_LEFT  = 0x25; // keyboard左箭頭
	const char KEY_UP    = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN  = 0x28; // keyboard下箭頭
	const char KEY_JUMP = 0x4B; // keyboard k
	const char KEY_ATTACK = 0x4A;
	const char KEY_DEF = 0x4C;
	if (nChar == KEY_LEFT)
		player[0].SetMovingLeft(true);
	if (nChar == KEY_RIGHT)
		player[0].SetMovingRight(true);
	if (nChar == KEY_UP)
		player[0].SetMovingUp(true);
	if (nChar == KEY_DOWN)
		player[0].SetMovingDown(true);
	if (nChar == KEY_JUMP)
		player[0].SetMovingJump(true);
	if (nChar == KEY_ATTACK) {
		player[0].SetAttack(true);
	}
	if (nChar == KEY_DEF) {
		player[0].SetDefense(true);
	}
		
	if (nChar == KEY_LEFT || nChar == KEY_RIGHT || nChar == KEY_UP || nChar == KEY_DOWN)
		player[0].SetMoving(true);
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT  = 0x25; // keyboard左箭頭
	const char KEY_UP    = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN  = 0x28; // keyboard下箭頭
	const char KEY_JUMP  = 0x6B; // keyboard k
	const char KEY_ATTACK = 0x4A;
	const char KEY_DEF = 0x4C;
	if (nChar == KEY_LEFT)
		player[0].SetMovingLeft(false);
	if (nChar == KEY_RIGHT)
		player[0].SetMovingRight(false);
	if (nChar == KEY_UP)
		player[0].SetMovingUp(false);
	if (nChar == KEY_DOWN)
		player[0].SetMovingDown(false);
	if (nChar == KEY_DEF) {
		player[0].SetDefense(false);
	}
	if (player[0].IsMoving() == false)
		player[0].SetMoving(false);
}
void CGameStateRun::OnShow()
{
	
	stageone.SetTopLeft(0, 100);
	stageone.ShowBitmap();
	up_block.SetTopLeft(0, 0);
	up_block.ShowBitmap();
	smallcharacter[0].SetTopLeft(0, 0);
	smallcharacter[0].ShowBitmap();
	int i = 0;
	for (i = 0; i < 5; i++) {
		if(enemy[i].enemy_now)
			enemy[i].OnShow();
	}
	player[0].DrawAllAboutPlayer();

	CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	CFont f, ff1,*fp, *ff;
	f.CreatePointFont(110, "Times New Roman");	// 產生 font f; 160表示16 point的字
	fp = pDC->SelectObject(&f);					// 選用 font f
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextColor(RGB(255, 255, 255));
	char str[80];								// Demo 數字對字串的轉換
	sprintf(str, "STAGE  %d",stage);
	pDC->TextOut(281, 94, str);

	ff1.CreatePointFont(110, "Times New Roman");	// 產生 font f; 160表示16 point的字
	ff = pDC->SelectObject(&ff1);					// 選用 font f
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextColor(RGB(255, 0, 255));
	char str1[80];								// Demo 數字對字串的轉換
	if(smallstage==1)
		sprintf(str1, "Man:  %d    HP:  %d", enemy_num,enemy[0].HP);
	else if(smallstage==2)
		sprintf(str1, "Man:  %d    HP:  %d", enemy_num, enemy[1].HP+enemy[2].HP);
	else if (smallstage == 3)
		sprintf(str1, "Man:  %d    HP:  %d", enemy_num, enemy[3].HP + enemy[4].HP);
	pDC->TextOut(523, 94, str1);
	pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	pDC->SelectObject(ff);
	CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC


}

//////////////////////////////////////////////////////////////////////////////////////
////////////////////STAGE2////////////////////////////////////////////////////
///////////////////////////////////////
CGameStateStage2::CGameStateStage2(CGame *g)
	: CGameState(g)//, NUMBALLS(28)
{

	//ball = new CBall [NUMBALLS];
}

CGameStateStage2::~CGameStateStage2()
{
	delete[] enemy;
	delete[] player;
	delete[] smallcharacter;
}

void CGameStateStage2::OnBeginState()
{
	CAudio::Instance()->Play(AUDIO_BACK2, true);			// 撥放 WAVE
	stage = 2;
	smallstage = 1;
	ifstream fin3("text1.txt", ios::in);
	int temp3;
	fin3 >> temp3;
	fin3.close();
	ifstream fin("blood.txt", ios::in);
	int temp;
	fin >> temp;
	fin.close();
	player = new Player[1];
	player[0].LoadBitmap(temp3);
	player[0].HP = temp;
	ifstream fin2("magic.txt", ios::in);
	int temp2;
	fin2 >> temp2;
	fin2.close();
	player[0].MAGIC = temp2;
	enemy = new Enemy[5];
	enemy_num = 0;
	int i = 0;
	for (i = 0; i < 5; i++) {
		enemy[i].LoadBitmap(temp);
		enemy[i].SetHP(60);
	}
	enemy[0].SetXY(400, 300);
	enemy[1].SetXY(400, 270);
	enemy[2].SetXY(400, 330);
	enemy[3].SetXY(400, 270);
	enemy[4].SetXY(400, 330);
	enemy_num = 1;
	player[0].SetXY(95, 300);
	if (smallstage == 1) {
		for (i = 1; i < 5; i++)
			enemy[i].enemy_now = false;
	}
	smallcharacter = new CMovingBitmap[1];
	if (temp3 == 1)
		smallcharacter[0].LoadBitmap(IDB_SMALLTEMPLATE);
	else if (temp3 == 2)
		smallcharacter[0].LoadBitmap(IDB_SMALLDEEP);
	else
		smallcharacter[0].LoadBitmap(IDB_SMALLDAVID);
}

void CGameStateStage2::OnMove()							// 移動遊戲元素
{
	int i = 0;
	enemy_num = 0;
	for (i = 0; i < 5; i++) {
		if (enemy[i].enemy_now)
			enemy_num++;
	}
	if (enemy[0].IsDead()) {
		if (smallstage == 1 && enemy[0].is_alive) {
			
			smallstage++;
			enemy[1].enemy_now = true;
			enemy[2].enemy_now = true;
		}
		enemy[0].is_alive = false;
		enemy[0].SetAlive(false);
		enemy[0].isAttack = false;
		enemy[0].enemy_now = false;
	}
	if (enemy[1].IsDead()) {
		
		enemy[1].is_alive = false;
		enemy[1].SetAlive(false);
		enemy[1].isAttack = false;
		enemy[1].enemy_now = false;
	}
	if (enemy[2].IsDead()) {
		
		enemy[2].is_alive = false;
		enemy[2].SetAlive(false);
		enemy[2].isAttack = false;
		enemy[2].enemy_now = false;
	}
	if (smallstage == 2 && enemy[1].IsDead() && enemy[2].IsDead()) {
		smallstage += 1;
		enemy[3].enemy_now = true;
		enemy[4].enemy_now = true;
	}
	if (enemy[3].IsDead()) {
		
		
		enemy[3].is_alive = false;
		enemy[3].SetAlive(false);
		enemy[3].isAttack = false;
		enemy[3].enemy_now = false;
	}
	if (enemy[4].IsDead()) {
		
		enemy[4].is_alive = false;
		enemy[4].SetAlive(false);
		enemy[4].isAttack = false;
		enemy[4].enemy_now = false;
	}
	if (smallstage == 3 && enemy[3].IsDead() && enemy[4].IsDead()) {
		ofstream fout("blood.txt");
		if (!fout)
		{
			TRACE("檔案I/O失敗");
		}

		fout << player[0].HP << endl;
		fout.close();
		ofstream fout2("magic.txt");
		if (!fout2)
		{
			TRACE("檔案I/O失敗");
		}
		fout2 << player[0].MAGIC << endl;
		fout2.close();
		CAudio::Instance()->Stop(AUDIO_BACK2);
		GotoGameState(GAME_STATE_STAGE3);
	}
	
	if (player[0].IsDead()) {
		CAudio::Instance()->Stop(AUDIO_BACK2);
		GotoGameState(GAME_STATE_OVER);
	}
		


	int p_x = 0, p_y = 0, e_x = 0, e_y = 0;
	player[0].Decrease();
	for (i = 0; i < 5; i++) {
		if (enemy[i].enemy_now)
			enemy[i].getCloseToPlayer(player[0].x, player[0].y);
	}

	for (i = 0; i < 5; i++) {
		if (enemy[i].enemy_now) {
			if (player[0].isAttack)
				enemy[i].isUnderAttack(player[0].x, player[0].y, player[0].z, player[0].isAttack);
			else
				player[0].isUnderAttack(enemy[i].x, enemy[i].y, enemy[i].z, enemy[i].isAttack);
		}
	}


}

void CGameStateStage2::OnInit()  								// 遊戲的初值及圖形設定
{
	ShowInitProgress(33);	// 接個前一個狀態的進度，此處進度視為33%	
	stageone.LoadBitmap(IDB_STAGETWOBACKGROUND);
	up_block.LoadBitmap(IDB_UPBLOCK);
	CAudio::Instance()->Load(AUDIO_BACK2, "sounds\\stage2.mp3");



}

void CGameStateStage2::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	int i = 0;
	const char KEY_LEFT = 0x25; // keyboard左箭頭
	const char KEY_UP = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN = 0x28; // keyboard下箭頭
	const char KEY_JUMP = 0x4B; // keyboard k
	const char KEY_ATTACK = 0x4A;
	const char KEY_DEF = 0x4C;
	if (nChar == KEY_LEFT)
		player[0].SetMovingLeft(true);
	if (nChar == KEY_RIGHT)
		player[0].SetMovingRight(true);
	if (nChar == KEY_UP)
		player[0].SetMovingUp(true);
	if (nChar == KEY_DOWN)
		player[0].SetMovingDown(true);
	if (nChar == KEY_JUMP)
		player[0].SetMovingJump(true);
	if (nChar == KEY_ATTACK) {
		player[0].SetAttack(true);
	}
	if (nChar == KEY_DEF) {
		player[0].SetDefense(true);
	}

	if (nChar == KEY_LEFT || nChar == KEY_RIGHT || nChar == KEY_UP || nChar == KEY_DOWN)
		player[0].SetMoving(true);
}

void CGameStateStage2::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT = 0x25; // keyboard左箭頭
	const char KEY_UP = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN = 0x28; // keyboard下箭頭
	const char KEY_JUMP = 0x6B; // keyboard k
	const char KEY_ATTACK = 0x4A;
	const char KEY_DEF = 0x4C;
	if (nChar == KEY_LEFT)
		player[0].SetMovingLeft(false);
	if (nChar == KEY_RIGHT)
		player[0].SetMovingRight(false);
	if (nChar == KEY_UP)
		player[0].SetMovingUp(false);
	if (nChar == KEY_DOWN)
		player[0].SetMovingDown(false);
	if (nChar == KEY_DEF) {
		player[0].SetDefense(false);
	}
	if (player[0].IsMoving() == false)
		player[0].SetMoving(false);
}

void CGameStateStage2::OnShow()
{
	
	stageone.SetTopLeft(0, 100);
	stageone.ShowBitmap();
	up_block.SetTopLeft(0, 0);
	up_block.ShowBitmap();
	smallcharacter[0].SetTopLeft(0, 0);
	smallcharacter[0].ShowBitmap();
	int i = 0;
	for (i = 0; i < 5; i++) {
		if (enemy[i].enemy_now)
			enemy[i].OnShow();
	}

	player[0].DrawAllAboutPlayer();

	CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	CFont f, ff1, *fp, *ff;
	f.CreatePointFont(110, "Times New Roman");	// 產生 font f; 160表示16 point的字
	fp = pDC->SelectObject(&f);					// 選用 font f
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextColor(RGB(255, 255, 255));
	char str[80];								// Demo 數字對字串的轉換
	sprintf(str, "STAGE  %d", stage);
	pDC->TextOut(281, 94, str);

	ff1.CreatePointFont(110, "Times New Roman");	// 產生 font f; 160表示16 point的字
	ff = pDC->SelectObject(&ff1);					// 選用 font f
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextColor(RGB(255, 0, 255));
	char str1[80];								// Demo 數字對字串的轉換
	if (smallstage == 1)
		sprintf(str1, "Man:  %d    HP:  %d", enemy_num, enemy[0].HP);
	else if (smallstage == 2)
		sprintf(str1, "Man:  %d    HP:  %d", enemy_num, enemy[1].HP + enemy[2].HP);
	else if (smallstage == 3)
		sprintf(str1, "Man:  %d    HP:  %d", enemy_num, enemy[3].HP + enemy[4].HP);
	pDC->TextOut(523, 94, str1);
	pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	pDC->SelectObject(ff);
	CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC


}
CGameStateStage3::CGameStateStage3(CGame *g)
	: CGameState(g)//, NUMBALLS(28)
{

}


/////////////////////stage3//////////////////
CGameStateStage3::~CGameStateStage3()
{
	delete[] enemy;
	delete[] player;
	delete[] smallcharacter;
}

void CGameStateStage3::OnBeginState()
{
	CAudio::Instance()->Play(AUDIO_BACK3, true);			// 撥放 WAVE
	stage = 3;
	smallstage = 1;
	ifstream fin3("text1.txt", ios::in);
	int temp3;
	fin3 >> temp3;
	fin3.close();
	ifstream fin("blood.txt", ios::in);
	int temp;
	fin >> temp;
	fin.close();
	player = new Player[1];
	player[0].LoadBitmap(temp3);
	player[0].HP = temp;
	ifstream fin2("magic.txt", ios::in);
	int temp2;
	fin2 >> temp2;
	fin2.close();
	player[0].MAGIC = temp2;
	enemy = new Enemy[5];
	enemy_num = 0;
	int i = 0;
	for (i = 0; i < 5; i++) {
		enemy[i].LoadBitmap(temp);
		enemy[i].SetHP(70);
	}
	enemy[0].SetXY(400, 300);
	enemy[1].SetXY(400, 270);
	enemy[2].SetXY(400, 330);
	enemy[3].SetXY(400, 270);
	enemy[4].SetXY(400, 330);
	enemy_num = 1;
	player[0].SetXY(95, 300);
	if (smallstage == 1) {
		for (i = 1; i < 5; i++)
			enemy[i].enemy_now = false;
	}
	smallcharacter = new CMovingBitmap[1];
	if (temp3 == 1)
		smallcharacter[0].LoadBitmap(IDB_SMALLTEMPLATE);
	else if (temp3 == 2)
		smallcharacter[0].LoadBitmap(IDB_SMALLDEEP);
	else
		smallcharacter[0].LoadBitmap(IDB_SMALLDAVID);
	
}

void CGameStateStage3::OnMove()							
{

	
	int i = 0;
	enemy_num = 0;
	for (i = 0; i < 5; i++) {
		if (enemy[i].enemy_now)
			enemy_num++;
	}
	if (enemy[0].IsDead()) {
		if (smallstage == 1 && enemy[0].is_alive) {
			
			smallstage++;
			enemy[1].enemy_now = true;
			enemy[2].enemy_now = true;
		}
		enemy[0].is_alive = false;
		enemy[0].SetAlive(false);
		enemy[0].isAttack = false;
		enemy[0].enemy_now = false;
	}
	if (enemy[1].IsDead()) {
		
		enemy[1].is_alive = false;
		enemy[1].SetAlive(false);
		enemy[1].isAttack = false;
		enemy[1].enemy_now = false;
	}
	if (enemy[2].IsDead()) {
		
		enemy[2].is_alive = false;
		enemy[2].SetAlive(false);
		enemy[2].isAttack = false;
		enemy[2].enemy_now = false;
	}
	if (smallstage == 2 && enemy[1].IsDead() && enemy[2].IsDead()) {
		smallstage += 1;
		enemy[3].enemy_now = true;
		enemy[4].enemy_now = true;
	}
	if (enemy[3].IsDead()) {
		
		enemy[3].is_alive = false;
		enemy[3].SetAlive(false);
		enemy[3].isAttack = false;
		enemy[3].enemy_now = false;
	}
	if (enemy[4].IsDead()) {
		
		enemy[4].is_alive = false;
		enemy[4].SetAlive(false);
		enemy[4].isAttack = false;
		enemy[4].enemy_now = false;
	}
	if (smallstage == 3 && enemy[3].IsDead() && enemy[4].IsDead()) {
		CAudio::Instance()->Stop(AUDIO_BACK3);
		GotoGameState(GAME_STATE_WIN);
	}
	
	if (player[0].IsDead()) {
		CAudio::Instance()->Stop(AUDIO_BACK3);
		GotoGameState(GAME_STATE_OVER);
	}
		


	int p_x = 0, p_y = 0, e_x = 0, e_y = 0;
	player[0].Decrease();
	for (i = 0; i < 5; i++) {
		if (enemy[i].enemy_now)
			enemy[i].getCloseToPlayer(player[0].x, player[0].y);
	}

	for (i = 0; i < 5; i++) {
		if (enemy[i].enemy_now) {
			if (player[0].isAttack)
				enemy[i].isUnderAttack(player[0].x, player[0].y, player[0].z, player[0].isAttack);
			else
				player[0].isUnderAttack(enemy[i].x, enemy[i].y, enemy[i].z, enemy[i].isAttack);
		}
	}


}
void CGameStateStage3::OnInit()  								// 遊戲的初值及圖形設定
{
	
	ShowInitProgress(33);	// 接個前一個狀態的進度，此處進度視為33%	
	stageone.LoadBitmap(IDB_STAGETHREEBACKGROUND);
	up_block.LoadBitmap(IDB_UPBLOCK);
	CAudio::Instance()->Load(AUDIO_BACK3, "sounds\\stage3.mp3");

}

void CGameStateStage3::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	int i = 0;
	const char KEY_LEFT = 0x25; // keyboard左箭頭
	const char KEY_UP = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN = 0x28; // keyboard下箭頭
	const char KEY_JUMP = 0x4B; // keyboard k
	const char KEY_ATTACK = 0x4A;
	const char KEY_DEF = 0x4C;
	if (nChar == KEY_LEFT)
		player[0].SetMovingLeft(true);
	if (nChar == KEY_RIGHT)
		player[0].SetMovingRight(true);
	if (nChar == KEY_UP)
		player[0].SetMovingUp(true);
	if (nChar == KEY_DOWN)
		player[0].SetMovingDown(true);
	if (nChar == KEY_JUMP)
		player[0].SetMovingJump(true);
	if (nChar == KEY_ATTACK) {
		player[0].SetAttack(true);
	}
	if (nChar == KEY_DEF) {
		player[0].SetDefense(true);
	}

	if (nChar == KEY_LEFT || nChar == KEY_RIGHT || nChar == KEY_UP || nChar == KEY_DOWN)
		player[0].SetMoving(true);
}

void CGameStateStage3::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT = 0x25; // keyboard左箭頭
	const char KEY_UP = 0x26; // keyboard上箭頭
	const char KEY_RIGHT = 0x27; // keyboard右箭頭
	const char KEY_DOWN = 0x28; // keyboard下箭頭
	const char KEY_JUMP = 0x6B; // keyboard k
	const char KEY_ATTACK = 0x4A;
	const char KEY_DEF = 0x4C;
	if (nChar == KEY_LEFT)
		player[0].SetMovingLeft(false);
	if (nChar == KEY_RIGHT)
		player[0].SetMovingRight(false);
	if (nChar == KEY_UP)
		player[0].SetMovingUp(false);
	if (nChar == KEY_DOWN)
		player[0].SetMovingDown(false);
	if (nChar == KEY_DEF) {
		player[0].SetDefense(false);
	}
	if (player[0].IsMoving() == false)
		player[0].SetMoving(false);
}

void CGameStateStage3::OnShow()
{
	
	stageone.SetTopLeft(0, 100);
	stageone.ShowBitmap();
	up_block.SetTopLeft(0, 0);
	up_block.ShowBitmap();
	smallcharacter[0].SetTopLeft(0, 0);
	smallcharacter[0].ShowBitmap();
	int i = 0;
	for (i = 0; i < 5; i++) {
		if (enemy[i].enemy_now)
			enemy[i].OnShow();
	}
	player[0].DrawAllAboutPlayer();

	CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	CFont f, ff1, *fp, *ff;
	f.CreatePointFont(110, "Times New Roman");	// 產生 font f; 160表示16 point的字
	fp = pDC->SelectObject(&f);					// 選用 font f
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextColor(RGB(255, 255, 255));
	char str[80];								// Demo 數字對字串的轉換
	sprintf(str, "STAGE  %d", stage);
	pDC->TextOut(281, 94, str);

	ff1.CreatePointFont(110, "Times New Roman");	// 產生 font f; 160表示16 point的字
	ff = pDC->SelectObject(&ff1);					// 選用 font f
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextColor(RGB(255, 0, 255));
	char str1[80];								// Demo 數字對字串的轉換
	if (smallstage == 1)
		sprintf(str1, "Man:  %d    HP:  %d", enemy_num, enemy[0].HP);
	else if (smallstage == 2)
		sprintf(str1, "Man:  %d    HP:  %d", enemy_num, enemy[1].HP + enemy[2].HP);
	else if (smallstage == 3)
		sprintf(str1, "Man:  %d    HP:  %d", enemy_num, enemy[3].HP + enemy[4].HP);
	pDC->TextOut(523, 94, str1);
	pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	pDC->SelectObject(ff);
	CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC


}


}

