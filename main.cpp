#include <Novice.h>
#include "Title.h"
#include "StageSelect.h"
#include "Stage1.h"
#include "EnemyInfo.h"
#include "WoodInfo.h"
#include "MetalInfo.h"
#include "IceInfo.h"
#include "tvInfo.h"
#include "Info.h"

const char kWindowTitle[] = "6007_boxine";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// シーン列挙体
	enum class Scene {
		TITLE,			 // タイトル
		INFO,			 // 説明
		STAGESELECTLOAD, // ステージセレクト初期化
		STAGESELECT,	 // ステージセレクト
		STAGE1LOAD,		 // ステージ1初期化
		STAGE1,			 // ステージ1
		STAGE2LOAD,		 // ステージ2初期化
		STAGE2,			 // ステージ2
		STAGE3LOAD,		 // ステージ3初期化
		STAGE3,			 // ステージ3
		STAGE4LOAD,		 // ステージ4初期化
		STAGE4,			 // ステージ4
		STAGE5LOAD,		 // ステージ5初期化
		STAGE5,			 // ステージ5
		STAGE6LOAD,		 // ステージ6初期化
		STAGE6,			 // ステージ6
		STAGE7LOAD,		 // ステージ7初期化
		STAGE7,			 // ステージ7
		STAGE8LOAD,		 // ステージ8初期化
		STAGE8,			 // ステージ8
		ENEMYINFO,		 // 箱情報
		WOODINFOLOAD,	 // 木箱情報初期化
		WOODINFO,		 // 木箱情報
		METALINFOLOAD,	 // 金属製の箱情報初期化
		METALINFO,		 // 金属製の箱情報
		ICEINFOLOAD,	 // 氷情報初期化
		ICEINFO,		 // 氷情報
		TVINFOLOAD,		 // tv情報初期化
		TVINFO			 // tv情報
	};
	Scene scene = Scene::STAGE1;

	// タイトル
	Title* title = new Title();
	title->Initialize();

	// 説明
	Info* info = new Info();
	info->Initialize();

	// ステージセレクト
	StageSelect* stageSelect = new StageSelect();
	stageSelect->Initiallize();

	// ステージ1
	Stage1* stage1 = new Stage1();
	stage1->Initialize();

	// ステージがいくつか
	Scene beforeStage = Scene::STAGE1;

	// 箱情報
	EnemyInfo* enemyInfo = new EnemyInfo();
	enemyInfo->Initialize();

	// 木箱情報
	WoodInfo* woodInfo = new WoodInfo();
	woodInfo->Initialize();

	// 鉄の箱情報
	MetalInfo* metalInfo = new MetalInfo();
	metalInfo->Initialize();

	// 氷情報
	IceInfo* iceInfo = new IceInfo();
	iceInfo->Initialize();

	// tv情報
	TvInfo* tvInfo = new TvInfo();
	tvInfo->Initialize();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		// タイトル
		if (scene == Scene::TITLE) {
			title->Update(keys);
			//enemyInfo->SetToBack(false);

			// 次のシーンへ
			if (title->GetToNext()) {
				scene = Scene::INFO;
			}
		}

		// 説明
		if (scene == Scene::INFO) {
			info->Update(keys, preKeys);

			if (info->GetToNext()) {
				scene = Scene::STAGESELECTLOAD;
			}
		}

		// ステージセレクト初期化
		if (scene == Scene::STAGESELECTLOAD) {
			stageSelect->Initiallize();
			scene = Scene::STAGESELECT;
		}

		// ステージセレクト
		if (scene == Scene::STAGESELECT) {
			stageSelect->Update(keys, preKeys);

			// 次のシーンへ
			if (stageSelect->GetToStage1()) {
				scene = Scene::STAGE1LOAD;
			}
			if (stageSelect->GetToStage2()) {
				scene = Scene::STAGE2LOAD;
			}
			if (stageSelect->GetToStage3()) {
				scene = Scene::STAGE3LOAD;
			}
			if (stageSelect->GetToStage4()) {
				scene = Scene::STAGE4LOAD;
			}
			if (stageSelect->GetToStage5()) {
				scene = Scene::STAGE5LOAD;
			}
			if (stageSelect->GetToStage6()) {
				scene = Scene::STAGE6LOAD;
			}
			if (stageSelect->GetToStage7()) {
				scene = Scene::STAGE7LOAD;
			}
			if (stageSelect->GetToStage8()) {
				scene = Scene::STAGE8LOAD;
			}
		}

		// ステージ1初期化
		if (scene == Scene::STAGE1LOAD) {
			stage1->Retry();
			scene = Scene::STAGE1;
		}

		// ステージ1
		if(scene==Scene::STAGE1){
			stage1->Update(keys, preKeys);
			
			if (stage1->GetPause()->GetToEnemyInfo() == false) {
				enemyInfo->Initialize();
			}
			// 敵情報へ
			if (stage1->GetPause()->GetToEnemyInfo()) {
				beforeStage = Scene::STAGE1;
				scene = Scene::ENEMYINFO;
			}

			// ステージセレクトへ
			if (stage1->GetClear()->GetToNext() || stage1->GetGameOver()->GetToStageSelect()) {
				scene = Scene::STAGESELECTLOAD;
			}
		}

		// 敵情報
		if (scene == Scene::ENEMYINFO) {
			enemyInfo->Update(keys, preKeys);
			stage1->SetCanPlay(true);
			stage1->SetIsPause(false);

			// 戻る
			if (enemyInfo->GetToBack()) {
				switch (beforeStage)
				{
				case Scene::STAGE1:
					stage1->GetInScene()->Initialize();
					scene = Scene::STAGE1;
					break;
				}
			}

			// 説明へ
			// 木箱
			if (enemyInfo->GetToWood()) {
				scene = Scene::WOODINFOLOAD;
			}

			// 鉄の箱
			if (enemyInfo->GetToMetal()) {
				scene = Scene::METALINFOLOAD;
			}

			// 氷
			if (enemyInfo->GetToIce()) {
				scene = Scene::ICEINFOLOAD;
			}

			// tv
			if (enemyInfo->GetToTv()) {
				scene = Scene::TVINFOLOAD;
			}
		}

		// 木箱情報初期化
		if (scene == Scene::WOODINFOLOAD) {
			woodInfo->Initialize();
			enemyInfo->Initialize();
			scene = Scene::WOODINFO;
		}

		// 木箱情報
		if (scene == Scene::WOODINFO) {
			woodInfo->Update(keys, preKeys);

			// シーン遷移
			if (woodInfo->GetToBack()) {
				scene = Scene::ENEMYINFO;
			}
		}

		// 鉄の箱情報初期化
		if (scene == Scene::METALINFOLOAD) {
			metalInfo->Initialize();
			enemyInfo->Initialize();
			scene = Scene::METALINFO;
		}

		// 鉄の箱
		if (scene == Scene::METALINFO) {
			metalInfo->Update(keys, preKeys);

			// シーン遷移
			if (metalInfo->GetToBack()) {
				scene = Scene::ENEMYINFO;
			}
		}

		// 氷情報初期化
		if (scene == Scene::ICEINFOLOAD) {
			iceInfo->Initialize();
			enemyInfo->Initialize();
			scene = Scene::ICEINFO;
		}

		// 氷情報
		if (scene == Scene::ICEINFO) {
			iceInfo->Update(keys, preKeys);

			// シーン遷移
			if (iceInfo->GetToBack()) {
				scene = Scene::ENEMYINFO;
			}
		}

		// tv情報初期化
		if (scene == Scene::TVINFOLOAD) {
			tvInfo->Initialize();
			enemyInfo->Initialize();
			scene = Scene::TVINFO;
		}

		// tv情報
		if (scene == Scene::TVINFO) {
			tvInfo->Update(keys, preKeys);

			// シーン遷移
			if (tvInfo->GetToBack()) {
				scene = Scene::ENEMYINFO;
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// タイトル
		if (scene == Scene::TITLE) {
			title->Draw();
		}

		// 説明
		if (scene == Scene::INFO) {
			info->Draw();
		}

		// ステージセレクト
		if (scene == Scene::STAGESELECTLOAD) {
			Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
		}
		if (scene == Scene::STAGESELECT) {
			stageSelect->Draw();
		}

		// ステージ1
		if(scene == Scene::STAGE1){
			stage1->Draw();
		}

		// 箱情報
		if (scene == Scene::ENEMYINFO) {
			enemyInfo->Draw();
		}

		// 木箱情報
		if (scene == Scene::WOODINFO) {
			woodInfo->Draw();
		}

		// 鉄の箱情報
		if (scene == Scene::METALINFO) {
			metalInfo->Draw();
		}

		// 氷情報
		if (scene == Scene::ICEINFO) {
			iceInfo->Draw();
		}

		// tv情報
		if (scene == Scene::TVINFO) {
			tvInfo->Draw();
		}

#ifdef _DEBUG
		if (stage1->GetPause()->GetToEnemyInfo()) {
			Novice::ScreenPrintf(0, 500, "true");
		}
		else { Novice::ScreenPrintf(0, 500, "false"); }
		if (enemyInfo->GetToBack()) {
			Novice::ScreenPrintf(0, 520, "true");
		}
		else { Novice::ScreenPrintf(0, 520, "false"); }
#endif // _DEBUG

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// 解放
	delete title;
	delete stageSelect;
	delete stage1;
	delete enemyInfo;
	delete woodInfo;
	delete metalInfo;
	delete iceInfo;
	delete tvInfo;
	delete info;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
