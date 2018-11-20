#pragma once
namespace math {
	class Vector3
	{
	public:
		float X;
		float Y;
		float Z;

		Vector3();
		Vector3(float x, float y, float z);
		Vector3(const Vector3&  other) = default;
		Vector3(Vector3&& other) = default;

		~Vector3() = default;

		Vector3& operator=(const Vector3& other) = default;
		Vector3& operator=(Vector3&& other) = default;

		Vector3& operator+=(const Vector3& rhs);
		Vector3& operator+=(float rhs);
		Vector3& operator-=(const Vector3& rhs);
		Vector3& operator-=(float rhs);
		Vector3& operator*=(float rhs);
		Vector3& operator/=(float rhs);

		float Dot(const Vector3& other) const;
		Vector3 Cross(const Vector3& other) const;

		float Magnitude() const;
		float SquareMagnitude() const;
		float Distance(const Vector3& other) const;
		Vector3 Normalized() const;
	};

	Vector3 operator+(Vector3 lhs, const Vector3& rhs);
	Vector3 operator+(Vector3 lhs, float rhs);
	Vector3 operator-(Vector3 lhs, const Vector3& rhs);
	Vector3 operator-(Vector3 lhs, float rhs);
	Vector3 operator*(Vector3 lhs, float rhs);
	Vector3 operator/(Vector3 lhs, float rhs);
}
