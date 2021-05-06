/*
 * mygame.cpp: ���ɮ��x�C��������class��implementation
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
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
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
// �o��class���C�����C���}�Y�e������
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g)
: CGameState(g)
{
	

	
	

}

void CGameStateInit::OnInit()
{
	//
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(0);	// �@�}�l��loading�i�׬�0%
	//
	// �}�l���J���
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
	const char KEY_LEFT = 0x25; // keyboard���b�Y
	const char KEY_UP = 0x26; // keyboard�W�b�Y
	const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
	const char KEY_DOWN = 0x28; // keyboard�U�b�Y
	const char KEY_ATTACK = 0x4A;
	const char KEY_DEF = 0x4C;
	const char KEY_JUMP = 0x4B;
	if (nChar == KEY_ATTACK) {
		TRACE("�ɮ�I/O����\n");
		attack++;
		if (attack == 3) {
			
			if (SelectMenu >= 0) {
				if (((SelectMenu + 1) % 6) == 1) {
					if ((abs(SelectMenu) % 6) == 0) {
						ofstream fout("text1.txt");
						if (!fout)
						{
							TRACE("�ɮ�I/O����");
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
						TRACE("�ɮ�I/O����");
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
		
		if (attack == 2 && counter!=0) {
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
	else if (nChar == KEY_ESC)								// Demo �����C������k
		PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0);	// �����C��
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	section++;
}
void CGameStateInit::OnShow()
{
	//
	// �K�Wlogo
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
// �o��class���C�����������A(Game Over)
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
	counter = 30 * 5; // 5 seconds
}

void CGameStateOver::OnInit()
{
	//
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(66);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���66%
	//
	// �}�l���J���
	//
	Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
	//
	// �̲׶i�׬�100%
	//
	ShowInitProgress(100);
}

void CGameStateOver::OnShow()
{
	CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
	CFont f,*fp;
	f.CreatePointFont(160,"Times New Roman");	// ���� font f; 160���16 point���r
	fp=pDC->SelectObject(&f);					// ��� font f
	pDC->SetBkColor(RGB(0,0,0));
	pDC->SetTextColor(RGB(255,255,0));
	char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
	sprintf(str, "Game Over ! (%d)", counter / 30);
	pDC->TextOut(240,210,str);
	pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
	CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
}

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g)
: CGameState(g)//, NUMBALLS(28)
{
	stage = 1;
	control_hit_speed = 0;
	//ball = new CBall [NUMBALLS];
}

CGameStateRun::~CGameStateRun()
{
	delete [] enemy;
}

void CGameStateRun::OnBeginState()
{
	ifstream fin("text1.txt", ios::in);
	int temp;
	fin >> temp;
	fin.close();
	player.LoadBitmap(temp);
	enemy = new Enemy[1];
	enemy[0].LoadBitmap(temp);
	player.SetXY(95, 300);
	enemy[0].SetXY(400, 300);
	if(temp==1)
		smallcharacter.LoadBitmap(IDB_SMALLTEMPLATE);
	else if(temp==2)
		smallcharacter.LoadBitmap(IDB_SMALLDEEP);
	else
		smallcharacter.LoadBitmap(IDB_SMALLDAVID);
	/*
	const int BALL_GAP = 90;
	const int BALL_XY_OFFSET = 45;
	const int BALL_PER_ROW = 7;
	const int HITS_LEFT = 10;
	const int HITS_LEFT_X = 590;
	const int HITS_LEFT_Y = 0;
	const int BACKGROUND_X = 60;
	const int ANIMATION_SPEED = 15;
	for (int i = 0; i < NUMBALLS; i++) {				// �]�w�y���_�l�y��
		int x_pos = i % BALL_PER_ROW;
		int y_pos = i / BALL_PER_ROW;
		ball[i].SetXY(x_pos * BALL_GAP + BALL_XY_OFFSET, y_pos * BALL_GAP + BALL_XY_OFFSET);
		ball[i].SetDelay(x_pos);
		ball[i].SetIsAlive(true);
	}
	eraser.Initialize();
	background.SetTopLeft(BACKGROUND_X,0);				// �]�w�I�����_�l�y��
	help.SetTopLeft(0, SIZE_Y - help.Height());			// �]�w�����Ϫ��_�l�y��
	hits_left.SetInteger(HITS_LEFT);					// ���w�ѤU��������
	hits_left.SetTopLeft(HITS_LEFT_X,HITS_LEFT_Y);		// ���w�ѤU�����ƪ��y��
	CAudio::Instance()->Play(AUDIO_LAKE, true);			// ���� WAVE
	CAudio::Instance()->Play(AUDIO_DING, false);		// ���� WAVE
	CAudio::Instance()->Play(AUDIO_NTUT, true);			// ���� MIDI
	*/
}

