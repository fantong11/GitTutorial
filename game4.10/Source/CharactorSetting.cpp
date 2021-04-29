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
	// �]�w�n map
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
		on_floor = true;

		HP = 500;
		MAGIC = 100;
		LEAVE_MAGIC = 100;
		LEAVE_BLOOD = 500;

	}

	void CharactorSetting::LoadBitmap(int a) {

	}

	void CharactorSetting::SetXY(int _x, int _y) {

	}

	bool CharactorSetting::IsMoving(void) {
		if (!isMovingLeft && !isMovingUp && !isMovingDown && !isMovingRight && !isMovingJump)
			return false;
		else 
			return true;
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

	bool CharactorSetting::IsDead() {
		if (LEAVE_BLOOD == 45)
			return true;
		else
			return false;
	}
	void CharactorSetting::OnMove() {
		const int STEP_SIZE = 2;
		///// test /////
		LEAVE_BLOOD = 148 - int((500 - HP)*0.2);
		LEAVE_MAGIC = 148 - (100 - MAGIC);
		HP-=5;
		MAGIC--;
		if (LEAVE_BLOOD <= 45) {
			LEAVE_BLOOD = 45;
			
			//PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	
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

		CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		CPen *pp, p(PS_NULL, 0, RGB(0, 0, 0));		// �M��pen
		pp = pDC->SelectObject(&p);

		CFont f, *fp;
		f.CreatePointFont(110, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);					// ��� font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(120, 120, 255));
		char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
		sprintf(str, "Man:  1    HP:  %d", HP);
		pDC->TextOut(10, 94, str);

		
		CBrush b2(RGB(255, 0, 0));					// �e���� progrss�i��
		pDC->SelectObject(&b2);
		pDC->Rectangle(45, 12, LEAVE_BLOOD, 25);

		CBrush b3(RGB(0, 0, 255));					// �e���� progrss�i��
		pDC->SelectObject(&b3);
		pDC->Rectangle(45, 29, LEAVE_MAGIC, 42);

		pDC->SelectObject(pp);						// ���� pen
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		//pDC->SelectObject(pb);						// ���� brush
		CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
		//
		// �p�G�O�O���a��Ψ�CDC���ܡA���n�ۥH�U�o��A�_�h�ù��|�{�{
		//

	}
}