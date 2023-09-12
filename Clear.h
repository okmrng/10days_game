#pragma once

#include <Novice.h>
#include <stdint.h> 
#include <Vector2.h>
#include <MathUtility.h>
#include "OutScene.h"

/// <summary>
/// クリア
/// </summary>
class Clear
{
public:
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
	bool GetToNext() { return toNext_; }

private:
	Vector2 pos_;      // 位置
	float t_;          // イージング用変数
	uint32_t clearTexture_; // CLEARテクスチャハンドル

	bool inEase_;		  // イージング開始フラグ
	int32_t inEaseCount_; // イージング開始までのカウント

	uint32_t spaceTexture_; // --SPACE--テクスチャハンドル

	bool canPush_;		   // キー受付フラグ
	int32_t canPushCount_; // キー受付までのカウント
	bool toNext_;		   // 次のシーンへ

	// シーン遷移演出
	OutScene* outScene_;
	bool toOutScene_;    // シーン遷移演出の更新を管理
};

