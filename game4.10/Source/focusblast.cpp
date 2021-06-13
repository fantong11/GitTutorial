#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "focusblast.h"

namespace game_framework {


	Focusblast::Focusblast()
	{
		x = 0;
		y = 0;
		direction_right = 0;
		distance = 0;
	}

	void Focusblast::LoadBitmap()
	{
		char *file_special_right[5] = { ".\\RES\\FocusBlast\\right\\special_attack_1.bmp",".\\RES\\FocusBlast\\right\\special_attack_2.bmp",".\\RES\\FocusBlast\\right\\special_attack_3.bmp",".\\RES\\FocusBlast\\right\\special_attack_4.bmp" ,".\\RES\\FocusBlast\\right\\special_attack_5.bmp"};
		char *file_special_left[5] = { ".\\RES\\FocusBlast\\left\\special_attack_1.bmp",".\\RES\\FocusBlast\\left\\special_attack_2.bmp",".\\RES\\FocusBlast\\left\\special_attack_3.bmp",".\\RES\\FocusBlast\\left\\special_attack_4.bmp" ,".\\RES\\FocusBlast\\left\\special_attack_5.bmp"};

		for (int i = 0; i < 5; i++) {
			charactor_special_right.AddBitmap(file_special_right[i], RGB(0, 0, 0));
			charactor_special_left.AddBitmap(file_special_left[i], RGB(0, 0, 0));
		}
	}
	void Focusblast::SetFocusblast(int _x, int _y, bool face_right)
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
	void Focusblast::OnMove()
	{
		if (direction_right) {
			x += 5;
			distance += 5;
			
		}
		else {
			x -= 5;
			distance += 5;
			
		}
		if (distance >= 20) {
			if(direction_right)
				charactor_special_right.OnMove();
			else
				charactor_special_left.OnMove();
		}
	}

	void Focusblast::OnShow()
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