#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void camera_in() { // VideoCapture 클래스를 이용하여 카메라로부터 프레임을 받아 처리하기

	// VideoCaptrue 클래스 객체 생성
	// 기본 카메라 사용 -> 인자를 0으로 설정
	//// VideoCaptrue cap;
	//// cap.open(0);
	// 의 코드도 사용가능
	VideoCapture cap(0);

	// 카메라 장치가 사용 가능한 상태로 열렸는지 확인
	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return;
	}

	// 카메라 장치에서 프레임 받아오기
	// 하나의 프레임 == 한 장의 정지영상 -> Mat 클래스 객체에 저장가능 -> imshow()로 출력 가능
	// 카메라에서 일정 시간 간격마다 프레임을 받아와서 화면에 출력
	Mat frame, inversed;

	while (true) {
		cap >> frame; // 프레임을 받아서 frame 변수에 저장

		if (frame.empty()) // 더이상 프레임을 못 받아오면 빈 영상을 반환하므로 받은 것이 빈 영상이면 break
			break;

		inversed = ~frame;

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(10) == 27) // 반환값을 조사하여 눌린 키 값이 "esc"에 해당하면 break
			break;
	}

	destroyAllWindows();
}

int main() { //VideoCapture 클래스

	camera_in();

	// 동영상 -> 일련의 정지 영상을 압축하여 파일로 저장한 형태
	// frame -> 동영상에 저장되어 있는 일련의 정지 영상
	// 동영상 처리 ; 동영상에서 frame 추출 -> 각각의 frame에 영상 처리 기법을 적용

	// VideoCapture 클래스 ; 카메라 또는 동영상 파일로부터 정지 영상 frame을 받아 옴.
	// -> VideoCapture 클래스의 멤버 변수는 모두 protected: 모드 -> 사용자가 직접 접근 불가능


	////// VideoCapture 클래스로 동영상 파일 불러오기 //////

	// 방법 1 ; VideoCapture 객체 생성시 생성자에 "동영상 파일 이름을 지정"
	// 방법 2 ; 기본 생성자로 VideoCaptrue 객체를 생성한 후 "VideoCapture::open()" 멤버 함수를 호출

	// VideoCaptrue(const String& filename, int apiPreference = CAP_ANY);
	// VideoCapture::open(const String& filename, int apiPreference = CAP_ANY);
	
	// filename ; 동영상 파일 이름+확장자 (프로그램 실행 폴더 밖에 존재하면 절대/상대 경로까지)
	// apiPreference ; 사용할 비디어 캡처 API 백엔드
	
	// img0001.jpg, img0002.jpg, img0003.jpg 와 같은 다수의 정지영상을 차례대로 불러오고 싶다면
	// filename 인자에 "img%04d.jpg"와 같이 작성하여 사용가능.
	// filename 인자에 비디오 스트림 URL을 지정하여 인터넷 동영상을 사용할 수도 있음.
	
	// apiPreference 인자에는 동영상 파일을 불러오는 방법을 지정.
	// 대부분 생략하거나 기본값인 CAP_ANY를 지정함. -> 시스템이 알아서 적절한 방법을 선택하여 사용


	////// VideoCapture 클래스로 컴퓨터에 연결된 카메라 장치 사용하기 //////

	// 카메라 장치를 열 때에도 VideoCapture 생성자 혹은 VideoCapture::open() 멤버 함수를 사용함.
	// 하지만 이대 함수의 인자에 문자열이 아닌 "정수 값"을 전달.

	// VideoCapture(int index, int apiPreference = CAP_ANY);
	// VideoCapture::open(int index, int apiPreference = CAP_ANY);
	
	// "index = camera_id + domain_offset_id" 로 index 값이 결정
	// 컴퓨터에 카메라가 한 대만 연결되어 있을 경우 -> 이 카메라의 camera_id = 0
	// 두 대 이상의 카메라가 연결되어 있을 경우 -> 각각의 카메라는 0보다 같거나 큰 정수를 ID로 가짐.
	
	// domain_offet_id는 카메라 장치를 사용하는 방식을 표현하는 정수 값 -> VideoCaptureAPIs 열거형 상수 중 하나 지정
	// 대부분 CAP_ANY로 설정되어있으므로 domain_offet_id는 자동 선택을 의미하는 0을 사용함.
	// 결국 camera_id와 같은 값으로 설정
	// 즉, 컴퓨터에 연결된 기본 카메라 사용 -> index = 0
	// 두 대의 카메라가 연결 -> index로 0 또는 1을 지정.

	// 카메라 또는 동영상 파일 열기를 수행한 후 -> VideoCapture::isOpened() 로 열기 작업이 성공적인지 확인하는 것이 좋음.
	// bool VideoCapture::isOpened() const; -> 카메라 또는 동영상 파일이 사용 가능하면 true, 아니면 false

	// 카메라 또는 동영상 파일 사용이 끝나면 -> VideoCapture::release() 로 사용하던 자원을 해제해야 함.
	// virtual void VideoCapture::release();


	////// 카메라 또는 동영상 파일로부터 한 frame의 정지 영상 받아오기 //////

	// VideoCapture 클래스로 카메라 도는 동영상 파일을 잘 열었다면 -> 공통의 멤버 함수로 frame을 받아 올 수 있음.
	// "VideoCapture::operator >>() 연산자 재정의 함수" 혹은 "VideoCapture::read() 함수" 사용

	// VideoCapture& VideoCaptrue::operator >> (Mat& image);
	// bool VideoCapture::read(OutputArray image);
	// image ; 다음 비디오 프레임. 더 가져올 프레임이 없으면 빈 행렬 반환
	// 반환값 ; 프레임을 더 받을 수 없으면 false 반환

	// 예시 코드
	// VideoCaptrue cap(0); // 기본 노트북 카메라 사용.
	// Mat frame1, frame2;
	// cap >> frame1;
	// cap.read(frame2);

	//// 여러 대의 카메라를 이용할 경우 ////

	// VideoCapture::grab() ; 카메라 장치에 다음 프레임을 획득하라는 명령을 내리는 함수
	// VidoeCapture::retrieve() ; 획득한 프레임을 실제로 받아오는 함수
	
	// 만약 여러 대의 카메라에서 동시에 영상을 획득하고 싶다면
	// 여러 대의 카메라 동기화를 고려하여
	// 여러 카메라에 대해 차례대로 VideoCaptrue::grab() 을 호출하고,
	// 다시 VideoCapture::retrieve() 함수를 차례대로 호출하여 실제 프레임을 받아오는 것이 좋음.
	// 동기화 고려 상황이 아니라면 VideoCaptrue::read() 또는 >> 연산자 재정의를 사용하는 것이 편리함.


	////// 현재 열려 있는 카메라 장치 또는 동영상 파일에서 정보 받아 오기 //////

	// double VideoCapture::get(int propId) const;
	// propId ; 속성 ID. VideoCaptureProperties 열거형 상수중 하나 지정
	// 반환값 ; 지정한 속성 값. 속성을 얻을 수 없으면 0을 반환

	// 예시 코드 (카메라의 기본 frame 크기를 확인)
	// VideoCaptrue cap(0);
	// int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
	// int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));

	// VideoCapture::get() 은 속성을 double 형으로 반환함.
	// 따라서 실제 코드에서 정수형 변수에 저장하려면 반올림하여 정수형으로 변환이 필요. -> cvRound() 사용


	////// 현재 열려 있는 카메라 장치 또는 비디오 파일 재생과 관련된 속성값을 설정하기 //////

	// bool VideoCapture::set(int propId, double value);
	// propId ; 속성 ID. VideoCaptureProperties 열거형 상수중 하나 지정
	// value ; 지정할 속성 값
	// 반환값 ; 속성 지정이 가능하면 true, 아니면 false

	// 예시 코드 (100 번째 프레임으로 이동하기)
	// VideoCaptrue cap("video.mp4"0;
	// cap.set(CAP_PROP_POS_FRAMES, 100);
}
