#pragma once
#ifndef GO_VECTORS_H
#define GO_VECTORS_H
#include "Core/Definitions.h"

namespace go
{

	template<class T>

	class Vec2
	{
	public:
		T x, y;

		Vec2() { this->x = 0; this->y = 0; }

		Vec2(T x, T y) { this->x = x; this->y = y; }

	};

	template<class T>

	class Vec3
	{
	public:
		T x, y, z;

		Vec3() { this->x = 0; this->y = 0;  this->z = 0; }

		Vec3(T x, T y, T z) { this->x = x; this->y = y; this->z = z; }

	};

	template<class T>

	class Vec4
	{
	public:
		T x, y, z, w;

		Vec4() { this->x = 0; this->y = 0;  this->z = 0; this->w = 0; }

		Vec4(T x, T y, T z, T w) { this->x = x; this->y = y; this->z = z; this->w = w; }

	};

	typedef Vec2<GOuint> Vec2ui;
	typedef Vec2<GOfloat> Vec2f;
	typedef Vec2<GOint> Vec2i;
	typedef Vec2<GOdouble> Vec2d;

	typedef Vec3<GOuint> Vec3ui;
	typedef Vec3<GOfloat> Vec3f;
	typedef Vec3<GOint> Vec3i;

	typedef Vec4<GOuint> Vec4ui;
	typedef Vec4<GOfloat> Vec4f;
	typedef Vec4<GOint> Vec4i;
}

#endif //GO_VECTORS_H
