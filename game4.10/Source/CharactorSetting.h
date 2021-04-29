#pragma once
namespace game_framework {
	class CharactorSetting {
	public:
		CharactorSetting();
		virtual void LoadBitmap(int);
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetMovingJump(bool flag);
		void SetMoving(bool flag);
		bool IsMoving(void);
<<<<<<< HEAD
		void SetXY(int x, int y);
		void RandomMoving(void);
		bool IsDead();
=======
		virtual void SetXY(int, int);
>>>>>>> c96d9a168b97fb9c6e6f1755c12da9f710e005bd

		virtual void OnMove();
		void OnShow();

		CAnimation charactor_walk_right;
		CAnimation charactor_run_right;
		CAnimation charactor_attack_right;
		CAnimation charactor_jump_right;
		CAnimation charactor_defense_right;
		CAnimation charactor_hit_right;
		CAnimation charactor_stand_right;

		CAnimation charactor_walk_left;
		CAnimation charactor_run_left;
		CAnimation charactor_attack_left;
		CAnimation charactor_jump_left;
		CAnimation charactor_defense_left;
		CAnimation charactor_hit_left;
		CAnimation charactor_stand_left;

		int x, y;
		bool face_right;
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool isMoving;
		bool isMovingJump;
		bool on_floor;

	protected:
		//CMovingBitmap try1;
	
		int charactor_walk_value;
		int charactor_run_value;
		int charactor_attack_value;
		int charactor_defense_value;
		int charactor_hit_value;
		int charactor_health_value;


		int HP;
		int MAGIC;
		int LEAVE_BLOOD;
		int LEAVE_MAGIC;
	
	};
}