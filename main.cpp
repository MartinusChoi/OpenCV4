// opencv2 ���� ������ ��ġ�ϴ� opencv.hpp ��� ���� ����
#include "opencv2/opencv.hpp"
// C++ ǥ�� ������� ���� iostream ��� ���� ����
#include <iostream>

// cv::�� std::�� �����ϱ� ���� �ڵ�
using namespace cv;
using namespace std;

int main() {
	// CV_VERSION -> ��ǻ�Ϳ� ��ġ�Ǿ� �ִ� OpenCV ���̺귯���� 
	// ���� ������ ���ڿ� ���·� ������ ��ũ��

	// C : printf() == C++ : std::cout << (���ڿ�) << std::endl;
	// std::endl == \n�� ���� (���๮��)

	cout << "Hello OpenCV " << CV_VERSION << endl;

	// Mat Ŭ����(cv::Mat) Ÿ���� ���� img ����
	Mat img;

	// imread()�Լ��� lenna.bmp������ �ҷ��ͼ� img ������ ����
	// imread() : ������ �о��. cv ���ӽ����̽� �ȿ��� ���� -> cv::imread()�� ���� ���
	img = imread("lenna.bmp");

	// ������ ����� �ҷ����� ������ ����� ���� ó��
	// ������ ����� �ҷ����� ���ϸ� Mat Ŭ������ ��� �Լ� Mat::empty()�� true�� ��ȯ��.

	if (img.empty()) {
		// std:cerr �� std::cout �� �޸� ��� ���� ���۸� ����.
		// ���� std::cout �ڿ� std::endl�� �ٿ��� ���۸� ���� ������ ���� �ʾƵ� �ȴ�.

		cerr << "Image load failed!" << endl;
		return -1;
	}

	// nameWindow() �Լ��� �̿��Ͽ� ������ ȭ�鿡 ����ϱ� ���� ���ο� â�� ����
	// �� â�� "image"��� �̸��� �ο�
	namedWindow("image");

	// imshow() �Լ��� �̿��Ͽ� "image"��� �̸��� â�� img ��ü�� ������ �ִ� ������ ���
	imshow("image", img);

	// waitKey() : ������� Ű���� �Է��� ��ٸ��� �Լ�
	// ����ڰ� Ű���带 ������ ������ ������ ȭ�鿡 ���
	// Ű���带 �Է��ϸ� �ڵ�󿡼� �� ������ �������� �ǰ�
	// ���� �������� return �� ������ ���α׷��� ����
	waitKey();

	return 0;
}