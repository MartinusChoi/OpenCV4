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

void MatOp4() { // 픽셀(행렬 원소) 값 접근 방법 세가지

	// Mat::at() //

	// -> 행과 열을 나타내는 두 개의 정수를 인자로 받아
	// 해당 위치의 행렬 원소 값을 "참조 형식"으로 반환
	// 템플릿 함수임. -> 자료형 명시해야함.
	// CV_8UC1 ; uchar, CV_32FC1 ; float, CV_8UC3 ; Vec3b 자료형
	// template<typename _Tp> _Tp& Mat::at(int y, int x)
	Mat mat1 = Mat::zeros(3, 4, CV_8UC1);

	for (int j = 0; j < mat1.rows; j++) {
		for (int i = 0; i < mat1.cols; i++) {
			// mat1이 CV_8UC1 이므로 자료형을 uchar로 명시
			// Mat::at()이 행렬 원소를 참조로 반환하기 때문에
			// 함수의 반환값을 변경하면 mat1 행렬 원소값도 함께 변함.
			mat1.at<uchar>(j, i)++; // 행렬의 모든 값을 1 증가
		}
	}

	
	// Mat::ptr() //

	// Mat 행렬에서 인자로 전달된 y번째 행의 시작 주소를 반환
	// 행 단위로 행렬 원소를 참조하는 경우에 유용.
	// 앞선 Mat::at() 보다 빠르게 동작함.
	// 하지만 연산을 수행하지 않고 임의 좌표 원소에 빈번히 접근해야하는 경우 Mat::at() 가 편리함.
	// 템플릿으로 정의 -> 자료형 명시가 필요함.
	// 즉, 지정한 자료형의 포인터를 반환함. -> 이 포인터로 지정한 행의 원소에 접근 할 수 있음.
	// template<typename _Tp> _Tp* Mat::ptr(int y)
	for (int j = 0; j < mat1.rows; j++) {
		uchar* p = mat1.ptr<uchar>(j); // j번째 행 원소의 시작 주소를 반환
		for (int i = 0; i < mat1.cols; i++) {
			// *(p + i) == p[i] -> 포인터 연산으로 접근 가능!!
			p[i]++; // j번째 행의 맨 마지막 열에 해당하는 원소는 p[mat1.cols - 1] 형식으로 접근 가능.
		}
	}


	// MatIterator_ 반복자 사용 방법 //

	// Mat::at() 이나 Mat::ptr()의 경우 행렬의 크기를 고려하지 않으면 실행중 에러가 발생함.
	// 반복자를 사용하면 행렬 크기에 상관없이 행렬 전체 원소를 차례대로 참조함.
	// 템플릿 클래스임. -> Mat 행렬에 맞는 자료형 명시가 필요
	// for문을 두 개 써서 가로, 세로 참조 필요 x
	// MatIterator_ 반복자를 이용하면 가로 세로 크기 상관없이 행렬의 모든 원소를 안전하게 방문 가능.
	// 하지만 동작속도가 Mat::ptr() 사용 방법보다 느리고, Mat::at() 처럼 임의의 위치에 자유롭게 접근 불가능.
	// Mat::begin() ; 행렬의 첫 번째 원소 위치, Mat::end() -> 마지막 원소 바로 다음 위치
	for (MatIterator_<uchar> it = mat1.begin<uchar>(); it != mat1.end<uchar>(); it++) {
		(*it)++; // 반복자 변수 it가 가리키는 원소 값을 참조하기 위해 (*it)->포인터 참조 형태로 코드를 작성.
	}

	cout << "mat1:\n" << mat1 << endl;
}

