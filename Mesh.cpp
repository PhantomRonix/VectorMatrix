#include <iostream>
#include <array>
#include <string>

#include "Mesh.h"

using namespace std;

//PASS IN AN ARRAY PLZ, also the size better be accurate or I'm coming down there to beat you up
Mesh::Mesh(Tri* triangles, int size, tMatrix4f* modelMatrix)
{
	_size = size;
	_modelMatrix = modelMatrix;
	vector<Tri> trianglesVector;
	for (int i = 0;i < size;i++) { trianglesVector.push_back(*(triangles + i)); }
	_triangles = trianglesVector;

	_scaleX = _modelMatrix->_scaleX;
	_scaleY = _modelMatrix->_scaleY;
	_scaleZ = _modelMatrix->_scaleZ;
	_rotRoll = _modelMatrix->_rotRoll;
	_rotPitch = _modelMatrix->_rotPitch;
	_rotYaw = _modelMatrix->_rotYaw;
	_posX = _modelMatrix->_posX;
	_posY = _modelMatrix->_posY;
	_posZ = _modelMatrix->_posZ;
}

Mesh::Mesh(vector<Tri> triangles, int size, tMatrix4f* modelMatrix)
{
	_size = size;
	_modelMatrix = modelMatrix;

	vector<Tri> trianglesVector;
	for (int i = 0;i < size;i++) { trianglesVector.push_back(triangles[i]); }
	_triangles = trianglesVector;

	_scaleX = _modelMatrix->_scaleX;
	_scaleY = _modelMatrix->_scaleY;
	_scaleZ = _modelMatrix->_scaleZ;
	_rotRoll = _modelMatrix->_rotRoll;
	_rotPitch = _modelMatrix->_rotPitch;
	_rotYaw = _modelMatrix->_rotYaw;
	_posX = _modelMatrix->_posX;
	_posY = _modelMatrix->_posY;
	_posZ = _modelMatrix->_posZ;
}


Mesh::Mesh(Mesh& copy)
{
	_size = copy._size;
	_modelMatrix = copy._modelMatrix;
	_triangles = copy._triangles;

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

Mesh::Mesh(const Mesh& copy)
{
	_size = copy._size;
	_modelMatrix = copy._modelMatrix;
	_triangles = copy._triangles;

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

Mesh::~Mesh()
{

}

//Mesh Mesh::operator*(mMatrix4f mult)
//{
//	for (int i = 0;i < _size;i++)
//	{
//		*(_triangles+i) = *(_triangles + i) * mult;
//	}
//	return *this;
//}

const vector<float> Mesh::getVertexVector()
{
	vector<float> output;
	for (int i = 0;i < _size;i++)
	{
		array<float, 9> triangleVertexData = _triangles[i].verticesToArray();
		for (int j = 0;j < triangleVertexData.size();j++)
		{
			//cout << "HELP ME" << endl;
			output.push_back(triangleVertexData[j]);
		}
	}
	return output;
}

const vector<float> Mesh::getUVVector()
{
	vector<float> output;
	for (int i = 0;i < _size;i++)
	{
		array<float, 6> triangleVertexData = _triangles[i].uvToArray();
		for (int j = 0;j < triangleVertexData.size();j++)
		{
			output.push_back(triangleVertexData[j]);
		}
	}
	return output;
}

const mMatrix4f Mesh::getModelMatrix()
{
	return _modelMatrix->getCombinedMatrix();
}

const array<float, 16> Mesh::getModelArray()
{
	return _modelMatrix->getCombinedArray();
}