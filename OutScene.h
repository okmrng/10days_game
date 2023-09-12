#pragma once

#include <Novice.h>
#include <MathUtility.h>

/// <summary>
/// シーン遷移(出)
/// </summary>
class OutScene
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
	bool GetToNext() { return toNext_; }

private:
	float posX_; // 位置
	float t_;    // フレーム

	int32_t toNextCount_; // 次のシーンへ遷移するまでのカウント
	bool toNext_;         // 次のシーンへ
};

