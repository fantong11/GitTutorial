#pragma once
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����﨤�����A�D�n���C���{�����b�o��
// �C��Member function��Implementation���n����
/////////////////////////////////////////////////////////////////////////////
	class CharactorChoose
	{
	public:
		CharactorChoose();
		void LoadBitmap();										// ���J�ϧ�
		void OnShow();											// �N�ϧζK��e��
		void SetXY(int nx, int ny);								// �]�w�Ϥ����y��
		void Initialize();				// �]�w�﨤����l��
		void LoadBitmap();				// ���J�ϧ�
		void IsLeft(bool flag);     	// �]�w�O�_��
		void IsRight(bool flag);       // �]�w�O�_�k
	protected:
		//CMovingBitmap bmp;			// �y����		
	private:
		//bool HitRectangle(int tx1, int ty1, int tx2, int ty2);	// �O�_�I��Ѽƽd�򪺯x��
	};


}
#pragma once
