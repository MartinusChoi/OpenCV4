#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void MatOp1() {
	
	// 기본 생성자 -> 아무런 인자를 받지 않음 //

	// img1은 비어 있는 객체로써, img1.rows, img1.cols, img1.data 모두 값이 0으로 저장됨.
	Mat img1;


	// Mat 객체를 생성함과 동시에 원소 값 저장을 위한 메모리 공간을 할당 //

	// rows와 cols로 행렬 크기 지정
	Mat img2(480, 640, CV_8UC1); //CV_8UC1 -> Grayscale 영상
	Mat img3(480, 640, CV_8UC3); //CV_8UC3 -> treucolor 영상
	// Size 클래스로 행렬 크기 지정
	// Size 클래스 -> 가로, 세로 순서로 크기를 입력받음.
	Mat img4(Size(640, 480), CV_8UC3); // Size(width, height)


	// Mat 객체를 입력함과 동시에 모든 원소 값을 특정 값으로 초기화 //

	// 초기값 S : Scalar 클래스 -> 4개의 실수 값을 저장할 수 있는 OpenCV 클래스
	Mat img5(480, 640, CV_8UC1, Scalar(128)); // 영상이 grayScale -> Scalar 멤버 변수 1개만 사용.
	// Scalar(0, 0, 255) -> 빨간색, B/G/R 순서로 지정
	Mat img6(480, 640, CV_8UC3, Scalar(0, 0, 255)); // 영상이 3채널 컬러 영상 -> Scalar 변수 3개 사용.
	// 모든 값 0으로 초기화
	Mat mat1 = Mat::zeros(3, 3, CV_32SC1);
	// 모든 값 1으로 초기화
	Mat mat2 = Mat::ones(3, 3, CV_32FC1);
	// identity matrix 생성
	Mat mat3 = Mat::eye(3, 3, CV_32FC1);


	// Mat 객체 생성 시, 기존에 이미 할당되어 있는 메모리 공간의 데이터를 행렬 원소 값으로 사용 //

	// 자체 메모리 할당을 하지 않고 외부 메모리 참조 -> 객체 생성이 빠름.
	// 외부 배열을 행렬 원소 값으로 사용할 때,
	// 외부 배열의 크기와 생성할 행렬 원소 개수가 같아야하고
	// 서로 사용하는 자료형도 같아야 함.
	// 원소 값과 외부 메모리 공간의 데이터 값이 상호 공유되어
	// 한쪽을 수정하면 다른 쪽도 함께 수정된다.
	float data[] = { 1, 2, 3, 4, 5, 6 };
	Mat mat4(2, 3, CV_32FC1, data); // data 배열을 행렬 원소로써 참조


	// Mat_ 클래스 사용하여 Mat 객체 생성 //

	// Mat_ 클래스 -> Mat 클래스 상속한 템플릿 클래스(자료형 명시 필요), 상호 변환 가능
	// << 연산자와 콤마(,)를 이용하여 간단하게 행렬 원소 값 설정 가능
	Mat_<float> mat5_(2, 3); // 2x3 크기의 Mat_ 클래스 객체 생성, 타입은 CV_32FC1 임.
	mat5_ << 1, 2, 3, 4, 5, 6; // << 연산자를 이용한 행렬 원소 설정
	Mat mat5 = mat5_; // Mat 클래스로 변환
	// 위를 한 줄로 요약
	Mat mat5_1 = (Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6);
	// C++11의 초기화 리스트를 이용한 행렬 초기화 방법 -> 생성자에 행렬 크기와 초기값을 중괄호를 이용한 리스트 형태로 전달.
	Mat mat6 = Mat_<float>({ 2, 3 }, { 1, 2, 3, 4, 5, 6 });


	// 비어있거나 이미 생성된 Mat 객체에 새로운 행렬을 할당 //

	// 함수 인자로 지정한 행렬 크기와 기존 행렬과 같으면 Mat::create()는 별다른 동작을 하지 않음.
	// 다르면 일단 기존 메모리 공간을 해제하고, 새로운 행렬 데이터 저장을 위한 메모리 공간 할당.
	// 하지만 원소 값 초기화 기능은 없음 -> = 연산자 혹은 Mat::setTo() 함수를 이용하여 행렬 전체 원소 값 한꺼번에 설정 가능.
	mat4.create(256, 256, CV_8UC3);
	mat5.create(4, 4, CV_32FC1);
	
	mat4 = Scalar(255, 0, 0); // 모든 픽셀을 파란색으로 설정
	mat5.setTo(1.f);
}

int main() {
	MatOp1();
}
