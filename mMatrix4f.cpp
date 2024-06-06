#include <iostream>
#include <array>
#include <string>
//#include <cmath>

//#include "..\..\Vectors\3f\mVector3f.h"
#include "mMatrix4f.h"

using namespace std;

mMatrix4f::mMatrix4f(float init, bool rowOrder)
{
	array<float, 4> initA;
	initA.fill(init);
	_numContainer.fill(initA);
	_rowOrder = rowOrder;
}

mMatrix4f::mMatrix4f(mMatrix4f& clonesrc)
{
	_numContainer = clonesrc._numContainer;
	_rowOrder = clonesrc._rowOrder;
}

mMatrix4f::mMatrix4f(const mMatrix4f& clonesrc)
{
	_numContainer = clonesrc._numContainer;
	_rowOrder = clonesrc._rowOrder;
}


const mMatrix4f mMatrix4f::operator+(mMatrix4f add)
{
	mMatrix4f output(*this);
	for (int i = 0; i < add._numContainer.size();i++)
	{
		for (int j = 0; j < add._numContainer[i].size(); j++)
		{
			output._numContainer[i][j] += add._numContainer[i][j];
		}
	}
	return output;
}

const mMatrix4f mMatrix4f::operator-(mMatrix4f sub)
{
	mMatrix4f output(*this);
	for (int i = 0; i < sub._numContainer.size(); i++)
	{
		for (int j = 0; j < sub._numContainer[i].size(); j++)
		{
			output._numContainer[i][j] -= sub._numContainer[i][j];
		}
	}
	return output;
}

const mMatrix4f mMatrix4f::operator*(mMatrix4f mult)
{
	mMatrix4f output;
	mMatrix4f multT;
	multT = mult;
	multT.transpose();
	//access each row of the current matrix
	for (int i = 0; i < _numContainer.size(); i++)
	{
		array<float, 4> row = _numContainer[i];
		array<float, 4> outputRow = { 0.0f };
		//access each "column" of the multiplying matrix
		for (int j = 0; j < multT._numContainer.size(); j++)
		{
			array<float, 4> column = multT._numContainer[j];
			//now dot product each row/column together
			outputRow[j] = dp(row, column);
		}
		//after loop, outputRow should be filled with values, so assign it as a row of the output matrix
		output._numContainer[i] = outputRow;
	}
	output._rowOrder = _rowOrder;
	return output;
}

const mMatrix4f mMatrix4f::operator*(int mult)
{
	mMatrix4f output(*this);
	for (int i = 0; i < output._numContainer.size(); i++)
	{
		for (int j = 0; j < output._numContainer[i].size(); j++)
		{
			output._numContainer[i][j] *= mult;
		}
	}
	return output;
}

const mMatrix4f mMatrix4f::operator*(float mult)
{
	mMatrix4f output(*this);
	for (int i = 0; i < output._numContainer.size(); i++)
	{
		for (int j = 0; j < output._numContainer[i].size(); j++)
		{
			output._numContainer[i][j] *= mult;
		}
	}
	return output;
}

const mMatrix4f mMatrix4f::operator/(int div)
{
	mMatrix4f output(*this);
	for (int i = 0; i < output._numContainer.size(); i++)
	{
		for (int j = 0; j < output._numContainer[i].size(); j++)
		{
			output._numContainer[i][j] /= div;
		}
	}
	return output;
}

const mMatrix4f mMatrix4f::operator/(float div)
{
	mMatrix4f output(*this);
	for (int i = 0; i < output._numContainer.size(); i++)
	{
		for (int j = 0; j < output._numContainer[i].size(); j++)
		{
			output._numContainer[i][j] /= div;
		}
	}
	return output;
}


void mMatrix4f::transpose()
{
	array<array<float, 4>, 4> transposed = { 0 };
	for (int i = 0; i < _numContainer.size(); i++)
	{
		array<float, 4> row = _numContainer[i];
		for (int j = 0; j < row.size(); j++)
		{
			transposed[j][i] = row[j];
		}
	}
	_numContainer = transposed;
	return;
}

