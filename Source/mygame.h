/*
 * mygame.h: 本檔案儲遊戲本身的class的interface
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
 *      1. Add 
 , CGameStateRun, and CGameStateOver to
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
#include "focusblast.h"
#include "swordgas.h"
namespace game_framework {
	
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////

	enum AUDIO_ID {				// 定義各種音效的編號
		AUDIO_BACK1,// 0
		AUDIO_BACK2,
		AUDIO_BACK3
		//AUDIO_LAKE,				// 1
		//AUDIO_NTUT				// 2
	};
	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲開頭畫面物件
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateMenu : public CGameState {
	public:
		CGameStateMenu(CGame *g);
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnKeyUp(UINT, UINT, UINT); 				// 處理鍵盤Up的動作
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
	protected:
		void OnShow();									// 顯示這個狀態的遊戲畫面
		void OnMove();
	private:
		CMovingBitmap logo;								// csie的logo
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
	// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMovingBitmap stageone;
		CMovingBitmap up_block;
		CMovingBitmap* smallcharacter;
		int map_floor_range_x;
		int map_floor_range_y;
		Enemy* enemy;
		Player* player;
		Focusblast* focusblast;
		SwordGas* swordgas;
		int stage;
		int enemy_num;
		int smallstage;
		int special_num;
		int count;
		int count_sec;
 	};
	class CGameStateStage2 : public CGameState {
	public:
		CGameStateStage2(CGame *g);
		~CGameStateStage2();
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMovingBitmap stageone;
		CMovingBitmap up_block;
		CMovingBitmap* smallcharacter;
		Focusblast* focusblast;
		SwordGas* swordgas;
		int special_num;
		int count;
		int map_floor_range_x;
		int map_floor_range_y;
		Enemy* enemy;
		Player* player;
		int stage;
		int enemy_num;
		int smallstage;
		int count_sec;
	};
	class CGameStateStage3 : public CGameState {
	public:
		CGameStateStage3(CGame *g);
		~CGameStateStage3();
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMovingBitmap stageone;
		CMovingBitmap up_block;
		CMovingBitmap* smallcharacter;
		Focusblast* focusblast;
		SwordGas* swordgas;
		int special_num;
		int count;
		int map_floor_range_x;
		int map_floor_range_y;
		Enemy* enemy;
		Player* player;
		int stage;
		int enemy_num;
		int smallstage;
		int count_sec;
	};
	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態(Game Over)
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		int counter;	// 倒數之計數器
		CMovingBitmap lose;
	};
	class CGameStateWin : public CGameState {
	public:
		CGameStateWin(CGame *g);
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		int counter;	// 倒數之計數器
		CMovingBitmap win;
	};

	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
		void OnKeyUp(UINT, UINT, UINT);
	private:
		int counter;
		int SelectMenu;
		CMovingBitmap menu1;
		CMovingBitmap menu2;
		CMovingBitmap menu3;
		CMovingBitmap menu4;
		CMovingBitmap menu5;
		CMovingBitmap menu6;
		CMovingBitmap menu7;
		CMovingBitmap menu8;
	};

	class CGameStateAbout : public CGameState {
	public:
		CGameStateAbout(CGame *g);
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		int counter;	// 倒數之計數器
		CMovingBitmap about;
	};


}