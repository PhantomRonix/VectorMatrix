#pragma once
#include <iostream>
#include <array>
#include <string>

#include "abstract_mVector.h"
//#include "..\..\Matrices\4f\mMatrix4f.h"

using namespace std;
class mMatrix4f;
class mVector3f : abstract_mVector
{
public:
	//constructors
	mVector3f();
	//constructor from array
	mVector3f(array<float, 3> arr);
	mVector3f(mVector3f& copy);
	mVector3f(const mVector3f& copy);

	//operator overloads
	//Vector-on-vector operators

	const mVector3f operator+(const mVector3f& add);
	const mVector3f operator-(const mVector3f& sub);

	//Scalar operators

	const mVector3f operator*(const int& mult);
	//const mVector3f operator*(const int mult);
	const mVector3f operator*(const float& mult);
	//const mVector3f operator*(const float mult);
	//const mVector3f operator*(float mult);

	//multiply by matrix, automatically appends the w value
	const mVector3f operator*(mMatrix4f& mult);

	/*Vector3f& operator*=(const int& mult);
	Vector3f& operator*=(const float& mult);*/

	const mVector3f operator/(const int& div);
	const mVector3f operator/(const float& div);

	//other methods
	//returns magnitude
	const float mag();

	//Normalize vector's magnitude to 1, can pass float to set magnitude to the value entered
	void normalize(float nMag = 1.0f);

	//calculates Dot Product between two mVector3f objects
	const float dp(const mVector3f& in);

	//calculates Cross Product between two mVector3f objects
	const mVector3f cp(const mVector3f& in);

	//prints string of vector's elements
	const std::string output();
	//uses 0-2, any number out of range will throw an error
	float& at(const int& index);
	const array<float, 3>& toArray();
	virtual const vector<float>& toVector();



	////returns a 3-element colour vector
	//void toColor();

private:
	array <float, 3> _numContainer;
};