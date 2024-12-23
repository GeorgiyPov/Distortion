#pragma once
#include <iostream>
#include "opencv2/opencv.hpp"


class CalcDistortion
{
public:
	int Distortion;
	void ProcessImage(cv::Mat);
};

