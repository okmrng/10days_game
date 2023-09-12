#include "GameOver.h"

void GameOver::Initialize()
{
	// 背景
	backgroundColor_ = 0x00000000;
	backgroundAlpha_ = 0x00000000;

	// FAILED
	failedTexture_ = Novice::LoadTexture("./resource/sprite/failed.png");
	color_ = 0xffffff00;
	alpha_ = 0x00000000;

	// UI
	// RETRY
	retryPos_ = Vector2(505.5f, 350.0f);
	retryTexture_ = Novice::LoadTexture("./resource/UI/retry.png");
	chooseRetryTexture_ = Novice::LoadTexture("./resource/UI/retry_choose.png");
	chooseRetry_ = true;
	toRetry_ = false;
	retryTheta_ = 0.0f;

	// STAGE SELECT
	stageSelectPos_ = Vector2(370.0f, 474.0f);
	stageSelectTexture_ = Novice::LoadTexture("./resource/UI/stageSelect.png");
	chooseStageSelectTexture_ = Novice::LoadTexture("./resource/UI/stageSelect_choose.png");
	chooseStageSelect_ = false;
	toRetry_ = false;
	stageSelectTheta_ = 0.0f;

	pushCount_ = 5;
	
	choose_ = Choose::RETRY;

	// シーン遷移演出
	outScene_ = new OutScene();
	outScene_->Initialize();
	toOutScene_ = false;
}

void GameOver::Update(char* keys, char* preKeys)
{
	keys;
	preKeys;
	// 背景
	// フェードイン
	backgroundAlpha_ = FadeIn(backgroundAlpha_, 0x00000002, 0x000000f0);

	//FAILED
	// フェードイン
	alpha_ = FadeIn(alpha_, 0x00000002, 0x000000ff);

	// UI
	// 波移動
	retryPos_.x = sinf(retryTheta_) * 3.0f + 505.5f;
	retryPos_.y = cosf(retryTheta_) * 3.0f + 350.5f;

	retryTheta_ += (float)M_PI / 45.0f;

	stageSelectPos_.x = cosf(stageSelectTheta_) * 3.0f + 370.0f;
	stageSelectPos_.y = sinf(stageSelectTheta_) * 3.0f + 474.0f;

	stageSelectTheta_ += (float)M_PI / 45.0f;

	if (alpha_ >= 0x000000ff) {
		switch (choose_)
		{
		case Choose::RETRY:
			RetryUpdate(keys, preKeys);
			break;

		case Choose::STAGESELECT:
			StageSelectUpdate(keys, preKeys);
			break;
		}
	}

	// シーン遷移演出
	if (toOutScene_) {
		outScene_->Update();
	}
}

void GameOver::RetryUpdate(char* keys, char* preKeys)
{
	// フラグ切り替え
	chooseRetry_ = true;
	chooseStageSelect_ = false;

	// 他選択
	if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0) {
		choose_ = Choose::STAGESELECT;
	}
	else if (keys[DIK_UP] && preKeys[DIK_UP] == 0) {
		choose_ = Choose::STAGESELECT;
	}

	// 実行
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		toOutScene_ = true;
	}
	if (outScene_->GetToNext()) {
		toRetry_ = true;
	}
}

void GameOver::StageSelectUpdate(char* keys, char* preKeys)
{
	// フラグ切り替え
	chooseRetry_ = false;
	chooseStageSelect_ = true;

	// 他選択
	if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0) {
		choose_ = Choose::RETRY;
	}
	else if (keys[DIK_UP] && preKeys[DIK_UP] == 0) {
		choose_ = Choose::RETRY;
	}

	// 実行
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		toOutScene_ = true;
	}
	if (outScene_->GetToNext()) {
		toStageSelect_ = true;
	}
}

void GameOver::Draw()
{
	// 背景
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, backgroundColor_ + backgroundAlpha_, kFillModeSolid);

	// FAILED
	Novice::DrawSprite(500, 200, failedTexture_, 1, 1, 0.0f, color_ + alpha_);

	// UI
	// RETRY
	if (chooseRetry_) {
		Novice::DrawSprite(int(retryPos_.x), int(retryPos_.y), chooseRetryTexture_, 1, 1, 0.0f, color_ + alpha_);
	}
	else { Novice::DrawSprite(int(retryPos_.x), int(retryPos_.y), retryTexture_, 1, 1, 0.0f, color_ + alpha_); }

	// STAGE SELECT
	if(chooseStageSelect_){
		Novice::DrawSprite(int(stageSelectPos_.x), int(stageSelectPos_.y), chooseStageSelectTexture_,
			1, 1, 0.0f, color_ + alpha_);
	}
	else{
		Novice::DrawSprite(int(stageSelectPos_.x), int(stageSelectPos_.y), stageSelectTexture_,
			1, 1, 0.0f, color_ + alpha_);
	}

	// シーン遷移演出
	outScene_->Draw();

	#ifdef _DEBUG
	Novice::ScreenPrintf(0, 100, "GAMEOVER");
	#endif // _DEBUG

}