const float mMatrix4f::determinant()
{
	//+a(f(kp-lo)-g(jp-ln)+h(jo-kn))
	float lineA = _numContainer[0][0] * (
		+_numContainer[1][1] * (+_numContainer[2][2] * _numContainer[3][3] - _numContainer[2][3] * _numContainer[3][2])
		- _numContainer[1][2] * (+_numContainer[2][1] * _numContainer[3][3] - _numContainer[2][3] * _numContainer[3][1])
		+ _numContainer[1][3] * (+_numContainer[2][1] * _numContainer[3][2] - _numContainer[2][2] * _numContainer[3][1]));
	//-b(e(kp-lo)-g(ip-lm)+h(io-km))
	float lineB = _numContainer[0][1] * (
		+_numContainer[0][1] * (+_numContainer[2][2] * _numContainer[3][3] - _numContainer[2][3] * _numContainer[3][2])
		- _numContainer[1][2] * (+_numContainer[2][0] * _numContainer[3][3] - _numContainer[2][3] * _numContainer[3][0])
		+ _numContainer[1][3] * (+_numContainer[2][0] * _numContainer[3][2] - _numContainer[2][2] * _numContainer[3][0]));
	//+c(e(jp-ln)-f(ip-lm)+h(in-jm))
	float lineC = _numContainer[0][2] * (
		+_numContainer[1][0] * (+_numContainer[2][1] * _numContainer[3][3] - _numContainer[2][3] * _numContainer[3][1])
		- _numContainer[1][1] * (+_numContainer[2][0] * _numContainer[3][3] - _numContainer[2][3] * _numContainer[3][0])
		+ _numContainer[1][3] * (+_numContainer[2][0] * _numContainer[3][1] - _numContainer[2][1] * _numContainer[3][0]));
	//-d(e(jo-kn)-f(io-km)+g(in-jm))
	float lineD = _numContainer[0][3] * (
		+_numContainer[1][0] * (+_numContainer[2][1] * _numContainer[3][2] - _numContainer[2][2] * _numContainer[3][1])
		- _numContainer[1][1] * (+_numContainer[2][0] * _numContainer[3][2] - _numContainer[2][2] * _numContainer[3][0])
		+ _numContainer[1][2] * (+_numContainer[2][0] * _numContainer[3][1] - _numContainer[2][1] * _numContainer[3][0]));

	return lineA - lineB + lineC - lineD;
}

const mMatrix4f mMatrix4f::minors()
{
	mMatrix4f output(0.0f, true);
	for (int y = 0; y < _numContainer.size(); y++)
	{
		for (int x = 0; x < _numContainer[y].size(); x++)
		{
			output._numContainer[y][x] = minordeterminant(y, x);
		}
	}
	return output;
}
const float mMatrix4f::minordeterminant(const int& row, const int& column)
{
	if ((row < 0 || row>3) || (column < 0 || column>3)) { return 0.0f; }
	array<float, 9> newMatrix;
	int matrixfill = 0;
	for (int i = 0; i < _numContainer.size(); i++)
	{
		if (i == row) { continue; }
		for (int j = 0; j < _numContainer[i].size(); j++)
		{
			if (j == column) { continue; }
			newMatrix[matrixfill] = _numContainer[i][j];
			matrixfill++;
		}
	}
	return newMatrix[0] * (newMatrix[4] * newMatrix[8] - newMatrix[5] * newMatrix[7])
		- newMatrix[1] * (newMatrix[3] * newMatrix[8] - newMatrix[5] * newMatrix[6])
		+ newMatrix[2] * (newMatrix[3] * newMatrix[7] - newMatrix[4] * newMatrix[6]);
}
const mMatrix4f mMatrix4f::cofactors()
{
	mMatrix4f output;
	output = minors();
	for (int y = 0; y < _numContainer.size(); y++)
	{
		for (int x = 0; x < _numContainer[y].size(); x++)
		{
			if ((y + x) % 2 == 1)
			{
				output._numContainer[y][x] = -output._numContainer[y][x];
			}
		}
	}
	return output;
}

const mMatrix4f mMatrix4f::invert()
{
	mMatrix4f output;
	if (determinant() == 0.0f) { return output; }
	output = cofactors();
	output.transpose();
	output = output * (1 / determinant());
	return output;
}



