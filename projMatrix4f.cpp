#include <iostream>
#include <array>
#include <string>

#include "projMatrix4f.h"
#include "mMatrix4f.h"
#include "tMatrix4f.h"

using namespace std;

projMatrix4f::projMatrix4f(float* near, float* far, float* right, float* left, float* top, float* bottom, float* fov, float* aspect)
{
	_near = near;
	_far = far;
	_right = right;
	_left = left;
	_top = top;
	_bottom = bottom;
	_fov = fov;
	_aspect = aspect;
}

const mMatrix4f projMatrix4f::calculate_ortho()
{
	mMatrix4f output(0.0f);
	output.at(0, 0) = (2 / ((*_right) - (*_left)));
	output.at(1, 1) = (2 / ((*_top) - (*_bottom)));
	output.at(2, 2) = (2 / ((*_near) - (*_far)));

	output.at(3, 3) = 1.0f;

	output.at(3, 0) = -(((*_right) + (*_left)) / ((*_right) - (*_left)));
	output.at(3, 1) = -(((*_top) + (*_bottom)) / ((*_top) - (*_bottom)));
	output.at(3, 2) = (((*_near) + (*_far)) / ((*_near) - (*_far)));

	//mMatrix4f translation;
	//translation = translation.identity();
	//translation.at(3, 0) = -((*_right + *_left) / 2);
	//translation.at(3, 1) = -((*_top + *_bottom) / 2);
	//translation.at(3, 2) = -((*_near + *_far) / 2);

	//mMatrix4f scaling;
	//scaling = scaling.scale((2 / ((*_right) - (*_left))), (2 / ((*_top) - (*_bottom))), (2 / ((*_near) - (*_far))));
	//mMatrix4f output;

	//translation.transpose();
	//scaling.transpose();

	//cout << translation.output() << endl;
	//cout << scaling.output() << endl;

	//output = translation * scaling;

	output.transpose();
	//cout << output.output() << endl;
	return output;
}

const mMatrix4f projMatrix4f::calculate_persp()
{
	float top = (*_near) * tan((*_fov) / 2);
	float right = (*_aspect) * top;
	mMatrix4f output(0.0f);
	output.at(0, 0) = (*_near) / right;
	output.at(1, 1) = (*_near) / top;
	output.at(2, 2) = -((*_far + *_near) / (*_far - *_near));
	output.at(2, 3) = -1.0f;
	output.at(3, 2) = -((2 * (*_far) * (*_near)) / (*_far - *_near));
	output.transpose();
	return output;
}

const array<float, 16> projMatrix4f::orthoToArray()
{
	mMatrix4f output;
	output = calculate_ortho();
	return output.toArray();
}

const array<float, 16> projMatrix4f::perspToArray()
{
	mMatrix4f output;
	output = calculate_persp();
	return output.toArray();
}

const array<array<float, 4>, 4> projMatrix4f::orthoToArray2D()
{
	mMatrix4f output;
	output = calculate_ortho();
	return output.toArray2D();
}

const array<array<float, 4>, 4> projMatrix4f::perspToArray2D()
{
	mMatrix4f output;
	output = calculate_persp();
	return output.toArray2D();
}

