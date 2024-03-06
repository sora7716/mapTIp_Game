#pragma once
#include <Novice.h>
#include "MapLoad.h"
class GameLoop :private Novice
{
private:
// キー入力結果を受け取る箱
char keys_[KEYS_NUM];
char preKeys_[KEYS_NUM];

//包含
MapLoad* mapLoad_;
public:
/// <summary>
/// コンストラクター
/// </summary>
GameLoop();

/// <summary>
/// デストラクター
/// </summary>
~GameLoop();

/// <summary>
/// キーを受け取る
/// </summary>
void KeysInput();

/// <summary>
/// 更新処理
/// </summary>
void Update();

/// <summary>
/// 描画処理
/// </summary>
void Draw();

/// <summary>
/// ゲームループ
/// </summary>
void Process();
};

