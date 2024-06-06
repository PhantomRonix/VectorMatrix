#include <iostream>
#include <array>
#include <string>

#include "mMatrix4f.h"
#include "tMatrix4f.h"

using namespace std;

tMatrix4f::tMatrix4f(float* scaleX, float* scaleY, float* scaleZ, float* rotRoll, float* rotPitch, float* rotYaw, float* posX, float* posY, float* posZ)
{
	_scaleX = scaleX;
	_scaleY = scaleY;
	_scaleZ = scaleZ;
	_rotRoll = rotRoll;
	_rotPitch = rotPitch;
	_rotYaw = rotYaw;
	_posX = posX;
	_posY = posY;
	_posZ = posZ;
}

tMatrix4f::tMatrix4f(array<float, 3> scale, array<float, 3> rot, array<float, 3> pos)
{
	_scaleX = &scale[0];
	_scaleY = &scale[1];
	_scaleZ = &scale[2];
	_rotRoll = &rot[0];
	_rotPitch = &rot[1];
	_rotYaw = &rot[2];
	_posX = &pos[0];
	_posY = &pos[1];
	_posZ = &pos[2];
}

tMatrix4f::tMatrix4f(mVector3f* scale, mVector3f* rot, mVector3f* pos)
{
	_scaleX = &scale->at(0);
	_scaleY = &scale->at(1);
	_scaleZ = &scale->at(2);
	_rotRoll = &rot->at(0);
	_rotPitch = &rot->at(1);
	_rotYaw = &rot->at(2);
	_posX = &pos->at(0);
	_posY = &pos->at(1);
	_posZ = &pos->at(2);
}


tMatrix4f::tMatrix4f(tMatrix4f& copy)
{
	_scaleX = copy._scaleX;
	_scaleY = copy._scaleY;
	_scaleZ = copy._scaleZ;
	_rotRoll = copy._rotRoll;
	_rotPitch = copy._rotPitch;
	_rotYaw = copy._rotYaw;
	_posX = copy._posX;
	_posY = copy._posY;
	_posZ = copy._posZ;
}

tMatrix4f::tMatrix4f(const tMatrix4f& copy)
{
	_scaleX = copy._scaleX;
	_scaleY = copy._scaleY;
	_scaleZ = copy._scaleZ;
	_rotRoll = copy._rotRoll;
	_rotPitch = copy._rotPitch;
	_rotYaw = copy._rotYaw;
	_posX = copy._posX;
	_posY = copy._posY;
	_posZ = copy._posZ;
}

const mMatrix4f tMatrix4f::getScaleMatrix()
{
	mMatrix4f output;
	return output.scale(*_scaleX, *_scaleY, *_scaleZ);
}

const mMatrix4f tMatrix4f::getRotationMatrix()
{
	mMatrix4f output;
	return output.rotationFromEuler(*_rotRoll, *_rotPitch, *_rotYaw);
}

const mMatrix4f tMatrix4f::getTranslationMatrix()
{
	mMatrix4f output;
	return output.transformation(*_posX, *_posY, *_posZ);
}


const mMatrix4f tMatrix4f::getCombinedMatrix()
{
	mMatrix4f output;
	mMatrix4f scale = getScaleMatrix();
	mMatrix4f rotation = getRotationMatrix();
	mMatrix4f translation = getTranslationMatrix();

	//cout << rotation.output() << endl;

	//translation must be transposed for reasons I don't bloody know
	//transposing rotation makes it spin in the other direction
	translation.transpose();
	rotation.transpose();

	output = translation;
	output = output * rotation;
	output = output * scale;

	//output.transpose();
	//cout << output.output() << endl;
	return output;
}

const array<float, 16> tMatrix4f::getScaleArray()
{
	mMatrix4f outputMatrix = getScaleMatrix();
	return outputMatrix.toArray();
}
const array<float, 16> tMatrix4f::getRotationArray()
{
	mMatrix4f outputMatrix = getRotationMatrix();
	return outputMatrix.toArray();
}
const array<float, 16> tMatrix4f::getTranslationArray()
{
	mMatrix4f outputMatrix = getTranslationMatrix();
	return outputMatrix.toArray();
}

const array<float, 16> tMatrix4f::getCombinedArray()
{
	mMatrix4f outputMatrix = getCombinedMatrix();
	return outputMatrix.toArray();
}
