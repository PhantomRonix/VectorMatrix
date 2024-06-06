#include <iostream>
#include <array>
#include <string>

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>

#include "Tri.h"


using namespace std;

Tri::Tri(mVector3f* vertex1, mVector3f* vertex2, mVector3f* vertex3, mVector2f* uv1, mVector2f* uv2, mVector2f* uv3)
{
	_vertices = { *vertex1,*vertex2,*vertex3 };
	_uvs = { *uv1,*uv2,*uv3 };
}

Tri::Tri(mVector3f vertex1, mVector3f vertex2, mVector3f vertex3, mVector2f uv1, mVector2f uv2, mVector2f uv3)
{
	_vertices = { vertex1,vertex2,vertex3 };
	_uvs = { uv1,uv2,uv3 };

}

Tri::~Tri()
{
	//for (int i = 0;i < _vertices.size();i++)
	//{
	//	_vertices[i] = NULL;
	//}
	//for (int i = 0;i < _uvs.size();i++)
	//{
	//	_uvs[i] = NULL;
	//}
}

//const Tri Tri::operator*(mMatrix4f& mult)
//{
//	array<mVector3f, 3> outputVertices;
//	for (int i = 0;i < _vertices.size();i++)
//	{
//		outputVertices[i] = *_vertices[i] * mult;
//	}
//	Tri output(outputVertices[0], outputVertices[1], outputVertices[2]);
//	return output;
//}

const array<float, 9> Tri::verticesToArray()
{
	array<float, 9> output;
	output.fill(0.0f);
	for (int i = 0;i < _vertices.size();i++)
	{
		output[i * 3] = _vertices[i].at(0);
		output[i * 3 + 1] = _vertices[i].at(1);
		output[i * 3 + 2] = _vertices[i].at(2);
	}
	return output;
}

const array<float, 6> Tri::uvToArray()
{
	array<float, 6> output;
	output.fill(0.0f);
	for (int i = 0;i < _uvs.size();i++)
	{
		output[i * 2] = _uvs[i].at(0);
		output[i * 2 + 1] = _uvs[i].at(1);
	}
	return output;
}

const float Tri::getVertexCoordinate(int vertex, int coordinate)
{
	return _vertices[vertex].at(coordinate);
}
const float Tri::getUVCoordinate(int uv, int coordinate)
{
	return _uvs[uv].at(coordinate);
}


mVector3f* Tri::getVertex(int pos)
{
	return &_vertices[pos];
}
mVector2f* Tri::getUV(int pos)
{
	return &_uvs[pos];
}