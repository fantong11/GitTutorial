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

		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isMovingJump = isMoving = false;
		face_right = true;
		on_floor = true;

		x = 95;
		y = 300;
	}


	bool CharactorSetting::IsMoving(void) {
		if (!isMovingLeft && !isMovingUp && !isMovingDown && !isMovingRight && !isMovingJump)
			return false;
		else 
			return true;
	}

	void CharactorSetting::LoadBitmap() {
		char *file_charactor_walk_to_right[6] = {".\\RES\\template\\walk_to_right\\walk1.bmp", ".\\RES\\template\\walk_to_right\\walk2.bmp", ".\\RES\\template\\walk_to_right\\walk3.bmp", ".\\RES\\template\\walk_to_right\\walk4.bmp", ".\\RES\\template\\walk_to_right\\walk3.bmp" , ".\\RES\\template\\walk_to_right\\walk2.bmp" };
		char *file_charactor_walk_to_left[6] = {".\\RES\\template\\walk_to_left\\walk1.bmp", ".\\RES\\template\\walk_to_left\\walk2.bmp", ".\\RES\\template\\walk_to_left\\walk3.bmp", ".\\RES\\template\\walk_to_left\\walk4.bmp", ".\\RES\\template\\walk_to_left\\walk3.bmp" , ".\\RES\\template\\walk_to_left\\walk2.bmp"};
		char *file_charactor_stand_right[4] = {".\\RES\\template\\stand_right\\stand1.bmp", ".\\RES\\template\\stand_right\\stand2.bmp", ".\\RES\\template\\stand_right\\stand3.bmp", ".\\RES\\template\\stand_right\\stand4.bmp"};
		char *file_charactor_stand_left[4] = { ".\\RES\\template\\stand_left\\stand1.bmp", ".\\RES\\template\\stand_left\\stand2.bmp", ".\\RES\\template\\stand_left\\stand3.bmp", ".\\RES\\template\\stand_left\\stand4.bmp" };

		for (int i = 0; i < 4; i ++) {
			charactor_stand_right.AddBitmap(file_charactor_stand_right[i], RGB(0, 0, 0));
			charactor_stand_left.AddBitmap(file_charactor_stand_left[i], RGB(0, 0, 0));
		}

		for (int i = 0; i < 6; i++) {
			charactor_walk_right.AddBitmap(file_charactor_walk_to_right[i], RGB(0, 0, 0));
			charactor_walk_left.AddBitmap(file_charactor_walk_to_left[i], RGB(0, 0, 0));
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
		if (face_right) {
			if (!isMoving) {
				charactor_stand_right.OnMove();
				charactor_stand_right.OnMove();
				charactor_stand_right.OnMove();
			}
			else {
				if (isMovingLeft) {
					isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isMovingJump = isMoving = false;
					return;
				}
				if (isMovingRight) {
					x += STEP_SIZE;
				}
				if (isMovingUp) {
					y -= STEP_SIZE;
				}
				if (isMovingDown) {
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
				if (isMovingRight) {
					isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isMovingJump = isMoving = false;
					return;
				}
				if (isMovingLeft) {
					x -= STEP_SIZE;
				}
				if (isMovingUp) {
					y -= STEP_SIZE;
				}
				if (isMovingDown) {
					y += STEP_SIZE;
				}
				charactor_walk_left.OnMove();
				charactor_walk_left.OnMove();
				charactor_walk_left.OnMove();
			}
		}
	}

	void CharactorSetting::OnShow() {
		try1.SetTopLeft(120, 120);
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
		try1.ShowBitmap();
	}
}