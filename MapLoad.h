#pragma once
#include <Novice.h>
#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"
class MapLoad
{
private:
	const char *fname_;
	FILE* fp_;
	errno_t err_;
	int ret_;
	int map_[MAP_Y][MAP_X];
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	/// <param name="fname"></param>
	MapLoad(const char *fname);

	/// <summary>
	/// ファイルがエラーを起こしていないか
	/// </summary>
	void FileOpen(char* keys, char* preKeys);

	/// <summary>
	/// ファイルにある値の代入
	/// </summary>
	void Assign();

	/// <summary>
	/// マップチップの表示
	/// </summary>
	void DrawMap();
};

