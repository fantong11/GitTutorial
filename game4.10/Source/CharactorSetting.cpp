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

namespace game_framework {
	// 設定好 map
	CharactorSetting::CharactorSetting() {
		const int ATTACK_VALUE = 100;
		const int DEFENSE_VALUE = 50;
		const int WALK_VALUE = 50;
		const int RUN_VALUE = 100;
		const int HEALTH_VALUE = 1000;
		
		

		charactor_attack_value = ATTACK_VALUE;
		charactor_defense_value = DEFENSE_VALUE;
		charactor_walk_value = WALK_VALUE;
		charactor_run_value = RUN_VALUE;
		charactor_health_value = HEALTH_VALUE;

		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isMovingJump = isMoving = false;
		face_right = true;
		on_floor = true;

		x = 95;
		y = 300;
		HP = 500;
		MAGIC = 100;
		LEAVE_MAGIC = 100;
		LEAVE_BLOOD = 500;

	}

	void CharactorSetting::SetXY(int _x, int _y) {
		x = _x;
		y = _y;
		face_right = false;
	}


	bool CharactorSetting::IsMoving(void) {
		if (!isMovingLeft && !isMovingUp && !isMovingDown && !isMovingRight && !isMovingJump)
			return false;
		else 
			return true;
	}

	void CharactorSetting::LoadBitmap(int a) {
		if (a == 1) {
			char *file_charactor_walk_to_right[6] = { ".\\RES\\template\\walk_to_right\\walk1.bmp", ".\\RES\\template\\walk_to_right\\walk2.bmp", ".\\RES\\template\\walk_to_right\\walk3.bmp", ".\\RES\\template\\walk_to_right\\walk4.bmp", ".\\RES\\template\\walk_to_right\\walk3.bmp" , ".\\RES\\template\\walk_to_right\\walk2.bmp" };
			char *file_charactor_walk_to_left[6] = { ".\\RES\\template\\walk_to_left\\walk1.bmp", ".\\RES\\template\\walk_to_left\\walk2.bmp", ".\\RES\\template\\walk_to_left\\walk3.bmp", ".\\RES\\template\\walk_to_left\\walk4.bmp", ".\\RES\\template\\walk_to_left\\walk3.bmp" , ".\\RES\\template\\walk_to_left\\walk2.bmp" };
			char *file_charactor_stand_right[4] = { ".\\RES\\template\\stand_right\\stand1.bmp", ".\\RES\\template\\stand_right\\stand2.bmp", ".\\RES\\template\\stand_right\\stand3.bmp", ".\\RES\\template\\stand_right\\stand4.bmp" };
			char *file_charactor_stand_left[4] = { ".\\RES\\template\\stand_left\\stand1.bmp", ".\\RES\\template\\stand_left\\stand2.bmp", ".\\RES\\template\\stand_left\\stand3.bmp", ".\\RES\\template\\stand_left\\stand4.bmp" };
			for (int i = 0; i < 4; i++) {
				charactor_stand_right.AddBitmap(file_charactor_stand_right[i], RGB(0, 0, 0));
				charactor_stand_left.AddBitmap(file_charactor_stand_left[i], RGB(0, 0, 0));
			}

			for (int i = 0; i < 6; i++) {
				charactor_walk_right.AddBitmap(file_charactor_walk_to_right[i], RGB(0, 0, 0));
				charactor_walk_left.AddBitmap(file_charactor_walk_to_left[i], RGB(0, 0, 0));
			}

		}		
		else if(a == 2){
			char *file_charactor_walk_to_right[6] = { ".\\RES\\deep\\walk_to_right\\walk1.bmp", ".\\RES\\deep\\walk_to_right\\walk2.bmp", ".\\RES\\deep\\walk_to_right\\walk3.bmp", ".\\RES\\deep\\walk_to_right\\walk4.bmp", ".\\RES\\deep\\walk_to_right\\walk3.bmp" , ".\\RES\\deep\\walk_to_right\\walk2.bmp" };
			char *file_charactor_walk_to_left[6] = { ".\\RES\\deep\\walk_to_left\\walk1.bmp", ".\\RES\\deep\\walk_to_left\\walk2.bmp", ".\\RES\\deep\\walk_to_left\\walk3.bmp", ".\\RES\\deep\\walk_to_left\\walk4.bmp", ".\\RES\\deep\\walk_to_left\\walk3.bmp" , ".\\RES\\deep\\walk_to_left\\walk2.bmp" };
			char *file_charactor_stand_right[4]  = { ".\\RES\\deep\\stand_right\\stand1.bmp", ".\\RES\\deep\\stand_right\\stand2.bmp", ".\\RES\\deep\\stand_right\\stand3.bmp", ".\\RES\\deep\\stand_right\\stand4.bmp" };
			char *file_charactor_stand_left[4] = { ".\\RES\\deep\\stand_left\\stand1.bmp", ".\\RES\\deep\\stand_left\\stand2.bmp", ".\\RES\\deep\\stand_left\\stand3.bmp", ".\\RES\\deep\\stand_left\\stand4.bmp" };
			for (int i = 0; i < 4; i++) {
				charactor_stand_right.AddBitmap(file_charactor_stand_right[i], RGB(0, 0, 0));
				charactor_stand_left.AddBitmap(file_charactor_stand_left[i], RGB(0, 0, 0));
			}

			for (int i = 0; i < 6; i++) {
				charactor_walk_right.AddBitmap(file_charactor_walk_to_right[i], RGB(0, 0, 0));
				charactor_walk_left.AddBitmap(file_charactor_walk_to_left[i], RGB(0, 0, 0));
			}
		}
		else {
			char *file_charactor_walk_to_right[6] = { ".\\RES\\david\\walk_to_right\\walk1.bmp", ".\\RES\\david\\walk_to_right\\walk2.bmp", ".\\RES\\david\\walk_to_right\\walk3.bmp", ".\\RES\\david\\walk_to_right\\walk4.bmp", ".\\RES\\david\\walk_to_right\\walk3.bmp" , ".\\RES\\david\\walk_to_right\\walk2.bmp" };
			char *file_charactor_walk_to_left[6] = { ".\\RES\\david\\walk_to_left\\walk1.bmp", ".\\RES\\david\\walk_to_left\\walk2.bmp", ".\\RES\\david\\walk_to_left\\walk3.bmp", ".\\RES\\david\\walk_to_left\\walk4.bmp", ".\\RES\\david\\walk_to_left\\walk3.bmp" , ".\\RES\\david\\walk_to_left\\walk2.bmp" };
			char *file_charactor_stand_right[4] = { ".\\RES\\david\\stand_right\\stand1.bmp", ".\\RES\\david\\stand_right\\stand2.bmp", ".\\RES\\david\\stand_right\\stand3.bmp", ".\\RES\\david\\stand_right\\stand4.bmp" };
			char *file_charactor_stand_left[4] = { ".\\RES\\david\\stand_left\\stand1.bmp", ".\\RES\\david\\stand_left\\stand2.bmp", ".\\RES\\david\\stand_left\\stand3.bmp", ".\\RES\\david\\stand_left\\stand4.bmp" };
			for (int i = 0; i < 4; i++) {
				charactor_stand_right.AddBitmap(file_charactor_stand_right[i], RGB(0, 0, 0));
				charactor_stand_left.AddBitmap(file_charactor_stand_left[i], RGB(0, 0, 0));
			}

			for (int i = 0; i < 6; i++) {
				charactor_walk_right.AddBitmap(file_charactor_walk_to_right[i], RGB(0, 0, 0));
				charactor_walk_left.AddBitmap(file_charactor_walk_to_left[i], RGB(0, 0, 0));
			}
		}
		
	}
	
