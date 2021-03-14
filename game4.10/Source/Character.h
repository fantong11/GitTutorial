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
		void OnShow();					// �N���l�ϧζK��e��
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetXY(int nx, int ny);		// �]�w���l���W���y��
	protected:
		CAnimation animation;		// ���l���ʵe
		int x, y;					// ���l���W���y��
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
	private:
	//private:
	//	CMovingBitmap character;
	};
}