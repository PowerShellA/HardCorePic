#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <windows.h>

using namespace cv;
using namespace std;

int main(int args, char* argv[]){
	Mat frame;
	String savePath = argv[1];
	if (args == 2){
		frame = cv::imread(argv[1],1);
		savePath += "_out.jpg";
		cout <<"���ڴ���......"<<endl<<"���Ŀ¼ΪԴ�ļ�Ŀ¼: "<< savePath;

		srand(rand() % (20));
		int RANGE = (rand() % (16 - 11)) + 11;
		double PI = 3.1;
		Mat dst(frame.rows, frame.cols, CV_8UC3, Scalar(0));
		for (int j = 0; j < dst.cols; j++) {
			double temp = RANGE + RANGE * sin(j*PI * 20 / dst.cols);
			for (int i = int(temp + 0.5); i < dst.rows + temp - 2 * RANGE; i++) {
				int m = (int)((i - temp)*(frame.rows) / (dst.rows - RANGE));
				if (m >= frame.rows)
					m = frame.rows - 1;
				if (m < 0)
					m = 0;
				dst.at<Vec3b>(i, j)[0] = frame.at<Vec3b>(m, j)[0];
				dst.at<Vec3b>(i, j)[1] = frame.at<Vec3b>(m, j)[1];
				dst.at<Vec3b>(i, j)[2] = frame.at<Vec3b>(m, j)[2];
			}
		}
		cv::imwrite(savePath, dst);
		cout <<endl << "���" ;
	}
	else {
		cout << "�뽫Ҫ�����ͼƬ ��ק ����exe�ļ��Ͻ��д���";
		Sleep(3000);
	}
	return 0;
}