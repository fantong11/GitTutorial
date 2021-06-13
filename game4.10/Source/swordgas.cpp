#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "swordgas.h"

namespace game_framework {
	

	SwordGas::SwordGas()
	{
		x = 0;
		y = 0;
		direction_right = 0;
		distance = 0;
	}

	void SwordGas::LoadBitmap()
	{
		char *file_special_right[8] = { ".\\RES\\SwordGas\\right\\special_attack_1.bmp",".\\RES\\SwordGas\\right\\special_attack_2.bmp",".\\RES\\SwordGas\\right\\special_attack_3.bmp",".\\RES\\SwordGas\\right\\special_attack_4.bmp" ,".\\RES\\SwordGas\\right\\special_attack_5.bmp" ,".\\RES\\SwordGas\\right\\special_attack_6.bmp" ,".\\RES\\SwordGas\\right\\special_attack_7.bmp" ,".\\RES\\SwordGas\\right\\special_attack_8.bmp" };
		char *file_special_left[8] = { ".\\RES\\SwordGas\\left\\special_attack_1.bmp",".\\RES\\SwordGas\\left\\special_attack_2.bmp",".\\RES\\SwordGas\\left\\special_attack_3.bmp",".\\RES\\SwordGas\\left\\special_attack_4.bmp" ,".\\RES\\SwordGas\\left\\special_attack_5.bmp" ,".\\RES\\SwordGas\\left\\special_attack_6.bmp" ,".\\RES\\SwordGas\\left\\special_attack_7.bmp" ,".\\RES\\SwordGas\\left\\special_attack_8.bmp" };

		for (int i = 0; i < 8; i++) {
			charactor_special_right.AddBitmap(file_special_right[i], RGB(0, 0, 0));
			charactor_special_left.AddBitmap(file_special_left[i], RGB(0, 0, 0));
		}
	}
	void SwordGas::SetSwordGas(int _x, int _y, bool face_right)
	{
		if (face_right) {
			x = _x + 80;
			y = _y + 40;
			direction_right = 1;
		}
		else {
			x = _x;
			y = _y + 40;
			direction_right = 0;
		}
	}
	void SwordGas::OnMove()
	{
		if (direction_right) {
			x += 10;
			distance += 10;
			charactor_special_right.OnMove();
		}
		else {
			x -= 10;
			distance += 10;
			charactor_special_left.OnMove();
		}
	}

	void SwordGas::OnShow()
	{
		charactor_special_left.SetTopLeft(x, y);
		charactor_special_right.SetTopLeft(x, y);
		if (direction_right) {
			charactor_special_right.OnShow();
		}
		else {
			charactor_special_left.OnShow();
		}
		
		
	}
}