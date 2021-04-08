#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CharactorSetting.h"
#include "cmath"
#include "iostream"

namespace game_framework {
	// ³]©w¦n map
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

		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		face_right = true;

		x = 95;
		y = 300;
	}

	void CharactorSetting::LoadBitmap(int RoleSelect222222) {
		if ((RoleSelect222222 % 3 )== 1)
			try1.LoadBitmap(IDB_TEMPLATE);
		else if ((RoleSelect222222 % 3) == 2)
			try1.LoadBitmap(IDB_DEEP);
		else if (RoleSelect222222  == 0)
			try1.LoadBitmap(IDB_DAVID);
		char *file_charactor_walk_to_right[4] = {".\\RES\\template\\walk_to_right\\walk1.bmp", ".\\RES\\template\\walk_to_right\\walk2.bmp", ".\\RES\\template\\walk_to_right\\walk3.bmp", ".\\RES\\template\\walk_to_right\\walk4.bmp"};
		char *file_charactor_walk_to_left[4] = {};
		char *file_charactor_run_to_right[4] = {};
		char *file_charactor_run_to_left[4] = {};
		char *file_charactor_stand_right[4] = { ".\\RES\\template\\stand_right\\stand1.bmp", ".\\RES\\template\\stand_right\\stand2.bmp", ".\\RES\\template\\stand_right\\stand3.bmp", ".\\RES\\template\\stand_right\\stand4.bmp"};

		for (int i = 0; i < 4; i ++) {
			charactor_stand_right.AddBitmap(file_charactor_stand_right[i], RGB(0, 0, 0));
		}

		for (int i = 0; i < 4; i++) {
			charactor_walk_right.AddBitmap(file_charactor_walk_to_right[i], RGB(0, 0, 0));
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
	}

	void CharactorSetting::SetMovingRight(bool flag) {
		isMovingRight = flag;
	}

	void CharactorSetting::OnMove() {
		const int STEP_SIZE = 2;
		if (face_right) {
			if (!isMovingDown && !isMovingLeft && !isMovingRight && !isMovingUp) {
				charactor_stand_right.OnMove();
			}
			else if (isMovingRight && !isMovingLeft && !isMovingUp && !isMovingDown) {
				x += STEP_SIZE;
				charactor_walk_right.OnMove();
			}
		}
		else {
			
		}
	}

	void CharactorSetting::OnShow() {
		try1.SetTopLeft(120, 120);
		charactor_stand_right.SetTopLeft(x, y);
		charactor_walk_right.SetTopLeft(x, y);
		if (face_right) {
			if (!isMovingDown && !isMovingLeft && !isMovingRight && !isMovingUp) {
				charactor_stand_right.OnShow();
			}
			else if (isMovingRight && !isMovingLeft && !isMovingUp && !isMovingDown) {
				charactor_walk_right.OnShow();
			}
		}
		else {

		}
		try1.ShowBitmap();
	}
}