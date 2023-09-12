#pragma once

#include <Vector2.h>
#include <Novice.h>
#include "MathUtility.h"

class Goal
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="posY">ゴールのY座標</param>
	void Initialize(float posY);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	// ゲッター
	Vector2 GetPos() { return pos_; }
	Vector2 GetCollisionPos() { return collisionPos_; }
	Vector2 GetCollisionSize() { return collisionSize_; }

private:
	// ゴール
	Vector2 pos_;		    // 座標
	Vector2 size_;		    // 幅
	Vector2 collisionP_;    // 通常の座標と当たり判定用の座標の差
	Vector2 collisionPos_;  // 当たり判定用の座標
	Vector2 collisionSize_; // 当たり判定用の幅
	int32_t drawCount_;     // 点滅用
};

