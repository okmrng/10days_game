#include "OutScene.h"

void OutScene::Initialize()
{
	posX_ = -1280.0f;
	t_ = 0.0f;

	toNextCount_ = 15;
	toNext_ = false;
}

void OutScene::Update()
{
	// イージング
	if (t_ < 1.0f) {
		t_ += 1.0f / 30.0f;
	}
	if (t_ >= 1.0f) {
		t_ = 1.0f;
	}
	posX_ = EaseOutCirc(-1280.0f, 0.0f, t_);

	if (posX_ >= 0.0f) {
		--toNextCount_;

		if (toNextCount_ <= 0) {
			toNext_ = true;
		}
	}
}

void OutScene::Draw()
{
	Novice::DrawBox(int(posX_), 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
}
