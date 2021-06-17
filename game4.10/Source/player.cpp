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
		char *file_charactor_shadow[1] = {".\\RES\\shadow.bmp"};
		defenseUpAttack = defenseDownAttack = defenseRightAttack = defenseLeftAttack = false;
		role = a;
		charactor_shadow.AddBitmap(file_charactor_shadow[0], RGB(0, 0, 0));
		if (a == 1) {
			char *file_charactor_walk_to_right[6] = { ".\\RES\\template\\walk_to_right\\walk1.bmp", ".\\RES\\template\\walk_to_right\\walk2.bmp", ".\\RES\\template\\walk_to_right\\walk3.bmp", ".\\RES\\template\\walk_to_right\\walk4.bmp", ".\\RES\\template\\walk_to_right\\walk3.bmp" , ".\\RES\\template\\walk_to_right\\walk2.bmp" };
			char *file_charactor_walk_to_left[6] = { ".\\RES\\template\\walk_to_left\\walk1.bmp", ".\\RES\\template\\walk_to_left\\walk2.bmp", ".\\RES\\template\\walk_to_left\\walk3.bmp", ".\\RES\\template\\walk_to_left\\walk4.bmp", ".\\RES\\template\\walk_to_left\\walk3.bmp" , ".\\RES\\template\\walk_to_left\\walk2.bmp" };
			char *file_charactor_stand_right[4] = { ".\\RES\\template\\stand_right\\stand1.bmp", ".\\RES\\template\\stand_right\\stand2.bmp", ".\\RES\\template\\stand_right\\stand3.bmp", ".\\RES\\template\\stand_right\\stand4.bmp" };
			char *file_charactor_stand_left[4] = { ".\\RES\\template\\stand_left\\stand1.bmp", ".\\RES\\template\\stand_left\\stand2.bmp", ".\\RES\\template\\stand_left\\stand3.bmp", ".\\RES\\template\\stand_left\\stand4.bmp" };
			char *file_charactor_attack_right[4] = { ".\\RES\\template\\attack_right\\attack1.bmp",".\\RES\\template\\attack_right\\attack2.bmp",".\\RES\\template\\attack_right\\attack3.bmp" ,".\\RES\\template\\attack_right\\attack4.bmp" };
			char *file_charactor_attack_left[4] = { ".\\RES\\template\\attack_left\\attack1.bmp",".\\RES\\template\\attack_left\\attack2.bmp",".\\RES\\template\\attack_left\\attack3.bmp",".\\RES\\template\\attack_left\\attack4.bmp" };
			char *file_charactor_run_left[3] = {".\\RES\\template\\run_to_left\\run1.bmp", ".\\RES\\template\\run_to_left\\run2.bmp", ".\\RES\\template\\run_to_left\\run3.bmp"};
			char *file_charactor_run_right[3] = {".\\RES\\template\\run_to_right\\run1.bmp", ".\\RES\\template\\run_to_right\\run2.bmp", ".\\RES\\template\\run_to_right\\run3.bmp"};
			char *file_charactor_jump_right[3] = {".\\RES\\template\\jump_to_right\\jump1.bmp", ".\\RES\\template\\jump_to_right\\jump2.bmp", ".\\RES\\template\\jump_to_right\\jump3.bmp"};
			char *file_charactor_jump_left[3] = {".\\RES\\template\\jump_to_left\\jump1.bmp", ".\\RES\\template\\jump_to_left\\jump2.bmp", ".\\RES\\template\\jump_to_left\\jump3.bmp"};
			char *file_charactor_behit_right[3] = { ".\\RES\\template\\be_hit_right\\behit1.bmp",".\\RES\\template\\be_hit_right\\behit2.bmp",".\\RES\\template\\be_hit_right\\behit3.bmp" };
			char *file_charactor_behit_left[3] = { ".\\RES\\template\\be_hit_left\\behit1.bmp",".\\RES\\template\\be_hit_left\\behit2.bmp",".\\RES\\template\\be_hit_left\\behit3.bmp" };
			char *file_charactor_defense_right[2] = { ".\\RES\\template\\defense_to_right\\defense1.bmp",".\\RES\\template\\defense_to_right\\defense2.bmp"};
			char *file_charactor_defense_left[2] = { ".\\RES\\template\\defense_to_left\\defense1.bmp",".\\RES\\template\\defense_to_left\\defense2.bmp"};
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
		else if (a == 2) {
			char *file_charactor_walk_to_right[6] = { ".\\RES\\deep\\walk_to_right\\walk1.bmp", ".\\RES\\deep\\walk_to_right\\walk2.bmp", ".\\RES\\deep\\walk_to_right\\walk3.bmp", ".\\RES\\deep\\walk_to_right\\walk4.bmp", ".\\RES\\deep\\walk_to_right\\walk3.bmp" , ".\\RES\\deep\\walk_to_right\\walk2.bmp" };
			char *file_charactor_walk_to_left[6] = { ".\\RES\\deep\\walk_to_left\\walk1.bmp", ".\\RES\\deep\\walk_to_left\\walk2.bmp", ".\\RES\\deep\\walk_to_left\\walk3.bmp", ".\\RES\\deep\\walk_to_left\\walk4.bmp", ".\\RES\\deep\\walk_to_left\\walk3.bmp" , ".\\RES\\deep\\walk_to_left\\walk2.bmp" };
			char *file_charactor_stand_right[4] = { ".\\RES\\deep\\stand_right\\stand1.bmp", ".\\RES\\deep\\stand_right\\stand2.bmp", ".\\RES\\deep\\stand_right\\stand3.bmp", ".\\RES\\deep\\stand_right\\stand4.bmp" };
			char *file_charactor_stand_left[4] = { ".\\RES\\deep\\stand_left\\stand1.bmp", ".\\RES\\deep\\stand_left\\stand2.bmp", ".\\RES\\deep\\stand_left\\stand3.bmp", ".\\RES\\deep\\stand_left\\stand4.bmp" };
			char *file_charactor_attack_right[4] = { ".\\RES\\deep\\attack_right\\attack1.bmp",".\\RES\\deep\\attack_right\\attack2.bmp",".\\RES\\deep\\attack_right\\attack3.bmp",".\\RES\\deep\\attack_right\\attack4.bmp" };
			char *file_charactor_attack_left[4] = { ".\\RES\\deep\\attack_left\\attack1.bmp",".\\RES\\deep\\attack_left\\attack2.bmp",".\\RES\\deep\\attack_left\\attack3.bmp",".\\RES\\deep\\attack_left\\attack4.bmp" };
			char *file_charactor_jump_right[3] = { ".\\RES\\deep\\jump_to_right\\jump1.bmp", ".\\RES\\deep\\jump_to_right\\jump2.bmp", ".\\RES\\deep\\jump_to_right\\jump3.bmp" };
			char *file_charactor_jump_left[3] = { ".\\RES\\deep\\jump_to_left\\jump1.bmp", ".\\RES\\deep\\jump_to_left\\jump2.bmp", ".\\RES\\deep\\jump_to_left\\jump3.bmp" };
			char *file_charactor_behit_right[3] = { ".\\RES\\deep\\be_hit_right\\behit1.bmp",".\\RES\\deep\\be_hit_right\\behit2.bmp",".\\RES\\deep\\be_hit_right\\behit3.bmp" };
			char *file_charactor_behit_left[3] = { ".\\RES\\deep\\be_hit_left\\behit1.bmp",".\\RES\\deep\\be_hit_left\\behit2.bmp",".\\RES\\deep\\be_hit_left\\behit3.bmp" };
			char *file_charactor_defense_right[2] = { ".\\RES\\deep\\defense_to_right\\defense1.bmp",".\\RES\\deep\\defense_to_right\\defense2.bmp" };
			char *file_charactor_defense_left[2] = { ".\\RES\\deep\\defense_to_left\\defense1.bmp",".\\RES\\deep\\defense_to_left\\defense2.bmp" };
			char *file_charactor_run_left[3] = {".\\RES\\deep\\run_to_left\\run1.bmp",".\\RES\\deep\\run_to_left\\run2.bmp",".\\RES\\deep\\run_to_left\\run3.bmp" };
			char *file_charactor_run_right[3] = { ".\\RES\\deep\\run_to_right\\run1.bmp", ".\\RES\\deep\\run_to_right\\run2.bmp",  ".\\RES\\deep\\run_to_right\\run3.bmp", };
			char *file_charactor_defense_down_attack_to_left[5] = {".\\RES\\deep\\defense_down_attack_to_left\\special2_1.bmp", ".\\RES\\deep\\defense_down_attack_to_left\\special2_2.bmp" , ".\\RES\\deep\\defense_down_attack_to_left\\special2_3.bmp" , ".\\RES\\deep\\defense_down_attack_to_left\\special2_4.bmp" , ".\\RES\\deep\\defense_down_attack_to_left\\special2_5.bmp" };
			char *file_charactor_defense_down_attack_to_right[5] = { ".\\RES\\deep\\defense_down_attack_to_right\\special2_1.bmp", ".\\RES\\deep\\defense_down_attack_to_right\\special2_2.bmp", ".\\RES\\deep\\defense_down_attack_to_right\\special2_3.bmp", ".\\RES\\deep\\defense_down_attack_to_right\\special2_4.bmp", ".\\RES\\deep\\defense_down_attack_to_right\\special2_5.bmp" };
			char *file_charactor_defense_left_attack[5] = {".\\RES\\deep\\defense_left_attack_to_left\\special1_1.bmp", ".\\RES\\deep\\defense_left_attack_to_left\\special1_2.bmp" , ".\\RES\\deep\\defense_left_attack_to_left\\special1_3.bmp" , ".\\RES\\deep\\defense_left_attack_to_left\\special1_4.bmp" , ".\\RES\\deep\\defense_left_attack_to_left\\special1_5.bmp" };
			char *file_charactor_defense_right_attack[5] = {".\\RES\\deep\\defense_right_attack_to_right\\special1_1.bmp", ".\\RES\\deep\\defense_right_attack_to_right\\special1_2.bmp" , ".\\RES\\deep\\defense_right_attack_to_right\\special1_3.bmp" , ".\\RES\\deep\\defense_right_attack_to_right\\special1_4.bmp" , ".\\RES\\deep\\defense_right_attack_to_right\\special1_5.bmp" };

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
				charactor_run_left.AddBitmap(file_charactor_run_left[i], RGB(0 ,0, 0));
				charactor_run_right.AddBitmap(file_charactor_run_right[i], RGB(0, 0, 0));
			}
			for (int i = 0; i < 2; i++) {
				charactor_defense_right.AddBitmap(file_charactor_defense_right[i], RGB(0, 0, 0));
				charactor_defense_left.AddBitmap(file_charactor_defense_left[i], RGB(0, 0, 0));
			}

			for (int i = 0; i < 5; i++) {
				charactor_defense_attack_down_to_left.AddBitmap(file_charactor_defense_down_attack_to_left[i], RGB(0, 0, 0));
				charactor_defense_attack_down_to_right.AddBitmap(file_charactor_defense_down_attack_to_right[i], RGB(0, 0, 0));
				charactor_defense_left_attack.AddBitmap(file_charactor_defense_left_attack[i], RGB(0, 0, 0));
				charactor_defense_right_attack.AddBitmap(file_charactor_defense_right_attack[i], RGB(0, 0, 0));
			}
		}
		else {
			char *file_charactor_walk_to_right[6] = { ".\\RES\\david\\walk_to_right\\walk1.bmp", ".\\RES\\david\\walk_to_right\\walk2.bmp", ".\\RES\\david\\walk_to_right\\walk3.bmp", ".\\RES\\david\\walk_to_right\\walk4.bmp", ".\\RES\\david\\walk_to_right\\walk3.bmp" , ".\\RES\\david\\walk_to_right\\walk2.bmp" };
			char *file_charactor_walk_to_left[6] = { ".\\RES\\david\\walk_to_left\\walk1.bmp", ".\\RES\\david\\walk_to_left\\walk2.bmp", ".\\RES\\david\\walk_to_left\\walk3.bmp", ".\\RES\\david\\walk_to_left\\walk4.bmp", ".\\RES\\david\\walk_to_left\\walk3.bmp" , ".\\RES\\david\\walk_to_left\\walk2.bmp" };
			char *file_charactor_stand_right[4] = { ".\\RES\\david\\stand_right\\stand1.bmp", ".\\RES\\david\\stand_right\\stand2.bmp", ".\\RES\\david\\stand_right\\stand3.bmp", ".\\RES\\david\\stand_right\\stand4.bmp" };
			char *file_charactor_stand_left[4] = { ".\\RES\\david\\stand_left\\stand1.bmp", ".\\RES\\david\\stand_left\\stand2.bmp", ".\\RES\\david\\stand_left\\stand3.bmp", ".\\RES\\david\\stand_left\\stand4.bmp" };
			char *file_charactor_attack_right[4] = { ".\\RES\\david\\attack_right\\attack1.bmp",".\\RES\\david\\attack_right\\attack2.bmp",".\\RES\\david\\attack_right\\attack3.bmp",".\\RES\\david\\attack_right\\attack4.bmp" };
			char *file_charactor_attack_left[4] = { ".\\RES\\david\\attack_left\\attack1.bmp",".\\RES\\david\\attack_left\\attack2.bmp",".\\RES\\david\\attack_left\\attack3.bmp",".\\RES\\david\\attack_left\\attack4.bmp" };
			char *file_charactor_jump_right[3] = { ".\\RES\\david\\jump_to_right\\jump1.bmp", ".\\RES\\david\\jump_to_right\\jump2.bmp", ".\\RES\\david\\jump_to_right\\jump3.bmp" };
			char *file_charactor_jump_left[3] = { ".\\RES\\david\\jump_to_left\\jump1.bmp", ".\\RES\\david\\jump_to_left\\jump2.bmp", ".\\RES\\david\\jump_to_left\\jump3.bmp" };
			char *file_charactor_behit_right[3] = { ".\\RES\\david\\be_hit_right\\behit1.bmp",".\\RES\\david\\be_hit_right\\behit2.bmp",".\\RES\\david\\be_hit_right\\behit3.bmp" };
			char *file_charactor_behit_left[3] = { ".\\RES\\david\\be_hit_left\\behit1.bmp",".\\RES\\david\\be_hit_left\\behit2.bmp",".\\RES\\david\\be_hit_left\\behit3.bmp" };
			char *file_charactor_defense_right[2] = { ".\\RES\\david\\defense_to_right\\defense1.bmp",".\\RES\\david\\defense_to_right\\defense2.bmp" };
			char *file_charactor_defense_left[2] = { ".\\RES\\david\\defense_to_left\\defense1.bmp",".\\RES\\david\\defense_to_left\\defense2.bmp" };
			char *file_charactor_run_left[3] = {".\\RES\\david\\run_to_left\\run1.bmp" , ".\\RES\\david\\run_to_left\\run2.bmp" , ".\\RES\\david\\run_to_left\\run3.bmp" };
			char *file_charactor_run_right[3] = {".\\RES\\david\\run_to_right\\run1.bmp", ".\\RES\\david\\run_to_right\\run2.bmp" , ".\\RES\\david\\run_to_right\\run3.bmp" };
			char *file_charactor_defense_down_attack_to_left[13] = {".\\RES\\david\\defense_down_attack_to_left\\special2_1.bmp", ".\\RES\\david\\defense_down_attack_to_left\\special2_2.bmp" , ".\\RES\\david\\defense_down_attack_to_left\\special2_3.bmp" , ".\\RES\\david\\defense_down_attack_to_left\\special2_4.bmp" , ".\\RES\\david\\defense_down_attack_to_left\\special2_5.bmp" , ".\\RES\\david\\defense_down_attack_to_left\\special2_6.bmp" , ".\\RES\\david\\defense_down_attack_to_left\\special2_7.bmp" , ".\\RES\\david\\defense_down_attack_to_left\\special2_8.bmp" , ".\\RES\\david\\defense_down_attack_to_left\\special2_9.bmp" , ".\\RES\\david\\defense_down_attack_to_left\\special2_10.bmp" , ".\\RES\\david\\defense_down_attack_to_left\\special2_11.bmp" , ".\\RES\\david\\defense_down_attack_to_left\\special2_12.bmp" , ".\\RES\\david\\defense_down_attack_to_left\\special2_13.bmp" };
			char *file_charactor_defense_down_attack_to_right[13] = { ".\\RES\\david\\defense_down_attack_to_right\\special2_1.bmp", ".\\RES\\david\\defense_down_attack_to_right\\special2_2.bmp" , ".\\RES\\david\\defense_down_attack_to_right\\special2_3.bmp" , ".\\RES\\david\\defense_down_attack_to_right\\special2_4.bmp" , ".\\RES\\david\\defense_down_attack_to_right\\special2_5.bmp" , ".\\RES\\david\\defense_down_attack_to_right\\special2_6.bmp" , ".\\RES\\david\\defense_down_attack_to_right\\special2_7.bmp" , ".\\RES\\david\\defense_down_attack_to_right\\special2_8.bmp" , ".\\RES\\david\\defense_down_attack_to_right\\special2_9.bmp" , ".\\RES\\david\\defense_down_attack_to_right\\special2_10.bmp" , ".\\RES\\david\\defense_down_attack_to_right\\special2_11.bmp" , ".\\RES\\david\\defense_down_attack_to_right\\special2_12.bmp" , ".\\RES\\david\\defense_down_attack_to_right\\special2_13.bmp"};
			char *file_charactor_defense_left_attack[10] = {".\\RES\\david\\defense_left_attack_to_left\\special1_1.bmp", ".\\RES\\david\\defense_left_attack_to_left\\special1_2.bmp" , ".\\RES\\david\\defense_left_attack_to_left\\special1_3.bmp" , ".\\RES\\david\\defense_left_attack_to_left\\special1_4.bmp" , ".\\RES\\david\\defense_left_attack_to_left\\special1_5.bmp" , ".\\RES\\david\\defense_left_attack_to_left\\special1_6.bmp" , ".\\RES\\david\\defense_left_attack_to_left\\special1_7.bmp" , ".\\RES\\david\\defense_left_attack_to_left\\special1_8.bmp" , ".\\RES\\david\\defense_left_attack_to_left\\special1_9.bmp" , ".\\RES\\david\\defense_left_attack_to_left\\special1_10.bmp" };
			char *file_charactor_defense_right_attack[10] = { ".\\RES\\david\\defense_right_attack_to_right\\special1_1.bmp", ".\\RES\\david\\defense_right_attack_to_right\\special1_2.bmp" , ".\\RES\\david\\defense_right_attack_to_right\\special1_3.bmp" , ".\\RES\\david\\defense_right_attack_to_right\\special1_4.bmp" , ".\\RES\\david\\defense_right_attack_to_right\\special1_5.bmp" , ".\\RES\\david\\defense_right_attack_to_right\\special1_6.bmp" , ".\\RES\\david\\defense_right_attack_to_right\\special1_7.bmp" , ".\\RES\\david\\defense_right_attack_to_right\\special1_8.bmp" , ".\\RES\\david\\defense_right_attack_to_right\\special1_9.bmp" , ".\\RES\\david\\defense_right_attack_to_right\\special1_10.bmp" };
			char *file_charactor_defense_up_attack_to_left[8] = {".\\RES\\david\\defense_up_attack_to_left\\special3_1.bmp", ".\\RES\\david\\defense_up_attack_to_left\\special3_2.bmp" , ".\\RES\\david\\defense_up_attack_to_left\\special3_3.bmp" , ".\\RES\\david\\defense_up_attack_to_left\\special3_4.bmp" , ".\\RES\\david\\defense_up_attack_to_left\\special3_5.bmp" , ".\\RES\\david\\defense_up_attack_to_left\\special3_6.bmp" , ".\\RES\\david\\defense_up_attack_to_left\\special3_7.bmp" , ".\\RES\\david\\defense_up_attack_to_left\\special3_8.bmp" };
			char *file_charactor_defense_up_attack_to_right[8] = { ".\\RES\\david\\defense_up_attack_to_right\\special3_1.bmp", ".\\RES\\david\\defense_up_attack_to_right\\special3_2.bmp" , ".\\RES\\david\\defense_up_attack_to_right\\special3_3.bmp" , ".\\RES\\david\\defense_up_attack_to_right\\special3_4.bmp" , ".\\RES\\david\\defense_up_attack_to_right\\special3_5.bmp" , ".\\RES\\david\\defense_up_attack_to_right\\special3_6.bmp" , ".\\RES\\david\\defense_up_attack_to_right\\special3_7.bmp" , ".\\RES\\david\\defense_up_attack_to_right\\special3_8.bmp" };

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
			for (int i = 0; i < 10; i++) {
				charactor_defense_left_attack.AddBitmap(file_charactor_defense_left_attack[i], RGB(0, 0, 0));
				charactor_defense_right_attack.AddBitmap(file_charactor_defense_right_attack[i], RGB(0, 0, 0));
			}
			for (int i = 0; i < 8; i++) {
				charactor_defense_up_attack_to_left.AddBitmap(file_charactor_defense_up_attack_to_left[i], RGB(0, 0, 0));
				charactor_defense_up_attack_to_right.AddBitmap(file_charactor_defense_up_attack_to_right[i], RGB(0, 0, 0));
			}
			for (int i = 0; i < 13; i++) {
				charactor_defense_attack_down_to_left.AddBitmap(file_charactor_defense_down_attack_to_left[i], RGB(0, 0, 0));
				charactor_defense_attack_down_to_right.AddBitmap(file_charactor_defense_down_attack_to_right[i], RGB(0, 0, 0));
			}
		}
	}

	void Player::whatStatus(void) {
		// 跑
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isMovingJump = isMoving = isAttack = UnderAttack = isDefense = isMovingRunLeft = isMovingRunRight = false;
		defenseUpAttack = defenseDownAttack = defenseRightAttack = defenseLeftAttack = false;
		// 劍男
		// 防下功  防左功 防右功
		if (data.size() > 3) {
			if (role == 2) {
				if (data[data.size() - 1].action == "attack" && data[data.size() - 2].action == "down" && data[data.size() - 3].action == "defense" && data[data.size() - 1].time - data[data.size() - 3].time <= 0) {
					defenseDownAttack = true;
				}
				else if (data[data.size() - 1].action == "attack" && data[data.size() - 2].action == "left" && data[data.size() - 3].action == "defense" && data[data.size() - 1].time - data[data.size() - 3].time <= 0) {
					defenseLeftAttack = true;
				}
				else if (data[data.size() - 1].action == "attack" && data[data.size() - 2].action == "right" && data[data.size() - 3].action == "defense" && data[data.size() - 1].time - data[data.size() - 3].time <= 0) {
					defenseRightAttack = true;
				}
			}
			// 氣功男
			// 防上攻 防下攻 防右攻 防左攻
			else if (role == 3) {
				if (data[data.size() - 1].action == "attack" && data[data.size() - 2].action == "up" && data[data.size() - 3].action == "defense" && data[data.size() - 1].time - data[data.size() - 3].time <= 0) {
					defenseUpAttack = true;
				}
				else if (data[data.size() - 1].action == "attack" && data[data.size() - 2].action == "down" && data[data.size() - 3].action == "defense" && data[data.size() - 1].time - data[data.size() - 3].time <= 0) {
					defenseDownAttack = true;
				}
				else if (data[data.size() - 1].action == "attack" && data[data.size() - 2].action == "right" && data[data.size() - 3].action == "defense" && data[data.size() - 1].time - data[data.size() - 3].time <= 0) {
					defenseRightAttack = true;
				}
				else if (data[data.size() - 1].action == "attack" && data[data.size() - 2].action == "left" && data[data.size() - 3].action == "defense" && data[data.size() - 1].time - data[data.size() - 3].time <= 0) {
					defenseLeftAttack = true;
				}
			}
		}

		if (data.size() > 1) {
			if (data[data.size() - 1].action == "left" && data[data.size() - 2].action == "left" && data[data.size() - 1].time - data[data.size() - 2].time <= 0) {
				isMovingRunLeft = true;
				isMovingLeft = false;
			}
			else if (data[data.size() - 1].action == "right" && data[data.size() - 2].action == "right" && data[data.size() - 1].time - data[data.size() - 2].time <= 0) {
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

	void Player::SetXY(int _x, int _y) {
		x = _x;
		y = _y;
		z = 0;
		face_right = true;
	}

	void Player::OnMove() {
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
						jump_count++;
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
				else if (role == 2 && defenseDownAttack) {
					charactor_defense_attack_down_to_right.OnMove();
				}
				else if (role == 2 && defenseRightAttack) {
					charactor_defense_right_attack.OnMove();
				}
				else if (role == 3 && defenseDownAttack) {
					if (x + STEP_SIZE < 594)
						x += STEP_SIZE;
					charactor_defense_attack_down_to_right.OnMove();
				}
				else if (role == 3 && defenseRightAttack) {
					charactor_defense_right_attack.OnMove();
				}
				else if (role == 3 && defenseUpAttack) {
					if (y - STEP_SIZE > 224)
						y -= STEP_SIZE;
					charactor_defense_up_attack_to_right.OnMove();
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
					return;
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
				else if (role == 2 && defenseDownAttack) {
					charactor_defense_attack_down_to_left.OnMove();
				}
				else if (role == 2 && defenseLeftAttack) {
					charactor_defense_left_attack.OnMove();
				}
				else if (role == 3 && defenseDownAttack) {
					if (x + STEP_SIZE < 594)
						x += STEP_SIZE;
					charactor_defense_attack_down_to_left.OnMove();
				}
				else if (role == 3 && defenseLeftAttack) {
					charactor_defense_left_attack.OnMove();
				}
				else if (role == 3 && defenseUpAttack) {
					if (y - STEP_SIZE > 224)
						y -= STEP_SIZE;
					charactor_defense_up_attack_to_left.OnMove();
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
	void Player::OnShow() {
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
			if (role == 2) {
				charactor_defense_attack_down_to_left.SetTopLeft(x, y - z);
				charactor_defense_attack_down_to_right.SetTopLeft(x, y - z);
				charactor_defense_left_attack.SetTopLeft(x, y - z);
				charactor_defense_right_attack.SetTopLeft(x, y - z);
			}
			else if (role == 3) {
				charactor_defense_attack_down_to_left.SetTopLeft(x, y - z);
				charactor_defense_attack_down_to_right.SetTopLeft(x, y - z);
				charactor_defense_up_attack_to_right.SetTopLeft(x, y - z);
				charactor_defense_up_attack_to_left.SetTopLeft(x, y - z);
				charactor_defense_left_attack.SetTopLeft(x, y - z);
				charactor_defense_right_attack.SetTopLeft(x, y - z);

			}

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
					else if (role == 2 && defenseDownAttack) {
						charactor_defense_attack_down_to_right.OnShow();
					}
					else if (role == 2 && defenseRightAttack) {
						charactor_defense_right_attack.OnShow();
					}
					else if (role == 3 && defenseDownAttack) {
						charactor_defense_attack_down_to_right.OnShow();
					}
					else if (role == 3 && defenseRightAttack) {
						charactor_defense_right_attack.OnShow();
					}
					else if (role == 3 && defenseUpAttack) {
						charactor_defense_up_attack_to_right.OnShow();
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
					else if (role == 2 && defenseDownAttack) {
						charactor_defense_attack_down_to_left.OnShow();
					}
					else if (role == 2 && defenseLeftAttack) {
						charactor_defense_left_attack.OnShow();
					}
					else if (role == 3 && defenseDownAttack) {
						charactor_defense_attack_down_to_left.OnShow();
					}
					else if (role == 3 && defenseLeftAttack) {
						charactor_defense_left_attack.OnShow();
					}
					else if (role == 3 && defenseUpAttack) {
						charactor_defense_up_attack_to_left.OnShow();
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
	void Player::Decrease() {
		LEAVE_BLOOD = 144 - int((500 - HP)*0.206);
		LEAVE_MAGIC = 144 - int((100 - MAGIC)*103/100);
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
		CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
		CPen *pp, p(PS_NULL, 0, RGB(0, 0, 0));		// 清除pen
		pp = pDC->SelectObject(&p);

		CFont f, *fp;
		f.CreatePointFont(110, "Times New Roman");	// 產生 font f; 160表示16 point的字
		fp = pDC->SelectObject(&f);					// 選用 font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(120, 120, 255));
		char str[80];								// Demo 數字對字串的轉換
		sprintf(str, "Man:  1    HP:  %d",HP);
		pDC->TextOut(6, 94, str);


		CBrush b2(RGB(255, 0, 0));					// 畫黃色 progrss進度
		pDC->SelectObject(&b2);
		pDC->Rectangle(41, 12, LEAVE_BLOOD, 25);

		CBrush b3(RGB(0, 0, 255));					// 畫黃色 progrss進度
		pDC->SelectObject(&b3);
		pDC->Rectangle(41, 29, LEAVE_MAGIC, 42);

		pDC->SelectObject(pp);						// 釋放 pen
		pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
		//pDC->SelectObject(pb);						// 釋放 brush
		CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
		
	}
}