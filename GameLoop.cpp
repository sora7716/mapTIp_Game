#include "GameLoop.h"

/// <summary>
/// コンストラクター
/// </summary>
GameLoop::GameLoop() {
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, (int)SCREEN_WIDTH, (int)SCREEN_HEIGHT);
	for (int i = 0; i < KEYS_NUM; i++) {
		keys_[i] = 0;
		preKeys_[i] = 0;
	}
	mapLoad_ = new MapLoad("test.csv");
	mapLoad_->FileOpen();
}

/// <summary>
/// デストラクター
/// </summary>
GameLoop::~GameLoop() {
	delete mapLoad_;
}

/// <summary>
/// キーを受け取る
/// </summary>
void GameLoop::KeysInput() {
	// キー入力を受け取る
	memcpy(preKeys_, keys_, KEYS_NUM);
	Novice::GetHitKeyStateAll(keys_);
}

/// <summary>
/// 更新処理
/// </summary>
void GameLoop::Update() {

}

/// <summary>
/// 描画処理
/// </summary>
void GameLoop::Draw() {
	mapLoad_->DrawMap();
}

/// <summary>
/// ゲームループ
/// </summary>
void GameLoop::Process() {
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		//キーの受け取り
		KeysInput();

		///更新処理
		Update();
		
		///描画処理
		Draw();

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys_[DIK_ESCAPE] == 0 && keys_[DIK_ESCAPE] != 0) {
			break;
		}
	}
}