void CGameStateRun::OnMove()							// ���ʹC������
{
	/*
	//
	// �p�G�Ʊ�ק�cursor���˦��A�h�N�U���{����commment�����Y�i
	//
	// SetCursor(AfxGetApp()->LoadCursor(IDC_GAMECURSOR));
	//
	// ���ʭI���Ϫ��y��
	//
	if (background.Top() > SIZE_Y)
		background.SetTopLeft(60 ,-background.Height());
	background.SetTopLeft(background.Left(),background.Top()+1);
	//
	// ���ʲy
	//
	int i;
	for (i=0; i < NUMBALLS; i++)
		ball[i].OnMove();
	//
	// �������l
	//
	eraser.OnMove();
	//
	// �P�_���l�O�_�I��y
	//
	for (i=0; i < NUMBALLS; i++)
		if (ball[i].IsAlive() && ball[i].HitEraser(&eraser)) {
			ball[i].SetIsAlive(false);
			CAudio::Instance()->Play(AUDIO_DING);
			hits_left.Add(-1);
			//
			// �Y�Ѿl�I�����Ƭ�0�A�h����Game Over���A
			//
			if (hits_left.GetInteger() <= 0) {
				CAudio::Instance()->Stop(AUDIO_LAKE);	// ���� WAVE
				CAudio::Instance()->Stop(AUDIO_NTUT);	// ���� MIDI
				GotoGameState(GAME_STATE_OVER);
			}
		}
	//
	// ���ʼu�����y
	//
	bball.OnMove();
	*/


	if(player.IsDead())
		GotoGameState(GAME_STATE_OVER);
	if (enemy[0].IsDead()) {
		enemy[0].SetAlive(false);
		enemy[0].isAttack = false;
	}
	int p_x = 0, p_y = 0, e_x = 0, e_y = 0;
	if (control_hit_speed > 0)
		control_hit_speed--;

	if (fabs(player.y - enemy[0].y) < 1) {
		if (fabs(player.x - enemy[0].x) < 30) {
			if (player.IsAttacking() && control_hit_speed==0) {
				control_hit_speed = 30;
				if (enemy[0].IsAttacking()) {
					player.DecreaseBlood();
					enemy[0].DecreaseBlood();
				}
				else
					enemy[0].DecreaseBlood();
			}
			else if (enemy[0].IsAttacking() && control_hit_speed == 0) {
				control_hit_speed = 30;
				if (player.IsAttacking()) {
					player.DecreaseBlood();
					enemy[0].DecreaseBlood();
				}
				else
					player.DecreaseBlood();
			}
		}
	}

	player.Decrease();
	enemy[0].getCloseToPlayer(player.x, player.y);

}

