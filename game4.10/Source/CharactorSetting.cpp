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
		// ¶]
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isMovingJump = isMoving = isAttack = UnderAttack = isDefense = isMovingRunLeft = isMovingRunRight = false;
		if (data.size() > 1) {
			if (data[data.size() - 1].action == "left" && data[data.size() - 2].action == "left") {
				isMovingRunLeft = true;
				isMovingLeft = false;
			}
			else if (data[data.size() - 1].action == "right" && data[data.size() - 2].action == "right") {
				isMovingRunRight = true;
				isMovingRight = false;
			} 
			else if (data[data.size() - 1].action == "left") {
				isMovingLeft = true;
				isMovingRunLeft = false;
				isMovingRunRight = false;
			}
			else if (data[data.size() - 1].action == "right") {
				isMovingRight = true;
				isMovingRunLeft = false;
				isMovingRunRight = false;
			}
			if (data[data.size() - 1].action == "up") {
				isMovingUp = true;
			}
			if (data[data.size() - 1].action == "down") {
				isMovingDown = true;
			}
			if (data[data.size() - 1].action == "attack") {
				isAttack = true;
				isMovingRunLeft = false;
				isMovingRunRight = false;
			}
			if (data[data.size() - 1].action == "jump") {
				isMovingJump = true;
				isMovingRunLeft = false;
				isMovingRunRight = false;
				on_floor = false;
			}
			if (data[data.size() - 1].action == "defense") {
				isDefense = true;
				isMovingRunLeft = false;
				isMovingRunRight = false;
			}
		}
		

		
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
		

		if (face_right) {
			if (UnderAttack) {
				if (isDefense) {
					charactor_defense_right.OnMove();
				}
				else {
					charactor_behit_right.OnMove();
					charactor_behit_right.OnMove();
				}

				//charactor_behit_right.OnMove();
				//return;
			}
			else if (!isMoving) {
				if (isAttack) {
					charactor_attack_right.OnMove();
					charactor_attack_right.OnMove();
					//charactor_attack_right.OnMove();
					//return;
				}
				else if (isMovingJump) {
					if (z == 0 && jump_count < 2) {
						charactor_jump_right.OnMove();
						charactor_jump_right.OnMove();
						charactor_jump_right.OnMove();
						is_up = true;
						jump_count ++;
					}
					if (jump_count < 2) {
						charactor_jump_right.OnMove();
						charactor_jump_right.OnMove();
						charactor_jump_right.OnMove();
					}
					if (z < 120 && is_up && jump_count == 2) {
						//charactor_jump_right.OnMove();
						z += 10;
					}
					if (z >= 120 && jump_count == 2) {
						//charactor_jump_right.OnMove();
						is_up = false;
					}
					if (!is_up && jump_count == 2) {
						//charactor_jump_right.OnMove();
						z -= 10;
					}
					if (z == 0 && jump_count == 2) {
						jump_count = 0;
						is_up = true;
						charactor_jump_right.OnMove();
						//charactor_jump_right.OnMove();
						isMovingJump = false;
					}
				}
				else if (isDefense) {
					charactor_defense_right.OnMove();
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
					charactor_walk_right.OnMove();
					charactor_walk_right.OnMove();
					charactor_walk_right.OnMove();
				}
				else if (isMovingUp) {
					if (y - STEP_SIZE > 224)
						y -= STEP_SIZE;
					charactor_walk_right.OnMove();
					charactor_walk_right.OnMove();
					charactor_walk_right.OnMove();
				}
				else if (isMovingDown) {
					if (y + STEP_SIZE < 380)
						y += STEP_SIZE;
					charactor_walk_right.OnMove();
					charactor_walk_right.OnMove();
					charactor_walk_right.OnMove();
				}
				else if (isMovingRunRight) {
					if (x + STEP_SIZE + 2 < 594)
						x += 4;
					charactor_run_right.OnMove();
					charactor_run_right.OnMove();
					charactor_run_right.OnMove();
				}
				else if (isMovingJump) {
					if (z == 0) {
						charactor_jump_right.OnMove();
						//charactor_jump_right.OnMove();
						is_up = true;
					}
					if (z < 120 && is_up) {
						z += 10;
					}
					if (z >= 120) {
						is_up = false;
					}
					if (!is_up) {
						z -= 10;
					}
					if (z == 0) {
						is_up = true;
						charactor_jump_right.OnMove();
						//charactor_jump_right.OnMove();
						isMovingJump = false;
					}
					return ;
				}
				
			}
		}
		else {
			if (UnderAttack) {
				if (isDefense) {
					charactor_defense_left.OnMove();
				}
				else {
					charactor_behit_left.OnMove();
					charactor_behit_left.OnMove();
				}
				//charactor_behit_right.OnMove();
				//return;

			}
			else if (!isMoving) {
				if (isAttack) {
					charactor_attack_left.OnMove();
					charactor_attack_left.OnMove();
					//charactor_attack_left.OnMove();
					//return;
				}
				else if (isMovingJump) {
					if (z == 0) {
						charactor_jump_left.OnMove();
						charactor_jump_left.OnMove();
						is_up = true;
					}
					if (z < 120 && is_up) {
						z += 10;
					}
					if (z >= 120) {
						is_up = false;
					}
					if (!is_up) {
						z -= 10;
					}
					if (z == 0) {
						is_up = true;
						charactor_jump_left.OnMove();
						charactor_jump_left.OnMove();
						isMovingJump = false;
					}
					return;
				}
				else if (isDefense) {
					charactor_defense_left.OnMove();
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
					charactor_walk_left.OnMove();
					charactor_walk_left.OnMove();
					charactor_walk_left.OnMove();

				}
				else if (isMovingUp) {
					if (y - STEP_SIZE > 224)
						y -= STEP_SIZE;
					charactor_walk_left.OnMove();
					charactor_walk_left.OnMove();
					charactor_walk_left.OnMove();

				}
				else if (isMovingDown) {
					if (y + STEP_SIZE < 380)
						y += STEP_SIZE;
					charactor_walk_left.OnMove();
					charactor_walk_left.OnMove();
					charactor_walk_left.OnMove();
		
				}
				else if (isMovingRunLeft) {
					if (x - STEP_SIZE - 2 > -40) {
						x -= 4;
						charactor_run_left.OnMove();
						charactor_run_left.OnMove();
						charactor_run_left.OnMove();
					}
				}
				else if (isMovingJump) {
					if (z == 0) {
						charactor_jump_left.OnMove();
						charactor_jump_left.OnMove();
						is_up = true;
					}
					if (z < 120 && is_up) {
						z += 10;
					}
					if (z >= 120) {
						is_up = false;
					}
					if (!is_up) {
						z -= 10;
					}
					if (z == 0) {
						is_up = true;
						charactor_jump_left.OnMove();
						charactor_jump_left.OnMove();
						isMovingJump = false;
					}
					return;
				}
				
			}
		}
	}

	void CharactorSetting::OnShow() {
		if (is_alive) {
			charactor_behit_left.SetTopLeft(x, y - z);
			charactor_jump_left.SetTopLeft(x, y - z);
			charactor_defense_right.SetTopLeft(x, y - z);
			charactor_defense_left.SetTopLeft(x, y - z);
			charactor_behit_right.SetTopLeft(x, y - z);
			charactor_jump_right.SetTopLeft(x, y - z);
			charactor_attack_right.SetTopLeft(x, y - z);
			charactor_attack_left.SetTopLeft(x, y - z);
			charactor_stand_right.SetTopLeft(x, y - z);
			charactor_stand_left.SetTopLeft(x, y - z);
			charactor_walk_right.SetTopLeft(x, y - z);
			charactor_walk_left.SetTopLeft(x, y - z);
			charactor_shadow.SetTopLeft(x + 20, y + 75);
			charactor_run_left.SetTopLeft(x, y - z);
			charactor_run_right.SetTopLeft(x, y - z);

			charactor_shadow.OnShow();


			if (face_right) {
				if (UnderAttack) {
					if (isDefense) {
						charactor_defense_right.OnShow();
					}
					else {
						charactor_behit_right.OnShow();
						charactor_behit_right.OnShow();
						//charactor_behit_right.OnShow();
						control_be_attack--;
						if (control_be_attack == 0) {
							control_be_attack = 10;
							UnderAttack = false;
						}
					}
					//return;
				}
				else if (!isMoving) {
					if (isAttack) {
						charactor_attack_right.OnShow();
						charactor_attack_right.OnShow();
						//charactor_attack_right.OnShow();
						control_attack--;
						if (control_attack == 0) {
							control_attack = 10;
							isAttack = false;
						}
						//return;
					}
					else if (isMovingJump) {
						charactor_jump_right.OnShow();
					}
					else if (isDefense) {
						charactor_defense_right.OnShow();
					}
					else {
						charactor_stand_right.OnShow();
						charactor_stand_right.OnShow();
						charactor_stand_right.OnShow();
					}
				}
				else {
					if (isMovingJump) {
						charactor_jump_right.OnShow();
					}
					else if (isMovingRunRight) {
						charactor_run_right.OnShow();
						charactor_run_right.OnShow();
						charactor_run_right.OnShow();
					}
					else {
						charactor_walk_right.OnShow();
						charactor_walk_right.OnShow();
						charactor_walk_right.OnShow();
					}
				}
			}
			else {
				if (UnderAttack) {
					if (isDefense) {

						charactor_defense_left.OnShow();
						
					}
					else {
						charactor_behit_left.OnShow();
						charactor_behit_left.OnShow();
						//charactor_behit_right.OnShow();
						control_be_attack--;
						if (control_be_attack == 0) {
							control_be_attack = 10;
							UnderAttack = false;
						}
					}
					//return;
				}
				else if (!isMoving) {
					if (isAttack) {
						charactor_attack_left.OnShow();
						charactor_attack_left.OnShow();
						//charactor_attack_left.OnShow();
						control_attack--;
						if (control_attack == 0) {
							control_attack = 10;
							isAttack = false;
						}
						//return;
					}
					else if (isMovingJump) {
						charactor_jump_left.OnShow();
					}
					else if (isDefense) {
						charactor_defense_left.OnShow();
					}
					else {
						charactor_stand_left.OnShow();
						charactor_stand_left.OnShow();
						charactor_stand_left.OnShow();
					}
				}
				else {
					if (isMovingJump) {
						charactor_jump_left.OnShow();
					}
					else if (isMovingRunLeft) {
						charactor_run_left.OnShow();
						charactor_run_left.OnShow();
						charactor_run_left.OnShow();
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
}