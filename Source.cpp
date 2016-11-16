// FILE: HeapSortTest.cpp
// Heap Sorting of a random sequence of integers.
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//open a file with salt and pepper noise and copy the file to an array
void syncFile(string fileName, int **&A, int &height, int &width, int &maxValue);
//copy array A to B where B has zeros around A
void AtoB(int **&A, int **&B, float &height, float &width, float);
//copy the filtered array A to a new file to poccess the output 
void arrToFile(string fileName, int **A, int height, int width, int maxValue);
//function that contains all the string paths to the noise and filtered files
void filePaths(string &inFile, string &outFile, int i);
void AtoB2(int **&A, int **&B, int height, int width);
void AtoB3(int **&A, int **&B, int height, int width);


int main()
{
	int **A, **B;
	int height = 10, width = 10;
	int maxValue = 255;
	A = new int*[10];
	for (int i = 0; i < 10; i++) A[i] = new int[10];
	B = new int*[10];
	for (int i = 0; i < 10; i++) B[i] = new int[10];
	
	int i = 0, num = 11;
	string infile = "amazons.pgm";
	string outfile = "amazonsNew.pgm";
	float scale = 0.7;
	syncFile(infile, A, height, width, maxValue);
	//AtoB2(A, B, height, width);
	AtoB3(A, B, height, width);
	arrToFile(outfile, B, height, width, maxValue);

	system("pause");
	return 0;
}

void filePaths(string &inFile, string &outFile, int i) {
	string s[11], d[11];
	s[0] = "\NoiseFiles\\amazons.pgm";
	d[0] = "\Filtered\\amazonsNew.pgm";
	s[1] = "C:\\Users\\Abraheem\\Documents\\Visual Studio 2015\\Projects\\CS 210\\GroupAss#5\\Prob_2\\Prob_2\\NoiseFiles\\astro.pgm";
	d[1] = "C:\\Users\\Abraheem\\Documents\\Visual Studio 2015\\Projects\\CS 210\\GroupAss#5\\Prob_2\\Prob_2\\Filtered\\astroNew.pgm";
	s[2] = "C:\\Users\\Abraheem\\Documents\\Visual Studio 2015\\Projects\\CS 210\\GroupAss#5\\Prob_2\\Prob_2\\NoiseFiles\\bb_ad_5.pgm";
	d[2] = "C:\\Users\\Abraheem\\Documents\\Visual Studio 2015\\Projects\\CS 210\\GroupAss#5\\Prob_2\\Prob_2\\Filtered\\bb_ad_5New.pgm";
	s[3] = "C:\\Users\\Abraheem\\Documents\\Visual Studio 2015\\Projects\\CS 210\\GroupAss#5\\Prob_2\\Prob_2\\NoiseFiles\\boys.pgm";
	d[3] = "C:\\Users\\Abraheem\\Documents\\Visual Studio 2015\\Projects\\CS 210\\GroupAss#5\\Prob_2\\Prob_2\\Filtered\\boysNew.pgm";
	s[4] = "C:\\Users\\Abraheem\\Documents\\Visual Studio 2015\\Projects\\CS 210\\GroupAss#5\\Prob_2\\Prob_2\\NoiseFiles\\butterfly.pgm";
	d[4] = "C:\\Users\\Abraheem\\Documents\\Visual Studio 2015\\Projects\\CS 210\\GroupAss#5\\Prob_2\\Prob_2\\Filtered\\butterflyNew.pgm";
	s[5] = "C:\\Users\\Abraheem\\Documents\\Visual Studio 2015\\Projects\\CS 210\\GroupAss#5\\Prob_2\\Prob_2\\NoiseFiles\\girls.pgm";
	d[5] = "C:\\Users\\Abraheem\\Documents\\Visual Studio 2015\\Projects\\CS 210\\GroupAss#5\\Prob_2\\Prob_2\\Filtered\\girlsNew.pgm";
	s[6] = "C:\\Users\\Abraheem\\Documents\\Visual Studio 2015\\Projects\\CS 210\\GroupAss#5\\Prob_2\\Prob_2\\NoiseFiles\\noise.pgm";
	d[6] = "C:\\Users\\Abraheem\\Documents\\Visual Studio 2015\\Projects\\CS 210\\GroupAss#5\\Prob_2\\Prob_2\\Filtered\\noiseNew.pgm";
	s[7] = "C:\\Users\\Abraheem\\Documents\\Visual Studio 2015\\Projects\\CS 210\\GroupAss#5\\Prob_2\\Prob_2\\NoiseFiles\\petal.pgm";
	d[7] = "C:\\Users\\Abraheem\\Documents\\Visual Studio 2015\\Projects\\CS 210\\GroupAss#5\\Prob_2\\Prob_2\\Filtered\\petalNew.pgm";
	s[8] = "C:\\Users\\Abraheem\\Documents\\Visual Studio 2015\\Projects\\CS 210\\GroupAss#5\\Prob_2\\Prob_2\\NoiseFiles\\photos.pgm";
	d[8] = "C:\\Users\\Abraheem\\Documents\\Visual Studio 2015\\Projects\\CS 210\\GroupAss#5\\Prob_2\\Prob_2\\Filtered\\photosNew.pgm";
	s[9] = "C:\\Users\\Abraheem\\Documents\\Visual Studio 2015\\Projects\\CS 210\\GroupAss#5\\Prob_2\\Prob_2\\NoiseFiles\\saturn.pgm";
	d[9] = "C:\\Users\\Abraheem\\Documents\\Visual Studio 2015\\Projects\\CS 210\\GroupAss#5\\Prob_2\\Prob_2\\Filtered\\saturnNew.pgm";
	s[10] = "C:\\Users\\Abraheem\\Documents\\Visual Studio 2015\\Projects\\CS 210\\GroupAss#5\\Prob_2\\Prob_2\\NoiseFiles\\wroses.pgm";
	d[10] = "C:\\Users\\Abraheem\\Documents\\Visual Studio 2015\\Projects\\CS 210\\GroupAss#5\\Prob_2\\Prob_2\\Filtered\\wrosesNew.pgm";
	inFile = s[i];
	outFile = d[i];
}

