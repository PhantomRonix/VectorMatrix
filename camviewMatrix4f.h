#pragma once

#include <iostream>
#include <array>
#include <string>

//#include "mMatrix4f.h"
#include "mVector3f.h"

using namespace std;

//class mVector3f;
class mMatrix4f;

//stores 3 vectors (pos,target,up) to calculate the camera related matrices
class camviewMatrix4f
{
public:
	camviewMatrix4f(mVector3f* position, mVector3f* target, mVector3f* worldup);

	const mMatrix4f translationMatrix();
	const mMatrix4f alignmentMatrix();

	const mMatrix4f calculate();
	const array<float, 16> toArray();
	//const array<array<float, 4>, 4> toArray2D();

	//stores camera position
	mVector3f* _pos;

	//stores camera target
	mVector3f* _target;

	//stores world up
	mVector3f* _worldUp;
};
