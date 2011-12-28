// compilation control #defines:
#if defined(_DEBUG) && !defined(DEBUG)
#define DEBUG
#endif

#ifdef DEBUG
#include "../exceptions/Exceptions.h"
#endif

template<typename StoredType>
inline StoredType operator * (const Vector3D<StoredType> &left , const Vector3D<StoredType> &right)				// operator * (dot product)
{
	return left.x*right.x + left.y*right.y + left.z*right.z;
} // end function operator * (dot product)


template<typename StoredType , typename ArgType>
inline Vector3D<StoredType> operator * (ArgType left , const Vector3D<StoredType> &right)						// operator * (scalar product)
{
	return Vector3D<StoredType>(left*right.x , left*right.y , left*right.z);
} // end function operator * (scalar product)


template<typename StoredType , typename ArgType>
inline Vector3D<StoredType> operator * (const Vector3D<StoredType> &left , ArgType right)						// operator * (scalar product)
{
	return Vector3D<StoredType>(left.x*right , left.y*right , left.z*right);
} // end function operator * (scalar product)


template<typename StoredType , typename ArgType>
inline Vector3D<StoredType> operator / (const Vector3D<StoredType> &left , ArgType right)						// operator / (division by scalar)
{
	return Vector3D<StoredType>(left.x/right , left.y/right , left.z/right);
} // end function operator / (division by scalar)


template<typename StoredType>
inline Vector3D<StoredType> operator % (const Vector3D<StoredType> &left , const Vector3D<StoredType> &right)	// operator % (cross product)
{
	return Vector3D<StoredType>(left.y*right.z - left.z*right.y , left.z*right.x - left.x*right.z , left.x*right.y - left.y*right.x);
} // end function operator % (cross product)


template<typename StoredType>
inline Vector3D<StoredType> operator + (const Vector3D<StoredType> &right)										// operator + (unary)
{
	return Vector3D<StoredType>(right);
} // end function operator + (unary)


template<typename StoredType>
inline Vector3D<StoredType> operator - (const Vector3D<StoredType> &right)										// operator - (unary)
{
	return Vector3D<StoredType>(-right.x , -right.y , -right.z);
} // end function operator - (unary)


template<typename StoredType>
inline Vector3D<StoredType> operator + (const Vector3D<StoredType> &left , const Vector3D<StoredType> &right)	// operator + (binary)
{
	return Vector3D<StoredType>(left.x+right.x , left.y+right.y , left.z+right.z);
} // end function operator + (binary)


template<typename StoredType>
inline Vector3D<StoredType> operator - (const Vector3D<StoredType> &left , const Vector3D<StoredType> &right)	// operator - (binary)
{
	return Vector3D<StoredType>(left.x-right.x , left.y-right.y , left.z-right.z);
} // end function operator - (binary)


template<typename StoredType>
inline Vector3D<StoredType> &operator += (Vector3D<StoredType> &left , const Vector3D<StoredType> &right)		// operator +=
{
	left.x += right.x;
	left.y += right.y;
	left.z += right.z;
	return left;
} // end function operator +=


template<typename StoredType>
inline Vector3D<StoredType> &operator -= (Vector3D<StoredType> &left , const Vector3D<StoredType> &right)		// operator -=
{
	left.x -= right.x;
	left.y -= right.y;
	left.z -= right.z;
	return left;
} // end function operator -=


template<typename StoredType , typename ArgType>
inline Vector3D<StoredType> &operator *= (Vector3D<StoredType> &left , ArgType right)							// operator *=
{
	left.x *= right;
	left.y *= right;
	left.z *= right;
	return left;
} // end function operator *=


template<typename StoredType , typename ArgType>
inline Vector3D<StoredType> &operator /= (Vector3D<StoredType> &left , ArgType right)							// operator /=
{
	left.x /= right;
	left.y /= right;
	left.z /= right;
	return left;
} // end function operator /=


template<typename StoredType>
inline StoredType operator ^ (const Vector3D<StoredType> &left , const Vector3D<StoredType> &right)				// operator ^ (the angle of the 2 vectors in rads)
{
	StoredType temp = left.norm();
	temp *= right.norm();
#ifdef DEBUG
	if(!temp) throw DivideByZeroException("An attempt was made to divide by zero in ","ASL","Vector3D::operator ^","This should be due to supplying the zero vector as an argument.");
#endif
	return std::acos((left*right)/temp);	// angle in [0,Pi]
} // end function operator ^ (the angle of the 2 vectors in rads)
