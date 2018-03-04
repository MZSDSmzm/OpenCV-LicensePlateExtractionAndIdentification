#include <iostream> 
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp> 
#include<opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp>
#include <math.h>
using namespace cv;
using namespace std;

int main()
{
	//装入图像
	Mat src = imread("C:\\text.jpg");
	if (!src.data) {
		return 0;
	}
	
	Mat bilateralFilterSrc;
	//双边滤波处理
	bilateralFilter(src, bilateralFilterSrc, 25, 25 * 2, 25 / 2);
	imshow("bilateralFilterSrc", bilateralFilterSrc);
	Mat src_gray;
	//转化为灰度图 
	cvtColor(bilateralFilterSrc, src_gray, CV_BGR2GRAY);
	imshow("src_gray", src_gray);
	
	//灰度直方图均衡化
	//equalizeHist(src_gray, src_gray);
	//imshow("equalizeHist", src_gray);

	//腐蚀与膨胀
	//erode(src_gray, src_gray, Mat(1, 1, CV_8U), Point(-1, -1),1);
	//dilate(src_gray, src_gray, Mat(5, 5, CV_8U), Point(-1, -1), 1);
	//morphologyEx(src_gray, src_gray, MORPH_OPEN, Mat(2, 2, CV_8U), Point(-1, -1), 1);
	morphologyEx(src_gray, src_gray, MORPH_CLOSE, Mat(2, 2, CV_8U), Point(-1, -1), 1);
	//imshow("dilate", src_gray);
	
	waitKey();
	return 0;
}
