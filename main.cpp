#include "GameLoop.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	GameLoop *gameLoop = new GameLoop;

	gameLoop->Process();

	delete gameLoop;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
