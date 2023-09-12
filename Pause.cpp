#include "Pause.h"

void Pause::Initialize()
{
	// 文字
	PPos_ = Vector2(-91.0f, 100.0f);
	APos_ = Vector2(-91.0f, 100.0f);
	UPos_ = Vector2(-91.0f, 100.0f);
	SPos_ = Vector2(-91.0f, 100.0f);
	EPos_ = Vector2(-91.0f, 100.0f);
	charT_ = 0.0f;
	
	PTexture_ = Novice::LoadTexture("./resource/sprite/P.png");
	ATexture_ = Novice::LoadTexture("./resource/sprite/A.png");
	UTexture_ = Novice::LoadTexture("./resource/sprite/U.png");
	STexture_ = Novice::LoadTexture("./resource/sprite/S.png");
	ETexture_ = Novice::LoadTexture("./resource/sprite/E.png");

	// UI
	playPos_ = Vector2(-224.0f, 271.0f);
	retryPos_ = Vector2(-269.0f, 375.0f);
	enemyInfoPos_ = Vector2(-452.0f, 479.0f);
	playT_ = 0.0f;
	retryT_ = 0.0f;
	enemyInfoT_ = 0.0f;

	playTexture_ = Novice::LoadTexture("./resource/UI/play.png");
	retryTexture_ = Novice::LoadTexture("./resource/UI/retry.png");
	enemyInfoTexture_ = Novice::LoadTexture("./resource/UI/boxInfo.png");
	choosePlayTexture_ = Novice::LoadTexture("./resource/UI/play_choose.png");
	chooseRetryTexture_ = Novice::LoadTexture("./resource/UI/retry_choose.png");
	chooseEnemyInfoTexture_ = Novice::LoadTexture("./resource/UI/boxInfo_choose.png");

	choosePlay_ = false;
	chooseRetry_ = false;
	chooseEnemyInfo_ = false;

	toPlay_ = false;
	toRetry_ = false;
	toEnemyInfo_ = false;

	toCount_ = 5;
	toCoundDown_ = false;

	pushCount_ = 5;
	choose_ = Choose::PLAY;
	
	// 背景
	color_ = 0x00000000;
	alpha_ = 0x00000000;

	onEase_ = true;
	leaveEase_ = false;

	// シーン遷移演出
	outScene_ = new OutScene();
	outScene_->Initialize();
	toOutScene_ = false;
}

void Pause::Update(char* keys, char* preKeys)
{
	// 背景フェード
	alpha_ = FadeIn(alpha_, 0x00000010, 0x000000f0);

	// イージング
	if (onEase_) {
		if (charT_ < 1.0f) {
			charT_ += 1.0f / 45.0f;
		}
		if (charT_ >= 1.0f) {
			charT_ = 1.0f;
		}
		PPos_.x = EaseOutCirc(-91.0f, 392.5f, charT_);
		APos_.x = EaseOutCirc(-91.0f, 493.5f, charT_);
		UPos_.x = EaseOutCirc(-91.0f, 594.5f, charT_);
		SPos_.x = EaseOutCirc(-91.0f, 695.5f, charT_);
		EPos_.x = EaseOutCirc(-91.0f, 796.5f, charT_);

		if (PPos_.x >= 300.0f) {
			if (playT_ < 1.0f) {
				playT_ += 1.0f / 30.0f;
			}
			if (playT_ >= 1.0f) {
				playT_ = 1.0f;
			}
			playPos_.x = EaseOutCirc(-224.0f, 528.0f, playT_);
		}
		if (playPos_.x >= 264.0f) {
			if (retryT_ < 1.0f) {
				retryT_ += 1.0f / 30.0f;
			}
			if (retryT_ >= 1.0f) {
				retryT_ = 1.0f;
			}
			retryPos_.x = EaseOutCirc(-269.0f, 505.5f, retryT_);
		}
		if (retryPos_.x >= 252.75f) {
			if (enemyInfoT_ < 1.0f) {
				enemyInfoT_ += 1.0f / 30.0f;
			}
			if (enemyInfoT_ >= 1.0f) {
				enemyInfoT_ = 1.0f;
			}
			enemyInfoPos_.x = EaseOutCirc(-374.0f, 453.0f, enemyInfoT_);
		}
		if (enemyInfoPos_.x >= 453.0f) {
			onEase_ = false;
		}
	}
	else{ 
		--pushCount_;
	}

	// 選択
	if (pushCount_ <= 0) {
		switch (choose_) {
		case Choose::PLAY:
			PlayUpdate(keys, preKeys);
			break;

		case Choose::RETRY:
			RetryUpdate(keys, preKeys);
			break;

		case Choose::ENEMYINFO:
			EnemyInfoUpdate(keys, preKeys);
			break;
		}
	}

	// シーン遷移演出
	if (toOutScene_) {
		outScene_->Update();
	}
}

