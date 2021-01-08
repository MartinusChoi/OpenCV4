# Computer Vision with OpenCV4
Study Computer Vision with OpenCV version 4.5.1


**OpenCV 4로 배우는 컴퓨터 비전과 머신러닝**을 참고하여 공부하였습니다.

---

## ch02 ; OpenCV의 기초 사용법을 학습합니다.

### HelloCV

| file | function | explanation |
| :----: | :----: | ---- |
| 2_2_1_OpenCV_프로젝트생성.pdf | - | OpenCV 응용 프로그램을 작성할 수 있는 Visual Studio 프로젝트를 생성하는 방법을 정리합니다. |
| ch02_OpenCV_functions.pdf | - | ch02를 학습하면서 학습한 OpenCV의 주요 함수를 정리합니다. |
| main.cpp | main() | 학습한 주요 함수로 화면에 영상을 띄우는 실습을 진행합니다. |

---

## ch03 ; OpenCV 주요 클래스를 학습합니다.

### MatOp

| file | function | explanation |
| :----: | :----: | ---- |
| main.cpp | MatOp1() | 행렬을 생성하고 초기화하는 다양한 방법을 실습합니다. |
| - | MatOp2() | 행렬 객체를 다른 행렬 객체에 대입하거나 복사하는 다양한 방법을 실습합니다. |
| - | MatOp3() | 영상에서 사각형 모양의 부분 영상을 추출하거나 참조하는 다양한 방법을 실습합니다. |
| - | MatOp4() | 픽셀(행렬 원소) 값 접근 방법 3가지를 실습합니다. |
| - | MatOp5() | Mat 클래스로 생성한 행렬 객체의 속성을 참조하는 방법을 실습합니다. |
| - | MatOp6() | Mat 클래스에서 제공하는 다양한 행렬 연산에 대해 실습합니다. |
| - | MatOp7() | Mat 클래스의 크기 또는 타입을 변화시키는 멤버 함수들을 실습합니다. |

### ScalarOp

| file | function | explanation |
| :----: | :----: | ---- |
| main.cpp | ScalarOp() | Scalar 클래스 객체의 생성 및 초기화 및 활용법을 학습하고 실습합니다. |

### InputArrayOp

| file | function | explanation |
| :----: | :----: | ---- |
| main.cpp | InputArrayOp() | 출력할 행렬 및 벡터를 생성하고 주로 함수 입력인자의 자료형으로 활용되는 InputArray 클래스를 활용해보기 위해 작성한 printMat() 함수를 호출하는 함수입니다. |
| - | printMat() | InputArray 자료형인 입력 인자를 받아서 .getMat() 멤버 함수로 Mat 객체로 변환하고 이를 출력하는 함수입니다. |

### Ch03_OpenCV_Classes.pdf

; OpenCV의 주요 클래스에 대해 정리합니다.

---

## ch04 ; OpenCV의 주요 기능에 대해 학습합니다.

### Video

| file | function | explanation |
| :----: | :----: | ---- |
| main.cpp | camera_in() | 카메라 장치를 이용한 입력에 대한 반전 처리를 실습합니다. |
| - | video_in() | 동영상 파일을 입력받아 반전 처리하는 과정을 실습합니다. |
| - | camera_in_video_out() | 카메라 장치로 부터 영상을 입력 받아 반전 처리한 동영상을 파일로 저장하는 과정을 실습합니다. |

### drawing

| file | fuction | explanation |
| :--: | :-----: | ----------- |
| main.cpp | drawLines() | 영상에 직선과 화살표, 그리고 drawMaker() 함수를 이용한 Maker 그리는 과정을 실습합니다. |
| - | drawPolys() | 사각형, 원, 타원, 다각형을 영상에 그리는 과정을 실습합니다. |
| drawLinesResult.png | - | main.cpp의 drawLines()를 실행시킨 결과 영상입니다. |
| drawPolysResult.png | - | main.cpp의 drawPolys()를 실행시킨 결과 영상입니다. |
