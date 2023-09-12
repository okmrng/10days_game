#pragma once

#include <Vector2.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <stdint.h>

/// <summary>
/// easeOutCirc
/// </summary>
/// <param name="startPoint">始点</param>
/// <param name="endPoint">終点</param>
/// <param name="t">フレーム</param>
float EaseOutCirc(float startPoint, float endPoint, float t);

/// <summary>
/// フェードイン
/// </summary>
/// <param name="alpha">現在の透明度</param>
/// <param name="addAlpha">足していく透明度</param>
/// <param name="maxAlpha">どこまでフェードインするか</param>
/// <returns></returns>
uint32_t FadeIn(uint32_t alpha, uint32_t addAlpha, uint32_t maxAlpha);

// 演算子オーバーロード
Vector2& operator+=(Vector2& v, float s);
const Vector2 operator+(const Vector2& v, float s);

Vector2& operator-=(Vector2& v, float s);
const Vector2 operator-(const Vector2& v, float s);

Vector2& operator/=(Vector2& v, float s);
const Vector2 operator/(const Vector2& v, float s);

Vector2& operator+=(Vector2& v1, const Vector2& v2);
const Vector2 operator+(const Vector2& v1, const Vector2& v2);
