/*
 * mygame.h: ���ɮ��x�C��������class��interface
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
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *   2006-02-08 V4.2
 *      1. Rename OnInitialUpdate() -> OnInit().
 *      2. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      3. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
*/

#include "CEraser.h"
#include "CBall.h"
#include "CBouncingBall.h"
#include "Character.h"
#include "CharactorSetting.h"
#include "player.h"
#include "enemy.h"

namespace game_framework {
	
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////

	enum AUDIO_ID {				// �w�q�U�ح��Ī��s��
		AUDIO_DING,				// 0
		AUDIO_LAKE,				// 1
		AUDIO_NTUT				// 2
	};
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C���}�Y�e������
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnKeyUp(UINT, UINT, UINT); 				// �B�z��LUp���ʧ@
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
	protected:
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
		void OnMove();
	private:
		CMovingBitmap logo;								// csie��logo
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
		CMovingBitmap countdown[35];
		CMovingBitmap menu;
		CMovingBitmap menu2;
		CMovingBitmap menu3;
		CMovingBitmap menu4;
		CMovingBitmap menu5;
		CMovingBitmap menu6;
		int control;
		int attack;
		int select;
		int section;
		int counter;
		int SelectMenu;
		
	};
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CMovingBitmap stageone;
		CMovingBitmap smallcharacter;
		int map_floor_range_x;
		int map_floor_range_y;
		Enemy* enemy;
		Player player;
		int stage;
		int control_hit_speed;
 	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����������A(Game Over)
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		int counter;	// �˼Ƥ��p�ƾ�
	};

}