#include "MathUtility.h"

float EaseOutCirc(float startPoint, float endPoint, float t) {
	float easedT = sqrt(1.0f - pow(t - 1.0f, 2.0f));

	float pos = (float)(1.0 - easedT) * startPoint + easedT * endPoint;

	return pos;
}

uint32_t FadeIn(uint32_t alpha, uint32_t addAlpha, uint32_t maxAlpha)
{
	if (alpha <= maxAlpha) {
		alpha +=addAlpha;
	}
	if (alpha >= maxAlpha) {
		alpha = maxAlpha;
	}

	return alpha;
}

Vector2& operator+=(Vector2& v, float s) {
	v.x += s;
	v.y += s;

	return v;
}

const Vector2 operator+(const Vector2& v, float s) {
	Vector2 temp(v);
	return temp += s;
}
Vector2& operator-=(Vector2& v, float s) {
	v.x -= s;
	v.y -= s;

	return v;
}

const Vector2 operator-(const Vector2& v, float s) {
	Vector2 temp(v);
	return temp -= s;
}

Vector2& operator/=(Vector2& v, float s) {
	v.x /= s;
	v.y /= s;

	return v;
}

const Vector2 operator/(const Vector2& v, float s) {
	Vector2 temp(v);
	return temp /= s;
}

Vector2& operator+=(Vector2& v1, const Vector2& v2) {
	v1.x += v2.x;
	v1.y += v2.y;

	return v1;
}

const Vector2 operator+(const Vector2& v1, const Vector2& v2) {
	Vector2 result = v1;
	return result += v2;
}