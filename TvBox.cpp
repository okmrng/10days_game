#include "TvBox.h"

#include "Player.h"

void TvBox::Initialize(Vector2 pos, Vector2 size)
{
	pos_ = pos;
	size_ = size;
	velocity_ = 0;
	acceleration_ = 1;
	hit_ = false;
	stop_ = false;
	count0_ = false;
	count_ = 3;
	texture_ = Novice::LoadTexture("./resource/sprite/tv-Box.png");
	//texture0_ = Novice::LoadTexture("./resource/sprite/tv-count_0.png");
	texture1_ = Novice::LoadTexture("./resource/sprite/tv-count_1.png");
	texture2_ = Novice::LoadTexture("./resource/sprite/tv-count_2.png");
	texture3_ = Novice::LoadTexture("./resource/sprite/tv-count_3.png");
	startPoint_ = pos_.x;
	isGoal_ = false;
	t_ = 0.0f;

	// ゴール
	goal_ = new Goal();
	goal_->Initialize(pos_.y);
	addStop_ = false;

	// SE
	// 被弾
	hitSound_ = Novice::LoadAudio("./resource/SE/damage.wav");
	hitVoice_ = 0u;

	// ゴール
	goalSound_ = Novice::LoadAudio("./resource/SE/goal.wav");
	goalVoice_ = 0u;
	stopGoalSoundCount_ = 15;
}

void TvBox::Update()
{
	// パワーによって速度を変える
	if (player_->GetBulletPower() == 1) {
		velocity_ = 10;
	}
	else if (player_->GetBulletPower() == 2) {
		velocity_ = 15;
	}
	else if (player_->GetBulletPower() == 3) {
		velocity_ = 20;
	}
	else if (player_->GetBulletPower() == 4) {
		velocity_ = 25;
	}
	else if (player_->GetBulletPower() == 5) {
		velocity_ = 30;
	}

	// 当たった時の処理
	if (hit_) {
		// 徐々に減速させる
		velocity_ -= acceleration_;
		if (velocity_ <= 0) {
			velocity_ = 0;

			stop_ = true;

			player_->SetIsBullet(true);
		}

		// 移動
		if (!stop_ && count_ >= 0) {
			pos_.x += velocity_;
		}
	}

	if (count_ <= 0) {
		if(velocity_<=0){
			// 0で固定
			count_ = -1;
		}
	}

	// ゴールするまで始点を箱の座標に合わせる
	if (!isGoal_) {
		startPoint_ = pos_.x;
	}

	// ゴールしたらゴールにイージング
	if (isGoal_) {
		if (t_ < 1.0f) {
			t_ += 1.0f / 30.0f;
		}
		if (t_ >= 1.0f) {
			t_ = 1.0f;
		}

		float easedT_ = sqrt(1.0f - pow(t_ - 1.0f, 2.0f));

		pos_.x = (1.0f - easedT_) * startPoint_ + easedT_ * (goal_->GetPos().x);

		if (!Novice::IsPlayingAudio(goalVoice_)) {
			goalVoice_ = Novice::PlayAudio(goalSound_, 0, 1);
		}
		if (--stopGoalSoundCount_ <= 0) {
			Novice::StopAudio(goalVoice_);
		}
	}

	goal_->Update();
}

void TvBox::OnCollision()
{
	hit_ = true;
	stop_ = false;
	player_->SetIsBullet(false);
	count_ -= 1;

	hitVoice_ = Novice::PlayAudio(hitSound_, 0, 1);
}

void TvBox::IsGoal()
{
	isGoal_ = true;
	addStop_ = true;
}

void TvBox::Draw()
{
	// ゴール
	goal_->Draw();

	// 本体
	Novice::DrawSprite(int(pos_.x), int(pos_.y), texture_, 1, 1, 0.0f, WHITE);

	// カウント
	if(count_ == 3){
		Novice::DrawSprite(int(pos_.x + 25), int(pos_.y + 15), texture3_, 1, 1, 0.0f, WHITE);
	}
	else if (count_ == 2) {
		Novice::DrawSprite(int(pos_.x + 25), int(pos_.y + 15), texture2_, 1, 1, 0.0f, WHITE);
	}
	if (count_ == 1) {
		Novice::DrawSprite(int(pos_.x + 25), int(pos_.y + 15), texture1_, 1, 1, 0.0f, WHITE);
	}
	if (count_ <= 0) {
		Novice::DrawSprite(int(pos_.x + 25), int(pos_.y + 15), texture0_, 1, 1, 0.0f, WHITE);
	}
}
