#pragma once
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����﨤�����A�D�n���C���{�����b�o��
// �C��Member function��Implementation���n����
/////////////////////////////////////////////////////////////////////////////
	class CGameStateChoose : public CGameState {
	public:
		CGameStateChoose(CGame *g);
		void OnInit();  								// �C������Ȥιϧγ]�w
		bool PressAttack(int a);
		void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	//	void OnBeginState();							// �]�w�C�������һݪ��ܼ�
	protected:
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CMovingBitmap CHO;
		CMovingBitmap character1;
		CMovingBitmap character2;
	};
	

}