	void CharactorSetting::SetMovingDown(bool flag) {
		isMovingDown = flag;
	}

	void CharactorSetting::SetMovingUp(bool flag) {
		isMovingUp = flag;
	}

	void CharactorSetting::SetMovingLeft(bool flag) {
		isMovingLeft = flag;
		face_right = false;
	}

	void CharactorSetting::SetMovingRight(bool flag) {
		isMovingRight = flag;
		face_right = true;
	}

	void CharactorSetting::SetMovingJump(bool flag) {
		isMovingJump = flag;
		on_floor = false;
	}

	void CharactorSetting::SetMoving(bool flag) {
		isMoving = flag;
	}

	void CharactorSetting::OnMove() {
		const int STEP_SIZE = 2;
		///// test /////
		LEAVE_BLOOD = 148 - int((500 - HP)*0.2);
		LEAVE_MAGIC = 148 - (100 - MAGIC);
		HP--;
		MAGIC--;
		if (LEAVE_BLOOD <= 45) {
			LEAVE_BLOOD = 45;
			PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	
		}
			
		if (LEAVE_MAGIC <= 45)
			LEAVE_MAGIC = 45;
		//////////////////
		if (face_right) {
			if (!isMoving) {
				charactor_stand_right.OnMove();
				charactor_stand_right.OnMove();
				charactor_stand_right.OnMove();
			}
			else {
				if (isMovingRight) {
					if(x+STEP_SIZE<594)
						x += STEP_SIZE;
				}
				if (isMovingUp) {
					if (y - STEP_SIZE > 224)
						y -= STEP_SIZE;
				}
				if (isMovingDown) {
					if (y + STEP_SIZE < 380)
						y += STEP_SIZE;
				}
				charactor_walk_right.OnMove();
				charactor_walk_right.OnMove();
				charactor_walk_right.OnMove();
			}
		}
		else {
			if (!isMoving) {
				charactor_stand_left.OnMove();
				charactor_stand_left.OnMove();
				charactor_stand_left.OnMove();
			}
			else {
				if (isMovingLeft) {
					if (x - STEP_SIZE > -40)
						x -= STEP_SIZE;
				}
				if (isMovingUp) {
					if (y - STEP_SIZE > 224)
						y -= STEP_SIZE;
				}
				if (isMovingDown) {
					if (y + STEP_SIZE < 380)
						y += STEP_SIZE;
				}
				charactor_walk_left.OnMove();
				charactor_walk_left.OnMove();
				charactor_walk_left.OnMove();
			}
		}
	}

