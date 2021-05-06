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

		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isMovingJump = isMoving = isAttack = false;
		on_floor = is_alive=true;

		HP = 500;
		MAGIC = 100;
		LEAVE_MAGIC = 100;
		LEAVE_BLOOD = 500;
		control_attack = 10;

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

	void CharactorSetting::SetAttack(bool flag) {
		isAttack = flag;
	}

	
	void CharactorSetting::SetMovingDown(bool flag) {
		isAttack = false;
		isMovingDown = flag;
	}

	void CharactorSetting::SetMovingUp(bool flag) {
		isAttack = false;
		isMovingUp = flag;
	}

	void CharactorSetting::SetMovingLeft(bool flag) {
		isAttack = false;
		isMovingLeft = flag;
		face_right = false;
	}

	void CharactorSetting::SetMovingRight(bool flag) {
		isAttack = false;
		isMovingRight = flag;
		face_right = true;
	}

	void CharactorSetting::SetMovingJump(bool flag) {
		isAttack = false;
		isMovingJump = flag;
		on_floor = false;
	}

	void CharactorSetting::SetMoving(bool flag) {
		isMoving = flag;
	}

	bool CharactorSetting::IsDead() {
		if (HP == 0)
			return true;
		else
			return false;
	}
	int CharactorSetting::NowX() {
		return x;
	}
	int CharactorSetting::NowY() {
		return y;
	}
	bool CharactorSetting::IsAttacking() {
		return isAttack;
	}
	
	void CharactorSetting::DecreaseBlood() {
		if(HP > 0)
			HP -=10;	
	}
	void CharactorSetting::SetAlive(bool flag) {
		is_alive = false;
	}
	
	void CharactorSetting::OnMove() {
		const int STEP_SIZE = 2;

		if (face_right) {
			if (!isMoving) {
				if (isAttack) {
					
					charactor_attack_right.OnMove();
					charactor_attack_right.OnMove();
					charactor_attack_right.OnMove();
					control_attack--;
					if (control_attack == 0) {
						control_attack = 10;
						isAttack = false;
					}
				}
				else{
				
					charactor_stand_right.OnMove();
					charactor_stand_right.OnMove();
					charactor_stand_right.OnMove();
				}

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
				if (isMovingJump) {
					
				}
				charactor_walk_right.OnMove();
				charactor_walk_right.OnMove();
				charactor_walk_right.OnMove();
			}
		}
		else {
			if (!isMoving) {
				if (isAttack) {

					charactor_attack_left.OnMove();
					charactor_attack_left.OnMove();
					charactor_attack_left.OnMove();
					control_attack--;
					if (control_attack == 0) {
						control_attack = 10;
						isAttack = false;
					}
				}
				else {
					charactor_stand_left.OnMove();
					charactor_stand_left.OnMove();
					charactor_stand_left.OnMove();
				}
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
		if (is_alive) {
			charactor_attack_right.SetTopLeft(x, y + z);
			charactor_attack_left.SetTopLeft(x, y + z);
			charactor_stand_right.SetTopLeft(x, y + z);
			charactor_stand_left.SetTopLeft(x, y + z);
			charactor_walk_right.SetTopLeft(x, y + z);
			charactor_walk_left.SetTopLeft(x, y + z);
			charactor_shadow.SetTopLeft(x + 20, y + 75 + z);

			charactor_shadow.OnShow();
			if (face_right) {
				if (!isMoving) {
					if (isAttack) {
						charactor_attack_right.OnShow();
						charactor_attack_right.OnShow();
						charactor_attack_right.OnShow();
					}
					else {

						charactor_stand_right.OnShow();
						charactor_stand_right.OnShow();
						charactor_stand_right.OnShow();
					}
				}
				else {
					charactor_walk_right.OnShow();
					charactor_walk_right.OnShow();
					charactor_walk_right.OnShow();
				}
			}
			else {
				if (!isMoving) {
					if (isAttack) {
						charactor_attack_left.OnShow();
						charactor_attack_left.OnShow();
						charactor_attack_left.OnShow();
					}
					else {
						charactor_stand_left.OnShow();
						charactor_stand_left.OnShow();
						charactor_stand_left.OnShow();
					}
				}
				else {
					charactor_walk_left.OnShow();
					charactor_walk_left.OnShow();
					charactor_walk_left.OnShow();
				}
			}


		}
	}
}