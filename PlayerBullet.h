#pragma once

#include <Vector2.h>
#include <Novice.h>
#include "MathUtility.h"
#include <stdint.h>

/// <summary>
/// 自機に弾
/// </summary>
class PlayerBullet
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Vector2 pos, int32_t power);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 当たり判定が働いたときの処理
	/// </summary>
	void OnCollision();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	//ゲッター
	bool GetIsDead() { return isDead_; }
	Vector2 GetCollisionPos() { return collisionPos_; }
	Vector2 GetSize() { return size_; }
	int32_t GetPower() { return power_; }

	// セッター

	
private:
	float radius_;         // 半径
	Vector2 pos_;          // 座標
	float velocity_;       // 速度
	Vector2 collisionPos_; // 当たり判定様の四角形の座標
	Vector2 size_;         // 当たり判定用の四角形の幅
	bool isDead_;          // デスフラグ
	int32_t power_;        // パワー
	uint32_t texture_;     // テクスチャハンドル
};

