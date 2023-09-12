#pragma once

#include <Novice.h>
#include <MathUtility.h>
#include <stdint.h>

/// <summary>
/// シーン遷移(入)
/// </summary>
class InScene
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	// ゲッター
	bool GetCanPlay() { return canPlay_; }

private:
	// 黒
	float blackPosX_; // 位置
	float t_;         // フレーム
	bool canPlay_;    // プレイ開始フラグ
};