	void CharactorSetting::OnShow() {

		charactor_stand_right.SetTopLeft(x, y);
		charactor_stand_left.SetTopLeft(x, y);
		charactor_walk_right.SetTopLeft(x, y);
		charactor_walk_left.SetTopLeft(x, y);

		if (face_right) {
			if (!isMoving) {
				charactor_stand_right.OnShow();
				charactor_stand_right.OnShow();
				charactor_stand_right.OnShow();
			}
			else {
				charactor_walk_right.OnShow();
				charactor_walk_right.OnShow();
				charactor_walk_right.OnShow();
			}
		}
		else {
			if (!isMoving) {
				charactor_stand_left.OnShow();
				charactor_stand_left.OnShow();
				charactor_stand_left.OnShow();
			}
			else {
				charactor_walk_left.OnShow();
				charactor_walk_left.OnShow();
				charactor_walk_left.OnShow();
			}
		}

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
		pDC->TextOut(10, 94, str);

		
		CBrush b2(RGB(255, 0, 0));					// 畫黃色 progrss進度
		pDC->SelectObject(&b2);
		pDC->Rectangle(45, 12, LEAVE_BLOOD, 25);

		CBrush b3(RGB(0, 0, 255));					// 畫黃色 progrss進度
		pDC->SelectObject(&b3);
		pDC->Rectangle(45, 29, LEAVE_MAGIC, 42);

		pDC->SelectObject(pp);						// 釋放 pen
		pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
		//pDC->SelectObject(pb);						// 釋放 brush
		CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
		//
		// 如果是別的地方用到CDC的話，不要抄以下這行，否則螢幕會閃爍
		//

	}
}