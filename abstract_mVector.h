#pragma once

#include <iostream>
#include <array>
#include <string>
#include <vector>

using namespace std;

//Ideally, all my custom MATHS vectors inherit from this for that sweet, sweet polymorphism
class abstract_mVector
{
public:
	virtual	const float mag() = 0;
	virtual void normalize(float nMag = 1.0f) = 0;

	virtual const std::string output() = 0;
	virtual float& at(const int& index) = 0;
	virtual const vector<float>& toVector() = 0;
};