const float mMatrix4f::dp(array<float, 4> vecA, array<float, 4> vecB)
{
	float output = 0.0f;
	for (int i = 0; i < vecA.size();i++)
	{
		output += vecA[i] * vecB[i];
	}
	return output;
}

const mMatrix4f mMatrix4f::identity()
{
	mMatrix4f output;
	for (int i = 0; i < output._numContainer.size(); i++)
	{
		for (int j = 0; j < output._numContainer[i].size(); j++)
		{
			if (i == j)
			{
				output._numContainer[i][j] = 1.0f;
			}
		}
	}
	return output;
}

const mMatrix4f mMatrix4f::transformation(float x, float y, float z)
{
	mMatrix4f output;
	output = identity();
	output._numContainer[3][0] = x;
	output._numContainer[3][1] = y;
	output._numContainer[3][2] = z;
	return output;
}

const mMatrix4f mMatrix4f::transformation(mVector3f move)
{
	mMatrix4f output;
	output = identity();
	output._numContainer[3][0] = move.at(0);
	output._numContainer[3][1] = move.at(1);
	output._numContainer[3][2] = move.at(2);
	return output;
}

const mMatrix4f mMatrix4f::transformation(array<float, 3> move)
{
	mMatrix4f output;
	output = identity();
	output._numContainer[3][0] = move[0];
	output._numContainer[3][1] = move[1];
	output._numContainer[3][2] = move[2];
	return output;
}

const mMatrix4f mMatrix4f::scale(float x, float y, float z)
{
	mMatrix4f output;
	output._numContainer[0][0] = x;
	output._numContainer[1][1] = y;
	output._numContainer[2][2] = z;
	output._numContainer[3][3] = 1.0f;
	return output;
}

const mMatrix4f mMatrix4f::scale(mVector3f scale)
{
	mMatrix4f output;
	output._numContainer[0][0] = scale.at(0);
	output._numContainer[1][1] = scale.at(1);
	output._numContainer[2][2] = scale.at(2);
	output._numContainer[3][3] = 1.0f;
	return output;
}

const mMatrix4f mMatrix4f::scale(array<float, 3> scale)
{
	mMatrix4f output;
	output._numContainer[0][0] = scale[0];
	output._numContainer[1][1] = scale[1];
	output._numContainer[2][2] = scale[2];
	output._numContainer[3][3] = 1.0f;
	return output;
}

