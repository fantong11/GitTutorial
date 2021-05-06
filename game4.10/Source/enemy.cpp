#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CharactorSetting.h"
#include "cmath"
#include "iostream"
#include <fstream>
#include "enemy.h"

namespace game_framework {
	void Enemy::LoadBitmap(int a) {
<<<<<<< HEAD
		char *file_charactor_shadow[1] = { ".\\RES\\shadow.bmp" };
		charactor_shadow.AddBitmap(file_charactor_shadow[0], RGB(0, 0, 0));
		if (a == 1) {
			char *file_charactor_walk_to_right[6] = { ".\\RES\\template\\walk_to_right\\walk1.bmp", ".\\RES\\template\\walk_to_right\\walk2.bmp", ".\\RES\\template\\walk_to_right\\walk3.bmp", ".\\RES\\template\\walk_to_right\\walk4.bmp", ".\\RES\\template\\walk_to_right\\walk3.bmp" , ".\\RES\\template\\walk_to_right\\walk2.bmp" };
			char *file_charactor_walk_to_left[6] = { ".\\RES\\template\\walk_to_left\\walk1.bmp", ".\\RES\\template\\walk_to_left\\walk2.bmp", ".\\RES\\template\\walk_to_left\\walk3.bmp", ".\\RES\\template\\walk_to_left\\walk4.bmp", ".\\RES\\template\\walk_to_left\\walk3.bmp" , ".\\RES\\template\\walk_to_left\\walk2.bmp" };
			char *file_charactor_stand_right[4] = { ".\\RES\\template\\stand_right\\stand1.bmp", ".\\RES\\template\\stand_right\\stand2.bmp", ".\\RES\\template\\stand_right\\stand3.bmp", ".\\RES\\template\\stand_right\\stand4.bmp" };
			char *file_charactor_stand_left[4] = { ".\\RES\\template\\stand_left\\stand1.bmp", ".\\RES\\template\\stand_left\\stand2.bmp", ".\\RES\\template\\stand_left\\stand3.bmp", ".\\RES\\template\\stand_left\\stand4.bmp" };
			char *file_charactor_attack_right[4] = { ".\\RES\\template\\attack_right\\attack1.bmp",".\\RES\\template\\attack_right\\attack2.bmp",".\\RES\\template\\attack_right\\attack3.bmp" ,".\\RES\\template\\attack_right\\attack4.bmp" };
			char *file_charactor_attack_left[4] = { ".\\RES\\template\\attack_left\\attack1.bmp",".\\RES\\template\\attack_left\\attack2.bmp",".\\RES\\template\\attack_left\\attack3.bmp",".\\RES\\template\\attack_left\\attack4.bmp" };
			char *file_charactor_jump_right[3] = { ".\\RES\\template\\jump_to_right\\jump1.bmp", ".\\RES\\template\\jump_to_right\\jump2.bmp", ".\\RES\\template\\jump_to_right\\jump3.bmp" };
			char *file_charactor_jump_left[3] = { ".\\RES\\template\\jump_to_left\\jump1.bmp", ".\\RES\\template\\jump_to_left\\jump2.bmp", ".\\RES\\template\\jump_to_left\\jump3.bmp" };
=======
>>>>>>> 51a4e4f8c1db43434feb818d4378e920b0d43f17

		
			char *file_charactor_walk_to_right[6] = { ".\\RES\\enemy\\walk_to_right\\walk1.bmp", ".\\RES\\enemy\\walk_to_right\\walk2.bmp", ".\\RES\\enemy\\walk_to_right\\walk3.bmp", ".\\RES\\enemy\\walk_to_right\\walk4.bmp", ".\\RES\\enemy\\walk_to_right\\walk3.bmp" , ".\\RES\\enemy\\walk_to_right\\walk2.bmp" };
			char *file_charactor_walk_to_left[6] = { ".\\RES\\enemy\\walk_to_left\\walk1.bmp", ".\\RES\\enemy\\walk_to_left\\walk2.bmp", ".\\RES\\enemy\\walk_to_left\\walk3.bmp", ".\\RES\\enemy\\walk_to_left\\walk4.bmp", ".\\RES\\enemy\\walk_to_left\\walk3.bmp" , ".\\RES\\enemy\\walk_to_left\\walk2.bmp" };
			char *file_charactor_stand_right[4] = { ".\\RES\\enemy\\stand_right\\stand1.bmp", ".\\RES\\enemy\\stand_right\\stand2.bmp", ".\\RES\\enemy\\stand_right\\stand3.bmp", ".\\RES\\enemy\\stand_right\\stand4.bmp" };
			char *file_charactor_stand_left[4] = { ".\\RES\\enemy\\stand_left\\stand1.bmp", ".\\RES\\enemy\\stand_left\\stand2.bmp", ".\\RES\\enemy\\stand_left\\stand3.bmp", ".\\RES\\enemy\\stand_left\\stand4.bmp" };
			char *file_charactor_attack_right[4] = { ".\\RES\\enemy\\attack_right\\attack1.bmp",".\\RES\\enemy\\attack_right\\attack2.bmp",".\\RES\\enemy\\attack_right\\attack3.bmp" ,".\\RES\\enemy\\attack_right\\attack4.bmp" };
			char *file_charactor_attack_left[4] = { ".\\RES\\enemy\\attack_left\\attack1.bmp",".\\RES\\enemy\\attack_left\\attack2.bmp",".\\RES\\enemy\\attack_left\\attack3.bmp",".\\RES\\enemy\\attack_left\\attack4.bmp" };

			char *file_charactor_shadow[1] = { ".\\RES\\shadow.bmp" };
			charactor_shadow.AddBitmap(file_charactor_shadow[0], RGB(0, 0, 0));
		
			for (int i = 0; i < 4; i++) {
				charactor_stand_right.AddBitmap(file_charactor_stand_right[i], RGB(0, 0, 0));
				charactor_stand_left.AddBitmap(file_charactor_stand_left[i], RGB(0, 0, 0));
			}

			for (int i = 0; i < 6; i++) {
				charactor_walk_right.AddBitmap(file_charactor_walk_to_right[i], RGB(0, 0, 0));
				charactor_walk_left.AddBitmap(file_charactor_walk_to_left[i], RGB(0, 0, 0));
			}

			for (int i = 0; i < 4; i++) {
				charactor_attack_right.AddBitmap(file_charactor_attack_right[i], RGB(0, 0, 0));
				charactor_attack_left.AddBitmap(file_charactor_attack_left[i], RGB(0, 0, 0));
			}

<<<<<<< HEAD
			for (int i = 0; i < 3; i++) {
				charactor_jump_left.AddBitmap(file_charactor_jump_left[i], RGB(0, 0, 0));
				charactor_jump_right.AddBitmap(file_charactor_jump_right[i], RGB(0, 0, 0));
			}

		}
		else if (a == 2) {
			char *file_charactor_walk_to_right[6] = { ".\\RES\\deep\\walk_to_right\\walk1.bmp", ".\\RES\\deep\\walk_to_right\\walk2.bmp", ".\\RES\\deep\\walk_to_right\\walk3.bmp", ".\\RES\\deep\\walk_to_right\\walk4.bmp", ".\\RES\\deep\\walk_to_right\\walk3.bmp" , ".\\RES\\deep\\walk_to_right\\walk2.bmp" };
			char *file_charactor_walk_to_left[6] = { ".\\RES\\deep\\walk_to_left\\walk1.bmp", ".\\RES\\deep\\walk_to_left\\walk2.bmp", ".\\RES\\deep\\walk_to_left\\walk3.bmp", ".\\RES\\deep\\walk_to_left\\walk4.bmp", ".\\RES\\deep\\walk_to_left\\walk3.bmp" , ".\\RES\\deep\\walk_to_left\\walk2.bmp" };
			char *file_charactor_stand_right[4] = { ".\\RES\\deep\\stand_right\\stand1.bmp", ".\\RES\\deep\\stand_right\\stand2.bmp", ".\\RES\\deep\\stand_right\\stand3.bmp", ".\\RES\\deep\\stand_right\\stand4.bmp" };
			char *file_charactor_stand_left[4] = { ".\\RES\\deep\\stand_left\\stand1.bmp", ".\\RES\\deep\\stand_left\\stand2.bmp", ".\\RES\\deep\\stand_left\\stand3.bmp", ".\\RES\\deep\\stand_left\\stand4.bmp" };
			char *file_charactor_attack_right[4] = { ".\\RES\\deep\\attack_right\\attack1.bmp",".\\RES\\deep\\attack_right\\attack2.bmp",".\\RES\\deep\\attack_right\\attack3.bmp",".\\RES\\deep\\attack_right\\attack4.bmp" };
			char *file_charactor_attack_left[4] = { ".\\RES\\deep\\attack_left\\attack1.bmp",".\\RES\\deep\\attack_left\\attack2.bmp",".\\RES\\deep\\attack_left\\attack3.bmp",".\\RES\\deep\\attack_left\\attack4.bmp" };

			for (int i = 0; i < 4; i++) {
				charactor_stand_right.AddBitmap(file_charactor_stand_right[i], RGB(0, 0, 0));
				charactor_stand_left.AddBitmap(file_charactor_stand_left[i], RGB(0, 0, 0));
			}

			for (int i = 0; i < 6; i++) {
				charactor_walk_right.AddBitmap(file_charactor_walk_to_right[i], RGB(0, 0, 0));
				charactor_walk_left.AddBitmap(file_charactor_walk_to_left[i], RGB(0, 0, 0));
			}

			for (int i = 0; i < 4; i++) {
				charactor_attack_right.AddBitmap(file_charactor_attack_right[i], RGB(0, 0, 0));
				charactor_attack_left.AddBitmap(file_charactor_attack_left[i], RGB(0, 0, 0));
			}
		}
		else {
			char *file_charactor_walk_to_right[6] = { ".\\RES\\david\\walk_to_right\\walk1.bmp", ".\\RES\\david\\walk_to_right\\walk2.bmp", ".\\RES\\david\\walk_to_right\\walk3.bmp", ".\\RES\\david\\walk_to_right\\walk4.bmp", ".\\RES\\david\\walk_to_right\\walk3.bmp" , ".\\RES\\david\\walk_to_right\\walk2.bmp" };
			char *file_charactor_walk_to_left[6] = { ".\\RES\\david\\walk_to_left\\walk1.bmp", ".\\RES\\david\\walk_to_left\\walk2.bmp", ".\\RES\\david\\walk_to_left\\walk3.bmp", ".\\RES\\david\\walk_to_left\\walk4.bmp", ".\\RES\\david\\walk_to_left\\walk3.bmp" , ".\\RES\\david\\walk_to_left\\walk2.bmp" };
			char *file_charactor_stand_right[4] = { ".\\RES\\david\\stand_right\\stand1.bmp", ".\\RES\\david\\stand_right\\stand2.bmp", ".\\RES\\david\\stand_right\\stand3.bmp", ".\\RES\\david\\stand_right\\stand4.bmp" };
			char *file_charactor_stand_left[4] = { ".\\RES\\david\\stand_left\\stand1.bmp", ".\\RES\\david\\stand_left\\stand2.bmp", ".\\RES\\david\\stand_left\\stand3.bmp", ".\\RES\\david\\stand_left\\stand4.bmp" };
			char *file_charactor_attack_right[4] = { ".\\RES\\david\\attack_right\\attack1.bmp",".\\RES\\david\\attack_right\\attack2.bmp",".\\RES\\david\\attack_right\\attack3.bmp",".\\RES\\david\\attack_right\\attack4.bmp" };
			char *file_charactor_attack_left[4] = { ".\\RES\\david\\attack_left\\attack1.bmp",".\\RES\\david\\attack_left\\attack2.bmp",".\\RES\\david\\attack_left\\attack3.bmp",".\\RES\\david\\attack_left\\attack4.bmp" };

			for (int i = 0; i < 4; i++) {
				charactor_stand_right.AddBitmap(file_charactor_stand_right[i], RGB(0, 0, 0));
				charactor_stand_left.AddBitmap(file_charactor_stand_left[i], RGB(0, 0, 0));
			}

			for (int i = 0; i < 6; i++) {
				charactor_walk_right.AddBitmap(file_charactor_walk_to_right[i], RGB(0, 0, 0));
				charactor_walk_left.AddBitmap(file_charactor_walk_to_left[i], RGB(0, 0, 0));
			}
			for (int i = 0; i < 4; i++) {
				charactor_attack_right.AddBitmap(file_charactor_attack_right[i], RGB(0, 0, 0));
				charactor_attack_left.AddBitmap(file_charactor_attack_left[i], RGB(0, 0, 0));
			}
		}
=======
		
>>>>>>> 51a4e4f8c1db43434feb818d4378e920b0d43f17
	}