void MatOp5() { // Mat 클래스를 이용하여 생성한 행렬 객체로부터 다양한 정보를 참조하는 방법
	
	Mat img1 = imread("lenna.bmp");

	// Mat 클래스 멤버 변수를 직접 참조 //

	// 행렬/영상의 크기정보
	// Mat::rows -> 행 개수(세로 픽셀 수), Mat::cols -> 열 개수(가로 픽셀 수)
	// 둘 모두 public 접근 지시자 -> 외부에서 직접 접근 가능
	cout << "Width : " << img1.cols << endl; // 영상의 가로 크기
	cout << "Height : " << img1.rows << endl; // 영상의 세로 크기

	// Mat::data 멤버 변수 -> 행렬 원소 데이터가 저장되어있는 메모리 공간의 시작 주소를 가리키는 포인터
	// 포인터 연산을 잘못 하면 에러가 발생하므로 Mat::at() 이나 Mat::ptr() 을 이용한 연산을 하는 것이 좋음.

	// Mat::chnnels() ; 행렬의 채널 수 반환
	// Mat::depth() ; 행렬의 깊이를 반환( CV_8U, CV_32F ...)
	// Mat::elemSize() ; 한 개의 원소가 차지하는 메모리크기를 바이트 단위 반환(CV_32SC3 -> 4(32bit) x 3(channels) = 12 반환)
	// Mat::empty() ; 비어 있는 행렬이면 true 반환
	// Mat::isContinuous ; 각 행의 원소가 연속적으로 저장되어있으면 true 반환
	// Mat::isSubmatrix() ; 행렬이 다른 행렬의 부분 행렬이면 true 반환
	// Mat::size() ; 행렬 크기를 Size 타입으로 반환
	// Mat::total() ; 전체 원소의 개수 반환
	// Mat::type() ; 행렬의 타입을 반환(CV_32FC1, CV_8UC3)

	// 아래에서 img1은 imread() 사용 시 두 번째 인자를 설정하지 않았기 때문에
	// 자동으로 IMREAD_COLOR가 지정되어 truecolor 영상으로 불러옴.
	if (img1.type() == CV_8UC1) { // 영상이 grayscale 이면
		cout << "img1 is grayscale image." << endl;
	}
	else if (img1.type() == CV_8UC3) { // 영상이 3 channels truecolor 영상이면
		cout << "img1 is truecolor image." << endl;
	}

	// Mat 객체에 저장된 행렬 속성이 아닌 원소 값을 직접 확인 하고 싶을 경우 //

	// Mat 클래스에 저장된 객체가 영상 -> imshow() 함수를 이용하여 화면에 표시 가능 (uchar 자료형)
	// Mat 객체에 int, float, double 자료형의 행렬이 저장되어있는 경우 -> imshow() 불가능
	// 이럴 때 C++ 표준 출력 스트림 std::cout를 이용.

	float data[] = { 2.f, 1.414f, 3.f, 1.732f };
	Mat mat1(2, 2, CV_32FC1, data);

	cout << "mat1 : \n" << mat1 << endl;
}

void MatOp6() { // Mat 클래스를 이요한 기본적인 행렬 연산, 역행렬, 전치 행렬 구하기

	float data[] = { 1, 1, 2, 3 };
	Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1 : \n " << mat1 << endl;

	// OpenCV에서는 행렬 연산을 위한 다양한 연사자 재정의 함수 제공
	// 각 사칙연산 연산자 재정의 함수의 반환형은 MatExpr
	// MatExpr -> Mat 객체, Scalar 객체, int, float, double 등 기본 자료형으로 구성된 행렬 표현
	// 복사 생성자 혹은 대입 연산자에 의해 Mat 객체로 변환 가능

	// mat3 = mat1 + mat2
	// mat3 = mat1 - mat2
	// -> 행렬 사이 덧셈 및 뺄셀 연산

	// mat3 = mat1 + s1
	// mat3 = mat1 - s1
	// mat3 = s1 + mat1
	// mat3 = s1 - mat1
	// -> 행렬과 스칼라 값 사이의 덧셈과 뺄셈 연산

	// mat3 = -mat1
	// -> mat1 행렬의 각 원소에 -1을 곱함

	// mat3 = mat1 * mat2
	// -> 행렬의 곱셈 연산 수행(원소간 곱셈 x)

	// mat3 = mat1 * d1
	// mat3 = d1 * mat1
	// 행렬의 각 원소에 스칼라 값을 곱함

	// mat3 = mat1 / mat2
	// -> 두 행렬의 같은 위치 원소끼리 나눗셈 연산

	// mat3 = mat1 / d1
	// mat3 = d1 / mat1
	// 행렬의 각 원소와 실수 끼리 나눗셈 연산 수행

	// 행렬 간 원소 간 곱셈 수행
	// Mat::mul() 멤버 함수 이용
	// Mat::mul(InputArray m, double scale=1)

	// 역행렬 구하기
	// Mat::inv() 멤버 함수 이용
	// Mat::inv(int method=DECOMP_LU)
	// method
	// -> DECOMP_LU ; 가우스 소거법을 이용
	// -> DECOMP_SVD ; 특잇값 분해를 이용하여 "의사 역행렬(pseudo-inverse matrix)" 반환
	// -> DECOMP_EIG ; 고윳값 분해 이용
	// -> DECOMP_CHOLESKY ; 촐레스키 분해 이용
	Mat mat2 = mat1.inv();
	cout << "mat2 : \n" << mat2 << endl;

	// 전치 행렬 구하기
	// Mat::t() 멤버 함수 사용
	cout << "mat1.t() : \n" << mat1.t() << endl;

	cout << "mat1 + mat2 : \n" << mat1 + mat2 << endl;
	cout << "mat1 - mat2 : \n" << mat1 - mat2 << endl;

	cout << "mat1 + 3 : \n" << mat1 + 3 << endl;
	cout << "mat1 - 3 : \n" << mat1 - 3 << endl;
	cout << "3 + mat1 : \n" << 3 + mat1 << endl;
	cout << "3 - mat1 : \n" << 3 - mat1 << endl;

	cout << "-mat1 : \n" << -mat1 << endl;

	cout << "mat1 * mat2 : \n" << mat1 * mat2 << endl;

	cout << "mat1 * 3 : \n" << mat1 * 3 << endl;
	cout << "3 * mat1 : \n" << 3 * mat1 << endl;

	cout << "mat1 / mat2 : \n" << mat1 / mat2 << endl;

	cout << "mat1 / 3 : \n" << mat1 / 3 << endl;
	cout << "3 / mat1 : \n" << 3 / mat1 << endl;

	cout << "mat1.mul(mat2) : \n" << mat1.mul(mat2) << endl;
}

