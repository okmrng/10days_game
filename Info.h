#pragma once

#include <Novice.h>
#include <InScene.h>
#include <OutScene.h>
#include <stdint.h>

/// <summary>
/// 説明画面
/// </summary>
class Info
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Info();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Info();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 描画
	/// </summary>
	void Update(char* keys, char* preKeys);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	// ゲッター
	bool GetToNext() { return toNext_; }

private:
	InScene* inScene_;
	OutScene* outScene_;
	bool toOutScene_;

	uint32_t texture_;
	bool toNext_;

	// bgm
	uint32_t bgmSound_;
	uint32_t bgmVoice_;
};

