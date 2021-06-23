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
#include <windows.h>
#include <vector>
#include <ctime>

namespace game_framework {
	// ³]©w¦n map
	CharactorSetting::CharactorSetting() {
		const int ATTACK_VALUE = 100;
		const int DEFENSE_VALUE = 50;
		const int WALK_VALUE = 50;
		const int RUN_VALUE = 100;
		const int HEALTH_VALUE = 1000;
		STEP_SIZE = 2;
		charactor_attack_value = ATTACK_VALUE;
		charactor_defense_value = DEFENSE_VALUE;
		charactor_walk_value = WALK_VALUE;
		charactor_run_value = RUN_VALUE;
		charactor_health_value = HEALTH_VALUE;

		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isMovingJump = isMoving = isAttack = UnderAttack = isDefense = isMovingRunLeft = isMovingRunRight = false;
		on_floor = is_alive= enemy_now= true;
		jump_count = 0;
		x = 95;
		y = 300;
		z = 0;
		HP = 500;
		MAGIC = 100;
		LEAVE_MAGIC = 100;
		LEAVE_BLOOD = 500;
		control_attack = 10;
		control_be_attack = 10;
		control_hit_speed = 0;
		is_up = false;
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

	void CharactorSetting::whatStatus(void) {
		
	}

	void CharactorSetting::SetAttack(bool flag) {
		// isAttack = flag;
		string s = "attack";
		Data d;
		d.action = s;
		d.time = time(0);
		data.push_back(d);
		whatStatus();
	}

	
	void CharactorSetting::SetMovingDown(bool flag) {
		// isAttack = false;
		// isMovingDown = flag;
		string s = "down";
		Data d;
		d.action = s;
		d.time = time(0);
		data.push_back(d);
		whatStatus();
	}

	void CharactorSetting::SetMovingUp(bool flag) {
		// isAttack = false;
		// isMovingUp = flag;
		string s = "up";
		Data d;
		d.action = s;
		d.time = time(0);
		data.push_back(d);
		whatStatus();
	}

	void CharactorSetting::SetMovingLeft(bool flag) {
		// isAttack = false;
		// isMovingLeft = flag;
		face_right = false;
		string s = "left";
		Data d;
		d.action = s;
		d.time = time(0);
		data.push_back(d);
		whatStatus();
	}

	void CharactorSetting::SetMovingRight(bool flag) {
		// isAttack = false;
		// isMovingRight = flag;
		face_right = true;
		string s = "right";
		Data d;
		d.action = s;
		d.time = time(0);
		data.push_back(d);
		whatStatus();
	}

	void CharactorSetting::SetMovingJump(bool flag) {
		// isAttack = false;
		// isMovingJump = flag;
		// on_floor = false;
		string s = "jump";
		Data d;
		d.action = s;
		d.time = time(0);
		data.push_back(d);
		whatStatus();
	}

	void CharactorSetting::SetMoving(bool flag) {
		isMoving = flag;
	}
	void CharactorSetting::SetDefense(bool flag) {
		// isDefense = flag;
		string s = "defense";
		Data d;
		d.action = s;
		d.time = time(0);
		data.push_back(d);
		whatStatus();
	}
	bool CharactorSetting::IsDead() {
		if (HP <= 0)
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
	void CharactorSetting::DecreaseBlood2() {
		if (HP > 0)
			HP -= 5;
	}
	void CharactorSetting::DecreaseBlood3() {
		if (HP > 0)
			HP -= 30;
	}
	void CharactorSetting::SetAlive(bool flag) {
		is_alive = false;
	}
	void CharactorSetting::isUnderAttack(int _x, int _y,int _z,bool flag) {
		if (control_hit_speed > 0) {
			control_hit_speed--;
		}
		if (fabs(_y - y) < 1) {
			if (fabs(_x - x) < 30) {
				if (_z == z) {
					if (flag && control_hit_speed == 0) {
						isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isMovingJump = isMoving = isAttack = false;
						control_hit_speed = 10;
						UnderAttack = true;
						if (isDefense) {
							DecreaseBlood2();
						}
						else {
							DecreaseBlood();
						}
						
						
					}

				}
			}
		}
	}
	void CharactorSetting::OnMove() {

		
	}
	void CharactorSetting::OnShow() {
		
	}
}