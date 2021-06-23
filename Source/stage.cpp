#include "stage.h"
#include "StdAfx.h"
#include "gamelib.h"
#include "Resource.h"
#include <ddraw.h>

namespace game_framework {
	// stage class

	void CGameStateStage::LoadBitmap() {
		char *file[11] = {
			"..\\RES\\stageOneBackground\\forestm1.bmp",
			"..\\RES\\stageOneBackground\\forestm2.bmp",
			"..\\RES\\stageOneBackground\\forestm3.bmp",
			"..\\RES\\stageOneBackground\\forestm4.bmp",
			"..\\RES\\stageOneBackground\\forests.bmp",
			"..\\RES\\stageOneBackground\\forestt.bmp",
			"..\\RES\\stageOneBackground\\land1.bmp",
			"..\\RES\\stageOneBackground\\land2.bmp",
			"..\\RES\\stageOneBackground\\land3.bmp",
			"..\\RES\\stageOneBackground\\land4.bmp",
			"..\\RES\\stageOneBackground\\s.bmp",
		};

		for (int i = 0; i < 11; i ++)
			stageOneBackground.AddBitmap(file[i], RGB(0, 0, 0));
	}

	void CGameStateStage::OnShow() {
		stageOneBackground.SetTopLeft(0, 0);
		stageOneBackground.OnShow();
	}
}