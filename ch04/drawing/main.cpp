#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void drawLines() // ���� �׸���
{
	//// OpenCV�� ���� �׸��� �Լ� ; line() �Լ� ////

	// void line(InputOutputArray img, Point pt1, Point pt2, const Scalar& color,
	//				int thickness = 1, int lineType = LINE_8, int shift = 0);

	// img ; ����� ����
	// pt1 ; ������
	// pt2 ; ����
	// color ; �� ����(�Ǵ� ���)
	// thickness ; �� �β�
	// lineType ; �� Ÿ��, (LINE_4, LINE_8, LINE_AA �� �ϳ��� ����)
	// shift ; �׸��� ��ǥ ���� ��� ����(������ ��Ʈ ����Ʈ(>>) ����)

	// line() ; pt1���� pt2 ������ ������ �׸�.
	
	// ���� ����� ��� -> color ���ڷ� ������ �� ����.
	// Scalar(0, 0, 255)�� �����ϸ� ���������� ������ �� ����
	// �׷��� ������ ���� ������ ���� �׸����� 0 �Ǵ� Scalar(0)�� ����

	// LineTypes -> ���� �׸��� ���
	// LINE_4 ; 4���� ���� (�����¿�)
	// LINE_8 ; 8���� ���� (�����¿� + �밢��)
	// LINE_AA ; ��Ƽ���ϸ����(anti-aliasing) (���� �� �ε巴��)

	// shift ; ������ ũ�⸸ŭ ���� ��ǥ ���� ������ ��Ʈ ����Ʈ ������ �����Ͽ� �׸��� ����
	// �� ���� 0 -> ������ ��ǥ�� �״�� ����Ͽ� �׸��⸦ ������.
	
	// thinkness, linetype, shift ���ڴ� �⺻�� ���� -> ���� ���� ����


	//// ȭ��ǥ �׸��� ////

	// arrowedLine() �Լ� �̿�
	// void arrowedLine(InputOutputArray img, Point pt1, Point pt2, const Scalar& color,
	//					int thinkness=1, int line_type=8, int shift=0, double tipLenght=0.1);

	// line_type ; �� Ÿ�� (LINE_4, LINE_8, LINE_AA �� �ϳ� ����
	// shift ; �׸��� ��ǥ ��� ����(������ ��Ʈ ����Ʈ(>>) ����)
	// tipLength ; ��ü ���� ���̿� ���� ȭ��ǥ ������ ����

	
	//// ���� �׸��� �Լ��� �̿��� �پ��� ����� ��Ŀ �׸��� ////

	// drawMarker() �Լ� �̿�
	// void drawMaker(InputOutputArray img, Point position, const Scalar& coloar,
	//					int markerType = MARKER_CROSS, int markerSize = 20, int thinkness = 1,
	//					int line_type = 8);

	// position ; ����� ����
	// markerType ; ��Ŀ ���� (MarkerTypes ������ ��� �� �ϳ��� ����)
	// markerSize ; ��Ŀ ũ��

	// MarkerTypes ������ ���
	// 1. MARKER_CROSS ; ���ڰ� ���(+���)
	// 2. MARKER_TILTED_CROSS ; 45�� ȸ���� ���ڰ� ���(X ���)
	// 3. MARKER_STAR ; MARKER_CROSS�� MARKER_TILTED_CROSS ����� ������(*���)
	// 4. MARKER_DIAMOND ; ������ ���
	// 5. MARKER_SQUARE ; ���簢�� ���
	// 6. MARKER_TRIANGLE_UP ; ���� ������ �ﰢ��
	// 7. MARKER_TRIANGLE_DOWN ; �Ʒ��� ������ �ﰢ��

	// ��� �� 400x400 ũ���� 3ä�� ���� ����
	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

	// (50, 50)->(200,50) , R=255, �β�=1
	line(img, Point(50, 50), Point(200, 50), Scalar(0, 0, 255));
	// (50, 100)->(200, 100), B=255+R=255, �β�=3
	line(img, Point(50, 100), Point(200, 100), Scalar(255, 0, 255), 3);
	// (50, 150)->(200, 150), B=255, �β�=10
	line(img, Point(50, 150), Point(200, 150), Scalar(255, 0, 255), 10);

	// 4 ���� ���� line type
	line(img, Point(250, 50), Point(350, 100), Scalar(0, 0, 255), 1, LINE_4);
	// 8 ���� ���� line type
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

void drawPolys() // ���� �׸���
{
	//// �簢�� �׸��� ////

	// rectangle() �Լ� �̿�
	// �׸� �簢�� ������ "�簢���� �밢 ��ġ�� �� ������ ��ǥ" Ȥ�� "Rect Ŭ���� Ÿ���� ��ü"�� �̿�
	// �� ���� ������ revtangle() �Լ� ����
	// void rectangle(InputOutputArray img, Point pt1, Point pt2, const Scalar& color,
	//					int thickness = 1, int lineType = LINE_8, int shift = 0);
	// void rectangle(InputOutputArray img, Rect rev, const Scalar& color,
	//					int thickness = 1, int linType = LINE_8, int shift = 0);

	// thinkcess ���� -1�� ���� ������ "FILLED ������ ���"�� �����ϸ�, ���θ� ä�� �簢���� �׸�.


	//// �� �׸��� ////
	
	// circle() �Լ� �̿�
	// ���� �߽��� ��ǥ�� ������ ����
	// void circle(InputOutputArray img, Point center, int radius,
	//				const Scalar& color, int thickness = 1,
	//				int lineType = LINE_8, int shift = 0);


	//// Ÿ�� �׸��� ////

	// ellipse() �Լ� -> "Ÿ��" Ȥ�� Ÿ���� �Ϻ��� "ȣ"�� �׸� �� ����.
	// ellipse(InputOutputArray img, Point center, size axes,
	//			double angel, double startAngle, double endAngle,
	//			int lineType = LINE_8, int shift = 0);

	// axes ; Ÿ���� ������ (Size(x�� ������, y�� ������))
	// angle ; Ÿ�� ȸ�� ���� (x�� ����, �ð� ����) -> ȸ���� Ÿ���� �׸� �� ����.
	// startAngle ; Ÿ�� ȣ�� ���� ���� (x�� ����, �ð� ����)
	// endAngle ; Ÿ�� ȣ�� �� ���� (x�� ����, �ð� ����)

	// startAngle �� endAngle�� ������ ����Ͽ� ȣ�� �׸��� �뵵�� ��� ����.


	//// ������ �ٰ��� �׸��� ////

	// polylines() �Լ� -> �ٰ����� ������ ��ǥ ���� �ʿ�
	// ������ ��ǥ�� ���� vector<Point> �ڷ����� �����Ͽ� ������.

	// void polyLines(InputOutputArray img, InputArrayOfArrays pts,
	//					bool isClosed, const Scalar& color,
	//					int thickness = 1, int lineType = LINE_8, int shift = 0);

	// pts ; �ٰ��� �ܰ� ������ ��ǥ �迭. �ַ� vector<Point> Ÿ��
	// isClosed ; �ٰ����� ���� �ִ����� ��Ÿ���� �÷���. 
	// �� ���� ture�̸� �ٰ����� ������ �������� ù ��° �������� �մ� ������ �߰��� �׸�.
	
	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

	rectangle(img, Rect(50, 50, 100, 50), Scalar(0, 0, 255), 2);
	rectangle(img, Rect(50, 150, 100, 50), Scalar(0, 0, 128), -1);

	circle(img, Point(300, 120), 30, Scalar(255, 255, 0), -1, LINE_AA);
	circle(img, Point(300, 120), 60, Scalar(255, 0, 0), 3, LINE_AA);

	// 20�� �������� 0�� ���� �ð�������� 270�� ������ Ÿ���� �׸�. ���ΰ� ä����.
	ellipse(img, Point(120, 300), Size(60, 30), 20, 0, 270, Scalar(255, 255, 0), -1, LINE_AA);
	// 20�� �������� 0�� ���� �ð�������� 360�� ���� �� �׸�. �β��� 2 ��.
	ellipse(img, Point(120, 300), Size(100, 50), 20, 0, 360, Scalar(0, 255, 0), 2, LINE_AA);

	// polyLines() �Լ��� pts�� �����ϱ� ���� vector<Point> ��ü
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
	// �پ��� �׸��� �Լ�
	// ���� ��� â ���� ����� ������ �簢������ ǥ�� �ϴ� �Ͱ� ����
	// ���� ǥ���ϴ� ���� ���� ���� ��찡 ����.

	drawLines();
	drawPolys();
}