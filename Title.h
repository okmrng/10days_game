#pragma once

#include <stdint.h>
#include <Novice.h>
#include <OutScene.h>

/// <summary>
/// タイトル
/// </summary>
class Title
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Title();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Title();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="keys">キー</param>
	void Update(char* keys);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	// ゲッター
	bool GetToNext() { return toNext_; }

private:
	// 画像
	uint32_t texture_; // テクスチャハンドル
	bool out_;      // フェードアウトフラグ

	// シーン遷移
	int32_t nextCount_; // 次のシーンへ遷移するまでのカウント
	bool toNext_;       // 次のシーンへ遷移するためのフラグ

	OutScene* outScene_; // シーン遷移(出)
};

