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
#include <cstdlib>

namespace game_framework {
	void Enemy::LoadBitmap(int a) {
		char *file_charactor_shadow[1] = { ".\\RES\\shadow.bmp" };
		charactor_shadow.AddBitmap(file_charactor_shadow[0], RGB(0, 0, 0));
			char *file_charactor_walk_to_right[6] = { ".\\RES\\enemy\\walk_to_right\\walk1.bmp", ".\\RES\\enemy\\walk_to_right\\walk2.bmp", ".\\RES\\enemy\\walk_to_right\\walk3.bmp", ".\\RES\\enemy\\walk_to_right\\walk4.bmp", ".\\RES\\enemy\\walk_to_right\\walk3.bmp" , ".\\RES\\enemy\\walk_to_right\\walk2.bmp" };
			char *file_charactor_walk_to_left[6] = { ".\\RES\\enemy\\walk_to_left\\walk1.bmp", ".\\RES\\enemy\\walk_to_left\\walk2.bmp", ".\\RES\\enemy\\walk_to_left\\walk3.bmp", ".\\RES\\enemy\\walk_to_left\\walk4.bmp", ".\\RES\\enemy\\walk_to_left\\walk3.bmp" , ".\\RES\\enemy\\walk_to_left\\walk2.bmp" };
			char *file_charactor_stand_right[4] = { ".\\RES\\enemy\\stand_right\\stand1.bmp", ".\\RES\\enemy\\stand_right\\stand2.bmp", ".\\RES\\enemy\\stand_right\\stand3.bmp", ".\\RES\\enemy\\stand_right\\stand4.bmp" };
			char *file_charactor_stand_left[4] = { ".\\RES\\enemy\\stand_left\\stand1.bmp", ".\\RES\\enemy\\stand_left\\stand2.bmp", ".\\RES\\enemy\\stand_left\\stand3.bmp", ".\\RES\\enemy\\stand_left\\stand4.bmp" };
			char *file_charactor_attack_right[4] = { ".\\RES\\enemy\\attack_right\\attack1.bmp",".\\RES\\enemy\\attack_right\\attack2.bmp",".\\RES\\enemy\\attack_right\\attack3.bmp" ,".\\RES\\enemy\\attack_right\\attack4.bmp" };
			char *file_charactor_attack_left[4] = { ".\\RES\\enemy\\attack_left\\attack1.bmp",".\\RES\\enemy\\attack_left\\attack2.bmp",".\\RES\\enemy\\attack_left\\attack3.bmp",".\\RES\\enemy\\attack_left\\attack4.bmp" };
			char *file_charactor_jump_right[3] = { ".\\RES\\enemy\\jump_to_right\\jump1.bmp", ".\\RES\\enemy\\jump_to_right\\jump2.bmp", ".\\RES\\enemy\\jump_to_right\\jump3.bmp" };
			char *file_charactor_jump_left[3] = { ".\\RES\\enemy\\jump_to_left\\jump1.bmp", ".\\RES\\enemy\\jump_to_left\\jump2.bmp", ".\\RES\\enemy\\jump_to_left\\jump3.bmp" };
			char *file_charactor_behit_right[3] = { ".\\RES\\enemy\\be_hit_right\\behit1.bmp",".\\RES\\enemy\\be_hit_right\\behit2.bmp",".\\RES\\enemy\\be_hit_right\\behit3.bmp" };
			char *file_charactor_behit_left[3] = { ".\\RES\\enemy\\be_hit_left\\behit1.bmp",".\\RES\\enemy\\be_hit_left\\behit2.bmp",".\\RES\\enemy\\be_hit_left\\behit3.bmp" };
			char *file_charactor_defense_right[2] = { ".\\RES\\enemy\\defense_to_right\\defense1.bmp",".\\RES\\enemy\\defense_to_right\\defense2.bmp" };
			char *file_charactor_defense_left[2] = { ".\\RES\\enemy\\defense_to_left\\defense1.bmp",".\\RES\\enemy\\defense_to_left\\defense2.bmp" };
			char *file_charactor_run_left[3] = { ".\\RES\\template\\run_to_left\\run1.bmp", ".\\RES\\template\\run_to_left\\run2.bmp", ".\\RES\\template\\run_to_left\\run3.bmp" };
			char *file_charactor_run_right[3] = { ".\\RES\\template\\run_to_right\\run1.bmp", ".\\RES\\template\\run_to_right\\run2.bmp", ".\\RES\\template\\run_to_right\\run3.bmp" };

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

			for (int i = 0; i < 3; i++) {
				charactor_jump_left.AddBitmap(file_charactor_jump_left[i], RGB(0, 0, 0));
				charactor_jump_right.AddBitmap(file_charactor_jump_right[i], RGB(0, 0, 0));
				charactor_behit_right.AddBitmap(file_charactor_behit_right[i], RGB(0, 0, 0));
				charactor_behit_left.AddBitmap(file_charactor_behit_left[i], RGB(0, 0, 0));
				charactor_run_left.AddBitmap(file_charactor_run_left[i], RGB(0, 0, 0));
				charactor_run_right.AddBitmap(file_charactor_run_right[i], RGB(0, 0, 0));

			}
			for (int i = 0; i < 2; i++) {
				charactor_defense_right.AddBitmap(file_charactor_defense_right[i], RGB(0, 0, 0));
				charactor_defense_left.AddBitmap(file_charactor_defense_left[i], RGB(0, 0, 0));
			}

		

	}

