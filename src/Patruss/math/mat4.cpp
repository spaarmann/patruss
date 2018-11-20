#include "mat4.h"

namespace math
{
	Mat4::Mat4(const Mat4& other)
	{
		for (auto i = 0; i < 16; ++i) values[i] = other.values[i];
	}

	Mat4& Mat4::operator=(const Mat4& other)
	{
		for (auto i = 0; i < 16; ++i) values[i] = other.values[i];
		return *this;
	}

	Mat4::Mat4(const Mat4&& other) noexcept
	{
		for (auto i = 0; i < 16; ++i) values[i] = other.values[i];
	}

	Mat4& Mat4::operator=(Mat4&& other) noexcept
	{
		for (auto i = 0; i < 16; ++i) values[i] = other.values[i];
		return *this;
	}

	float& Mat4::operator()(const int i, const int j)
	{
		return values[i + j * 4];
	}

	Mat4& Mat4::operator+=(const float scalar)
	{
		for (auto i = 0; i < 16; ++i) values[i] += scalar;
		return *this;
	}

	Mat4& Mat4::operator+=(const Mat4& other)
	{
		for (auto i = 0; i < 16; ++i) values[i] += other.values[i];
		return *this;
	}

	Mat4& Mat4::operator-=(const float scalar)
	{
		for (auto i = 0; i < 16; ++i) values[i] -= scalar;
		return *this;
	}

	Mat4& Mat4::operator-=(const Mat4& other)
	{
		for (auto i = 0; i < 16; ++i) values[i] -= other.values[i];
		return *this;
	}

	Mat4& Mat4::operator*=(const float scalar)
	{
		for (auto i = 0; i < 16; ++i) values[i] *= scalar;
		return *this;
	}

	Mat4& Mat4::operator*=(const Mat4& other)
	{
		// Store original values
		float ov[16];
		for (auto i = 0; i < 16; ++i) ov[i] = values[i];

		// Compute new values
		for (auto i = 0; i < 4; ++i)
		{
			for (auto j = 0; j < 4; ++j)
			{
				values[i + j * 4] = 0.0f;
				for (auto k = 0; k < 4; ++k)
				{
					values[i + j * 4] += ov[k + j * 4] * other.values[i + k * 4];
				}
			}
		}

		return *this;
	}

	Mat4 Mat4::identity()
	{
		Mat4 i;
		i(0, 0) = 1.0f;
		i(1, 1) = 1.0f;
		i(2, 2) = 1.0f;
		i(3, 3) = 1.0f;
		return i;
	}

	Mat4 Mat4::translation(const float x, const float y, const float z)
	{
		auto t = identity();
		t(3, 0) = x;
		t(3, 1) = y;
		t(3, 2) = z;
		return t;
	}

	Mat4 Mat4::translation(const Vector3& v)
	{
		return Mat4::translation(v.X, v.Y, v.Z);
	}

	Mat4 operator+(Mat4 lhs, const float rhs)
	{
		return lhs += rhs;
	}

	Mat4 operator+(Mat4 lhs, const Mat4& rhs)
	{
		return lhs += rhs;
	}

	Mat4 operator-(Mat4 lhs, float rhs)
	{
		return lhs -= rhs;
	}

	Mat4 operator-(Mat4 lhs, const Mat4& rhs)
	{
		return lhs -= rhs;
	}

	Mat4 operator*(Mat4 lhs, const float rhs)
	{
		return lhs *= rhs;
	}

	Mat4 operator*(const float lhs, Mat4 rhs)
	{
		return rhs *= lhs;
	}

	Mat4 operator*(Mat4 lhs, const Mat4& rhs)
	{
		return lhs *= rhs;
	}
}