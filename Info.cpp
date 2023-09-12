#include "Info.h"

Info::Info()
{
}

Info::~Info()
{
}

void Info::Initialize()
{
	inScene_ = new InScene();
	inScene_->Initialize();
	outScene_ = new OutScene();
	outScene_->Initialize();
	toOutScene_ = false;

	texture_ = Novice::LoadTexture("./resource/background/info.png");
	toNext_ = false;
}

void Info::Update(char* keys, char* preKeys)
{
	inScene_->Update();

	if (inScene_->GetCanPlay()) {
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			toOutScene_ = true;
		}
	}
	if (toOutScene_) {
		outScene_->Update();
	}
	if (outScene_->GetToNext()) {
		toNext_ = true;
	}
}

void Info::Draw()
{
	Novice::DrawSprite(0, 0, texture_, 1, 1, 0.0f, WHITE);

	inScene_->Draw();
	outScene_->Draw();
}
