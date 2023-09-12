#pragma once

#include <Novice.h>
#include "Player.h"
#include "Box.h"
#include "MetalBox.h"
#include "IceBox.h"
#include "TvBox.h"
#include "Clear.h"
#include "GameOver.h"
#include "Pause.h"
#include "HitEffect.h"
#include "InScene.h"
#include "TimeLimit.h"
#include <list>
#include <sstream>
#include <cassert>

/// <summary>
/// ステージ1
/// </summary>
class Stage1
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Stage1();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Stage1();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 箱発生データの読み込み
	/// </summary>
	void LoadData(const std::string& filename, std::stringstream& targetStream);

	/// <summary>
	/// 更新
	/// </summary>
	void Update(char* keys, char* preKeys);

	/// <summary>
	/// 当たり判定
	/// </summary>
	void CheckAllCollision();

	/// <summary>
	/// 木箱生成
	/// </summary>
	/// <param name="pos">座標</param>
	/// <param name="size">大きさ</param>
	void AddBox(Vector2 pos, Vector2 size);

	/// <summary>
	/// 金属製の箱生成
	/// </summary>
	/// <param name="pos">座標</param>
	/// <param name="size">大きさ</param>
	void AddMetalBox(Vector2 pos, Vector2 size);

	/// <summary>
	/// 氷生成
	/// </summary>
	/// <param name="pos">座標</param>
	/// <param name="size">大きさ</param>
	void AddIceBox(Vector2 pos, Vector2 size);

	/// <summary>
	/// tv生成
	/// </summary>
	/// <param name="pos">座標</param>
	/// <param name="size">大きさ</param>
	void AddTvBox(Vector2 pos, Vector2 size);

	/// <summary>
	/// ヒットエフェクト生成
	/// </summary>
	/// <param name="texture">テクスチャハンドル</param>
	/// <param name="anim">アニメーションの数</param>
	/// <param name="animMax">アニメーションの最大値</param>
	/// <param name="flame">フレーム数</param>
	/// <param name="flameMax">最大フレーム数</param>
	/// <param name="pos">位置</param>
	/// <param name="size">幅</param>
	void AddHitEffect(uint32_t texture, uint32_t anim, uint32_t animMax, uint32_t flame, uint32_t flameMax,
		Vector2 pos, Vector2 size);

	/// <summary>
	/// 敵発生コマンドの更新
	/// </summary>
	void UpdateBoxComands(std::stringstream& boxPopComands);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// リトライ
	/// </summary>
	void Retry();

	// ゲッター
	Pause* GetPause() { return pause_; }
	Clear* GetClear() { return clear_; }
	GameOver* GetGameOver() { return gameOver_; }
	InScene* GetInScene() { return inScene_; }

	// セッター
	void SetCanPlay(bool canPlay) { canPlay_ = canPlay; }
	void SetIsPause(bool isPause) { isPause_ = isPause; }

private:
	Player* player_ = nullptr; // 自機

	// 箱
	std::list<Box*> box_;           // 木箱
	std::list<MetalBox*> metalBox_; // 金属製の箱
	std::list<IceBox*> iceBox_;     // 氷
	std::list<TvBox*> tvBox_;       // tv

	Clear* clear_; // クリア

	GameOver* gameOver_; // ゲームオーバー

	Pause* pause_; // ポーズ

	HitEffect* hitEffect_; // ヒットエフェクト

	InScene* inScene_; // シーン遷移演出

	TimeLimit* timeLimitC_; // 制限時間

	std::stringstream boxPopComands_; // コマンド

	int32_t boxCount_; // 箱
	Vector2 boxPos_;   // 箱の位置
	Vector2 boxSize_;  // 箱の幅
	int32_t boxKinds_; // 箱の種類

	int32_t clearCount_; // クリア判定

	//	クリア
	bool isClear_;		    // クリアフラグ
	int32_t toClearCount_;  // クリアに入るまでの時間
	int32_t addClearCount_; // クリアカウントを足す時間

	// ゲームオーバー
	bool isGameOver_;		  // ゲームオーバーフラグ
	int32_t inGameOverCount_; // ゲームオーバーに入るまでのカウント

	// プレイ
	bool canPlay_;	    // プレイフラグ
	int32_t playCount_; // プレイできるようになるまでのカウント
	bool isStart_;      // スタートフラグ

	// ポーズ
	bool isPause_; // ポーズ

	int32_t bulletCount_;

	// テクスチャハンドル
	uint32_t metalHitEffect_; // 金属製の箱のヒットエフェクト
	uint32_t iceHitEffect_;   // 氷のヒットエフェクト
	uint32_t woodHitEffect_;  // 木箱のヒットエフェクト
	uint32_t tvHitEffect_;    // tvのヒットエフェクト

	int32_t timeLimit_; // 制限時間
	int32_t time_;      // 制限時間csv入力用

	int32_t canPlayCount_; // 誤射対策
};

