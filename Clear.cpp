#include "Clear.h"

void Clear::Initialize()
{
	pos_ = Vector2(-426.0f, 250.0f);
	t_ = 0.0f;
	clearTexture_ = Novice::LoadTexture("./resource/sprite/clear.png");

	inEase_ = false;
	inEaseCount_ = 30;

	spaceTexture_ = Novice::LoadTexture("./resource/sprite/clear_space.png");

	canPush_ = false;
	canPushCount_ = 45;
	toNext_ = false;

	// シーン遷移演出
	outScene_ = new OutScene();
	outScene_->Initialize();
	toOutScene_ = false;
}

void Clear::Update(char* keys, char* preKeys)
{
	if (--inEaseCount_ <= 0) {
		inEase_ = true;
	}

	// イージング
	if(inEase_){
		if (t_ < 1.0f) {
			t_ += 1.0f / 30.0f;
		}
		if (t_ >= 1.0f) {
			t_ = 1.0f;
		}
		pos_.x = EaseOutCirc(-426.0f, 427.0f, t_);
	}

	// イージングが終わったらキーを受け付ける
	if (pos_.x >= 427.0f) {
		if(--canPushCount_<=0){
			canPush_ = true;
		}
	}
	if (canPush_) {
		// 次のシーンへ
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			toOutScene_ = true;
		}
	}

	// シーン遷移演出
	if (toOutScene_) {
		outScene_->Update();
	}
	if (outScene_->GetToNext()) {
		toNext_ = true;
	}
}

void Clear::Draw()
{
	// CLEAR
	Novice::DrawSprite(int(pos_.x), int(pos_.y), clearTexture_, 1, 1, 0.0f, WHITE);

	// --SPACE--
	if (canPush_) {
		Novice::DrawSprite(int(430.5f), 400, spaceTexture_, 1, 1, 0.0f, WHITE);
	}

	// シーン遷移演出
	outScene_->Draw();

	// デバッグテキスト
	#ifdef _DEBUG
	Novice::ScreenPrintf(0, 80, "Clear");
	#endif // _DEBUG
}
