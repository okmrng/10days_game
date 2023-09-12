#pragma once

#include <stdint.h>
#include <Vector2.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <Novice.h>
#include "InScene.h"
#include "OutScene.h"

/// <summary>
/// tv情報
/// </summary>
class TvInfo
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	TvInfo();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~TvInfo();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="keys">キー1</param>
	/// <param name="preKeys">キー2</param>
	void Update(char* keys, char* preKeys);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	// ゲッター
	bool GetToBack() { return toBack_; }

private:
	// tv
	Vector2 pos_;         // 位置 
	float theta_;         // 回転角
	uint32_t tvTexture_; // テクスチャ

	// 説明
	uint32_t infoTexture_; // テクスチャ

	bool toBack_; // 画面遷移フラグ

	// シーン遷移演出
	InScene* inScene_;   // 入

	OutScene* outScene_; // 出
	bool toOutScene_;    // シーン遷移演出(出)の更新を管理
};

