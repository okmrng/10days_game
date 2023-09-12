#pragma once

#include <Vector2.h>
#include <Novice.h>
#include "PlayerBullet.h"
#include <list>

/// <summary>
/// 自機クラス
/// </summary>
class Player
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Player();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	///  更新
	/// </summary>
	void Update(char* keys, char* preKeys);

	/// <summary>
	/// 攻撃
	/// </summary>
	void Attack(char* keys, char* preKeys);

	/// <summary>
	/// 弾の当たった時の処理
	/// </summary>
	void BulletOnCollision();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(bool gameOver);

	// ゲッター
	Vector2 GetBulletCollisionPos();
	Vector2 GetBulletSize();
	int32_t GetBulletPower();
	int32_t GetCanShoot() { return canShoot_; }
	bool GetBulletIsDead();

	// セッター
	void SetIsBullet(bool isBullet) { isBullet_ = isBullet; }
	void SetCanShoot(int32_t canShoot) { canShoot_ = canShoot; }
	PlayerBullet* GetBullet() { return bullet_; }

private:
	// 自機情報
	float radius_;     // 半径
	Vector2 pos_;      // 座標
	float velocity_;   // 速度
	uint32_t texture_; // テクスチャハンドル

	// 弾
	PlayerBullet* bullet_ = nullptr;  // 弾のリスト
	int32_t charge_;                  // 弾のチャージ
	int32_t power_;                   // 弾のパワー
	int32_t canShoot_;                // 弾を撃つことができる回数
	bool isBullet_;                   // 弾フラグ

	//HUD
	Vector2 powerPos_; // 座標
	uint32_t power1Texture_;  // パワー1のテクスチャハンドル
	uint32_t power2Texture_;  // パワー2のテクスチャハンドル
	uint32_t power3Texture_;  // パワー3のテクスチャハンドル
	uint32_t power4Texture_;  // パワー4のテクスチャハンドル
	uint32_t power5Texture_;  // パワー5のテクスチャハンドル
};

