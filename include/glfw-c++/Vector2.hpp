#pragma once

namespace glfw
{
	template<typename T>
	class Vector2
	{
	public:
		T x;
		T y;

		Vector2<T> operator+(const Vector2<T> &right){return Vector2<T>(x+right.x, y+right.y);}
		Vector2<T> operator+(const T right){return Vector2<T>(x+right, y+right);}
		Vector2<T> operator+=(const Vector2<T> &right){x += right.x; y += right.y;}
		Vector2<T> operator+=(const T right){x += right; y += right;}

		Vector2<T> operator-(const Vector2<T> &right){return Vector2<T>(x-right.x, y-right.y);}
		Vector2<T> operator-(const T right){return Vector2<T>(x-right, y-right);}
		Vector2<T> operator-=(const Vector2<T> &right){x -= right.x; y -= right.y;}
		Vector2<T> operator-=(const T right){x -= right; y -= right;}

		Vector2<T> operator*(const Vector2<T> &right){return Vector2<T>(x*right.x, y*right.y);}
		Vector2<T> operator*(const T right){return Vector2<T>(x*right, y*right);}
		Vector2<T> operator*=(const Vector2<T> &right){x *= right.x; y *= right.y;}
		Vector2<T> operator*=(const T right){x *= right; y *= right;}

		Vector2<T> operator/(const Vector2<T> &right){return Vector2<T>(x/right.x, y/right.y);}
		Vector2<T> operator/(const T right){return Vector2<T>(x/right, y/right);}
		Vector2<T> operator/=(const Vector2<T> &right){x /= right.x; y /= right.y;}
		Vector2<T> operator/=(const T right){x /= right; y /= right;}

		Vector2<T>(): x{0}, y{0} {}
		Vector2<T>(T x_, T y_): x{x_}, y{y_} {}
	};

	using MousePos = Vector2<double>;
	using WindowSize = Vector2<int>;
	using WindowPos = Vector2<int>;
	using MonitorSize = Vector2<int>;
	using MonitorPos = Vector2<int>;
}
