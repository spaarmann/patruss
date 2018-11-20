#include "vector3.h"

#include "fmath.h"

namespace math {
	Vector3::Vector3() : X(0.0), Y(0.0), Z(0.0) { }
	Vector3::Vector3(const float x, const float y, const float z) : X(x), Y(y), Z(z) { }

	Vector3& Vector3::operator+=(const Vector3& rhs)
	{
		X += rhs.X;
		Y += rhs.Y;
		Z += rhs.Z;
		return *this;
	}

	Vector3& Vector3::operator+=(const float rhs)
	{
		X += rhs;
		Y += rhs;
		Z += rhs;
		return *this;
	}

	Vector3& Vector3::operator-=(const Vector3& rhs)
	{
		X -= rhs.X;
		Y -= rhs.Y;
		Z -= rhs.Z;
		return *this;
	}

	Vector3& Vector3::operator-=(const float rhs)
	{
		X -= rhs;
		Y -= rhs;
		Z -= rhs;
		return *this;
	}

	Vector3& Vector3::operator*=(const float rhs)
	{
		X *= rhs;
		Y *= rhs;
		Z *= rhs;
		return *this;
	}

	Vector3& Vector3::operator/=(const float rhs)
	{
		X /= rhs;
		Y /= rhs;
		Z /= rhs;
		return *this;
	}

	float Vector3::Dot(const Vector3& other) const
	{
		return X * other.X + Y * other.Y + Z * other.Z;
	}

	Vector3 Vector3::Cross(const Vector3& other) const
	{
		return {
			Y * other.Z - Z * other.Y,
			Z * other.X - X * other.Z,
			X * other.Y - Y * other.X
		};
	}


	float Vector3::Magnitude() const
	{
		return sqrt(X * X + Y * Y + Z * Z);
	}

	float Vector3::SquareMagnitude() const
	{
		return X * X + Y * Y + Z * Z;
	}

	float Vector3::Distance(const Vector3& other) const
	{
		return (*this - other).Magnitude();
	}

	class Vector3 Vector3::Normalized() const
	{
		const auto magnitude = Magnitude();
		return {
			X / magnitude,
			Y / magnitude,
			Z / magnitude
		};
	}



	Vector3 operator+(Vector3 lhs, const Vector3& rhs)
	{
		return lhs += rhs;
	}

	Vector3 operator+(Vector3 lhs, const float rhs)
	{
		return lhs += rhs;
	}

	Vector3 operator-(Vector3 lhs, const Vector3& rhs)
	{
		return lhs -= rhs;
	}

	Vector3 operator-(Vector3 lhs, const float rhs)
	{
		return lhs -= rhs;
	}

	Vector3 operator*(Vector3 lhs, const float rhs)
	{
		return lhs *= rhs;
	}

	Vector3 operator/(Vector3 lhs, const float rhs)
	{
		return lhs /= rhs;
	}
}
