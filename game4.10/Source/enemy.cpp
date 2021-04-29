#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CharactorSetting.h"
#include "cmath"
#include "iostream"
#include "enemy.h"

namespace game_framework {
	void CharactorSetting::LoadBitmap() {
		char *file_charactor_walk_to_right[6] = { ".\\RES\\template\\walk_to_right\\walk1.bmp", ".\\RES\\template\\walk_to_right\\walk2.bmp", ".\\RES\\template\\walk_to_right\\walk3.bmp", ".\\RES\\template\\walk_to_right\\walk4.bmp", ".\\RES\\template\\walk_to_right\\walk3.bmp" , ".\\RES\\template\\walk_to_right\\walk2.bmp" };
		char *file_charactor_walk_to_left[6] = { ".\\RES\\template\\walk_to_left\\walk1.bmp", ".\\RES\\template\\walk_to_left\\walk2.bmp", ".\\RES\\template\\walk_to_left\\walk3.bmp", ".\\RES\\template\\walk_to_left\\walk4.bmp", ".\\RES\\template\\walk_to_left\\walk3.bmp" , ".\\RES\\template\\walk_to_left\\walk2.bmp" };
		char *file_charactor_stand_right[4] = { ".\\RES\\template\\stand_right\\stand1.bmp", ".\\RES\\template\\stand_right\\stand2.bmp", ".\\RES\\template\\stand_right\\stand3.bmp", ".\\RES\\template\\stand_right\\stand4.bmp" };
		char *file_charactor_stand_left[4] = { ".\\RES\\template\\stand_left\\stand1.bmp", ".\\RES\\template\\stand_left\\stand2.bmp", ".\\RES\\template\\stand_left\\stand3.bmp", ".\\RES\\template\\stand_left\\stand4.bmp" };

		for (int i = 0; i < 4; i++) {
			charactor_stand_right.AddBitmap(file_charactor_stand_right[i], RGB(0, 0, 0));
			charactor_stand_left.AddBitmap(file_charactor_stand_left[i], RGB(0, 0, 0));
		}

		for (int i = 0; i < 6; i++) {
			charactor_walk_right.AddBitmap(file_charactor_walk_to_right[i], RGB(0, 0, 0));
			charactor_walk_left.AddBitmap(file_charactor_walk_to_left[i], RGB(0, 0, 0));
		}
	}

	void Enemy::action(void) {
		
	}

	void Enemy::SetXY(int _x, int _y) {
		
	}
}