#include "BasicHeader.h"
#define console_width
#define console_height
#define console_cwidth 80
#define console_cheight 25
#define GAP 2

//사운드 출력에 사용
#pragma comment(lib, "kernel32.lib")

//변수 선언부 시작 ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

//마우스 입력 보정에 사용
int titlebar_size = 35;
int bottombar_size = 10;
int leftbar_size = 10;
int rightbar_size = 20;

//Option.cpp에서 주로 쓰일 변수
int Sound_enable = 1; //소리출력 할지 말지
int Autosave_enable = 1; //자동세이브 할지 말지

//select_YN() 예 아니오를 버튼으로 출력하고 마우스로 선택하면 1인지 0인지 반환하는 함수입니다.
int select_YN(int top, int bottom, int left, int right) {

	//(주의)left와 right는 홀수 홀수 또는 짝수 짝수 만 입력, right-left가 GAP*2보다 더 커야만 된다.

	//예 아니오 버튼 출력
	RECT Y_Rect, N_Rect;
	int center = left + ((right - left) / 2);
	Rectchange(&Y_Rect, top, bottom, left, center - GAP);
	Rectchange(&N_Rect, top, bottom, center + GAP, right);
	Print_Rect(Y_Rect, "예");
	Print_Rect(N_Rect, "아니오");

	//마우스 입력
	while (1) {
		if (GetMouseClicked()) {
			if (Point_in_Rect(GetMousePoint(), Y_Rect)) {
				return 1;
			}
			else if (Point_in_Rect(GetMousePoint(), N_Rect)) {
				return 0;
			}
		}
	}
}

//GetMousePoint(): 현재 마우스 좌표의 값을 화면 위치를 고려해서 반환해줌
POINT GetMousePoint()
{
	POINT tempP;
	HWND window = GetConsoleWindow();
	RECT stand;

	GetWindowRect(window, &stand);
	GetCursorPos(&tempP);

	tempP.x -= (stand.left + leftbar_size);
	tempP.y -= (stand.top + titlebar_size);
	tempP.x = (long)((double)(tempP.x) * ((double)console_cwidth / (double)(((stand.right - rightbar_size) - (stand.left + leftbar_size)))));
	tempP.y = (long)((double)(tempP.y) * ((double)console_cheight / (double)(((stand.bottom - bottombar_size) - (stand.top + titlebar_size)))));

	return tempP;
}

//Rectchange(): RECT구조체를 좀더 편하게 변환
void Rectchange(RECT* rec, int top, int bottom, int left, int right)
{
	rec->bottom = bottom;
	rec->top = top;
	rec->left = left;
	rec->right = right;
}

//Point_in_Rect(): POINT가 RECT 안에 들어가있는지 판단하는 함수
int Point_in_Rect(POINT p, RECT r)
{
	if ((p.x >= r.left && p.x <= r.right && p.y >= r.top && p.y <= r.bottom)) {
		Soundplay("snd\\click.wav", SND_ASYNC || SND_NOSTOP);
		return 1;
	}

	return 0;
}

//GetMouseClicked(): 마우스가 클릭된 상태인지 아닌지를 반환
int GetMouseClicked()
{
	HWND window = GetConsoleWindow();
	if (window == GetForegroundWindow())
	{
		if (GetAsyncKeyState(VK_LBUTTON) < 0) {
			//(수정) GetMouseClicked가 이제 마우스 클릭 버튼을 눌렀다가 떼야 값을 반환합니다 김동환 11.24
			while (GetAsyncKeyState(VK_LBUTTON) < 0) {}
			return 1;
		}
	}
	return 0;
}

//gotoxy(): 콘솔 내에서 커서 이동
void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//Soundplay(): 사운드 파일의 소리를 출력하는 함수
void Soundplay(LPCSTR direction, int option)
{
	if (Sound_enable) sndPlaySoundA(direction, option);
	else sndPlaySoundA(NULL, SND_ASYNC);
}

//Print_Rect(): 짧은 단어가 있는 깔끔한 마우스 버튼을 쉽게 만들어주는 함수
void Print_Rect(RECT rect, const char arr[])
{
	int i; //반복문 제어 변수
	gotoxy(rect.left, rect.top);
	for (i = 0; i < (int)((rect.right - rect.left) / 2); i++)
	{
		if (i == 0) printf("┌");
		else printf("ㅡ");
	}
	printf("┐");
	gotoxy(rect.left, rect.bottom - 1);
	for (i = 0; i < rect.right - rect.left - 1; i += 2)
	{
		if (i == 0) printf("└");
		else printf("ㅡ");
	}
	printf("┘");
	for (i = 1; i < rect.bottom - rect.top - 1; i++)
	{
		gotoxy(rect.left, rect.top + i);
		printf("ㅣ");
		gotoxy(rect.right - rect.right % 2, rect.top + i);
		printf("ㅣ");
	}
	gotoxy((((rect.right + rect.left) - strlen(arr)) / 2) + 1, (int)((rect.top + rect.bottom) / 2));
	printf("%s", arr);
}//print rect 함수 만듬 준혁
//사용법
//RECT구조체 집어넣고 arr에 문자열 집어넣으면 알아서 사각형 출력해주고 거기 안에 글자도 출력해줍니다(가운데정렬)

void Save_Option()
{

	FILE* option = fopen("option.bin", "wb");
	//이건 참고용으로 둠.
	fwrite((void*)&Sound_enable, sizeof(Sound_enable), 1, option);//기본값은 1
	fwrite((void*)&Autosave_enable, sizeof(Autosave_enable), 1, option);//기본값은 1
	fwrite((void*)&titlebar_size, sizeof(titlebar_size), 1, option);//기본값은 35
	fwrite((void*)&bottombar_size, sizeof(bottombar_size), 1, option);//10
	fwrite((void*)&leftbar_size, sizeof(leftbar_size), 1, option);//10
	fwrite((void*)&rightbar_size, sizeof(rightbar_size), 1, option);//20
	fclose(option);
}
void Load_Option()
{
	FILE* option = fopen("option.bin", "rb");
	if (option == NULL)
	{
		Save_Option();
		option = fopen("option.bin", "rb");
	}
	fread((void*)&Sound_enable, sizeof(Sound_enable), 1, option);
	fread((void*)&Autosave_enable, sizeof(Autosave_enable), 1, option);
	fread((void*)&titlebar_size, sizeof(titlebar_size), 1, option);
	fread((void*)&bottombar_size, sizeof(bottombar_size), 1, option);
	fread((void*)&leftbar_size, sizeof(leftbar_size), 1, option);
	fread((void*)&rightbar_size, sizeof(rightbar_size), 1, option);
	fclose(option);

}
