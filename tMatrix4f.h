#pragma once

#include <iostream>
#include <array>
#include <string>

#include "mVector3f.h"
#include "mMatrix4f.h"
using namespace std;

//Stores a values needed to calculate all model matrices (scale, rotation, translation), for ease of opengl implementation
class tMatrix4f
{
public:
	tMatrix4f(float* _scaleX, float* _scaleY, float* _scaleZ, float* _rotRoll, float* _rotPitch, float* _rotYaw, float* _posX, float* _posY, float* _posZ);
	tMatrix4f(array<float, 3> scale, array<float, 3> rot, array<float, 3> pos);
	tMatrix4f(mVector3f* scale, mVector3f* rot, mVector3f* pos);
	tMatrix4f(tMatrix4f& copy);
	tMatrix4f(const tMatrix4f& copy);

	const mMatrix4f getScaleMatrix();
	const mMatrix4f getRotationMatrix();
	const mMatrix4f getTranslationMatrix();
	const mMatrix4f getCombinedMatrix();

	const array<float, 16> getScaleArray();
	const array<float, 16> getRotationArray();
	const array<float, 16> getTranslationArray();
	const array<float, 16> getCombinedArray();

	//mMatrix4f _scale;
	float* _scaleX;float* _scaleY;float* _scaleZ;

	//mMatrix4f _rotation;
	float* _rotRoll;float* _rotPitch;float* _rotYaw;

	//mMatrix4f _translation;
	float* _posX;float* _posY;float* _posZ;
};
