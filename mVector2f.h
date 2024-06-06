#pragma once
#include <iostream>
#include <array>
#include <string>

#include "abstract_mVector.h"
#include "mMatrix4f.h"

using namespace std;
class mMatrix4f;
class mVector2f : abstract_mVector
{
public:
	//constructors
	mVector2f();
	//constructor from array
	mVector2f(array<float, 2> arr);

	//operator overloads
	//Vector-on-vector operators

	const mVector2f operator+(const mVector2f& add);
	const mVector2f operator-(const mVector2f& sub);

	//Scalar operators

	const mVector2f operator*(const int& mult);
	const mVector2f operator*(const float& mult);

	/*Vector3f& operator*=(const int& mult);
	Vector3f& operator*=(const float& mult);*/

	const mVector2f operator/(const int& div);
	const mVector2f operator/(const float& div);

	//other methods
	//returns magnitude
	const float mag();

	//Normalize vector's magnitude to 1, can pass float to set magnitude to the value entered
	void normalize(float nMag = 1.0f);

	//calculates Dot Product between two mVector2f objects
	const float dp(const mVector2f& in);

	//prints string of vector's elements
	const std::string output();

	//uses 0-2, any number out of range will throw an error
	float& at(const int& index);

	const array<float, 2>& toArray();
	const vector<float>& toVector();

private:
	array <float, 2> _numContainer;
};