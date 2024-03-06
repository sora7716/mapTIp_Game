#include "MapLoad.h"

/// <summary>
/// コンストラクター
/// </summary>
/// <param name="fname"></param>
MapLoad::MapLoad(const char* fname) {
	fname_ = fname;
	fp_ = 0;
	err_ = fopen_s(&fp_, fname_, "r");
	ret_ = 0;
	for (int x = 0; x < MAP_X; x++) {
		for (int y = 0; y < MAP_Y; y++) {
			map_[y][x] = -1;
		}
	}
}

/// <summary>
/// ファイル読み込み
/// </summary>
void MapLoad::FileOpen() {
	if (err_ != 0) {
		printf("%sファイルが開けません\n", fname_);
	}
	else {
		Novice::ScreenPrintf(0, 0, "%d", (int)ret_);
		while ((ret_ = fgetc(fp_)) != EOF) {
			Assign();
		}
		fclose(fp_);
	}
}

/// <summary>
/// ファイル内の数字をmap_に代入
/// </summary>
void MapLoad::Assign() {
	for (int y = 0; y < MAP_Y; y++) {
		for (int x = 0; x < MAP_X; x++) {
			if (map_[y][x] == -1) {
				if (ret_ == '1')
				{
					map_[y][x] = 1;
					return;
				}
				if (ret_ == '0')
				{
					map_[y][x] = 0;
					return;
				}
			}
		}
	}
}

/// <summary>
/// マップチップの表示
/// </summary>
void MapLoad::DrawMap() {
	for (int x = 0; x < MAP_X; x++) {
		for (int y = 0; y < MAP_Y; y++) {
			if (map_[y][x] == 1) {
				Novice::DrawBox(x * MAP_SIZE, y * MAP_SIZE, MAP_SIZE, MAP_SIZE, 0.0f, WHITE, kFillModeSolid);
				Novice::DrawBox(x * MAP_SIZE, y * MAP_SIZE, MAP_SIZE, MAP_SIZE, 0.0f, RED, kFillModeWireFrame);
			}
		}
	}
}