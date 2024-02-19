#include "MapLoad.h"

MapLoad::MapLoad(const char *fname) {
	fname_ = fname;
	fp_ = 0;
	err_ = fopen_s(&fp_, fname_, "r");
	ret_ = 0;
	for (int x = 0; x < MAP_SIZE_X; x++) {
		for (int y = 0; y < MAP_SIZE_Y; y++) {
			map_[y][x] = 0;
		}
	}
}

void MapLoad::FileOpen() {
	if (err_ != 0) {
		printf("%sファイルが開けません\n", fname_);
	}
	else {
		while ((ret_ = fgetc(fp_)) != EOF) {
			putchar(ret_);
			Assignt();
		}
		putchar('\n');
		fclose(fp_);
	}
}

void MapLoad::Assignt() {
	for (int x = 0; x < 50; x++) {
		for (int y = 0; y < 27; y++) {
			if (ret_ == '1')
			{
				map_[y][x] = 1;
				break;
			}
			if (ret_ == '0')
			{
				map_[y][x] = 0;
				break;
			}
		}
	}
}