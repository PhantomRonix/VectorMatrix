#include <iostream>
#include <array>
#include <string>

#include "camviewMatrix4f.h"
#include "mMatrix4f.h"
#include "mVector3f.h"

using namespace std;

camviewMatrix4f::camviewMatrix4f(mVector3f* position, mVector3f* target, mVector3f* worldup)
{
	_pos = position;
	_target = target;
	_worldUp = worldup;
}

const mMatrix4f camviewMatrix4f::translationMatrix()
{
	mMatrix4f output;
	output = output.transformation(((*_pos) * -1));
	output.transpose();
	//cout << output.output() << endl;

	return output;
}

const mMatrix4f camviewMatrix4f::alignmentMatrix()
{
	mVector3f front;
	mVector3f right;
	mVector3f up;
	mMatrix4f output(0.0f);
	//cout << _target->output() << endl;
	//cout << _worldUp->output() << endl;
	front = (*_target) - (*_pos);
	front.normalize();

	right = front.cp(*_worldUp);
	right.normalize();

	up = right.cp(front);
	up.normalize();

	//cout << front.output() << endl;
	//cout << right.output() << endl;
	//cout << up.output() << endl;

	for (int i = 0;i < 3;i++)
	{
		output.at(i, 0) = right.at(i);
		output.at(i, 1) = up.at(i);
		output.at(i, 2) = -front.at(i);
	}

	output.at(3, 3) = 1.0f;
	output.transpose();
	//cout << output.output() << endl;
	return output;
}

const mMatrix4f camviewMatrix4f::calculate()
{
	mMatrix4f output;
	mMatrix4f tMatrix;
	mMatrix4f aMatrix;

	tMatrix = translationMatrix();
	aMatrix = alignmentMatrix();

	//tMatrix.transpose();
	//aMatrix.transpose();

	//cout << tMatrix.output() << endl;
	//cout << aMatrix.output() << endl;

	output = aMatrix * tMatrix;
	//output.transpose();

	//cout << output.output() << endl;

	return output;
}

const array<float, 16> camviewMatrix4f::toArray()
{
	mMatrix4f output;
	output = calculate();
	return output.toArray();
}