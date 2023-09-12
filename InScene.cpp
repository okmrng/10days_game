#include "InScene.h"

void InScene::Initialize()
{
	// 黒
	blackPosX_ = 0.0f;
	t_ = 0.0f;
	canPlay_ = false;
}

void InScene::Update()
{
	// イージング
	if (t_ < 1.0f) {
		t_ += 1.0f /60.0f;
	}
	if (t_ >= 1.0f) {
		t_ = 1.0f;
	}
	blackPosX_ = EaseOutCirc(0.0f, 2000.0f, t_);

	if (t_ >= 1.0f) {
		canPlay_ = true;
	}
}

void InScene::Draw()
{
	// 黒
	Novice::DrawBox(int(blackPosX_), 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);

#ifdef _DEBUG
	Novice::ScreenPrintf(0, 240, "%0.0f", t_);
#endif // _DEBUG

}
