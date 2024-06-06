#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <fstream>

#include "importOBJ.h"

using namespace std;

OBJ_Importer::OBJ_Importer()
{
	_fileLines;
}

void OBJ_Importer::readFile(string filepath)
{
	ifstream file;
	file.open(filepath);
	string fileString;
	if (file.is_open())
	{
		cout << "obj opened" << endl;
		while (getline(file, fileString))
		{
			_fileLines.push_back(fileString);
			//cout << fileString << endl;
		}
	}
	else { cout << "obj could not be opened" << endl; }
	return;
}

const vector<mVector3f> OBJ_Importer::getVertices()
{
	cout << "getting vertices" << endl;

	vector<mVector3f> vertices;
	for (int i = 0;i < _fileLines.size();i++)
	{
		string fileline = _fileLines[i];
		if (fileline.substr(0, 2) == "v ")
		{
			fileline = fileline.substr(2, fileline.length());
			vector<float> vertexPositions = readline(fileline, " ");
			//cout << "vertex data obtained" << endl;

			mVector3f vertex({ vertexPositions[0],vertexPositions[1],vertexPositions[2] });
			//cout << "vertex data written to vector" << endl;

			vertices.push_back(vertex);
		}
		else { continue; }
	}
	//cout << "returning vertices" << endl;
	return vertices;
}
const vector<mVector2f> OBJ_Importer::getUVs()
{
	//cout << "getting uvs" << endl;
	vector<mVector2f> UVs;
	for (int i = 0;i < _fileLines.size();i++)
	{
		string fileline = _fileLines[i];
		if (fileline.substr(0, 3) == "vt ")
		{
			fileline = fileline.substr(3, fileline.length());
			vector<float> UVpos = readline(fileline, " ");

			mVector2f UV({ UVpos[0],UVpos[1] });
			//cout << "adding UV vector to collection" << endl;
			UVs.push_back(UV);
		}
		else { continue; }
	}
	return UVs;
}
const vector<Tri> OBJ_Importer::getFaces()
{
	vector<Tri> triangles;
	vector<mVector3f> vertices = getVertices();
	vector<mVector2f> UVs = getUVs();
	for (int i = 0;i < _fileLines.size();i++)
	{
		string fileline = _fileLines[i];
		if (fileline.substr(0, 2) == "f ")
		{
			fileline = fileline.substr(2, fileline.length());
			vector<int> faceData = readFaceData(fileline);
			for (int i = 0;i < faceData.size();i += 9)
			{
				//cout << "VERTICES TO USE: " << faceData[i] << "," << faceData[i + 3] << "," << faceData[i + 6] << endl;
				//cout << "UVS TO USE: " << faceData[i + 1] << "," << faceData[i + 4] << "," << faceData[i + 7] << endl;
				Tri newTriangle(vertices[faceData[i] - 1], vertices[faceData[i + 3] - 1], vertices[faceData[i + 6] - 1], UVs[faceData[i + 1] - 1], UVs[faceData[i + 4] - 1], UVs[faceData[i + 7] - 1]);
				//cout << "new triangle constructed, adding to collection..." << endl;
				triangles.push_back(newTriangle);
			}
		}
		else { continue; }
	}
	return triangles;
}

const vector<float> OBJ_Importer::readline(string line, string delimiter)
{
	//cout << "Calling readline with: " << line << "... " << endl;
	vector<float> output;
	//remove the vertex tag and prepare to read the vertex datas
	while (line.size() != 0)
	{
		//cout << "looping..." << endl;
		//cout << "splitting string..." << endl;
		string data = line.substr(0, line.find(delimiter));
		//cout << "substring found: "<<data<<" ..." << endl;
		//cout << stof(data) << endl;
		//cout << "erasing string data" << endl;
		line.erase(0, data.length() + delimiter.length());
		output.push_back(stof(data));
	}
	//for (int i = 0;i < output.size();i++) { cout << output[i] << endl; }
	//cout << "returning output" << endl;

	return output;
}

const vector<int> OBJ_Importer::readFaceData(string line)
{
	vector<int> output;
	string faceDelimiter = " ";
	string dataDelimiter = "/";
	//remove the vertex tag and prepare to read the vertex positions
	while (line.size() != 0)
	{
		int dataLen = 0;
		//cout << "loop" << endl;
		string data = line.substr(0, line.find(faceDelimiter));
		//cout << data << endl;
		dataLen = data.length();
		while (data.size() != 0)
		{
			//cout << "accessing face data..." << endl;
			string faceData = data.substr(0, data.find(dataDelimiter));
			//cout << faceData << endl;
			output.push_back(stoi(faceData));
			data.erase(0, faceData.length() + dataDelimiter.length());
		}
		//cout << "what" << endl;
		line.erase(0, dataLen + faceDelimiter.length());
		//cout << data << endl;
		//output.push_back(stof(data));
	}
	//for (int i = 0;i < output.size();i++) { cout << output[i] << endl; }
	return output;
}