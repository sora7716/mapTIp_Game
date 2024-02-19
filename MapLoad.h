#pragma once
#include <Novice.h>
#include <stdio.h>
#include "Struct.h"
class MapLoad
{
private:
	const char *fname_;
	FILE* fp_;
	errno_t err_;
	int ret_;
	int map_[MAP_SIZE_Y][MAP_SIZE_X];
public:
	MapLoad(const char *fname);
	void FileOpen();
	void Assignt();
};