void Pause::PlayUpdate(char* keys, char* preKeys)
{
	// フラグ切り替え
	choosePlay_ = true;
	chooseRetry_ = false;
	chooseEnemyInfo_ = false;

	// 他選択
	if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0) {
		choose_ = Choose::RETRY;
	}
	else if (keys[DIK_UP] && preKeys[DIK_UP] == 0) {
		choose_ = Choose::ENEMYINFO;
	}

	// 実行
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		toCoundDown_ = true;
	}

	if (toCoundDown_) {
		--toCount_;
		if (toCount_ > 0) {
			charT_ = 0.0f;
			playT_ = 0.0f;
			retryT_ = 0.0f;
			enemyInfoT_ = 0.0f;
		}

		if (toCount_ <= 0) {
			leaveEase_ = true;

			// 離脱イージング
			if (leaveEase_) {
				if (charT_ < 1.0f) {
					charT_ += 1.0f / 45.0f;
				}
				if (charT_ >= 1.0f) {
					charT_ = 1.0f;
				}
				PPos_.x = EaseOutCirc(392.5f, 1371.0f, charT_);
				APos_.x = EaseOutCirc(493.5f, 1371.0f, charT_);
				UPos_.x = EaseOutCirc(594.5f, 1371.0f, charT_);
				SPos_.x = EaseOutCirc(695.5f, 1371.0f, charT_);
				EPos_.x = EaseOutCirc(796.5f, 1371.0f, charT_);

				if (PPos_.x >= 850.0f) {
					if (playT_ < 1.0f) {
						playT_ += 1.0f / 30.0f;
					}
					if (playT_ >= 1.0f) {
						playT_ = 1.0f;
					}
					playPos_.x = EaseOutCirc(528.0f, 1504.0f, playT_);
				}
				if (playPos_.x >= 1028.0f) {
					if (retryT_ < 1.0f) {
						retryT_ += 1.0f / 30.0f;
					}
					if (retryT_ >= 1.0f) {
						retryT_ = 1.0f;
					}
					retryPos_.x = EaseOutCirc(505.5f, 1549.0f, retryT_);
				}
				if (retryPos_.x >= 1000.5f) {
					if (enemyInfoT_ < 1.0f) {
						enemyInfoT_ += 1.0f / 30.0f;
					}
					if (enemyInfoT_ >= 1.0f) {
						enemyInfoT_ = 1.0f;
					}
					enemyInfoPos_.x = EaseOutCirc(453.0f, 1654.0f, enemyInfoT_);
				}
				if (enemyInfoPos_.x >= 1654.0f) {
					toPlay_ = true;
				}
			}
		}
	}
}

void Pause::RetryUpdate(char* keys, char* preKeys)
{
	// フラグ切り替え
	choosePlay_ = false;
	chooseRetry_ = true;
	chooseEnemyInfo_ = false;

	// 他選択
	if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0) {
		choose_ = Choose::ENEMYINFO;
	}
	else if (keys[DIK_UP] && preKeys[DIK_UP] == 0) {
		choose_ = Choose::PLAY;
	}

	// 実行
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		toOutScene_ = true;
	}
	if (outScene_->GetToNext()) {
		toRetry_ = true;
	}
}

void Pause::EnemyInfoUpdate(char* keys, char* preKeys)
{
	// フラグ切り替え
	choosePlay_ = false;
	chooseRetry_ = false;
	chooseEnemyInfo_ = true;

	// 他選択
	if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0) {
		choose_ = Choose::PLAY;
	}
	else if (keys[DIK_UP] && preKeys[DIK_UP] == 0) {
		choose_ = Choose::RETRY;
	}

	// 実行
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		toOutScene_ = true;
	}
	if (outScene_->GetToNext()) {
		toEnemyInfo_ = true;
	}
}

void Pause::Draw()
{
	// 背景
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, color_ + alpha_, kFillModeSolid);

	// 文字
	Novice::DrawSprite(int(PPos_.x), int(PPos_.y), PTexture_, 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(int(APos_.x), int(APos_.y), ATexture_, 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(int(UPos_.x), int(UPos_.y), UTexture_, 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(int(SPos_.x), int(SPos_.y), STexture_, 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(int(EPos_.x), int(EPos_.y), ETexture_, 1, 1, 0.0f, WHITE);

	// UI
	if (!choosePlay_) {
		Novice::DrawSprite(int(playPos_.x), int(playPos_.y), playTexture_, 1, 1, 0.0f, WHITE);
	}
	else if (choosePlay_) {
		Novice::DrawSprite(int(playPos_.x), int(playPos_.y), choosePlayTexture_, 1, 1, 0.0f, WHITE);
	}

	if (!chooseRetry_) {
		Novice::DrawSprite(int(retryPos_.x), int(retryPos_.y), retryTexture_, 1, 1, 0.0f, WHITE);
	}
	else if (chooseRetry_) {
		Novice::DrawSprite(int(retryPos_.x), int(retryPos_.y), chooseRetryTexture_, 1, 1, 0.0f, WHITE);
	}

	if (!chooseEnemyInfo_) {
		Novice::DrawSprite(int(enemyInfoPos_.x), int(enemyInfoPos_.y), enemyInfoTexture_, 1, 1, 0.0f, WHITE);
	}
	else if (chooseEnemyInfo_) {
		Novice::DrawSprite(int(enemyInfoPos_.x), int(enemyInfoPos_.y), chooseEnemyInfoTexture_, 1, 1, 0.0f, WHITE);
	}

	// シーン遷移演出
	outScene_->Draw();

#ifdef _DEBUG
	Novice::ScreenPrintf(0, 580, "%f", charT_);
	if (leaveEase_) {
		Novice::ScreenPrintf(0, 600, "true");
	}else{ Novice::ScreenPrintf(0, 600, "false"); }
#endif // _DEBUG

}
