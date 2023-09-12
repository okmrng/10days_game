#pragma once

#include <stdint.h>
#include <Vector2.h>
#include <Novice.h>
#include "MathUtility.h"
#include "InScene.h"
#include "OutScene.h"

/// <summary>
/// 敵情報
/// </summary>
class EnemyInfo
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	EnemyInfo();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~EnemyInfo();

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
	/// 木箱更新
	/// </summary>
	/// <param name="keys">キー1</param>
	/// <param name="preKeys">キー2</param>
	void WoodUpdate(char* keys, char* preKeys);

	/// <summary>
	/// 金属製の箱更新
	/// </summary>
	/// <param name="keys">キー1</param>
	/// <param name="preKeys">キー2</param>
	void MetalUpdate(char* keys, char* preKeys);

	/// <summary>
	/// 氷更新
	/// </summary>
	/// <param name="keys">キー1</param>
	/// <param name="preKeys">キー2</param>
	void IceUpdate(char* keys, char* preKeys);

	/// <summary>
	/// tv更新
	/// </summary>
	/// <param name="keys">キー1</param>
	/// <param name="preKeys">キー2</param>
	void TvUpdate(char* keys, char* preKeys);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	// ゲッター
	bool GetToBack() { return toBack_; }
	bool GetToWood() { return toWood_; }
	bool GetToMetal() { return toMetal_; }
	bool GetToIce() { return toIce_; }
	bool GetToTv() { return toTv_; }

	// セッター
	void SetToBack(bool toBack) { toBack_ = toBack; }

private:
	// 敵
	uint32_t woodTexture_;  // 木のテクスチャハンドル
	uint32_t metalTexture_; // 金属製の箱のテクスチャハンドル
	uint32_t iceTexture_;   // 氷のテクスチャハンドル
	uint32_t tvTexture_;    // tvのテクスチャハンドル

	// UI
	Vector2 choosePos_;		 // 位置
	float chooseT_;
	uint32_t chooseTexture_; // テクスチャ
	bool onEaseWood_;        // 木箱へのイージングフラグ
	bool onEaseMetal_;       // 金属製の箱へのイージングフラグ
	bool onEaseIce_;         // 氷へのイージングフラグ
	bool onEaseTv_;          // tvへのイージングフラグ

	bool toWood_;            // 木箱情報へ
	bool toMetal_;			 //	金属製の箱情報へ
	bool toIce_;			 // 氷情報へ
	bool toTv_;				 //	tv情報へ

	bool toBack_; // 戻る

	int32_t pushCount_; // キー受付までのカウント
	bool canPush_;      // キー受付

	enum class Choose {
		WOOD,
		METAL,
		ICE,
		TV
	};
	Choose choose_; // 選択中

	// シーン遷移演出追加
	InScene* inScene_;   // 入

	OutScene* outScene_;  // 出
	bool toOutScene_;     // シーン遷移演出(出)の更新を管理
	bool toOutSceneBack_; // 前のシーンへの遷移演出(出)の更新を管理
};

