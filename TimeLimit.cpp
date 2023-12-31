#include "TimeLimit.h"

void TimeLimit::Initialize()
{
	// テクスチャ読み込み
	textureHandleNumber_[0] = Novice::LoadTexture("./resource/number/0.png");
	textureHandleNumber_[1] = Novice::LoadTexture("./resource/number/1.png");
	textureHandleNumber_[2] = Novice::LoadTexture("./resource/number/2.png");
	textureHandleNumber_[3] = Novice::LoadTexture("./resource/number/3.png");
	textureHandleNumber_[4] = Novice::LoadTexture("./resource/number/4.png");
	textureHandleNumber_[5] = Novice::LoadTexture("./resource/number/5.png");
	textureHandleNumber_[6] = Novice::LoadTexture("./resource/number/6.png");
	textureHandleNumber_[7] = Novice::LoadTexture("./resource/number/7.png");
	//textureHandleNumber_[8] = Novice::LoadTexture("./resource/number/8.png");
	//textureHandleNumber_[9] = Novice::LoadTexture("./resource/number/9.png");
	time_ = timeLimit_;

	width_ = 52;

	eachTime_[2] = { 0 };
}

void TimeLimit::Update()
{
	// 画像割り当て
	eachTime_[0] = time_ / 10;
	eachTime_[1] = time_ % 10;

	//time_ = timeLimit_;
	//time_ = 10;
	
	// 制限
	if (timeLimit_ <= 0) {
		timeLimit_ = 0;
		time_ = 0;
	}
	if (timeLimit_ > 99) {
		timeLimit_ = 99;
		time_ = 99;
	}
}

void TimeLimit::Draw()
{
	
	Novice::DrawSprite(1218 - width_, 10, textureHandleNumber_[eachTime_[0]], 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(1218, 10, textureHandleNumber_[eachTime_[1]], 1, 1, 0.0f, WHITE);

}
