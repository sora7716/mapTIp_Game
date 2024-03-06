#pragma once

const char kWindowTitle[] = "学籍番号";
const float SCREEN_WIDTH  = 1280;
const float SCREEN_HEIGHT = 720;
const int KEYS_NUM = 256;

#pragma region マップチップ
const int MAP_X = 40;
const int MAP_Y = 23;
const int MAP_SIZE = 32;

typedef struct VectorInt {
	int x;
	int y;
}VectorInt;
#pragma endregion

#pragma region Vector2
class Vector2
{
private:
	float x_, y_;
public:
	/// <summary>
		///コンストラクター
		/// </summary>
		/// <param name="x"></param>
		/// <param name="y"></param>
	Vector2(float x, float y) {
		x_ = x;
		y_ = y;
	}

	/// <summary>
	///加算
	/// </summary>
	/// <param name="num"></param>
	/// <returns></returns>
	Vector2 operator+(const Vector2& num) {
		Vector2 result({ 0,0 });
		result.x_ = x_ + num.x_;
		result.y_ = y_ + num.y_;
		return result;
	}

	/// <summary>
	/// 減算
	/// </summary>
	/// <param name="num"></param>
	/// <returns></returns>
	Vector2 operator-(const Vector2& num) {
		Vector2 result({ 0,0 });
		result.x_ = x_ - num.x_;
		result.y_ = y_ - num.y_;
		return result;
	}

	/// <summary>
	/// +=での加算
	/// </summary>
	/// <param name="num"></param>
	/// <returns></returns>
	Vector2& operator+=(const Vector2& num) {
		x_ += num.x_;
		y_ += num.y_;
		return *this;
	}
};
#pragma endregion

#pragma region プレイヤー
typedef struct PlayerObject {
	Vector2 position;
	Vector2 velocity;
	float size;
	unsigned int color;
	bool isAlive;
}PlayerObject;
#pragma endregion