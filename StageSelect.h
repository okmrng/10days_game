#pragma once

#include <stdint.h>
#include <Novice.h>
#include <Vector2.h>
#include "MathUtility.h"
#include "InScene.h"
#include "OutScene.h"

/// <summary>
/// ステージセレクト
/// </summary>
class StageSelect
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	StageSelect();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~StageSelect();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initiallize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update(char* keys, char* preKeys);

	/// <summary>
	/// ステージ1の更新処理
	/// </summary>
	/// <param name="keys">キー1</param>
	/// <param name="preKeys">キー2</param>
	void Stage1Update(char* keys, char*preKeys);

	/// <summary>
	/// ステージ2の更新処理
	/// </summary>
	/// <param name="keys">キー1</param>
	/// <param name="preKeys">キー2</param>
	void Stage2Update(char* keys, char* preKeys);

	/// <summary>
	/// ステージ3の更新処理
	/// </summary>
	/// <param name="keys">キー1</param>
	/// <param name="preKeys">キー2</param>
	void Stage3Update(char* keys, char* preKeys);

	/// <summary>
	/// ステージ4の更新処理
	/// </summary>
	/// <param name="keys">キー1</param>
	/// <param name="preKeys">キー2</param>
	void Stage4Update(char* keys, char* preKeys);

	/// <summary>
	/// ステージ5の更新処理
	/// </summary>
	/// <param name="keys">キー1</param>
	/// <param name="preKeys">キー2</param>
	void Stage5Update(char* keys, char* preKeys);

	/// <summary>
	/// ステージ6の更新処理
	/// </summary>
	/// <param name="keys">キー1</param>
	/// <param name="preKeys">キー2</param>
	void Stage6Update(char* keys, char* preKeys);

	/// <summary>
	/// ステージ7の更新処理
	/// </summary>
	/// <param name="keys">キー1</param>
	/// <param name="preKeys">キー2</param>
	void Stage7Update(char* keys, char* preKeys);

	/// <summary>
	/// ステージ8の更新処理
	/// </summary>
	/// <param name="keys">キー1</param>
	/// <param name="preKeys">キー2</param>
	void Stage8Update(char* keys, char* preKeys);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	// ゲッター
	bool GetToStage1() { return toStage1_; }
	bool GetToStage2() { return toStage2_; }
	bool GetToStage3() { return toStage3_; }
	bool GetToStage4() { return toStage4_; }
	bool GetToStage5() { return toStage5_; }
	bool GetToStage6() { return toStage6_; }
	bool GetToStage7() { return toStage7_; }
	bool GetToStage8() { return toStage8_; }

private:
	// UI
	uint32_t stage1Texture_;       // ステージ1のテクスチャハンドル
	uint32_t stage2Texture_;       // ステージ2のテクスチャハンドル
	uint32_t stage3Texture_;       // ステージ3のテクスチャハンドル
	uint32_t stage4Texture_;       // ステージ4のテクスチャハンドル
	uint32_t stage5Texture_;       // ステージ5のテクスチャハンドル
	uint32_t stage6Texture_;       // ステージ6のテクスチャハンドル
	uint32_t stage7Texture_;       // ステージ7のテクスチャハンドル
	uint32_t stage8Texture_;       // ステージ8のテクスチャハンドル

	uint32_t chooseStage1Texture_; // ステージ1を選択中のテクスチャハンドル
	uint32_t chooseStage2Texture_; // ステージ2を選択中のテクスチャハンドル
	uint32_t chooseStage3Texture_; // ステージ3を選択中のテクスチャハンドル
	uint32_t chooseStage4Texture_; // ステージ4を選択中のテクスチャハンドル
	uint32_t chooseStage5Texture_; // ステージ5を選択中のテクスチャハンドル
	uint32_t chooseStage6Texture_; // ステージ6を選択中のテクスチャハンドル
	uint32_t chooseStage7Texture_; // ステージ7を選択中のテクスチャハンドル
	uint32_t chooseStage8Texture_; // ステージ8を選択中のテクスチャハンドル

	bool chooseStage1_;            // ステージ1を選択中
	bool chooseStage2_;            // ステージ2を選択中
	bool chooseStage3_;            // ステージ3を選択中
	bool chooseStage4_;            // ステージ4を選択中
	bool chooseStage5_;            // ステージ5を選択中
	bool chooseStage6_;            // ステージ6を選択中
	bool chooseStage7_;            // ステージ7を選択中
	bool chooseStage8_;            // ステージ8を選択中

	bool toStage1_;                // ステージ1へ
	bool toStage2_;                // ステージ2へ
	bool toStage3_;                // ステージ3へ
	bool toStage4_;                // ステージ4へ
	bool toStage5_;                // ステージ5へ
	bool toStage6_;                // ステージ6へ
	bool toStage7_;                // ステージ7へ
	bool toStage8_;                // ステージ8へ

	Vector2 sinPos_; // 波移動sinの位置
	Vector2 cosPos_; // 波移動cosの位置
	float sinTheta_; // 波移動sinの回転角
	float cosTheta_; // 波移動cosの回転角

	int32_t pushCount_; // キーが押せるようになるまでのカウント

	enum class Choose {
		STAGE1,
		STAGE2,
		STAGE3,
		STAGE4,
		STAGE5,
		STAGE6,
		STAGE7,
		STAGE8
	};
	Choose choose_; // どれを選択中か

	// シーン遷移
	InScene* inScene_;   // 入

	OutScene* outScene_; // 出
	bool toOutScene_;    // シーン遷移(出)の更新処理を管理するためのフラグ
};