	void Enemy::SetXY(int _x, int _y) {
		x = _x;
		y = _y;
		z = 0;
		face_right = false;
		STEP_SIZE = 1;
	}
	void Enemy::SetHP(int hp) {
		HP = hp;
	}
	void Enemy::EnemySetAttack(bool flag) {
		isAttack = flag;
	}


	void Enemy::EnemySetMovingDown(bool flag) {
		isAttack = false;
		isMovingDown = flag;
	}

	void Enemy::EnemySetMovingUp(bool flag) {
		isAttack = false;
		isMovingUp = flag;
	}

	void Enemy::EnemySetMovingLeft(bool flag) {
		isAttack = false;
		isMovingLeft = flag;
		face_right = false;
	}

	void Enemy::EnemySetMovingRight(bool flag) {
		isAttack = false;
		isMovingRight = flag;
		face_right = true;
	}

	void Enemy::EnemySetMovingJump(bool flag) {
		isAttack = false;
		isMovingJump = flag;
		on_floor = false;
	}

	void Enemy::EnemySetMoving(bool flag) {
		isMoving = flag;
	}
	void Enemy::EnemySetDefense(bool flag) {
		isDefense = flag;
	}

	void Enemy::OnMove() {
		if (face_right) {
			if (UnderAttack) {
				if (isDefense) {
					charactor_defense_right.OnMove();
				}
				else {
					charactor_behit_right.OnMove();
					charactor_behit_right.OnMove();
				}


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
						jump_count++;
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
				else {
					charactor_stand_right.OnMove();
					charactor_stand_right.OnMove();
					charactor_stand_right.OnMove();
				}

			}
			else {
				if (isMovingRight) {
					if (x + STEP_SIZE < 594)
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
					return;
				}
				charactor_walk_right.OnMove();
				charactor_walk_right.OnMove();
				charactor_walk_right.OnMove();
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
				charactor_walk_left.OnMove();
				charactor_walk_left.OnMove();
				charactor_walk_left.OnMove();
			}
		}
	}
	void Enemy::OnShow() {
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
					else {
						charactor_walk_left.OnShow();
						charactor_walk_left.OnShow();
						charactor_walk_left.OnShow();
					}
				}
			}


		}
	}

	void Enemy::getCloseToPlayer(int _x, int _y) {
		if (enemy_now) {
			
			if (x > _x && fabs(x - _x) > 10) {

				EnemySetMovingLeft(true);
			}
			if (x < _x && fabs(x - _x) > 10) {

				EnemySetMovingRight(true);
			}
			if (y > _y && fabs(y - _y) > 1) {

				EnemySetMovingUp(true);
				EnemySetMovingDown(false);
			}
			if (y < _y && fabs(y - _y) > 1) {

				EnemySetMovingDown(true);
				EnemySetMovingUp(false);
			}
			EnemySetMoving(true);
			if (fabs(y - _y) < 1) {
				if (fabs(x - _x) < 30) {
					EnemySetMoving(false);
					EnemySetDefense(false);

					int x = rand() % 30 + 1;
					if (!UnderAttack) {
						if (isAttack == 0 && isDefense == 0 && isMovingJump == 0) {
							if (x == 1) {
								EnemySetMovingJump(true);
							}
							else if (x == 2) {
								EnemySetDefense(true);
							}
							else {

								EnemySetAttack(true);
							}
						}
					}

				}


			}
			
			OnMove();
		}
	}
	void Enemy::getHit() {
		EnemySetAttack(true);
	}


}