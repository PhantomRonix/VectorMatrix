
#include <iostream>
#include <array>
#include <string>
//#include <cmath>

#include "mVector4f.h"
#include "abstract_mVector.h"
#include "mMatrix4f.h"

using namespace std;

//default constructor
mVector4f::mVector4f() { _numContainer = { 0.0f, 0.0f, 0.0f }; }

mVector4f::mVector4f(array<float, 4> arr) { _numContainer = arr; }


//returns a new vector, with operation applied
const mVector4f mVector4f::operator+(const mVector4f& add)
{
	array<float, 4> outarray = { _numContainer[0] + add._numContainer[0], _numContainer[1] + add._numContainer[1], _numContainer[2] + add._numContainer[2], _numContainer[3] + add._numContainer[3] };
	mVector4f out(outarray);
	return out;
}

const mVector4f mVector4f::operator-(const mVector4f& sub)
{
	array<float, 4> outarray = { _numContainer[0] - sub._numContainer[0], _numContainer[1] - sub._numContainer[1], _numContainer[2] - sub._numContainer[2], _numContainer[3] - sub._numContainer[3] };
	mVector4f out(outarray);
	return out;
}

const mVector4f mVector4f::operator*(const int& mult)
{
	array<float, 4> outarray = { _numContainer[0] * mult,_numContainer[1] * mult,_numContainer[2] * mult,_numContainer[3] * mult };
	mVector4f out(outarray);
	return out;
}

const mVector4f mVector4f::operator*(const float& mult)
{
	array<float, 4> outarray = { _numContainer[0] * mult,_numContainer[1] * mult,_numContainer[2] * mult,_numContainer[3] * mult };
	mVector4f out(outarray);
	return out;
}

const mVector4f mVector4f::operator*(mMatrix4f& mult)
{
	array<float, 4> outarray =
	{
		(_numContainer[0] * mult.at(0,0)) + (_numContainer[1] * mult.at(1,0)) + (_numContainer[2] * mult.at(2,0)) + (_numContainer[3] * mult.at(3,0)),
		(_numContainer[0] * mult.at(0,1)) + (_numContainer[1] * mult.at(1,1)) + (_numContainer[2] * mult.at(2,1)) + (_numContainer[3] * mult.at(3,1)),
		(_numContainer[0] * mult.at(0,2)) + (_numContainer[1] * mult.at(1,2)) + (_numContainer[2] * mult.at(2,2)) + (_numContainer[3] * mult.at(3,2)),
		(_numContainer[0] * mult.at(0,3)) + (_numContainer[1] * mult.at(1,3)) + (_numContainer[2] * mult.at(2,3)) + (_numContainer[3] * mult.at(3,3)),
	};
	mVector4f out(outarray);
	return out;
}

const mVector4f mVector4f::operator/(const int& div)
{
	array<float, 4> outarray = { _numContainer[0] / div, _numContainer[1] / div, _numContainer[2] / div,_numContainer[3] / div };
	mVector4f out(outarray);
	return out;
}

const mVector4f mVector4f::operator/(const float& div)
{
	array<float, 4> outarray = { _numContainer[0] / div, _numContainer[1] / div, _numContainer[2] / div,_numContainer[3] / div };
	mVector4f out(outarray);
	return out;
}

//returns magnitude of vector
const float mVector4f::mag()
{
	return sqrt(pow(_numContainer[0], 2) + pow(_numContainer[1], 2) + pow(_numContainer[2], 2) + pow(_numContainer[3], 2));
}


void mVector4f::normalize(float nMag)
{
	float mult = mag() / nMag;
	_numContainer[0] /= mult;
	_numContainer[1] /= mult;
	_numContainer[2] /= mult;
	_numContainer[3] /= mult;
	return;
}

const float mVector4f::dp(const mVector4f& in)
{
	float output = 0.0f;
	output += _numContainer[0] * in._numContainer[0];
	output += _numContainer[1] * in._numContainer[1];
	output += _numContainer[2] * in._numContainer[2];
	output += _numContainer[3] * in._numContainer[3];
	return output;
}

const std::string mVector4f::output()
{
	string out = "Maths Vector 4f: ";
	for (int i = 0; i < _numContainer.size(); i++)
	{
		out += to_string(_numContainer.at(i));
		out += " ";
	}
	return out;
}

float& mVector4f::at(const int& index)
{
	if (index >= _numContainer.size() || index < 0) { throw "out of index, bro"; }
	else
	{
		return _numContainer.at(index);
	}
}

const array<float, 4>& mVector4f::toArray()
{
	array<float, 4> output;
	output.fill(0.0f);
	for (int i = 0;i < _numContainer.size();i++)
	{
		output[i] = _numContainer[i];
	}
	return output;
}

const vector<float>& mVector4f::toVector()
{
	vector<float> output;
	for (int i = 0;i < _numContainer.size();i++)
	{
		output.push_back(_numContainer[i]);
	}
	return output;
}