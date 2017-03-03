#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>


using namespace cv;
using namespace std;


Mat frame;


int main()
{       int v=0,va=0,aa=0,a=0,f,fa;
        
	namedWindow("window");
	//namedWindow("window1");
	int c=0;
	

	VideoCapture video("/home/shourya/Documents/ip/new.mp4");//video >> frame;cvtColor(frame,frame, CV_RGB2HSV);imwrite( "/home/shourya/Documents/ip/a.jpg", frame );
    
       while (1)
    {
        video >> frame;

	cvtColor(frame,frame, CV_RGB2HSV);

	f=0,fa=0;

        Mat bw(frame.rows,frame.cols, CV_8UC3, 255), bw1(frame.rows,frame.cols, CV_8UC3, 255);

	GaussianBlur(frame,frame, Size(21,21), 2, 2);

	Canny( frame, bw, 10, 200,3 );

      for(int j=0;j<79;j++)
	for(int i=498;i>233;i--)
	{
		bw1.at<Vec3b>(i, j)[2]=frame.at<Vec3b>(i, j)[2];
		bw1.at<Vec3b>(i, j)[1]=frame.at<Vec3b>(i, j)[1];
		bw1.at<Vec3b>(i, j)[0]=frame.at<Vec3b>(i, j)[0];
	}

    for(int j=0;j<79;j++)for(int i=498;i>233;i--)
	{
		if(frame.at<Vec3b>(i, j)[0]==95&&frame.at<Vec3b>(i, j)[2]==255)
			f++;
	}

    for(int j=1055;j<1135;j++)for(int i=553;i>290;i--)
	{
		if(frame.at<Vec3b>(i, j)[0]==95&&frame.at<Vec3b>(i, j)[2]==2255)
			fa++;
	}

   

   if(f>9)
	a++;
   else 
	a=0;
   if(fa>9)
	aa++;
   else 
	aa=0;

   if(f>9&&a==9)
	cout<<"team A goal - "<<++v<<"\n";
   if(fa>9&&aa==9)
	cout<<"team B goal - "<<++va<<"\n";






	imshow("window",frame);
       // imshow("window1", bw1);
        if (waitKey(33) == 27)
            break;
    }cout<<"\n\n\tscore card\n__________________________\nteam A - "<<v<<"\tteam B - "<<va<<"\n\n\n";
}




