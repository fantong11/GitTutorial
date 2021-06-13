#pragma once
namespace game_framework {
	class Player : public CharactorSetting {
	using CharactorSetting::CharactorSetting;
	public:
		void LoadBitmap(int) override;
		void SetXY(int x, int y) override;
		void Decrease(void);
		void DrawAllAboutPlayer(void);
		void OnShow(void) override;
		void OnMove(void) override;
	};
}