#pragma once

#include <iostream>
#include <array>
#include <string>

#include "mMatrix4f.h"

using namespace std;

//ortho projection matrix
//call constructor as: near,far,right,left,top,bottom
class projMatrix4f
{
public:
	projMatrix4f(float* near, float* far, float* right, float* left, float* top, float* bottom, float* fov, float* aspect);

	const mMatrix4f calculate_ortho();
	const mMatrix4f calculate_persp();
	const array<float, 16> orthoToArray();
	const array<float, 16> perspToArray();

	const array<array<float, 4>, 4> orthoToArray2D();
	const array<array<float, 4>, 4> perspToArray2D();

	//used for both projections
	float* _near; float* _far;

	//used only for orthographic projection
	float* _right; float* _left; float* _top; float* _bottom;

	//used only in perspective projection
	float* _fov; float* _aspect;
};
