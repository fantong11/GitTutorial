#pragma once
#include "Character.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����﨤�����A�D�n���C���{�����b�o��
// �C��Member function��Implementation���n����
/////////////////////////////////////////////////////////////////////////////
	class CGameStateChoose : public CGameState {
	public:
		CGameStateChoose(CGame *g);
	//	void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();  								// �C������Ȥιϧγ]�w
	//	bool PressAttack(int a);
	//	void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
	//	void OnBeginState();							// �]�w�C�������һݪ��ܼ�
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CMovingBitmap CHO;
		ChooseCharactor role;
		CMovingBitmap character1;
		CMovingBitmap character2;
		CMovingBitmap character3;
		CMovingBitmap character4;
		CMovingBitmap character5;
		CMovingBitmap character6;
		CMovingBitmap character7;
		CMovingBitmap character8;
		CMovingBitmap character9;
		CMovingBitmap character10;
		CMovingBitmap character11;
		CMovingBitmap character12;
		CMovingBitmap character13;
		CMovingBitmap character14;
		CMovingBitmap character15;
		CMovingBitmap character16;
		CMovingBitmap initialplayer1;
		CMovingBitmap initialplayer2;
		CMovingBitmap initialplayer3;
		CMovingBitmap initialplayer4;
		CMovingBitmap initialplayer5;
		CMovingBitmap initialplayer6;
		CMovingBitmap initialplayer7;
		CMovingBitmap initialplayer8;
		CMovingBitmap initialplayer9;
		CMovingBitmap initialplayer10;
		CMovingBitmap initialplayer11;
		CMovingBitmap initialplayer12;
		CMovingBitmap initialplayer13;
		CMovingBitmap initialplayer14;
		CMovingBitmap initialplayer15;
		CMovingBitmap initialplayer16;

		int control;
		int attack;
		int select;
	};	

}
