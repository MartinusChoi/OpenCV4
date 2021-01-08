#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void drawLines() // 직선 그리기
{
	//// OpenCV의 직선 그리기 함수 ; line() 함수 ////

	// void line(InputOutputArray img, Point pt1, Point pt2, const Scalar& color,
	//				int thickness = 1, int lineType = LINE_8, int shift = 0);

	// img ; 입출력 영상
	// pt1 ; 시작점
	// pt2 ; 끝점
	// color ; 선 색상(또는 밝기)
	// thickness ; 선 두께
	// lineType ; 선 타임, (LINE_4, LINE_8, LINE_AA 중 하나를 지정)
	// shift ; 그리기 좌표 값의 축소 비율(오른쪽 비트 시프트(>>) 연산)

	// line() ; pt1부터 pt2 까지의 직선을 그림.
	
	// 선의 색상과 밝기 -> color 인자로 지정할 수 있음.
	// Scalar(0, 0, 255)를 전달하면 빨간색으로 설정할 수 있음
	// 그레이 스케일 영상에 검은색 선을 그리려면 0 또는 Scalar(0)을 전달

	// LineTypes -> 선을 그리는 방식
	// LINE_4 ; 4방향 연결 (상하좌우)
	// LINE_8 ; 8방향 연결 (상하좌우 + 대각선)
	// LINE_AA ; 안티에일리어싱(anti-aliasing) (조금 더 부드럽게)

	// shift ; 지정한 크기만큼 직선 좌표 값을 오른쪽 비트 시프트 연산을 수행하여 그리기 수행
	// 이 값이 0 -> 지정한 좌표를 그대로 사용하여 그리기를 수행함.
	
	// thinkness, linetype, shift 인자는 기본값 지정 -> 지정 생략 가능


	//// 화살표 그리기 ////

	// arrowedLine() 함수 이용
	// void arrowedLine(InputOutputArray img, Point pt1, Point pt2, const Scalar& color,
	//					int thinkness=1, int line_type=8, int shift=0, double tipLenght=0.1);

	// line_type ; 선 타입 (LINE_4, LINE_8, LINE_AA 중 하나 지정
	// shift ; 그리기 좌표 축소 비율(오른쪽 비트 시프트(>>) 연산)
	// tipLength ; 전체 직선 길이에 대한 화살표 길이의 비율

	
	//// 직선 그리기 함수를 이용한 다양한 모양의 마커 그리기 ////

	// drawMarker() 함수 이용
	// void drawMaker(InputOutputArray img, Point position, const Scalar& coloar,
	//					int markerType = MARKER_CROSS, int markerSize = 20, int thinkness = 1,
	//					int line_type = 8);

	// position ; 입출력 영상
	// markerType ; 마커 종류 (MarkerTypes 열거형 상수 중 하나를 지정)
	// markerSize ; 마커 크기

	// MarkerTypes 열거형 상수
	// 1. MARKER_CROSS ; 십자가 모양(+모양)
	// 2. MARKER_TILTED_CROSS ; 45도 회전된 십자가 모양(X 모양)
	// 3. MARKER_STAR ; MARKER_CROSS와 MARKER_TILTED_CROSS 모양이 합쳐짐(*모양)
	// 4. MARKER_DIAMOND ; 마름모 모양
	// 5. MARKER_SQUARE ; 정사각형 모양
	// 6. MARKER_TRIANGLE_UP ; 위로 뾰족한 삼각형
	// 7. MARKER_TRIANGLE_DOWN ; 아래로 뾰족한 삼각형

	// 흰색 빈 400x400 크기의 3채널 영상 생성
	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

	// (50, 50)->(200,50) , R=255, 두께=1
	line(img, Point(50, 50), Point(200, 50), Scalar(0, 0, 255));
	// (50, 100)->(200, 100), B=255+R=255, 두께=3
	line(img, Point(50, 100), Point(200, 100), Scalar(255, 0, 255), 3);
	// (50, 150)->(200, 150), B=255, 두께=10
	line(img, Point(50, 150), Point(200, 150), Scalar(255, 0, 255), 10);

	// 4 방향 연결 line type
	line(img, Point(250, 50), Point(350, 100), Scalar(0, 0, 255), 1, LINE_4);
	// 8 방향 연결 line type
	line(img, Point(250, 70), Point(350, 120), Scalar(255, 0, 255), 1, LINE_8);
	// anti-aliasing line type
	line(img, Point(250, 90), Point(350, 140), Scalar(255, 0, 0), 1, LINE_AA);

	arrowedLine(img, Point(50, 200), Point(150, 200), Scalar(0, 0, 255), 1);
	arrowedLine(img, Point(50, 250), Point(150, 250), Scalar(255, 0, 255), 1);
	arrowedLine(img, Point(50, 300), Point(150, 300), Scalar(255, 0, 0), 1, LINE_8, 0, 0.05);

	drawMarker(img, Point(50, 350), Scalar(0, 0, 255), MARKER_CROSS);
	drawMarker(img, Point(100, 350), Scalar(0, 0, 255), MARKER_TILTED_CROSS);
	drawMarker(img, Point(150, 350), Scalar(0, 0, 255), MARKER_STAR);
	drawMarker(img, Point(200, 350), Scalar(0, 0, 255), MARKER_DIAMOND);
	drawMarker(img, Point(250, 350), Scalar(0, 0, 255), MARKER_SQUARE);
	drawMarker(img, Point(300, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_UP);
	drawMarker(img, Point(350, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_DOWN);

	imshow("img", img);
	waitKey();

	destroyAllWindows();
}

void drawPolys() // 도형 그리기
{
	//// 사각형 그리기 ////

	// rectangle() 함수 이용
	// 그릴 사각형 정보는 "사각형의 대각 위치의 두 꼭지점 좌표" 혹은 "Rect 클래스 타입의 객체"를 이용
	// 두 가지 형식의 revtangle() 함수 정의
	// void rectangle(InputOutputArray img, Point pt1, Point pt2, const Scalar& color,
	//					int thickness = 1, int lineType = LINE_8, int shift = 0);
	// void rectangle(InputOutputArray img, Rect rev, const Scalar& color,
	//					int thickness = 1, int linType = LINE_8, int shift = 0);

	// thinkcess 값에 -1과 같은 음수나 "FILLED 열거형 상수"를 지정하면, 내부를 채운 사각형을 그림.


	//// 원 그리기 ////
	
	// circle() 함수 이용
	// 원의 중심점 좌표와 반지름 지정
	// void circle(InputOutputArray img, Point center, int radius,
	//				const Scalar& color, int thickness = 1,
	//				int lineType = LINE_8, int shift = 0);


	//// 타원 그리기 ////

	// ellipse() 함수 -> "타원" 혹은 타원의 일부인 "호"를 그릴 수 있음.
	// ellipse(InputOutputArray img, Point center, size axes,
	//			double angel, double startAngle, double endAngle,
	//			int lineType = LINE_8, int shift = 0);

	// axes ; 타원의 반지름 (Size(x축 반지름, y축 반지름))
	// angle ; 타원 회전 각도 (x축 기준, 시계 방향) -> 회전된 타원을 그릴 수 있음.
	// startAngle ; 타원 호의 시작 각도 (x축 기준, 시계 방향)
	// endAngle ; 타원 호의 끝 각도 (x축 기준, 시계 방향)

	// startAngle 과 endAngle을 적절히 사용하여 호를 그리는 용도로 사용 가능.


	//// 임의의 다각형 그리기 ////

	// polylines() 함수 -> 다각형의 꼭지점 좌표 전달 필요
	// 꼭지점 좌표는 보통 vector<Point> 자료형에 저장하여 전달함.

	// void polyLines(InputOutputArray img, InputArrayOfArrays pts,
	//					bool isClosed, const Scalar& color,
	//					int thickness = 1, int lineType = LINE_8, int shift = 0);

	// pts ; 다각형 외곽 점들의 좌표 배열. 주로 vector<Point> 타입
	// isClosed ; 다각형이 닫혀 있는지를 나타내는 플래그. 
	// 이 값이 ture이면 다각형의 마지막 꼭지점과 첫 번째 꼭지점을 잇는 직선을 추가로 그림.
	
	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

	rectangle(img, Rect(50, 50, 100, 50), Scalar(0, 0, 255), 2);
	rectangle(img, Rect(50, 150, 100, 50), Scalar(0, 0, 128), -1);

	circle(img, Point(300, 120), 30, Scalar(255, 255, 0), -1, LINE_AA);
	circle(img, Point(300, 120), 60, Scalar(255, 0, 0), 3, LINE_AA);

	// 20도 기울어지고 0도 부터 시계방향으로 270도 까지만 타원을 그림. 내부가 채워짐.
	ellipse(img, Point(120, 300), Size(60, 30), 20, 0, 270, Scalar(255, 255, 0), -1, LINE_AA);
	// 20도 기울어지고 0도 부터 시계방향으로 360도 까지 다 그림. 두께가 2 임.
	ellipse(img, Point(120, 300), Size(100, 50), 20, 0, 360, Scalar(0, 255, 0), 2, LINE_AA);

	// polyLines() 함수의 pts에 전달하기 위한 vector<Point> 객체
	vector<Point> pts;
	pts.push_back(Point(250, 250)); pts.push_back(Point(300, 250));
	pts.push_back(Point(300, 300)); pts.push_back(Point(350, 300));
	pts.push_back(Point(350, 350)); pts.push_back(Point(250, 350));
	
	polylines(img, pts, true, Scalar(255, 0, 255), 2);

	imshow("img", img);
	waitKey();

	destroyAllWindows();

}

int main() {
	// 다양한 그리기 함수
	// 영상 출력 창 위에 검출된 영역을 사각형으로 표시 하는 것과 같이
	// 직접 표시하는 것이 보기 좋을 경우가 많음.

	drawLines();
	drawPolys();
}