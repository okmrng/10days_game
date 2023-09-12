#pragma once

#include <Vector2.h>
#include <Novice.h>
#include <stdint.h>
#include "Goal.h"

// 前方宣言
class Player;

/// <summary>
/// 氷
/// </summary>
class IceBox
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Vector2 pos, Vector2 size, Player* player);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 当たり判定が働いたときの処理
	/// </summary>
	void OnCollision();

	/// <summary>
	/// ゴール
	/// </summary>
	void IsGoal();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	// ゲッター
	Vector2 GetPos() { return pos_; }
	Vector2 GetSize() { return size_; }
	Vector2 GetGoalCollisionPos() { return goal_->GetCollisionPos(); }
	Vector2 GetGoalCollisionSize() { return goal_->GetCollisionSize(); }
	float GetVelocity() { return velocity_; }
	bool GetAddStop() { return addStop_; }

	// セッター
	void SetPlayer(Player* player) { player_ = player; }

private:
	// 箱
	Vector2 pos_;        // 座標
	Vector2 size_;       // 横幅と縦幅
	float velocity_;     // 速度
	float acceleration_; // 加速度
	bool hit_;           // 当たったかの判定
	bool stop_;          // 他の箱に当てた時にも動くのを防止
	uint32_t texture_;   // テクスチャハンドル
	float startPoint_;   // 始点
	bool isGoal_;        // ゴールフラグ
	float t_;            // フレーム
	
	// ゴール
	Goal* goal_ = nullptr;
	bool addStop_ = false; // クリア判定カウント増加停止フラグ

	// 自機
	Player* player_ = nullptr;

	// SE
	// 被弾音
	uint32_t hitSound_; // サウンドハンドル
	uint32_t hitVoice_; // ボイスハンドル

	// ゴール
	uint32_t goalSound_;         // サウンドハンドル
	uint32_t goalVoice_;         // ボイスハンドル
	int32_t stopGoalSoundCount_; // サウンド止める
};

