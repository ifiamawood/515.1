// 515.1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include"stdafx.h"  
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;


int main()
 {
 	cv::Mat srcMat = imread("D:\\2.jpg", 0);
 	cv::Mat dstMat;

	if (srcMat.empty()) {
 		cout << "fail to read pic!" << endl;
 		return -1;

	}

	//0.����ͼ�������� 8λ��ͨ�� 
	//1.���ͼ��������ͬ���ߴ�ͬ������ 
 	if (srcMat.type() == CV_8UC1) {
 		equalizeHist(srcMat, dstMat);

	} 	else if (srcMat.type() == CV_8UC3) {
		Mat channel[3];
 		Mat out[3];
		split(srcMat, channel);


		for (int i = 0; i < 3; i++) {
			equalizeHist(channel[i], out[i]);

		}

		merge(out, 3, dstMat);
	
	}
 	//����ֱ��ͼ 
 	float srcHist[256];
 	float dstHist[256];
 	cv::Mat srcHistMat;
 	cv::Mat dstHistMat;
 	//calcIntenHist(srcMat, srcHist); 
	//calcSimpleHist(dstMat, dstHist); 
	//drawSimpleHist(srcHistMat, srcHist,3,100); 
 	//drawSimpleHist(dstHistMat, dstHist,3,100); 
 	imshow("srcMat", srcMat);
 	imshow("dstMat", dstMat);
 	/*imshow("srcHistMat", srcHistMat);
 	imshow("dstHistMat", dstHistMat);*/
 	waitKey(0);

 	destroyAllWindows();

 	return 0;


 }


