#pragma once
namespace game_framework {
	class CharactorSetting {
	public:
		CharactorSetting();
		void LoadBitmap();
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetMovingJump(bool flag);
		void SetMoving(bool flag);
		bool IsMoving(void);

		void OnMove();
		void OnShow();
	private:
		CMovingBitmap try1;
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

		int charactor_walk_value;
		int charactor_run_value;
		int charactor_attack_value;
		int charactor_defense_value;
		int charactor_hit_value;
		int charactor_health_value;

		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool isMoving;
		bool isMovingJump;
		bool face_right;
		bool on_floor;

		int x, y;
	};
}