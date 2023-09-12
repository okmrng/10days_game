#pragma once

#include <Novice.h>
#include <stdint.h>
#include <MathUtility.h>
#include "OutScene.h"

/// <summary>
/// ゲームオーバー
/// </summary>
class GameOver
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
	/// リトライ更新
	/// </summary>
	/// <param name="keys">キー1</param>
	/// <param name="preKeys">キー2</param>
	void RetryUpdate(char* keys, char* preKeys);

	/// <summary>
	/// ステージセレクト更新
	/// </summary>
	/// <param name="keys">キー1</param>
	/// <param name="preKeys">キー2</param>
	void StageSelectUpdate(char* keys, char* preKeys);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	// ゲッター
	bool GetToRetry() { return toRetry_; }
	bool GetToStageSelect() { return toStageSelect_; }

private:
	// 背景
	uint32_t backgroundColor_; // 色
	uint32_t backgroundAlpha_; // 透明度

	// FAILED
	uint32_t failedTexture_; // テクスチャハンドル
	uint32_t color_;         // 色
	uint32_t alpha_;         // 透明度

	// UI
	// RETRY
	Vector2 retryPos_;		      // 座標
	uint32_t retryTexture_;       // テクスチャハンドル
	uint32_t chooseRetryTexture_; // 選択中のテクスチャハンドル
	bool chooseRetry_;            // 選択中
	bool toRetry_;                // リトライへ
	float retryTheta_;
	
	// STAGE SELECT
	Vector2 stageSelectPos_;		    // 座標
	uint32_t stageSelectTexture_;       // テクスチャハンドル
	uint32_t chooseStageSelectTexture_; // 選択中のテクスチャハンドル
	bool chooseStageSelect_;            // 選択中
	bool toStageSelect_;                // ステージセレクトへ
	float stageSelectTheta_;

	int32_t pushCount_; // キー受付までのカウント

	enum class Choose {
		RETRY,
		STAGESELECT
	};
	Choose choose_; // 何を選択しているか

	// シーン遷移演出
	OutScene* outScene_;
	bool toOutScene_;    // シーン遷移演出の更新を管理
};

