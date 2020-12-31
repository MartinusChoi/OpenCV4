#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void printMat(InputArray _mat) { // 인자의 자료형을 InputArray 로 설정
	Mat mat = _mat.getMat(); // 실제 사용시 .getMat() 함수로 Mat 객체로 변환하여 사용
	cout << mat << endl;
}

void InputArrayOp() { // OpenCV 함수 인자로 자주 사용되는 InputArray 클래스 실습.

	// InputArray 클래스 -> Mat, vector<T> 등 다양한 타입을 표현할 수 있는 인터페이스 클래스
	// 주로 함수의 입력 인자 자료형으로 사용
	// _InputArray 클래스의 재정의임.
	// _InputArray 클래스 -> Mat, Mat_<T>, Matx<T, m, n>, vector<T>, vector< vector<T> > 등
	// 다양한 타입으로 부터 생성될 수 있는 인터페이스 클래스
	// 사용자가 명시적으로 _InputArray 클래스의 인스턴스 또는 변수를 생성하는 것은 금지되어있음(인터페이스 클래스임.)

	// 함수의 인자가 InputArray 타입을 받도록 설명되어있다면
	// "Mat 클래스 객체" 혹은 "vector<T> 타이의 변수"를 전달하는 형태로 코드를 작성해야함.
	// -> InputArray 타입의 함수 인자에 비어 있는 행렬 전달 -> 함수 인자에 "noArray()" 혹은 "Mat()"를 입력

	// OpenCV에서 제공하는 함수처럼 "Mat 객체"뿐 아니라 "vector<T>"타입의 객체를 한꺼번에 전달받을 수 있도록 하려면
	// 함수 인자에 InputArray 자료형을 사용함.
	// 단, 함수 본문에서 해당 인자를 사용시 _InputArray 클래스의 멤버 함수인 _InputArray::getMat() 함수를 사용하여
	// Mat 객체 타입 형태로 변환하여 사용해야 함.
	// Mat _InputArray::getMat(int idx=-1)
	// idx ; 참조할 행 번호 ( 음수 값이면 행렬 전체를 참조)

	uchar data1[] = { 1, 2, 3, 4, 5, 6 };
	Mat mat1(2, 3, CV_8UC1, data1);
	printMat(mat1);

	vector<float> vec1 = { 1.2f, 3.4f, -2.1f };
	printMat(vec1);
}

int main() {
	InputArrayOp();
}
