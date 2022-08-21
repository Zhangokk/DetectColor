#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat imgLab,imgRGB,imgRUV, imgHSV;
Mat  mask1,mask2,mask3;
int hmin = 150, smin = 210, vmin =110;
int hmax = 190, smax = 250, vmax = 160;
int lmin=60, amin=140, bmin=140;
int lmax=85, amax=180, bmax=180;
int rmin=120, gmin=10, Bmin=20;
int rmax=160, gmav=30, Bmax=45;
//int ymin, umin, vmin;
//int ymax, umax, vmax;

int main()
{

	Mat img = imread("images/rub%02d.jpg");
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	cvtColor(img,imgLab, COLOR_BGR2Lab);
	cvtColor(img,imgRGB, COLOR_BGR2RGB);
	//cvtColor(img, imgRUV, COLOR_BGR2);



	while (true) {

		Scalar lower1(hmin, smin, vmin);
		Scalar upper1(hmax, smax, vmax);
		
		Scalar lower2(lmin, amin, bmin);
		Scalar upper2(lmax, amax, bmax);
		
		Scalar lower3(rmin, gmin, Bmin);
		Scalar upper3(rmax, gmav, Bmax);
		
		inRange(imgHSV, lower1, upper1, mask1);
		inRange(imgLab, lower2, upper2, mask2);
		inRange(imgRGB, lower3, upper3, mask3);

		imshow("Image", img);
		imshow("Image MaskHSV", mask1);
		imshow("Image MaskLab", mask2);
		imshow("Image MaskRGB", mask3);
		waitKey(1);

	}

	return 0;
}
