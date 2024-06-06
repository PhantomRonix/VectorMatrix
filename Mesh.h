#pragma once

#include <iostream>
#include <array>
#include <string>
#include <vector>

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>

//#include "Vectors\mVector3f.h"
//#include "Matrices\mMatrix4f.h"
#include "tMatrix4f.h"
#include "Tri.h"

using namespace std;

//class mVector3f;
//class mMatrix4f;
//class Tri;

class Mesh
{
public:
	Mesh(Tri* triangles, int size, tMatrix4f* modelMatrix);
	Mesh(vector<Tri> triangles, int size, tMatrix4f* modelMatrix);
	Mesh(Mesh& copy);
	Mesh(const Mesh& copy);

	~Mesh();
	//Mesh operator*(mMatrix4f mult);

	//return a vector containing the values of each vertex coordinate
	//I SWEAR I'M NOT USING THIS FOR CALCULATION! ONLY SO I CAN RETURN A VARIABLE SIZED ARRAY
	const vector<float> getVertexVector();

	//return a vector containing the values of each uv coordinate
	const vector<float> getUVVector();

	const mMatrix4f getModelMatrix();
	const array<float, 16> getModelArray();



	float* _posX;float* _posY;float* _posZ;
	float* _scaleX;float* _scaleY;float* _scaleZ;
	float* _rotRoll;float* _rotPitch;float* _rotYaw;

private:
	int _size;
	vector<Tri> _triangles;
	tMatrix4f* _modelMatrix;
};