	void Enemy::SetXY(int _x, int _y) {
		x = _x;
		y = _y;
		z = 0;
		face_right = false;
		HP = 50;
	}

	void Enemy::getCloseToPlayer(int _x, int _y) {
		if (x > _x && fabs(x - _x) > 10) {

			SetMovingLeft(true);
		}
		if (x < _x && fabs(x - _x) > 10) {

			SetMovingRight(true);
		}
		if (y > _y && fabs(y - _y) > 1) {
	
			SetMovingUp(true);
			SetMovingDown(false);
		}
		if (y < _y && fabs(y - _y) > 1) {
			
			SetMovingDown(true);
			SetMovingUp(false);
		}
		SetMoving(true);
		if (fabs(y - _y) < 1) {
			
			if (fabs(x - _x) < 30){
				SetMoving(false);
				SetAttack(true);
			}
				
		}
		OnMove();


	}
	void Enemy::getHit() {
		SetAttack(true);
	}
	void Enemy::DrawAllAboutEnemy() {
		OnShow();
		CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
		CPen *pp, p(PS_NULL, 0, RGB(0, 0, 0));		// 清除pen
		pp = pDC->SelectObject(&p);

		CFont f, *fp;
		f.CreatePointFont(110, "Times New Roman");	// 產生 font f; 160表示16 point的字
		fp = pDC->SelectObject(&f);					// 選用 font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(120, 120, 255));
		char str[80];								// Demo 數字對字串的轉換
		sprintf(str, "Man:  1    HP:  %d", HP);
		pDC->TextOut(300, 94, str);


		pDC->SelectObject(pp);						// 釋放 pen
		pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
		//pDC->SelectObject(pb);						// 釋放 brush
		CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC

	}

}