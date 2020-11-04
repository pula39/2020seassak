
//프로그램 모든 파일에서 쓰이는 부분입니다.
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#include<mmsystem.h>//sndPlaysound;
#pragma warning(disable:4996)
#pragma comment(lib,"winmm.lib")

#define col GetStdHandle(STD_OUTPUT_HANDLE)
#define LIGHT_RED SetConsoleTextAttribute( col,0x000c);
#define LIGHT_GREEN SetConsoleTextAttribute( col,0x000a);
#define LIGHT_CYAN SetConsoleTextAttribute( col,0x000b);
#define WHITE SetConsoleTextAttribute( col,0x000f);

//(수정)마우스 입력 사용법
/*
RECT test_Rect; //이 변수는 cmd 검은 화면 안에 버튼 하나를 만들어 낸다.(아직 크기는 0이다.)
Rectchange(&test_Rect, top, bottom, left, right); //이 함수는 버튼의 범위를 설정한다.
//top에서 bottom까지, left에서 right까지의 공간이 입력 범위가 된다(저만한 사이즈의 버튼 하나를 만든다고 생각하자)
//절대 좌표다. top,bottom은 0 이상의 y값, left, right는 0 이상의 x값이다.
while (1){
if (GetMouseClicked()){	//마우스를 클릭하면
if (Point_in_Rect(GetMousePoint(), test_Rect)){	//test_Rect라는 버튼을 눌렀는지 확인한다.
//여기에 버튼을 눌렀을 때 실행할 내용을 적는다.
}
}
}
*/

//sndPlaySound 사용법
/*
//sndplaySound(파일경로,옵션 || 옵션 || 옵션);
//파일경로에서 \는 \\로 해야됨. 아래는 옵션 목록
// sndPlaySound 함수에서 wave 파일을 실행시킬 모드 종류
// SND_ASYNC : 지정한 wave 파일이 실행될 때 언제든지 중지시킬 수 있다.
// SND_LOOP : 지정한 wave 파일이 무한반복으로 실행된다.
// SND_MEMORY : 사운드가 메모리에 있다.
// SND_NODEFAULT : 지정한 경로에 wave 파일이 없어도 경고음이 나오지 않게한다.
// SND_NOSTOP : wave 파일이 실행될 때 다른 사운드로 같이 재생시킬 수 있다.
// SND_SYNC   : 지정한 wave 파일이 실행될 때 중지시킬 수 없다.
*/

//select_YN() 예 아니오를 버튼으로 출력하고 마우스로 선택하면 1인지 0인지 반환하는 함수입니다.
int select_YN(int top, int bottom, int left, int right);
//rand_pro(): rand()함수를 개량함. 확률을 입력하면(퍼센트) 1인지 0인지 출력함
int rand_pro(int probablity);
//GetMousePoint(): 현재 마우스 좌표의 값을 화면 위치를 고려해서 반환해줌
POINT GetMousePoint();
//Rectchange(): RECT구조체를 좀더 편하게 변환
void Rectchange(RECT* rec, int top, int bottom, int left, int right);
//Point_in_Rect(): POINT가 RECT 안에 들어가있는지 판단하는 함수
int Point_in_Rect(POINT p, RECT r);
//GetMouseClicked(): 마우스가 클릭된 상태인지 아닌지를 반환
int GetMouseClicked();
//gotoxy(): 콘솔 내에서 커서 이동
void gotoxy(int x, int y);
//Soundplay(): 사운드 파일의 소리를 출력하는 함수
void Soundplay(LPCSTR direction, int option);//준혁
//Print_Rect(): 짧은 단어가 있는 깔끔한 마우스 버튼을 쉽게 만들어주는 함수
void Print_Rect(RECT rect, const char arr[]);
//사용법
//RECT구조체 집어넣고 arr에 문자열 집어넣으면 알아서 사각형 출력해주고 거기 안에 글자도 출력해줍니다(가운데정렬)

//File_print(): 게임에서 사용할 아스키 아트 이미지 파일을 출력해주는 함수
void File_print(char* direction);
void Save_Option();
void Load_Option();
