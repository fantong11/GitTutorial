#pragma once
namespace game_framework {
	class Enemy : public CharactorSetting {
		using CharactorSetting::CharactorSetting;
	public:
		void LoadBitmap(int) override;
		void SetXY(int x, int y) override;
		void EnemySetAttack(bool flag);
		void EnemySetMovingDown(bool flag);
		void EnemySetMovingUp(bool flag);
		void EnemySetMovingRight(bool flag);
		void EnemySetMovingLeft(bool flag);
		void EnemySetMovingJump(bool flag);
		void EnemySetMoving(bool flag);
		void EnemySetDefense(bool flag);
		void SetHP(int);
		void getCloseToPlayer(int, int);
		void getHit(void);
		void OnShow(void) override;
		void OnMove(void) override;
	};
}