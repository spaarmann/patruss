#pragma once

#include "vector3.h"

namespace math
{
	class Mat4
	{

		/*
		 * From the outside, we treat matrices as being row-major,
		 * i.e. [i][j] means the j-th element of the i-th row.
		 *
		 * However, internally, we store it column-by-column,
		 * since that's what OpenGL uses and we save on a couple of
		 * transpose operations.
		 * In the function defintions of this class, we still use i
		 * as row index and j as column index though.
		 */

	private:
		float values[16]{};
	public:
		Mat4() = default;
		~Mat4() = default;

		Mat4(const Mat4& other);
		Mat4& operator=(const Mat4& other);

		Mat4(const Mat4&& other) noexcept;
		Mat4& operator=(Mat4&& other) noexcept;

		float& operator()(int i, int j);

		Mat4& operator+=(float scalar);
		Mat4& operator+=(const Mat4& other);
		Mat4& operator-=(float scalar);
		Mat4& operator-=(const Mat4& other);
		Mat4& operator*=(float scalar);
		Mat4& operator*=(const Mat4& other);

		static Mat4 identity();
		static Mat4 translation(float x, float y, float z);
		static Mat4 translation(const Vector3& v);
		//static Mat4 scale(float amt);
		//static Mat4 perspective(float near, float far)
		//static Mat4 orthographic();
	};

	Mat4 operator+(Mat4 lhs, float rhs);
	Mat4 operator+(Mat4 lhs, const Mat4& rhs);
	Mat4 operator-(Mat4 lhs, float rhs);
	Mat4 operator-(Mat4 lhs, const Mat4& rhs);
	Mat4 operator*(Mat4 lhs, float rhs);
	Mat4 operator*(float lhs, Mat4 rhs);
	Mat4 operator*(Mat4 lhs, const Mat4& rhs);
}