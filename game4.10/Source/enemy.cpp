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
		char *file_charactor_shadow[1] = { ".\\RES\\shadow.bmp" };
		charactor_shadow.AddBitmap(file_charactor_shadow[0], RGB(0, 0, 0));
			char *file_charactor_walk_to_right[6] = { ".\\RES\\enemy\\walk_to_right\\walk1.bmp", ".\\RES\\enemy\\walk_to_right\\walk2.bmp", ".\\RES\\enemy\\walk_to_right\\walk3.bmp", ".\\RES\\enemy\\walk_to_right\\walk4.bmp", ".\\RES\\enemy\\walk_to_right\\walk3.bmp" , ".\\RES\\enemy\\walk_to_right\\walk2.bmp" };
			char *file_charactor_walk_to_left[6] = { ".\\RES\\enemy\\walk_to_left\\walk1.bmp", ".\\RES\\enemy\\walk_to_left\\walk2.bmp", ".\\RES\\enemy\\walk_to_left\\walk3.bmp", ".\\RES\\enemy\\walk_to_left\\walk4.bmp", ".\\RES\\enemy\\walk_to_left\\walk3.bmp" , ".\\RES\\enemy\\walk_to_left\\walk2.bmp" };
			char *file_charactor_stand_right[4] = { ".\\RES\\enemy\\stand_right\\stand1.bmp", ".\\RES\\enemy\\stand_right\\stand2.bmp", ".\\RES\\enemy\\stand_right\\stand3.bmp", ".\\RES\\enemy\\stand_right\\stand4.bmp" };
			char *file_charactor_stand_left[4] = { ".\\RES\\enemy\\stand_left\\stand1.bmp", ".\\RES\\enemy\\stand_left\\stand2.bmp", ".\\RES\\enemy\\stand_left\\stand3.bmp", ".\\RES\\enemy\\stand_left\\stand4.bmp" };
			char *file_charactor_attack_right[4] = { ".\\RES\\enemy\\attack_right\\attack1.bmp",".\\RES\\enemy\\attack_right\\attack2.bmp",".\\RES\\enemy\\attack_right\\attack3.bmp" ,".\\RES\\enemy\\attack_right\\attack4.bmp" };
			char *file_charactor_attack_left[4] = { ".\\RES\\enemy\\attack_left\\attack1.bmp",".\\RES\\enemy\\attack_left\\attack2.bmp",".\\RES\\enemy\\attack_left\\attack3.bmp",".\\RES\\enemy\\attack_left\\attack4.bmp" };
			char *file_charactor_jump_right[3] = { ".\\RES\\template\\jump_to_right\\jump1.bmp", ".\\RES\\template\\jump_to_right\\jump2.bmp", ".\\RES\\template\\jump_to_right\\jump3.bmp" };
			char *file_charactor_jump_left[3] = { ".\\RES\\template\\jump_to_left\\jump1.bmp", ".\\RES\\template\\jump_to_left\\jump2.bmp", ".\\RES\\template\\jump_to_left\\jump3.bmp" };
			char *file_charactor_behit_right[3] = { ".\\RES\\enemy\\be_hit_right\\behit1.bmp",".\\RES\\enemy\\be_hit_right\\behit2.bmp",".\\RES\\enemy\\be_hit_right\\behit3.bmp" };
			char *file_charactor_behit_left[3] = { ".\\RES\\enemy\\be_hit_left\\behit1.bmp",".\\RES\\enemy\\be_hit_left\\behit2.bmp",".\\RES\\enemy\\be_hit_left\\behit3.bmp" };
			char *file_charactor_defense_right[2] = { ".\\RES\\enemy\\defense_to_right\\defense1.bmp",".\\RES\\enemy\\defense_to_right\\defense2.bmp" };
			char *file_charactor_defense_left[2] = { ".\\RES\\enemy\\defense_to_left\\defense1.bmp",".\\RES\\enemy\\defense_to_left\\defense2.bmp" };

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
		HP = 50;
	}

	void Enemy::getCloseToPlayer(int _x, int _y) {
		if (enemy_now) {
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
				if (fabs(x - _x) < 30) {
					SetMoving(false);
					if (!UnderAttack) {
						SetAttack(true);
					}

				}

			}
			OnMove();
		}		
	}
	void Enemy::getHit() {
		SetAttack(true);
	}


}