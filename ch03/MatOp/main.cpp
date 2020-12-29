#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void MatOp1() { // 행렬을 생성하고 초기화하는 다양한 방법
	
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

void MatOp2() { //행렬 객체를 다른 행렬 객체에 대입하거나 복사하는 다양한 방법.
	Mat img1 = imread("dog.bmp");

	// 복사 생성자 or 대입 연산자 사용 //

	// 복사 생성자 사용
	// 복사 생성자 -> img1과 같은 크기, 타입의 Mat 객체 img2를 생성하고,
	// img1의 픽셀 데이터를 img2가 참조하도록 함 -> 즉, 하나의 영상을 공유하는 서로 다른 객체가 됨,
	// 이를 "얕은 복사(shallow copy)"라고 함.
	Mat img2 = img1; // 복사 생성자(얕은 복사)

	// 대입 연산자 사용
	// 마찬가지로 "얕은 복사"가 이루어짐.
	Mat img3;
	img3 = img1;


	// 얕은 복사 가 아닌 메모리 공간을 새로 할당하여 픽셀 데이터 전체를 복사하는 경우 //
	// 깊은 복사(deep copy)
	// Mat::clone() 또는 Mat::copyTo()를 사용

	// Mat::clone() -> 자기 자신과 동일한 Mat 객체를 완전히 새로 만들어서 반환.
	Mat img4 = img1.clone(); // 깊은 복사

	// Mat::copyTo() -> 인자로 전달된 행렬에 자기 자신을 복사
	// 호출한 행렬과 인자로 전달될 행렬이 서로 크기와 타입이 같으면 -> 원소 값 복사만 수행
	// 크기와 타입이 다르면 -> 행렬을 새로 생성한 후 메모리를 새로 할당하여 픽셀 값을 복사.
	Mat img5;
	img1.copyTo(img5); // 깊은 복사


	// 깊은 복사와 얕은 복사의 차이 //

	img1.setTo(Scalar(0, 255, 255)); // 노란색으로 img1 설정

	imshow("img1", img1);
	imshow("img2", img2); // 얕은 복사 -> img1 과 함께 변함.
	imshow("img3", img3); // 얕은 복사 -> img1 과 함께 변함.
	imshow("img4", img4); // 깊은 복사 -> img1 가 변해도 변하지 않음.
	imshow("img5", img5); // 깊은 복사 -> img1 가 변해도 변하지 않음.

	waitKey();
	destroyAllWindows();
}

void MatOp3() { // 영상에서 사각형 모양의 부분 영상을 추출하거나 참조하는 다양한 방법

	// Mat 클래스에 저장된 영상에서 사각형 모양의 부분 영상 추출 //

	Mat img1 = imread("cat.bmp");

	if (img1.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	// 괄호 연산자 재정의
	// Rect 클래스 -> (220, 120) 부터 340x240(widthxheight) 만큼의 부분 영상을 img2에 저장
	// Mat 클래스의 괄호 연산자를 이용하여 얻은 부분 영상은 "얕은 복사" 형식임
	// 이를 이용하여 영상의 특정 부분에만 영상 처리를 수행할 수 있음. -> 픽셀 데이터를 공유하기 때문.
	// 이러한 Mat 클래스의 부분 영상 참조 기능은 입력 영상에 "ROI(Region Of Interest)"를 설정하는 용도로 사용가능
	Mat img2 = img1(Rect(220, 120, 340, 240)); // 얕은 복사
	
	// 독립된 메모리 영역 확보하여 부분영상 추출
	// Mat::clone 활용하기
	Mat img3 = img1(Rect(220, 120, 340, 240)).clone();

	// Mat 행렬에서 특정 범위의 행을 참조/추출
	Mat img4 = img1.rowRange(120, 361); // 참조(얕은 복사)
	Mat img5 = img1.rowRange(Range(120, 361)).clone(); //추출(깊은 복사)

	// Mat 행렬에서 특정 범위의 열을 참조/추출
	Mat img6 = img1.colRange(220, 561); // 참조(얕은 복사)
	Mat img7 = img1.colRange(Range(220, 561)).clone(); // 추출(깊은 복사)

	// Mat 행렬에서 하나의 행을 참조/추출
	Mat img8 = img1.row(120); // 참조(얕은 복사)
	Mat img9 = img1.row(120).clone(); // 추출(깊은 복사)

	// Mat 행렬에서 하나의 열을 참조/추출
	Mat img10 = img1.col(220); // 참조(얕은 복사)
	Mat img11 = img1.col(220).clone(); // 추출(깊은 복사)

	// 얕은 복사의 특성을 이용한 영상의 부분에만 반전 처리하기
	// 컬러 영상의 경우 각각의 색상 성분에 대해 반전을 수행
	// ~ 연산자를 붙이는 방식으로 적용가능.
	img2 = ~img2;

	imshow("image1", img1); // 원본 영상
	imshow("image2", img2); // ROI (얕은 복사로 부분영상 참조)
	imshow("image3", img3); // 깊은 복사로 부분영상 추출
	imshow("image4", img4); // 특정 범위 행 참조 (ROI의 모든 열, 얕은 복사)
	imshow("image5", img5); // 특정 범위 행 추출 (ROI의 모든 열, 깊은 복사)
	imshow("image6", img6); // 특정 범위 열 참조 (ROI의 모든 행, 얕은 복사)
	imshow("image7", img7); // 특정 범위 열 추출 (ROI의 모든 행, 깊은 복사)
	imshow("image8", img8); // 하나의 행 참조
	imshow("image9", img9); // 하나의 행 추출
	imshow("image10", img10); // 하나의 열 참조
	imshow("image11", img11); // 하나의 열 추출

	waitKey();
	destroyAllWindows();
}

int main() {
	MatOp1();
	MatOp2();
	MatOp3();
}
