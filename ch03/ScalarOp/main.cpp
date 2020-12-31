#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void ScalarOp() { // Scalar 클래스 활용 실습

	// Scalar 클래스 -> 4 채널 이하의 영상에서 픽셀 값을 표현하는 용도로 주로 사용
	// -> Scalar_ 클래스 템플릿의 재정의임.
	// Scalar_ 클래스는 Vec 클래스를 상속, 4 개의 원소를 가지고 있는 템플릿 클래스임.
	// Scalar_ 클래스는 템플릿 클래스이기 때문에 다양한 자료형에 대해 정의할 수 있음.
	// 특히, double 자료형을 사용하는 Scalar_ 클래스를 Scalar라고 재정의함.
	// 즉, Scalar 클래스는 크기가 4인 double형 배열 val을 멤버 변수로 가지는 자료형임.

	// Scalar 클래스는 보통 4 개 이하의 채널을 갖는 영상의 픽셀 값 표현
	// Grayscale ; 첫 번째 원소가 픽셀 밝기, 나머지 세 개의 원소는 0으로 설정
	// TrueColor ; 처음 세 개 원소가 B, R, R 색상 성분 값, 네 번째 원소는 보통 0으로 설정
	// PNG 파일 형식처럼 투명도를 표현하는 알파 채널 ; 네 번째 원소를 이용
	// Scalar(밝기) -> grayscale
	// Scalar(파란색, 녹색, 빨간색) -> truecolor
	// Scalar(파란색, 녹색 빨간색, 투명도) -> png

	Scalar gray = 128; // gray.val = [128, 0, 0, 0]
	cout << "gray : " << gray << endl;

	Scalar yellow(0, 255, 255); // yellow.val = [0, 255, 255, 0]
	cout << "yellow : " << yellow << endl;

	Mat img1(256, 256, CV_8UC3, yellow);

	for (int i = 0; i < 4; i++)
		cout << yellow[i] << endl; // yellow.val[i] 도 사용가능하지만 yellow[i]를 더 많이 사용함.
}

int main() {
	ScalarOp();
}
