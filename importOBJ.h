#pragma once
#include <iostream>
#include <array>
#include <string>
#include <vector>

#include "mVector3f.h"
#include "mVector2f.h"
#include "Mesh.h"
#include "Tri.h"

using namespace std;

class OBJ_Importer
{
public:
	OBJ_Importer();
	void readFile(string filepath);
	//reads and returns vector full of data from a given line
	const vector<float> readline(string line, string delimiter);
	const vector<int> readFaceData(string line);
	const vector<mVector3f> getVertices();
	const vector<mVector2f> getUVs();
	const vector<Tri> getFaces();
private:
	vector<string> _fileLines;
};