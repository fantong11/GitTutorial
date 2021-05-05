#pragma once
namespace game_framework {
	class Enemy : public CharactorSetting {
		using CharactorSetting::CharactorSetting;
	public:
		void LoadBitmap(int) override;
		void SetXY(int x, int y) override;
		void getCloseToPlayer(int, int);
		void getHit(void);
		void DrawAllAboutEnemy(void);
	};
}