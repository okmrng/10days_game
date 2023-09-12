#include "StageSelect.h"

StageSelect::StageSelect()
{
}

StageSelect::~StageSelect()
{
}

void StageSelect::Initiallize()
{
	stage1Texture_ = Novice::LoadTexture("./resource/UI/stage1.png");
	stage2Texture_ = Novice::LoadTexture("./resource/UI/stage2.png");
	stage3Texture_ = Novice::LoadTexture("./resource/UI/stage3.png");
	stage4Texture_ = Novice::LoadTexture("./resource/UI/stage4.png");
	stage5Texture_ = Novice::LoadTexture("./resource/UI/stage5.png");
	stage6Texture_ = Novice::LoadTexture("./resource/UI/stage6.png");
	stage7Texture_ = Novice::LoadTexture("./resource/UI/stage7.png");
	stage8Texture_ = Novice::LoadTexture("./resource/UI/stage8.png");

	chooseStage1Texture_ = Novice::LoadTexture("./resource/UI/stage1_choose.png");
	chooseStage2Texture_ = Novice::LoadTexture("./resource/UI/stage2_choose.png");
	chooseStage3Texture_ = Novice::LoadTexture("./resource/UI/stage3_choose.png");
	chooseStage4Texture_ = Novice::LoadTexture("./resource/UI/stage4_choose.png");
	chooseStage5Texture_ = Novice::LoadTexture("./resource/UI/stage5_choose.png");
	chooseStage6Texture_ = Novice::LoadTexture("./resource/UI/stage6_choose.png");
	chooseStage7Texture_ = Novice::LoadTexture("./resource/UI/stage7_choose.png");
	chooseStage8Texture_ = Novice::LoadTexture("./resource/UI/stage8_choose.png");

	chooseStage1_ = true;
	chooseStage2_ = false;
	chooseStage3_ = false;
	chooseStage4_ = false;
	chooseStage5_ = false;
	chooseStage6_ = false;
	chooseStage7_ = false;
	chooseStage8_ = false;

	toStage1_ = false;
	toStage2_ = false;
	toStage3_ = false;
	toStage4_ = false;
	toStage5_ = false;
	toStage6_ = false;
	toStage7_ = false;
	toStage8_ = false;

	sinPos_ = Vector2(50.0f, 50.0f);
	cosPos_ = Vector2(350.0f, 50.0f);

	pushCount_ = 5;

	choose_ = Choose::STAGE1;

	// シーン遷移
	inScene_ = new InScene();
	inScene_->Initialize();

	outScene_ = new OutScene();
	outScene_->Initialize();
	toOutScene_ = false;
}

void StageSelect::Update(char* keys, char* preKeys)
{
	// シーン遷移(入)
	inScene_->Update();

	if (toOutScene_) {
		outScene_->Update();
	}
	
	if (inScene_->GetCanPlay()) {
		// 選択
		if (--pushCount_ <= 0) {
			switch (choose_)
			{
			case StageSelect::Choose::STAGE1:
				Stage1Update(keys, preKeys);

				break;

			case StageSelect::Choose::STAGE2:
				Stage2Update(keys, preKeys);

				break;

			case StageSelect::Choose::STAGE3:
				Stage3Update(keys, preKeys);

				break;

			case StageSelect::Choose::STAGE4:
				Stage4Update(keys, preKeys);

				break;

			case StageSelect::Choose::STAGE5:
				Stage5Update(keys, preKeys);

				break;

			case StageSelect::Choose::STAGE6:
				Stage6Update(keys, preKeys);

				break;

			case StageSelect::Choose::STAGE7:
				Stage7Update(keys, preKeys);

				break;

			case StageSelect::Choose::STAGE8:
				Stage8Update(keys, preKeys);

				break;
			}
		}
	}
}

void StageSelect::Stage1Update(char* keys, char* preKeys)
{
	// フラグ変化
	chooseStage1_ = true;
	chooseStage2_ = false;
	chooseStage3_ = false;
	chooseStage4_ = false;
	chooseStage5_ = false;
	chooseStage6_ = false;
	chooseStage7_ = false;
	chooseStage8_ = false;

	// 別のを選択
	if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0) {
		choose_ = Choose::STAGE2;
	}
	if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0) {
		choose_ = Choose::STAGE8;
	}
	if (keys[DIK_UP] && preKeys[DIK_UP] == 0) {
		choose_ = Choose::STAGE5;
	}
	if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0) {
		choose_ = Choose::STAGE5;
	}

	// 実行
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		toOutScene_ = true;
	}
	if (outScene_->GetToNext()) {
		toStage1_ = true;
	}
}

