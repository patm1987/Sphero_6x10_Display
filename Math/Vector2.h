
#ifndef _VECTOR2_H
#define _VECTOR2_H

#include <cstdint>

class Vector2
{
public:
	Vector2(float x, float y);
	Vector2(const Vector2& org);
	Vector2();

	// public - for now
	union
	{
		struct {float m_x, m_y;};
		float m_aData[2];
	};
};

inline Vector2::Vector2(float x, float y) : m_x(x), m_y(y) {}
inline Vector2::Vector2(const Vector2& org) : m_x(org.m_x), m_y(org.m_y) {}
inline Vector2::Vector2() : m_x(0.f), m_y(0.f) {}

#endif//_VECTOR2_H