void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
{
	//
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(33);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���33%	
	stageone.LoadBitmap(IDB_STAGEONEBG);

	
	
	//
	// �}�l���J���
	//
	/*
	int i;
	for (i = 0; i < NUMBALLS; i++)	
		ball[i].LoadBitmap();								// ���J��i�Ӳy���ϧ�
	eraser.LoadBitmap();
	background.LoadBitmap(IDB_BACKGROUND);					// ���J�I�����ϧ�
	//
	// ��������Loading�ʧ@�A�����i��
	//
	ShowInitProgress(50);
	Sleep(300); // ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
	//
	// �~����J��L���
	//
	help.LoadBitmap(IDB_HELP,RGB(255,255,255));				// ���J�������ϧ�
	corner.LoadBitmap(IDB_CORNER);							// ���J�����ϧ�
	corner.ShowBitmap(background);							// �Ncorner�K��background
	bball.LoadBitmap();										// ���J�ϧ�
	hits_left.LoadBitmap();									
	CAudio::Instance()->Load(AUDIO_DING,  "sounds\\ding.wav");	// ���J�s��0���n��ding.wav
	CAudio::Instance()->Load(AUDIO_LAKE,  "sounds\\lake.mp3");	// ���J�s��1���n��lake.mp3
	CAudio::Instance()->Load(AUDIO_NTUT,  "sounds\\ntut.mid");	// ���J�s��2���n��ntut.mid
	//
	// ��OnInit�ʧ@�|����CGameStaterOver::OnInit()�A�ҥH�i���٨S��100%
	//
	*/
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT  = 0x25; // keyboard���b�Y
	const char KEY_UP    = 0x26; // keyboard�W�b�Y
	const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
	const char KEY_DOWN  = 0x28; // keyboard�U�b�Y
	const char KEY_JUMP = 0x4B; // keyboard k
	const char KEY_ATTACK = 0x4A;
	if (nChar == KEY_LEFT)
		player.SetMovingLeft(true);
	if (nChar == KEY_RIGHT)
		player.SetMovingRight(true);
	if (nChar == KEY_UP)
		player.SetMovingUp(true);
	if (nChar == KEY_DOWN)
		player.SetMovingDown(true);
	if (nChar == KEY_JUMP)
		player.SetMovingJump(true);
	if (nChar == KEY_ATTACK)
		player.SetAttack(true);
	if (nChar == KEY_LEFT || nChar == KEY_RIGHT || nChar == KEY_UP || nChar == KEY_DOWN || nChar == KEY_JUMP || nChar == KEY_ATTACK)
		player.SetMoving(true);
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT  = 0x25; // keyboard���b�Y
	const char KEY_UP    = 0x26; // keyboard�W�b�Y
	const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
	const char KEY_DOWN  = 0x28; // keyboard�U�b�Y
	const char KEY_JUMP  = 0x6B; // keyboard k
	const char KEY_ATTACK = 0x4A;
	if (nChar == KEY_LEFT)
		player.SetMovingLeft(false);
	if (nChar == KEY_RIGHT)
		player.SetMovingRight(false);
	if (nChar == KEY_UP)
		player.SetMovingUp(false);
	if (nChar == KEY_DOWN)
		player.SetMovingDown(false);
	if (player.IsMoving() == false)
		player.SetMoving(false);
}
/*
void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
	eraser.SetMovingLeft(true);
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
	eraser.SetMovingLeft(false);
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
	// �S�ơC�p�G�ݭn�B�z�ƹ����ʪ��ܡA�gcode�b�o��
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
	eraser.SetMovingRight(true);
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
	eraser.SetMovingRight(false);
}
*/
void CGameStateRun::OnShow()
{
	//
	//  �`�N�GShow�̭��d�U���n���ʥ��󪫥󪺮y�СA���ʮy�Ъ��u�@����Move���~��A
	//        �_�h��������sø�Ϯ�(OnDraw)�A����N�|���ʡA�ݰ_�ӷ|�ܩǡC���ӳN�y
	//        ���AMove�t�dMVC����Model�AShow�t�dView�A��View�������Model�C
	//
	//
	//  �K�W�I���ϡB�����ơB�y�B���l�B�u�����y
	//
	
	/*
	background.ShowBitmap();			// �K�W�I����
	help.ShowBitmap();					// �K�W������
	hits_left.ShowBitmap();
	for (int i=0; i < NUMBALLS; i++)
		ball[i].OnShow();				// �K�W��i���y
	bball.OnShow();						// �K�W�u�����y
	eraser.OnShow();					// �K�W���l
	//
	//  �K�W���W�Υk�U��������
	//
	corner.SetTopLeft(0,0);
	corner.ShowBitmap();
	corner.SetTopLeft(SIZE_X-corner.Width(), SIZE_Y-corner.Height());
	corner.ShowBitmap();
	*/
	stageone.SetTopLeft(0, 0);
	stageone.ShowBitmap();
	smallcharacter.SetTopLeft(0, 0);
	smallcharacter.ShowBitmap();
	enemy[0].DrawAllAboutEnemy();
	player.DrawAllAboutPlayer();

	CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
	CFont f, *fp;
	f.CreatePointFont(110, "Times New Roman");	// ���� font f; 160���16 point���r
	fp = pDC->SelectObject(&f);					// ��� font f
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextColor(RGB(255, 255, 255));
	char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
	sprintf(str, "STAGE  %d",stage);
	pDC->TextOut(285, 94, str);
	pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
	CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC

}


}

