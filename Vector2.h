#pragma once
struct Vector2 {
	Vector2() : x(0), y(0) {}
	Vector2(float xP, float yP) : x(xP), y(yP) {}

	float x;
	float y;

	Vector2& operator += (const Vector2& right) {
		x += right.x;
		y += right.y;
		return *this;
	}

	friend Vector2 operator + (const Vector2& left, const Vector2& right) {
		return Vector2(left.x + right.x, left.y + right.y);
	}

	friend Vector2 operator - (const Vector2& left, const Vector2& right) {
		return Vector2(left.x - right.x, left.y - right.y);
	}

	friend Vector2 operator * (const Vector2& vec, float scalar) {
		return Vector2(vec.x * scalar, vec.y * scalar);
	}

	static const Vector2 zero;
};