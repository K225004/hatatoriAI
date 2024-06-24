#pragma once
#include <DxLib.h>
#include <math.h>

namespace DxLib {
	inline float DegToRad(float deg) { return deg * DX_PI_F / 180.0f; };
	inline double DegToRad(double deg) { return deg * DX_PI / 180.0; };
	inline float RadToDeg(float rad) { return rad * 180.0f / DX_PI_F; };
	inline double RadToDeg(double rad) { return rad * 180.0 / DX_PI; };

	inline VECTOR VGet(VECTOR_D v) { return VGet((float)v.x, (float)v.y, (float)v.z); }
	inline VECTOR_D VGetD(VECTOR v) { return VGetD((double)v.x, (double)v.y, (double)v.z); }

	inline const VECTOR operator +(const VECTOR& v1, const VECTOR& v2) { return VAdd(v1, v2); }
	inline const VECTOR_D operator +(const VECTOR_D& v1, const VECTOR_D& v2) { return VAddD(v1, v2); }

	inline VECTOR& operator +=(VECTOR& v1, const VECTOR& v2) { return v1 = VAdd(v1, v2); }
	inline VECTOR_D& operator +=(VECTOR_D& v1, const VECTOR_D& v2) { return v1 = VAddD(v1, v2); }

	inline const VECTOR operator -(const VECTOR& v1, const VECTOR& v2) { return VSub(v1, v2); }
	inline const VECTOR_D operator -(const VECTOR_D& v1, const VECTOR_D& v2) { return VSubD(v1, v2); }

	inline VECTOR& operator -=(VECTOR& v1, const VECTOR& v2) { return v1 = VSub(v1, v2); }
	inline VECTOR_D& operator -=(VECTOR_D& v1, const VECTOR_D& v2) { return v1 = VSubD(v1, v2); }

	inline const VECTOR operator *(const VECTOR& v1, const float& scale) { return VScale(v1, scale); }
	inline const VECTOR_D operator *(const VECTOR_D& v1, const double& scale) { return VScaleD(v1, scale); }

	inline const VECTOR operator *(const float& scale, const VECTOR& v1) { return VScale(v1, scale); }
	inline const VECTOR_D operator *(const double& scale, const VECTOR_D& v1) { return VScaleD(v1, scale); }

	inline const VECTOR operator /(const VECTOR& v1, const float& scale) { return VScale(v1, 1.0f / scale); }
	inline const VECTOR_D operator /(const VECTOR_D& v1, const double& scale) { return VScaleD(v1, 1.0 / scale); }

	inline VECTOR& operator *=(VECTOR& v1, const float& scale) { return v1 = VScale(v1, scale); }
	inline VECTOR_D& operator *=(VECTOR_D& v1, const double& scale) { return v1 = VScaleD(v1, scale); }

	inline VECTOR& operator *=(const float& scale, VECTOR& v1) { return v1 = VScale(v1, scale); }
	inline VECTOR_D& operator *=(const double& scale, VECTOR_D& v1) { return v1 = VScaleD(v1, scale); }

	inline VECTOR& operator /=(VECTOR& v1, const float& scale) { return v1 = VScale(v1, 1.0f / scale); }
	inline VECTOR_D& operator /=(VECTOR_D& v1, const double& scale) { return v1 = VScaleD(v1, 1.0 / scale); }

	inline const MATRIX operator +(const MATRIX& m1, const MATRIX& m2) { return MAdd(m1, m2); }
	inline const MATRIX_D operator +(const MATRIX_D& m1, const MATRIX_D& m2) { return MAddD(m1, m2); }

	inline MATRIX& operator +=(MATRIX& m1, const MATRIX& m2) { return m1 = MAdd(m1, m2); }
	inline MATRIX_D& operator +=(MATRIX_D& m1, const MATRIX_D& m2) { return m1 = MAddD(m1, m2); }

	inline const MATRIX operator *(const MATRIX& m1, const MATRIX& m2) { return MMult(m1, m2); }
	inline const MATRIX_D operator *(const MATRIX_D& m1, const MATRIX_D& m2) { return MMultD(m1, m2); }

	inline MATRIX& operator *=(MATRIX& m1, const MATRIX& m2) { return m1 = MMult(m1, m2); }
	inline MATRIX_D& operator *=(MATRIX_D& m1, const MATRIX_D& m2) { return m1 = MMultD(m1, m2); }

	inline const VECTOR operator *(const VECTOR& v, const MATRIX& m1) { return VTransform(v, m1); }
	inline const VECTOR_D operator *(const VECTOR_D& v, const MATRIX_D& m1) { return VTransformD(v, m1); }

	inline VECTOR& operator *=(VECTOR& v, const MATRIX& m1) { return v = VTransform(v, m1); }
	inline VECTOR_D& operator *=(VECTOR_D& v, const MATRIX_D& m1) { return v = VTransformD(v, m1); }

	struct Vector2 {
		float x = 0.0f;
		float y = 0.0f;
		Vector2() { x = 0.0f, y = 0.0f; }
		Vector2(float _x, float _y) { x = _x, y = _y; }
	};

	inline Vector2 V2Get(float _x, float _y) {
		Vector2 v;
		v.x = _x;
		v.y = _y;
		return v;
	}

	inline Vector2 V2Get(int x, int y) {
		return V2Get((float)x, (float)y);
	}

	inline Vector2 V2Add(Vector2 v1, Vector2 v2) {
		return V2Get(v1.x + v2.x, v1.y + v2.y);
	}

	inline Vector2 V2Sub(Vector2 v1, Vector2 v2) {
		return V2Get(v1.x - v2.x, v1.y - v2.y);
	}

	inline Vector2 V2Scale(Vector2 v, float scale) {
		return V2Get(v.x * scale, v.y * scale);
	}

	inline float V2Size(Vector2 v) {
		return sqrtf(v.x * v.x + v.y * v.y);
	}

	inline Vector2 V2Norm(Vector2 v) {
		float size = V2Size(v);
		v.x = v.x / size;
		v.y = v.y / size;
		return v;
	}


	inline const Vector2 operator +(const Vector2& v1, const Vector2& v2) { return V2Add(v1, v2); }
	inline Vector2& operator +=(Vector2& v1, const Vector2& v2) { return v1 = V2Add(v1, v2); }

	inline const Vector2 operator -(const Vector2& v1, const Vector2& v2) { return V2Sub(v1, v2); }
	inline Vector2& operator -=(Vector2& v1, const Vector2& v2) { return v1 = V2Sub(v1, v2); }

	inline const Vector2 operator *(const Vector2& v, const float& scale) { return V2Scale(v, scale); }

	inline const Vector2 operator *(const float& scale, const Vector2& v) { return V2Scale(v, scale); }

	inline const Vector2 operator /(const Vector2& v, const float& scale) { return V2Scale(v, 1.0f / scale); }

	inline Vector2& operator *=(Vector2& v, const float& scale) { return v = V2Scale(v, scale); }

	inline Vector2& operator *=(const float& scale, Vector2& v) { return v = V2Scale(v, scale); }

	inline Vector2& operator /=(Vector2& v, const float& scale) { return v = V2Scale(v, 1.0f / scale); }

	inline int GetRandom(int max, int min = 0) {
		return min + GetRand(abs(max - min));
	}
};