void MatOp7() { // Mat 클래스의 크기 또는 타입을 변화시키는 멤버 함수들

	Mat img1 = imread("lenna.bmp", IMREAD_GRAYSCALE);
				
	// 행렬의 타입 변경 //
	
	// Mat::convertTo()
	// Mat::convertTo(OutputArray m, int rtype, double alpha=1, double betq=0) const;
	// m ; 출력 행렬. 만약 m 행렬이 적절한 크기/타입이 아니라면 행렬 원소 데이터를 새로 할당
	// rtype ; 원하는 출력 행렬 타입. 음수이면 입력행렬과 같은 타입을 설정
	// alpha ; 추가적으로 곱할 값
	// betq ; 추가적으로 더할 값
	// m(x, y) = saturate_cast<rtype> (alphax(*this)(x,y)+beta) 의 수식으로 각 원소값 결정
	Mat img1f;
	img1.convertTo(img1f, CV_32FC1); // 1channel 32bit float type으로 변환


	// 행렬의 크기 또는 채널 수 변경 // 

	// Mat::reshape()
	// Mat::reshape(int cn, int rows=0) const;
	// cn ; 새로운 채널의 수 (이 값이 0이면 채널 수를 변경하지 x)
	// rows ; 새로운 행의 수 (이 값이 0이면 채널 수를 변경하지 x)
	// 하나의 행렬 원소 데이터를 같이 참조하는 행렬을 반환(즉, 얕은 복사를 통한 행렬 반환)
	uchar data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	Mat mat1(3, 4, CV_8UC1, data); //3x4 의 행렬 생성
	Mat mat2 = mat1.reshape(0, 1); // 채널을 변경하지 않고(cn=0), 1개의 행을 가진 행렬로 변환(rows=1)

	cout << "mat1 : \n" << mat1 << endl;
	cout << "mat2 : \n" << mat2 << endl;

	
	// 행렬의 모양을 변경하지 않고 단순히 행렬의 행 크기를 변경 //

	// Mat::resize()
	// Mat::resize(size_t sz, const Scalar& s);
	// sz ; 새로운 행 개수
	// s ; 새로 추가되는 행 원소의 초기값
	// sz 가 기존 행렬의 행 개수보다 작으면 아래쪽 행 제거.
	// sz 가 기존 행렬의 행 개수보다 크면 아래쪽에 행 추가.
	mat1.resize(5, 100);
	cout << "resized : \n" << mat1 << endl;


	// 이미 존재하는 행렬에 원소 데이터 추가 //

	// Mat::push_back()
	// template<typename _Tp> void Mat::push_back(const _Tp& elem);
	// template<typename _Tp> void Mat::push_back(const Mat_<_Tp>& elem);
	// template<typename _Tp> void Mat::push_back(const std::vector<_Tp>& elem);
	// void Mat::push_back(const Mat& m);
	// elem ; 행렬의 맨 마지막에 추가할 원소 데이터
	// m ; 행렬의 맨 마지막 행에 추가할 행렬. (*this 와 타입과 열 개수가 같아야함.
	// push_back() 함수 인자로 _Tp& 이나 std::vector<_Tp>& 타입 사용 -> *this 행렬이 1열짜리 행렬이어야 함.
	// push_back() 함수 인자로 Mat_<_Tp>& 이나 Mat& 타입을 사용 -> *this 행렬과 인자로 전달된 m 행렬의 열 개수가 같아야 함.
	Mat mat3 = Mat::ones(1, 4, CV_8UC1) * 255;
	mat1.push_back(mat3);

	cout << "mat1.push_back(mat3) : \n" << mat1 << endl;


	// 행렬의 행 제거 //

	// Mat::pop_back()
	// Mat::pop_back(size_t nelems=1);
	// nelems ; 제거할 행 개수
	mat1.pop_back(3);

	cout << "mat.pop_back(3) : \n" << mat1 << endl;
}

int main() {
	MatOp1();
	MatOp2();
	MatOp3();
	MatOp4();
	MatOp5();
	MatOp6();
	MatOp7();
}
