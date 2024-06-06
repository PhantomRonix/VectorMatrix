#pragma once
#include <iostream>
#include <array>
#include <string>

#include "abstract_mVector.h"

using namespace std;
class mMatrix4f;
class mVector4f : abstract_mVector
{
public:
	//constructors
	mVector4f();
	//constructor from array
	mVector4f(array<float, 4> arr);

	//operator overloads
	//Vector-on-vector operators

	const mVector4f operator+(const mVector4f& add);
	const mVector4f operator-(const mVector4f& sub);

	//Scalar operators

	const mVector4f operator*(const int& mult);
	const mVector4f operator*(const float& mult);

	//multiply by matrix, automatically appends the w value
	const mVector4f operator*(mMatrix4f& mult);

	/*Vector3f& operator*=(const int& mult);
	Vector3f& operator*=(const float& mult);*/

	const mVector4f operator/(const int& div);
	const mVector4f operator/(const float& div);

	//other methods
	//returns magnitude
	const float mag();

	//Normalize vector's magnitude to 1, can pass float to set magnitude to the value entered
	void normalize(float nMag = 1.0f);

	//calculates Dot Product between two mVector4f objects
	const float dp(const mVector4f& in);

	//prints string of vector's elements
	const std::string output();

	//uses 0-3, any number out of range will throw an error
	float& at(const int& index);

	const array<float, 4>& toArray();
	const vector<float>& toVector();

private:
	array <float, 4> _numContainer;
};