#pragma once

#include <Novice.h>
#include <Vector2.h>
#include <stdint.h>
#include <MathUtility.h>
#include "OutScene.h"

/// <summary>
/// ポーズ
/// </summary>
class Pause
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
	/// UI PLAY
	/// </summary>
	/// <param name="keys">キー1</param>
	/// <param name="preKeys">キー2</param>
	void PlayUpdate(char* keys, char* preKeys);

	/// <summary>
	/// UI RETRY
	/// </summary>
	/// <param name="keys">キー1</param>
	/// <param name="preKeys">キー2</param>
	void RetryUpdate(char* keys, char* preKeys);

	/// <summary>
	/// UI ENEMY INFO
	/// </summary>
	/// <param name="keys">キー1</param>
	/// <param name="preKeys">キー2</param>
	void EnemyInfoUpdate(char* keys, char* preKeys);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	// ゲッター
	bool GetToPlay() { return toPlay_; }
	bool GetToRetry() { return toRetry_; }
	bool GetToEnemyInfo() { return toEnemyInfo_; }

	// セッター
	void SetToEnemyInfo(bool toEnemyInfo) { toEnemyInfo_ = toEnemyInfo; }

private:
	// 文字
	Vector2 PPos_;      // Pの座標
	Vector2 APos_;      // Aの座標
	Vector2 UPos_;      // Uの座標
	Vector2 SPos_;      // Sの座標
	Vector2 EPos_;      // Eの座標
	float charT_;       // フレーム

	uint32_t PTexture_; // Pのテクスチャハンドル
	uint32_t ATexture_; // Aのテクスチャハンドル
	uint32_t UTexture_; // Uのテクスチャハンドル
	uint32_t STexture_; // Sのテクスチャハンドル
	uint32_t ETexture_; // Eのテクスチャハンドル

	// UI
	Vector2 playPos_;				  // 再開の位置
	Vector2 retryPos_;				  // リトライの位置
	Vector2 enemyInfoPos_;			  // 箱情報の位置
	float playT_;                     // 再開のフレーム
	float retryT_;                    // リトライのフレーム
	float enemyInfoT_;                // 箱情報のフレーム
									  
	uint32_t playTexture_;			  // 再開のテクスチャハンドル
	uint32_t retryTexture_;			  // リトライのテクスチャハンドル
	uint32_t enemyInfoTexture_;		  // 箱情報のテクスチャハンドル
	uint32_t choosePlayTexture_;      // 再開選択中のテクスチャハンドル
	uint32_t chooseRetryTexture_;     // リトライ選択中のテクスチャハンドル
	uint32_t chooseEnemyInfoTexture_; // 箱情報選択中のテクスチャハンドル

	bool choosePlay_;				  // 再開選択中フラグ
	bool chooseRetry_;				  // リトライ選択中フラグ
	bool chooseEnemyInfo_;			  // 箱情報選択中フラグ

	bool toPlay_;					  // 再開へ
	bool toRetry_;					  // リトライへ
	bool toEnemyInfo_;				  // 箱情報へ

	int32_t toCount_;                 // 連続受け付け防止
	bool toCoundDown_;				  // toCount_のカウントダウン

	int32_t pushCount_;               // キー入力を受け付けるまでのカウント
	enum class Choose {               // 選択列挙体
		PLAY,
		RETRY,
		ENEMYINFO
	};
	Choose choose_;                  // 選択

	// 背景
	uint32_t color_; // 色
	uint32_t alpha_; // 透明度

	bool onEase_;    // イージングフラグ
	bool leaveEase_; // 離脱イージングフラグ

	// シーン遷移演出
	OutScene* outScene_; // シーン遷移演出
	bool toOutScene_;    // シーン遷移の更新を管理
};

