#pragma once

#include <iostream>
#include <array>
#include <string>

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>

#include "mVector2f.h"
#include "mVector3f.h"
//#include "..\Matrices\4f\mMatrix4f.h"

using namespace std;

//stores a triad of 3d vectors as a mesh triangle and 2d vectors as a uv triangle, to make opengl integration easier
class Tri
{
public:
	//Tri();
	Tri(mVector3f* vertex1, mVector3f* vertex2, mVector3f* vertex3, mVector2f* uv1, mVector2f* uv2, mVector2f* uv3);
	Tri(mVector3f vertex1, mVector3f vertex2, mVector3f vertex3, mVector2f uv1, mVector2f uv2, mVector2f uv3);

	~Tri();

	//creates an array of all points of the triangle
	const array<float, 9> verticesToArray();

	//creates an array of all points of the uv triangle
	const array<float, 6> uvToArray();

	//use to access a single coordinate of one of the vertices
	const float getVertexCoordinate(int vertex, int coordinate);

	//use to access a single coordinate of one of the UVs
	const float getUVCoordinate(int uv, int coordinate);

	mVector3f* getVertex(int pos);
	mVector2f* getUV(int pos);
private:
	array<mVector3f, 3> _vertices;
	array<mVector2f, 3> _uvs;
};