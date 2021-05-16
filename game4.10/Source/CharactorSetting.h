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
		void SetAttack(bool flag);
		void DecreaseBlood(void);
		void DecreaseBlood2(void);
		void SetAlive(bool flag);
		void isUnderAttack(int, int,int, bool);

		int NowX(void);
		int NowY(void);
		bool IsMoving(void);
		bool IsAttacking(void);
		void SetDefense(bool flag);
		
		bool isDefense;
		bool IsDead();
		bool is_alive;
		bool enemy_now;
		bool underAttack;

		virtual void SetXY(int, int);
		virtual void OnMove();
		void OnShow();

		CAnimation charactor_shadow;

		CAnimation charactor_walk_right;
		CAnimation charactor_run_right;
		CAnimation charactor_attack_right;
		CAnimation charactor_jump_right;
		CAnimation charactor_hit_right;
		CAnimation charactor_stand_right;
		CAnimation charactor_behit_right;
		CAnimation charactor_walk_left;
		CAnimation charactor_run_left;
		CAnimation charactor_attack_left;
		CAnimation charactor_jump_left;
		CAnimation charactor_hit_left;
		CAnimation charactor_stand_left;
		CAnimation charactor_behit_left;
		CAnimation charactor_defense_right;
		CAnimation charactor_defense_left;

		int x, y, z;
		int HP;
		bool is_up;
		bool face_right;
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool isAttack;
		bool isMoving;
		bool isMovingJump;
		bool on_floor;
		bool UnderAttack;
		int MAGIC;
		int LEAVE_BLOOD;
		int LEAVE_MAGIC;
		int control_attack;
		int control_be_attack;
		int control_hit_speed;

	protected:
		//CMovingBitmap try1;
	
		int charactor_walk_value;
		int charactor_run_value;
		int charactor_attack_value;
		int charactor_defense_value;
		int charactor_hit_value;
		int charactor_health_value;


		

	
	};
}