void syncFile(string fileName, int **&A, int &height, int &width, int &maxValue) {
	ifstream in;
	in.open(fileName);
	if (in.is_open()) cout << "File successfully open" << endl;
	else cout << "Error opening File!!" << endl;
	string P2, w, h, mv;
	in >> P2;
	in >> width;
	in >> height;
	in >> maxValue;
	/*
	width = stoi(w);
	height = stoi(h);
	maxValue = stoi(mv);
	*/
	A = new int*[height];
	for (int i = 0; i <= height; i++) A[i] = new int[width];
	int count1 = 0, count2 = 0;
	for (int i = 1; i <= height&&!in.eof(); i++) 
		for (int j = 1; j <= width; j++)
			in >> A[i][j];
		
	
	in.close();
	/* 
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}*/
}

void AtoB(int **&A, int **&B, float &height, float &width, float scale) {
	height *= scale;
	width *= scale;
	B = new int*[height];
	for (int i = 0; i < height; i++) B[i] = new int[width];
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			B[i][j] = A[i][j];
		}
	}
	
	/*
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << B[i][j] << " ";
		}
		cout << endl;
	}*/
}

//Rotate like transpose
void AtoB2(int **&A, int **&B, int height, int width) {

	B = new int*[height];
	for (int i = 0; i < height; i++) B[i] = new int[width];
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			B[j][i] = A[height - i][j];
		}
	}

	/*
	for (int i = 0; i < h; i++) {
	for (int j = 0; j < w; j++) {
	cout << B[i][j] << " ";
	}
	cout << endl;
	}*/
}

//Rotate using linear transformations
void AtoB3(int **&A, int **&B, int height, int width) {
	int x, y;
	B = new int*[height];
	for (int i = 0; i < height; i++) B[i] = new int[width];

	vector<vector<vector<int> > > array3D;

	// Set up sizes. (HEIGHT x WIDTH)
	array3D.resize(height);
	for (int i = 0; i < height; ++i) {
		array3D[i].resize(width);

		for (int j = 0; j < width; ++j)
			array3D[i][j].resize(2);
	}

	int R[2][2];
	R[0][0] = 0;
	R[0][1] = 1;
	R[1][0] = -1;
	R[1][1] = 0;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			array3D[i][j][0] = ((R[0][0] * j) + (R[0][1] * i));
			array3D[i][j][1] = ((R[1][0] * j) + (R[1][1] * i));
		}
	}


	int oj = 0;
	int oi = height - 1;
	int nx, ny;
	for (int i = 0; i < height; i++) {
		y = oi - i;
		for (int j = 0; j < width; j++) {
			x = j - oj;
			nx = array3D[y][x][0];
			ny = oi + array3D[y][x][1];
			B[ny][nx] = A[i][j];
		}
	}


	/*
	for (int i = 0; i < h; i++) {
	for (int j = 0; j < w; j++) {
	cout << B[i][j] << " ";
	}
	cout << endl;
	}*/
}

void arrToFile(string fileName, int **A, int height, int width, int maxValue) {
	ofstream out;
	out.open(fileName);
	if (out.is_open()) cout << "File successfully open" << endl;
	else cout << "Error opening File!!" << endl;

	out << "P2 " << width << " " << height << " " << maxValue;

	/*
	width = stoi(w);
	height = stoi(h);
	maxValue = stoi(mv);
	*/
	
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			out << " " << A[i][j];

	out.close();
	/*
	for (int i = 1; i <= height; i++) {
	for (int j = 1; j <= width; j++) {
	cout << A[i][j] << " ";
	}
	cout << endl;
	}*/
}