const mMatrix4f mMatrix4f::rotation(float x, float y, float z, float w)
{
	mMatrix4f output(0.0f, true);
	float s = 2.0f / ((w * w) + (x * x) + (y * y) + (z * z));
	output._numContainer[0][0] = 1 - s * (powf(y, 2) + powf(z, 2));
	output._numContainer[0][1] = s * (x * y + z * w);
	output._numContainer[0][2] = s * (x * z - y * w);
	output._numContainer[1][0] = s * (x * y - z * w);
	output._numContainer[1][1] = 1 - s * (powf(x, 2) + powf(z, 2));
	output._numContainer[1][2] = s * (y * z + x * w);
	output._numContainer[2][0] = s * (x * z + y * w);
	output._numContainer[2][1] = s * (y * z - x * w);
	output._numContainer[2][1] = 1 - s * (powf(x, 2) + powf(y, 2));
	output._numContainer[3][3] = 1.0f;
	return output;
}
const mMatrix4f mMatrix4f::rotationFromEuler(float roll, float pitch, float yaw)
{
	mMatrix4f output(0.0f, true);
	float radiansConv = (4 * atan(1)) / 180.0f;
	float cosRoll = cos(roll * radiansConv * 0.5);
	float sinRoll = sin(roll * radiansConv * 0.5);
	float cosPitch = cos(pitch * radiansConv * 0.5);
	float sinPitch = sin(pitch * radiansConv * 0.5);
	float cosYaw = cos(yaw * radiansConv * 0.5);
	float sinYaw = sin(yaw * radiansConv * 0.5);

	float w = (cosPitch * cosRoll * cosYaw) - (sinPitch * sinRoll * sinYaw);
	float x = (sinPitch * cosRoll * cosYaw) + (cosPitch * sinRoll * sinYaw);
	float y = (cosPitch * cosRoll * sinYaw) - (sinPitch * sinRoll * cosYaw);
	float z = (cosPitch * sinRoll * cosYaw) + (sinPitch * cosRoll * sinYaw);

	float s = 2.0f / ((w * w) + (x * x) + (y * y) + (z * z));

	output._numContainer[0][0] = 1 - (s * ((y * y) + (z * z)));
	output._numContainer[0][1] = s * ((x * y) + (z * w));
	output._numContainer[0][2] = s * ((x * z) - (y * w));

	output._numContainer[1][0] = s * ((x * y) - (z * w));
	output._numContainer[1][1] = 1 - s * ((x * x) + (z * z));
	output._numContainer[1][2] = s * ((y * z) + (x * w));

	output._numContainer[2][0] = s * ((x * z) + (y * w));
	output._numContainer[2][1] = s * ((y * z) - (x * w));
	output._numContainer[2][2] = 1 - s * ((x * x) + (y * y));
	output._numContainer[3][3] = 1.0f;

	//float xs = x * s, ys = y * s, zs = z * s;
	//float xx = x * xs, xy = x * ys, xz = x * zs;
	//float yy = y * ys, yz = y * zs, zz = z * zs;
	//float xw = w * xs, yw = w * ys, zw = w * zs;

	//output._numContainer[0][0] = 1.0f - (yy + zz);
	//output._numContainer[0][1] = xy + zw;
	//output._numContainer[0][2] = xz - yw;

	//output._numContainer[1][0] = xy - zw;
	//output._numContainer[1][1] = 1.0f - (xx + zz);
	//output._numContainer[1][2] = yz - xw;

	//output._numContainer[2][0] = xz + yw;
	//output._numContainer[2][1] = yz - xw;
	//output._numContainer[2][2] = 1.0f - (xx + yy);
	//output._numContainer[3][3] = 1.0f;

	return output;
}


float& mMatrix4f::at(const int& y, const int& x)
{
	return _numContainer[y][x];
}

bool& mMatrix4f::isRowOrder()
{
	return _rowOrder;
}

const string mMatrix4f::output()
{
	string out = "4x4 Maths Matrix ";
	if (_rowOrder) { out += "(Row-Major Order)"; }
	else { out += "(Column-Major Order)"; }
	out += ":\n";
	for (int i = 0; i < _numContainer.size(); i++)
	{
		string rowString = "";
		array<float, 4> row = _numContainer[i];
		for (int j = 0; j < row.size(); j++)
		{
			rowString += std::to_string(row[j]);
			rowString += ", ";
		}
		out += rowString + "\n";
	}
	return out;
}

const string mMatrix4f::outputline()
{
	mMatrix4f clone(*this);
	string output = "4x4 Maths Matrix ";
	if (_rowOrder) { output += "(Row-Major Order)"; }
	else { output += "(Column-Major Order)"; }
	output += ": ";
	for (int i = 0; i < _numContainer.size(); i++)
	{
		for (int j = 0; j < _numContainer[i].size(); j++)
		{
			if (_rowOrder) { output += std::to_string(_numContainer[i][j]); }
			else { output += std::to_string(_numContainer[j][i]); }
			output += ", ";
		}
	}
	return output;
}

const array<float, 16>& mMatrix4f::toArray()
{
	array<float, 16> output;
	output.fill(0.0f);
	//access each row
	for (int i = 0; i < _numContainer.size(); i++)
	{
		//access each element of the row
		for (int j = 0; j < _numContainer[i].size(); j++)
		{
			if (_rowOrder) { output[(i * 4) + j] = _numContainer[i][j]; }
			else { output[(i * 4) + j] = _numContainer[j][i]; }
		}
	}
	return output;
}

const array<array<float, 4>, 4>& mMatrix4f::toArray2D()
{
	array<float, 4> outputrow;
	outputrow.fill(0.0f);
	array<array<float, 4>, 4> output;
	output.fill(outputrow);
	for (int i = 0; i < _numContainer.size(); i++)
	{
		//access each element of the row
		for (int j = 0; j < _numContainer[i].size(); j++)
		{
			output[i][j] = _numContainer[i][j];
		}
	}
	return output;
}