
#include <iostream>
#include <array>
#include <string>
//#include <cmath>

#include "mVector2f.h"
#include "abstract_mVector.h"
#include "mMatrix4f.h"

using namespace std;

//default constructor
mVector2f::mVector2f() { _numContainer = { 0.0f, 0.0f }; }

mVector2f::mVector2f(array<float, 2> arr) { _numContainer = arr; }


//returns a new vector, with operation applied
const mVector2f mVector2f::operator+(const mVector2f& add)
{
	array<float, 2> outarray = { _numContainer[0] + add._numContainer[0], _numContainer[1] + add._numContainer[1] };
	mVector2f out(outarray);
	return out;
}

const mVector2f mVector2f::operator-(const mVector2f& sub)
{
	array<float, 2> outarray = { _numContainer[0] - sub._numContainer[0], _numContainer[1] - sub._numContainer[1] };
	mVector2f out(outarray);
	return out;
}

const mVector2f mVector2f::operator*(const int& mult)
{
	array<float, 2> outarray = { _numContainer[0] * mult,_numContainer[1] * mult };
	mVector2f out(outarray);
	return out;
}

const mVector2f mVector2f::operator*(const float& mult)
{
	array<float, 2> outarray = { _numContainer[0] * mult,_numContainer[1] * mult };
	mVector2f out(outarray);
	return out;
}

const mVector2f mVector2f::operator/(const int& div)
{
	array<float, 2> outarray = { _numContainer[0] / div, _numContainer[1] / div };
	mVector2f out(outarray);
	return out;
}

const mVector2f mVector2f::operator/(const float& div)
{
	array<float, 2> outarray = { _numContainer[0] / div, _numContainer[1] / div };
	mVector2f out(outarray);
	return out;
}

//returns magnitude of vector
const float mVector2f::mag()
{
	return sqrt(pow(_numContainer[0], 2) + pow(_numContainer[1], 2));
}


void mVector2f::normalize(float nMag)
{
	float mult = mag() / nMag;
	_numContainer[0] /= mult;
	_numContainer[1] /= mult;
	return;
}

const float mVector2f::dp(const mVector2f& in)
{
	float output = 0.0f;
	output += _numContainer[0] * in._numContainer[0];
	output += _numContainer[1] * in._numContainer[1];
	return output;
}


const std::string mVector2f::output()
{
	string out = "Maths Vector 2f: ";
	for (int i = 0; i < _numContainer.size(); i++)
	{
		out += to_string(_numContainer.at(i));
		out += " ";
	}
	return out;
}

float& mVector2f::at(const int& index)
{
	if (index >= _numContainer.size() || index < 0) { throw "out of index, bro"; }
	else
	{
		return _numContainer.at(index);
	}
}

const array<float, 2>& mVector2f::toArray()
{
	array<float, 2> output;
	output.fill(0.0f);
	for (int i = 0;i < _numContainer.size();i++)
	{
		output[i] = _numContainer[i];
	}
	return output;
}

const vector<float>& mVector2f::toVector()
{
	vector<float> output;
	output.push_back(_numContainer[0]);
	output.push_back(_numContainer[1]);
	return output;
}
