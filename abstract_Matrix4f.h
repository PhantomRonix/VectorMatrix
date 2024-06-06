#pragma once

#include <iostream>
#include <array>
#include <string>

class mMatrix4f;

using namespace std;
//class for a 4x4 custom maths-centric Matrix
class abstract_Matrix4f
{
public:
	virtual const mMatrix4f toMatrix() = 0;
	virtual float at(const int& y, const int& x) = 0;

	//converts the matrix into an array
	virtual const array<float, 16>& toArray() = 0;
	virtual const array<array<float, 4>, 4>& toArray2D() = 0;
};

