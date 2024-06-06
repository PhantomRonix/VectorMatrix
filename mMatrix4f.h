#pragma once

#include <iostream>
#include <array>
#include <string>

#include "mVector3f.h"

using namespace std;
class mVector3f;
//class for a 4x4 custom maths-centric Matrix
class mMatrix4f
{
public:
	//constructors

	//default constructor
	mMatrix4f(float init = 0.0f, bool rowOrder = true);

	//copy constructor
	mMatrix4f(mMatrix4f& clonesrc);
	mMatrix4f(const mMatrix4f& clonesrc);

	//operator overloads

	const mMatrix4f operator+(mMatrix4f add);

	const mMatrix4f operator-(mMatrix4f sub);

	//matrix4 x matrix4 multiply overload
	const mMatrix4f operator*(mMatrix4f mult);

	//scalar multiply overloads

	const mMatrix4f operator*(int mult);
	const mMatrix4f operator*(float mult);

	//scalar division overloads

	const mMatrix4f operator/(int div);
	const mMatrix4f operator/(float div);

	//wHO CAME UP WITH COLUMN DOMINANT ORDER???????
	//*ahem* transposes the matrix so that it flips from row/column major order to the other
	void transpose();

	//calculates determinant of current matrix
	const float determinant();

	//calculates minor of current matrix
	const mMatrix4f minors();

	//calculates the determinant, from the remaining values not including the xy provided
	const float minordeterminant(const int& row, const int& column);

	const mMatrix4f cofactors();
	const mMatrix4f invert();

	//returns the dot product of two inputted arrays
	const static float dp(array<float, 4> vecA, array<float, 4> vecB);

	//static constructor thingy, returns identity matrix
	const static mMatrix4f identity();

	//constructs a new matrix, which can be used to translate things
	const static mMatrix4f transformation(float x, float y, float z);
	const static mMatrix4f transformation(mVector3f move);
	const static mMatrix4f transformation(array<float, 3> move);

	const static mMatrix4f scale(float x, float y, float z);
	const static mMatrix4f scale(mVector3f scale);
	const static mMatrix4f scale(array<float, 3> scale);


	//uses a quaternion based rotation matrix
	const static mMatrix4f rotation(float x, float y, float z, float w);
	//uses degrees, because f[language censored] radians, everyone hates radians >:(
	const static mMatrix4f rotationFromEuler(float roll, float pitch, float yaw);


	float& at(const int& y, const int& x);

	//returns a pointer to the rowOrder, so it can be manipulated
	bool& isRowOrder();

	const string output();
	const string outputline();

	//converts the matrix into an array
	const array<float, 16>& toArray();
	const array<array<float, 4>, 4>& toArray2D();

private:
	array<array<float, 4>, 4> _numContainer;

	//displays row order priority by default, but can be swapped
	bool _rowOrder;
};

