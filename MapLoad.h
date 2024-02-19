#pragma once
#include <stdio.h>
const int MAP_SIZE_X = 50;
const int MAP_SIZE_Y = 27;
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

