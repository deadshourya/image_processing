/*To detect motion of the object (Use blue color window)*/

//#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <queue>


using namespace cv;
using namespace std;

int main()
{
	Mat img;
	VideoCapture vc(0);
	int h = 10, s = 255, v = 255, t = 100;
	int l=10;

	while (1)
	{
		int count = 0;
		int count1 = 0;
		int count2 = 0;
		vc >> img;
		Mat img1;
		cvtColor(img, img1, CV_BGR2HSV);
		Mat color(img.rows, img.cols, CV_LOAD_IMAGE_GRAYSCALE);
		
		for (int i = 0; i < img.rows; i++)
		{
			for (int j = 0; j < img.cols; j++)
			{
				if (((h - t) <= img1.at<Vec3b>(i, j)[0]) && img1.at<Vec3b>(i, j)[0] <= (h + t) && ((s - t) <= img1.at<Vec3b>(i, j)[1]) && img1.at<Vec3b>(i, j)[1] <= (s + t) && ((v - t) <= img1.at<Vec3b>(i, j)[2]) && img1.at<Vec3b>(i, j)[2] <= (v + t))
				{
					color.at<uchar>(i, j) = 255;
				}
				else
				{
					color.at<uchar>(i, j) = 0;
				}
				
			}
		}
		imshow("hsv", color);
		for (int i = 0; i < img.rows; i++)
		{
			for (int j = (img.cols / 2) - 120; j < (img.cols / 2) + 120; j++)
			{
				if (color.at<uchar>(i, j) == 255)
					count++;
			}
		}
		for (int i = 0; i < img.rows; i++)
		{
			for (int j = (img.cols / 2) - 120; j >= 0; j--)
			{
				if (color.at<uchar>(i, j) == 255)
					count1++;
			}
		}
		for (int i = 0; i < img.rows; i++)
		{
			for (int j = (img.cols / 2) + 120; j < img.cols; j++)
			{
				if (color.at<uchar>(i, j) == 255)
					count2++;
			}
		}
		if (count > count1 && count > count2 && count > 100)
		{
			
			
			if (l != 0)
			{
				printf("MIDDLE\n");
				l = 0;
			}
		}

		if (count1 >count && count1 > count2 && count1 > 100)
		{
			
			if (l != 1)
			{
				printf("RIGHT\n");
				l = 1;
			}
		}
		if (count2>count1 && count2 > count && count2 > 100)
		{
		
		
			if (l != 2)
			{
				printf("LEFT\n");
				l = 2;
			}
		}
		
		int iKey = waitKey(50);
		//if user press 'ESC' key
		if (iKey == 27)
		{
			break;
		}
	}
	return 0;
}


