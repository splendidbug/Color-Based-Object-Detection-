//*****************************************************************************
//
// Image.h : Defines the class operations on images
//
// Author - Parag Havaldar
// Main Image class structure 
//
//*****************************************************************************

#ifndef IMAGE_DISPLAY
#define IMAGE_DISPLAY

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"
#include "afxwin.h"

// C RunTime Header Files
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <cstdlib> 
#include <limits>
using namespace std;

// Class structure of Image 
// Use to encapsulate an RGB image
class MyImage 
{

private:
	int		Width;					// Width of Image
	int		Height;					// Height of Image
	char	ImagePath[_MAX_PATH];	// Image location
	unsigned char*	Data;					// RGB data of the image

public:
	// Constructor
	MyImage();
	// Copy Constructor
	MyImage::MyImage( MyImage *otherImage);
	// Destructor
	~MyImage();

	// operator overload
	MyImage & operator= (const MyImage & otherImage);

	// Reader & Writer functions
	void	setWidth( const int w)  { Width = w; }; 
	void	setHeight(const int h) { Height = h; }; 
	void	setImageData( const char *img ) { Data = (unsigned char *)img; };
	void	setImagePath( const char *path) { strcpy(ImagePath, path); }
	int		getWidth() { return Width; };
	int		getHeight() { return Height; };
	unsigned char*	getImageData() { return Data; };
	char*	getImagePath() { return ImagePath; }

	// Input Output operations
	bool	ReadImage();
	bool	WriteImage();

	//rgb to hsv
	void RGBtoHSV(int R, int G, int B, float& H, float& S, float& V);
	unsigned char* parseRGB(const char* path);
	
	void plotBox(vector<unordered_set<int>> consideredClusters, string args);
	pair<vector<int>, vector<unordered_set<int>>> kMeans(const vector<int>& data, int K);
	
	vector <pair< vector<unordered_set<int>>, string> > makeCluster(vector< vector<vector<int>>>& imageHSV, vector< vector<vector<int>>>& objectHSV, unordered_map<int, vector<int>>& pixelToHSV, vector<string> args);
	// Modifications
	vector <pair< vector<unordered_set<int>>, string> > Modify(vector<string> args);

};

#endif //IMAGE_DISPLAY
