// opencv2 하위 폴더에 위치하는 opencv.hpp 헤더 파일 포함
#include "opencv2/opencv.hpp"
// C++ 표준 입출력을 위한 iostream 헤더 파일 포함
#include <iostream>

// cv::와 std::를 생략하기 위한 코드
using namespace cv;
using namespace std;

int main() {
	// CV_VERSION -> 컴퓨터에 설치되어 있는 OpenCV 라이브러리의 
	// 버전 정보를 문자열 형태로 정의한 매크로

	// C : printf() == C++ : std::cout << (문자열) << std::endl;
	// std::endl == \n과 같음 (개행문자)

	cout << "Hello OpenCV " << CV_VERSION << endl;

	// Mat 클래스(cv::Mat) 타입의 변수 img 선언
	Mat img;

	// imread()함수로 lenna.bmp파일을 불러와서 img 변수에 저장
	// imread() : 영상을 읽어옴. cv 네임스페이스 안에서 선언 -> cv::imread()와 같이 사용
	img = imread("lenna.bmp");

	// 파일을 제대로 불러오지 못했을 경우의 예외 처리
	// 파일을 제대로 불러오지 못하면 Mat 클래스의 멤버 함수 Mat::empty()는 true를 반환함.

	if (img.empty()) {
		// std:cerr 은 std::cout 와 달리 출력 이후 버퍼를 비운다.
		// 따라서 std::cout 뒤에 std::endl을 붙여서 버퍼를 비우는 행위를 하지 않아도 된다.

		cerr << "Image load failed!" << endl;
		return -1;
	}

	// nameWindow() 함수를 이용하여 영상을 화면에 출력하기 위한 새로운 창을 생성
	// 그 창에 "image"라는 이름을 부여
	namedWindow("image");

	// imshow() 함수를 이용하여 "image"라는 이름의 창에 img 객체가 가지고 있는 영상을 출력
	imshow("image", img);

	// waitKey() : 사용자의 키보드 입력을 기다리는 함수
	// 사용자가 키보드를 누르기 전까지 영상을 화면에 출력
	// 키보드를 입력하면 코드상에서 이 구문을 지나가게 되고
	// 다음 구문에서 return 을 만나서 프로그램이 종료
	waitKey();

	return 0;
}