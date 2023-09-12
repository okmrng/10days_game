#include "IceBox.h"

#include "Player.h"

void IceBox::Initialize(Vector2 pos, Vector2 size, Player* player)
{
	pos_ = pos;
	size_ = size;
	velocity_ = 0;
	acceleration_ = 0.5;
	hit_ = false;
	stop_ = false;
	texture_ = Novice::LoadTexture("./resource/sprite/ice-Box.png");
	startPoint_ = pos_.x;
	isGoal_ = false;
	t_ = 0.0f;

	player_ = player;

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

void IceBox::Update()
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
		if (!stop_) {
			pos_.x += velocity_;
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

void IceBox::OnCollision()
{
	hit_ = true;
	stop_ = false;
	player_->SetIsBullet(false);

	hitVoice_ = Novice::PlayAudio(hitSound_, 0, 1);
}

void IceBox::IsGoal()
{
	isGoal_ = true;
	addStop_ = true;
}

void IceBox::Draw()
{
	// ゴール
	goal_->Draw();

	// 本体
	Novice::DrawSprite(int(pos_.x), int(pos_.y), texture_, 1, 1, 0.0f, WHITE);

	// デバッグ
#ifdef _DEBUG
	Novice::ScreenPrintf(0, 220, "pos_.x:%0.0f", pos_.x);
	Novice::ScreenPrintf(0, 240, "velocity:%0.0f", velocity_);
	Novice::ScreenPrintf(0, 260, "acceleration:%0.1f", acceleration_);
	if (hit_) {
		Novice::ScreenPrintf(0, 280, "hit:true");
	}
	else{ Novice::ScreenPrintf(0, 280, "hit:false"); }
	if (stop_) {
		Novice::ScreenPrintf(0, 300, "stop:true");
	}
	else { Novice::ScreenPrintf(0, 300, "stop:false"); }
	Novice::ScreenPrintf(0, 320, "startPoint:%0.0f", startPoint_);
	if (goal_) {
		Novice::ScreenPrintf(0, 340, "goal:true");
	}
	else { Novice::ScreenPrintf(0, 340, "goal:false"); }
	Novice::ScreenPrintf(0, 360, "t:%0.0f", t_);
	Novice::ScreenPrintf(0, 380, "power:%d", player_->GetBulletPower());
	if (player_->GetBullet()) {
		Novice::ScreenPrintf(0, 400, "bullet:true");
	}else{ Novice::ScreenPrintf(0, 400, "bullet:false"); }
	if (player_) {
		Novice::ScreenPrintf(0, 440, "player:true");
	}
	else { Novice::ScreenPrintf(0, 440, "player:false"); }
#endif // _DEBUG
}
