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
	//	void OnBeginState();							// �]�w�C�������һݪ��ܼ�
	protected:
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
		void OnKeyUp(UINT, UINT, UINT);
		void OnLButtonDown(UINT, CPoint);
	private:
		CMovingBitmap CHO;
	};
	

}