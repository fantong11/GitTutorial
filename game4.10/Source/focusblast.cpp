#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "focusblast.h"
#include "cmath"

namespace game_framework {


	Focusblast::Focusblast()
	{
		x = 0;
		y = 0;
		z = 0;
		direction_right = 0;
		distance = 0;
		hit = false;
		now_pic = 1;
		show = false;
	}

	void Focusblast::LoadBitmap()
	{
		char *file_special_right[5] = { ".\\RES\\FocusBlast\\right\\special_attack1.bmp",".\\RES\\FocusBlast\\right\\special_attack2.bmp",".\\RES\\FocusBlast\\right\\special_attack3.bmp",".\\RES\\FocusBlast\\right\\special_attack4.bmp" ,".\\RES\\FocusBlast\\right\\special_attack5.bmp" };
		char *file_special_left[5] = { ".\\RES\\FocusBlast\\left\\special_attack1.bmp",".\\RES\\FocusBlast\\left\\special_attack2.bmp",".\\RES\\FocusBlast\\left\\special_attack3.bmp",".\\RES\\FocusBlast\\left\\special_attack4.bmp" ,".\\RES\\FocusBlast\\left\\special_attack5.bmp"};

		for (int i = 0; i < 5; i++) {
			charactor_special_right.AddBitmap(file_special_right[i], RGB(0, 0, 0));
			charactor_special_left.AddBitmap(file_special_left[i], RGB(0, 0, 0));
		}
	}
	void Focusblast::SetFocusblast(int _x, int _y, bool face_right)
	{
		
			if (face_right) {
				x = _x + 40;
				y = _y+20;
				direction_right = 1;
			}
			else {
				x = _x;
				y = _y+20;
				direction_right = 0;
			}
		
	}
	void Focusblast::OnMove()
	{
		if (show) {
			if (hit) {
				
				if (direction_right) {
					charactor_special_right.OnMove();
					charactor_special_right.OnMove();
					charactor_special_right.OnMove();

				}
				else {
					charactor_special_left.OnMove();
					charactor_special_left.OnMove();
					charactor_special_left.OnMove();

				}
				now_pic++;
				if (now_pic > 10)
				
					show = false;
			}
			else if (direction_right) {
				x++;
				distance++;
				if (distance >= 145) {


			
						show = false;
				}
			}
			else if (!direction_right) {
				x--;
				distance++;
				if (distance >= 145) {

			
						show = false;
				}
			}
		}
	}
	bool Focusblast::Collision(int _x, int _y,int _z) {
		if (show) {
			if (fabs(_y - y) < 21) {
				if (fabs(_x - x) < 10) {
					if (_z == z) {
						hit = true;
						return true;
					}
				}
			}
		}
		return false;
	}
	void Focusblast::OnShow()
	{
		charactor_special_left.SetTopLeft(x, y);
		charactor_special_right.SetTopLeft(x, y);
		if (show) {
			if (direction_right) {
				charactor_special_right.OnShow();
			}
			else {
				charactor_special_left.OnShow();
			}
		}
	}
}