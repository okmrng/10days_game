#include "Title.h"

Title::Title()
{
}

Title::~Title()
{
}

void Title::Initialize()
{
	// 画像
	texture_ = Novice::LoadTexture("./resource/background/title.png");
	out_ = false;

	// シーン遷移
	nextCount_ = 45;
	toNext_ = false;

	outScene_ = new OutScene();
	outScene_->Initialize();
}

void Title::Update(char* keys)
{
	if (keys[DIK_SPACE]) {
		out_ = true;
	}

	// シーン遷移
	if (out_) {
		outScene_->Update();

		if (outScene_->GetToNext()) {
			toNext_ = true;
		}
	}
}

void Title::Draw()
{
	Novice::DrawSprite(0, 0, texture_, 1, 1, 0.0f, WHITE);
	outScene_->Draw();
}