void StageSelect::Stage2Update(char* keys, char* preKeys)
{
	// フラグ変化
	chooseStage1_ = false;
	chooseStage2_ = true;
	chooseStage3_ = false;
	chooseStage4_ = false;
	chooseStage5_ = false;
	chooseStage6_ = false;
	chooseStage7_ = false;
	chooseStage8_ = false;

	// 別のを選択
	if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0) {
		choose_ = Choose::STAGE3;
	}
	if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0) {
		choose_ = Choose::STAGE1;
	}
	if (keys[DIK_UP] && preKeys[DIK_UP] == 0) {
		choose_ = Choose::STAGE6;
	}
	if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0) {
		choose_ = Choose::STAGE6;
	}

	// 実行
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		toOutScene_ = true;
	}
	if (outScene_->GetToNext()) {
		toStage2_ = true;
	}
}

void StageSelect::Stage3Update(char* keys, char* preKeys)
{
	// フラグ変化
	chooseStage1_ = false;
	chooseStage2_ = false;
	chooseStage3_ = true;
	chooseStage4_ = false;
	chooseStage5_ = false;
	chooseStage6_ = false;
	chooseStage7_ = false;
	chooseStage8_ = false;

	// 別のを選択
	if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0) {
		choose_ = Choose::STAGE4;
	}
	if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0) {
		choose_ = Choose::STAGE2;
	}
	if (keys[DIK_UP] && preKeys[DIK_UP] == 0) {
		choose_ = Choose::STAGE7;
	}
	if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0) {
		choose_ = Choose::STAGE7;
	}

	// 実行
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		toOutScene_ = true;
	}
	if (outScene_->GetToNext()) {
		toStage3_ = true;
	}
}

void StageSelect::Stage4Update(char* keys, char* preKeys)
{
	// フラグ変化
	chooseStage1_ = false;
	chooseStage2_ = false;
	chooseStage3_ = false;
	chooseStage4_ = true;
	chooseStage5_ = false;
	chooseStage6_ = false;
	chooseStage7_ = false;
	chooseStage8_ = false;

	// 別のを選択
	if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0) {
		choose_ = Choose::STAGE5;
	}
	if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0) {
		choose_ = Choose::STAGE3;
	}
	if (keys[DIK_UP] && preKeys[DIK_UP] == 0) {
		choose_ = Choose::STAGE8;
	}
	if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0) {
		choose_ = Choose::STAGE8;
	}

	// 実行
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		toOutScene_ = true;
	}
	if (outScene_->GetToNext()) {
		toStage4_ = true;
	}
}

void StageSelect::Stage5Update(char* keys, char* preKeys)
{
	// フラグ変化
	chooseStage1_ = false;
	chooseStage2_ = false;
	chooseStage3_ = false;
	chooseStage4_ = false;
	chooseStage5_ = true;
	chooseStage6_ = false;
	chooseStage7_ = false;
	chooseStage8_ = false;

	// 別のを選択
	if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0) {
		choose_ = Choose::STAGE6;
	}
	if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0) {
		choose_ = Choose::STAGE4;
	}
	if (keys[DIK_UP] && preKeys[DIK_UP] == 0) {
		choose_ = Choose::STAGE1;
	}
	if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0) {
		choose_ = Choose::STAGE1;
	}

	// 実行
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		toOutScene_ = true;
	}
	if (outScene_->GetToNext()) {
		toStage5_ = true;
	}
}

void StageSelect::Stage6Update(char* keys, char* preKeys)
{
	// フラグ変化
	chooseStage1_ = false;
	chooseStage2_ = false;
	chooseStage3_ = false;
	chooseStage4_ = false;
	chooseStage5_ = false;
	chooseStage6_ = true;
	chooseStage7_ = false;
	chooseStage8_ = false;

	// 別のを選択
	if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0) {
		choose_ = Choose::STAGE7;
	}
	if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0) {
		choose_ = Choose::STAGE5;
	}
	if (keys[DIK_UP] && preKeys[DIK_UP] == 0) {
		choose_ = Choose::STAGE2;
	}
	if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0) {
		choose_ = Choose::STAGE2;
	}

	// 実行
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		toOutScene_ = true;
	}
	if (outScene_->GetToNext()) {
		toStage6_ = true;
	}
}

