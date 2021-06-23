#ifndef CHARACTER_H
#define CHARACTER_H
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////

	class ChooseCharactor
	{
	public:
		ChooseCharactor();
		void Initialize();				// �]�w���l����l��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// �������l
		void OnShow(int,int,int);					// �N���l�ϧζK��e��
		//void RoleSelect(int);
		//void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		//void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		//void SetXY(int nx, int ny);		// �]�w���l���W���y��
		//void Attack(UINT);
	protected:
		CAnimation animation;		// ���l���ʵe
		//CAnimation animation;		// ���l���ʵe
		//bool isMovingLeft;			// �O�_���b��������
		//bool isMovingRight;			// �O�_���b���k����
	private:
		int roleSel;
		CMovingBitmap role1;
		CMovingBitmap role2;
		CMovingBitmap role3;
		CMovingBitmap player1;
		CMovingBitmap player2;
		CMovingBitmap rolename1;
		CMovingBitmap rolename2;
		CMovingBitmap rolename3;
		CMovingBitmap rolename4;
		CMovingBitmap rolename5;
		CMovingBitmap rolename6;
		CMovingBitmap team;
		int control;
	};
}
#endif