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
#include "player.h"

namespace game_framework {
	void Player::LoadBitmap(int a) {
		if (a == 1) {
			char *file_charactor_walk_to_right[6] = { ".\\RES\\template\\walk_to_right\\walk1.bmp", ".\\RES\\template\\walk_to_right\\walk2.bmp", ".\\RES\\template\\walk_to_right\\walk3.bmp", ".\\RES\\template\\walk_to_right\\walk4.bmp", ".\\RES\\template\\walk_to_right\\walk3.bmp" , ".\\RES\\template\\walk_to_right\\walk2.bmp" };
			char *file_charactor_walk_to_left[6] = { ".\\RES\\template\\walk_to_left\\walk1.bmp", ".\\RES\\template\\walk_to_left\\walk2.bmp", ".\\RES\\template\\walk_to_left\\walk3.bmp", ".\\RES\\template\\walk_to_left\\walk4.bmp", ".\\RES\\template\\walk_to_left\\walk3.bmp" , ".\\RES\\template\\walk_to_left\\walk2.bmp" };
			char *file_charactor_stand_right[4] = { ".\\RES\\template\\stand_right\\stand1.bmp", ".\\RES\\template\\stand_right\\stand2.bmp", ".\\RES\\template\\stand_right\\stand3.bmp", ".\\RES\\template\\stand_right\\stand4.bmp" };
			char *file_charactor_stand_left[4] = { ".\\RES\\template\\stand_left\\stand1.bmp", ".\\RES\\template\\stand_left\\stand2.bmp", ".\\RES\\template\\stand_left\\stand3.bmp", ".\\RES\\template\\stand_left\\stand4.bmp" };
			char *file_charactor_attack_right[4] = { ".\\RES\\template\\attack_right\\attack1.bmp",".\\RES\\template\\attack_right\\attack2.bmp",".\\RES\\template\\attack_right\\attack3.bmp" ,".\\RES\\template\\attack_right\\attack4.bmp" };
			char *file_charactor_attack_left[4] = { ".\\RES\\template\\attack_left\\attack1.bmp",".\\RES\\template\\attack_left\\attack2.bmp",".\\RES\\template\\attack_left\\attack3.bmp",".\\RES\\template\\attack_left\\attack4.bmp" };

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
	}

	void Player::SetXY(int _x, int _y) {
		x = _x;
		y = _y;
		face_right = true;
	}

	void Player::Decrease() {
		LEAVE_BLOOD = 144 - int((500 - HP)*0.206);
		LEAVE_MAGIC = 144 - int((100 - MAGIC)*103/100);
		//HP--;
		//MAGIC--;
		if (LEAVE_BLOOD <= 41) {
			LEAVE_BLOOD = 41;
		}
		if (LEAVE_MAGIC <= 41)
			LEAVE_MAGIC = 41;
		if (HP < 0)
			HP = 0;
		if (MAGIC < 0)
			MAGIC = 0;
		OnMove();
	}
	void Player::DrawAllAboutPlayer() {
		OnShow();
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
		pDC->TextOut(6, 94, str);


		CBrush b2(RGB(255, 0, 0));					// �e���� progrss�i��
		pDC->SelectObject(&b2);
		pDC->Rectangle(41, 12, LEAVE_BLOOD, 25);

		CBrush b3(RGB(0, 0, 255));					// �e���� progrss�i��
		pDC->SelectObject(&b3);
		pDC->Rectangle(41, 29, LEAVE_MAGIC, 42);

		pDC->SelectObject(pp);						// ���� pen
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		//pDC->SelectObject(pb);						// ���� brush
		CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
		
	}
}