void StageSelect::Stage7Update(char* keys, char* preKeys)
{
	// フラグ変化
	chooseStage1_ = false;
	chooseStage2_ = false;
	chooseStage3_ = false;
	chooseStage4_ = false;
	chooseStage5_ = false;
	chooseStage6_ = false;
	chooseStage7_ = true;
	chooseStage8_ = false;

	// 別のを選択
	if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0) {
		choose_ = Choose::STAGE8;
	}
	if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0) {
		choose_ = Choose::STAGE6;
	}
	if (keys[DIK_UP] && preKeys[DIK_UP] == 0) {
		choose_ = Choose::STAGE3;
	}
	if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0) {
		choose_ = Choose::STAGE3;
	}

	// 実行
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		toOutScene_ = true;
	}
	if (outScene_->GetToNext()) {
		toStage7_ = true;
	}
}

void StageSelect::Stage8Update(char* keys, char* preKeys)
{
	// フラグ変化
	chooseStage1_ = false;
	chooseStage2_ = false;
	chooseStage3_ = false;
	chooseStage4_ = false;
	chooseStage5_ = false;
	chooseStage6_ = false;
	chooseStage7_ = false;
	chooseStage8_ = true;

	// 別のを選択
	if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0) {
		choose_ = Choose::STAGE1;
	}
	if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0) {
		choose_ = Choose::STAGE7;
	}
	if (keys[DIK_UP] && preKeys[DIK_UP] == 0) {
		choose_ = Choose::STAGE4;
	}
	if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0) {
		choose_ = Choose::STAGE4;
	}

	// 実行
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		toOutScene_ = true;
	}
	if (outScene_->GetToNext()) {
		toStage8_ = true;
	}
}

void StageSelect::Draw()
{
	if (!chooseStage1_) {
		Novice::DrawSprite(int(sinPos_.x), int(sinPos_.y), stage1Texture_, 1, 1, 0.0f, WHITE);
	}
	else{ Novice::DrawSprite(int(sinPos_.x), int(sinPos_.y), chooseStage1Texture_, 1, 1, 0.0f, WHITE); }

	if (!chooseStage2_) {
		Novice::DrawSprite(int(cosPos_.x), int(cosPos_.y), stage2Texture_, 1, 1, 0.0f, WHITE);
	}
	else { Novice::DrawSprite(int(cosPos_.x), int(cosPos_.y), chooseStage2Texture_, 1, 1, 0.0f, WHITE); }

	if (!chooseStage3_) {
		Novice::DrawSprite(int(sinPos_.x + 600.0f), int(sinPos_.y), stage3Texture_, 1, 1, 0.0f, WHITE);
	}
	else { Novice::DrawSprite(int(sinPos_.x + 600.0f), int(sinPos_.y), chooseStage3Texture_, 1, 1, 0.0f, WHITE); }

	if (!chooseStage4_) {
		Novice::DrawSprite(int(cosPos_.x + 600.0f), int(cosPos_.y), stage4Texture_, 1, 1, 0.0f, WHITE);
	}
	else { Novice::DrawSprite(int(cosPos_.x + 600.0f), int(cosPos_.y), chooseStage4Texture_, 1, 1, 0.0f, WHITE); }

	if (!chooseStage5_) {
		Novice::DrawSprite(int(sinPos_.x), int(sinPos_.y + 300.0f), stage5Texture_, 1, 1, 0.0f, WHITE);
	}
	else { Novice::DrawSprite(int(sinPos_.x), int(sinPos_.y + 300.0f), chooseStage5Texture_, 1, 1, 0.0f, WHITE); }

	if (!chooseStage6_) {
		Novice::DrawSprite(int(cosPos_.x), int(cosPos_.y + 300.0f), stage6Texture_, 1, 1, 0.0f, WHITE);
	}
	else { Novice::DrawSprite(int(cosPos_.x), int(cosPos_.y + 300.0f), chooseStage6Texture_, 1, 1, 0.0f, WHITE); }

	if (!chooseStage7_) {
		Novice::DrawSprite(int(sinPos_.x + 600.0f), int(sinPos_.y + 300.0f), stage7Texture_, 1, 1, 0.0f, WHITE);
	}
	else { Novice::DrawSprite(int(sinPos_.x + 600.0f), int(sinPos_.y + 300.0f), chooseStage7Texture_, 1, 1, 0.0f, WHITE); }

	if (!chooseStage8_) {
		Novice::DrawSprite(int(cosPos_.x + 600.0f), int(cosPos_.y + 300.0f), stage8Texture_, 1, 1, 0.0f, WHITE);
	}
	else { Novice::DrawSprite(int(cosPos_.x + 600.0f), int(cosPos_.y + 300.0f), chooseStage8Texture_, 1, 1, 0.0f, WHITE); }

	// シーン遷移
	inScene_->Draw();

	outScene_->Draw();
}
