
#include <iostream>
#include <array>
#include <string>
#include <vector>
//#include <cmath>

#include "mVector3f.h"
#include "abstract_mVector.h"
#include "mMatrix4f.h"

//using namespace std;

//default constructor
mVector3f::mVector3f() { _numContainer = { 0.0f, 0.0f, 0.0f }; }

mVector3f::mVector3f(array<float, 3> arr) { _numContainer = arr; }

mVector3f::mVector3f(mVector3f& copy) { _numContainer = copy._numContainer; }
mVector3f::mVector3f(const mVector3f& copy) { _numContainer = copy._numContainer; }




//returns a new vector, with operation applied
const mVector3f mVector3f::operator+(const mVector3f& add)
{
	array<float, 3> outarray = { _numContainer[0] + add._numContainer[0], _numContainer[1] + add._numContainer[1], _numContainer[2] + add._numContainer[2] };
	mVector3f out(outarray);
	return out;
}

const mVector3f mVector3f::operator-(const mVector3f& sub)
{
	array<float, 3> outarray = { _numContainer[0] - sub._numContainer[0], _numContainer[1] - sub._numContainer[1], _numContainer[2] - sub._numContainer[2] };
	mVector3f out(outarray);
	return out;
}

const mVector3f mVector3f::operator*(const int& mult)
{
	array<float, 3> outarray = { _numContainer[0] * mult,_numContainer[1] * mult,_numContainer[2] * mult };
	mVector3f out(outarray);
	return out;
}
//const mVector3f mVector3f::operator*(const int mult)
//{
//	array<float, 3> outarray = { _numContainer[0] * mult,_numContainer[1] * mult,_numContainer[2] * mult };
//	mVector3f out(outarray);
//	return out;
//}

const mVector3f mVector3f::operator*(const float& mult)
{
	array<float, 3> outarray = { _numContainer[0] * mult,_numContainer[1] * mult,_numContainer[2] * mult };
	mVector3f out(outarray);
	return out;
}
//const mVector3f mVector3f::operator*(const float mult)
//{
//	array<float, 3> outarray = { _numContainer[0] * mult,_numContainer[1] * mult,_numContainer[2] * mult };
//	mVector3f out(outarray);
//	return out;
//
//}
//const mVector3f mVector3f::operator*(float mult)
//{
//	array<float, 3> outarray = { _numContainer[0] * mult,_numContainer[1] * mult,_numContainer[2] * mult };
//	mVector3f out(outarray);
//	return out;
//}

const mVector3f mVector3f::operator*(mMatrix4f& mult)
{
	array<float, 3> outarray =
	{
		_numContainer[0] * mult.at(0,0) + _numContainer[1] * mult.at(1,0) + _numContainer[2] * mult.at(2,0) + 1.0f * mult.at(3,0),
		_numContainer[0] * mult.at(0,1) + _numContainer[1] * mult.at(1,1) + _numContainer[2] * mult.at(2,1) + 1.0f * mult.at(3,1),
		_numContainer[0] * mult.at(0,2) + _numContainer[1] * mult.at(1,2) + _numContainer[2] * mult.at(2,2) + 1.0f * mult.at(3,2)
	};
	mVector3f out(outarray);
	return out;
}

const mVector3f mVector3f::operator/(const int& div)
{
	array<float, 3> outarray = { _numContainer[0] / div, _numContainer[1] / div, _numContainer[2] / div };
	mVector3f out(outarray);
	return out;
}

const mVector3f mVector3f::operator/(const float& div)
{
	array<float, 3> outarray = { _numContainer[0] / div, _numContainer[1] / div, _numContainer[2] / div };
	mVector3f out(outarray);
	return out;
}

//returns magnitude of vector
const float mVector3f::mag()
{
	return sqrt(pow(_numContainer[0], 2) + pow(_numContainer[1], 2) + pow(_numContainer[2], 2));
}


void mVector3f::normalize(float nMag)
{
	float mult = sqrt(pow(_numContainer[0], 2) + pow(_numContainer[1], 2) + pow(_numContainer[2], 2)) / nMag;
	_numContainer[0] /= mult;
	_numContainer[1] /= mult;
	_numContainer[2] /= mult;
	return;
}

const float mVector3f::dp(const mVector3f& in)
{
	float output = 0.0f;
	output += _numContainer[0] * in._numContainer[0];
	output += _numContainer[1] * in._numContainer[1];
	output += _numContainer[2] * in._numContainer[2];
	return output;
}

const mVector3f mVector3f::cp(const mVector3f& in)
{
	array<float, 3> outArr = { 0,0,0 };
	outArr[0] = _numContainer[1] * in._numContainer[2] - _numContainer[2] * in._numContainer[1];
	outArr[1] = _numContainer[2] * in._numContainer[0] - _numContainer[0] * in._numContainer[2];
	outArr[2] = _numContainer[0] * in._numContainer[1] - _numContainer[1] * in._numContainer[0];
	return mVector3f(outArr);
}

const std::string mVector3f::output()
{
	string out = "Maths Vector 3f: ";
	for (int i = 0; i < _numContainer.size(); i++)
	{
		out += to_string(_numContainer.at(i));
		out += " ";
	}
	return out;
}

float& mVector3f::at(const int& index)
{
	if (index >= _numContainer.size() || index < 0) { throw "out of index, bro"; }
	else
	{
		return _numContainer.at(index);
	}
}

const array<float, 3>& mVector3f::toArray()
{
	array<float, 3> output;
	output.fill(0.0f);
	for (int i = 0;i < _numContainer.size();i++)
	{
		output[i] = _numContainer[i];
	}
	return output;
}

const vector<float>& mVector3f::toVector()
{
	vector<float> output;
	output.push_back(_numContainer[0]);
	output.push_back(_numContainer[1]);
	output.push_back(_numContainer[2]);
	return output;
}