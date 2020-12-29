#define	_CRT_SECURE_NO_WARNINGS
//////////////////////////////////////////////////////////////
// C 표준 라이브러리 헤더 파일
//////////////////////////////////////////////////////////////
#include <stdio.h> //printf(), scanf()
#include <stdlib.h> //srand(), rand(), malloc()
#include <string.h> //문자열
#include <ctype.h> //문자
#include <time.h> //time(), clock()
#include <math.h> //수학함수
//////////////////////////////////////////////////////////////
// OS, Hardware 종속 라이브러리 헤더 파일 
//////////////////////////////////////////////////////////////
#include <windows.h> //윈도우즈 API
//SetConsoleCursorPosition(), GetStdHandle(), Sleep()
#include <conio.h> //getch(), kbhit()
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
//////////////////////////////////////////////////////////////
// 게임에 자주 사용하는 키보드 상수 
//////////////////////////////////////////////////////////////
#define ESC 27 //게임 탈출 
#define ENTER 13
#define SPACE 32 //총알, 점프 
#define LEFT 75 //224 다음에 75
#define RIGHT 77 //224 다음에 77
#define UP 72 //224 다음에 72
#define DOWN 80 //224 다음에 80
#define R 114 //리셋
#define SHIFT 16 //일단 보류
//////////////////////////////////////////////////////////////
#define winX 30  //창의 시작 위치
#define winY 2  //창의 시작 위치
#define winWidth 10 //창의 폭
#define winHeight 20 //창의 높이
#define FREE_DROP 0 //아래 자유 낙하
#define MOVE_DOWN 1 //아래 강제 이동
#define MOVE_LEFT 2 //좌측 이동
#define MOVE_RIGHT 3 //우측 이동
#define MOVE_DROP 4 //떨어뜨리기
#define ROTATION 5 //떨어뜨리기

#define TEDURI_WALL -1 //벽
#define ISITEM 8 //아이템
//////////////////////////////////////////////////////////////
// 함수 프로토타입 
//////////////////////////////////////////////////////////////
void gotoXY(int x, int y); //콘솔 화면 특정 위치로 이동
void checkKey(); //키보드 처리 담당 
void Display(); //화면 표시 담당, 1초에 25프레임 
void Erase();
void Update(); //게임 객체 상태 업데이트, 시뮬레이션 
void Start(); //게임 초기 상태 설정
int IsCollision(); //충돌 검사
void FixBrick(); //블록 고정하기
void NewBrick(); //새 블록 만들기
void BarCheck(); //누적된 막대 확인 제거, 점수 상승 
void hideCursor(); //커서 숨기기
//////////////////////////////////////////////////////////////
// 게임 객체의 구조체 
//////////////////////////////////////////////////////////////
int isNotItem = 1;
int nextIsNotItem;
int isGetItem = 0;
int therIsItem = 0;
int numForShowItem = 0;
int brick_x, brick_y; //객체의 윈도우 안의 위치 
int brick_shape; //객체의 모양
int brick_rotation; //객체의 회전
int next_brick, save_next, tmp_brick;
int brick_number = 0;
int win[winHeight][winWidth]; //창의 내용물 
int brick_action; //객체의 행동
int free_drop_delay = 20; //낙하 시간 간격 
int free_drop_count; //낙하 시간 카운트  
int state_hold = 0;
int state_brick, state_next = 0;
int level = 0; //게임 레벨
void use_Item();  //아이템 사용
void recordSaving(); //이름/날짜/점수 저장
void recordPrinting(); //이름/날짜/점수 출력
// 객체의 모양 7개, 회전 4개, y, x
char brick[7][4][4][4] = {
// ㅗ 회전 0
0,1,0,0,
1,1,1,0,
0,0,0,0,
0,0,0,0,
// ㅏ 회전 1
0,1,0,0,
0,1,1,0,
0,1,0,0,
0,0,0,0,
// ㅜ 회전 2
0,0,0,0,
1,1,1,0,
0,1,0,0,
0,0,0,0,
// ㅓ 회전 3
0,1,0,0,
1,1,0,0,
0,1,0,0,
0,0,0,0,
//Z 회전0
0,1,1,0,
1,1,0,0,
0,0,0,0,
0,0,0,0,
//Z 회전1
0,1,0,0,
0,1,1,0,
0,0,1,0,
0,0,0,0,
//Z 회전2
0,1,1,0,
1,1,0,0,
0,0,0,0,
0,0,0,0,
//Z 회전3
0,1,0,0,
0,1,1,0,
0,0,1,0,
0,0,0,0,
//Z 회전0
1,1,0,0,
0,1,1,0,
0,0,0,0,
0,0,0,0,
//Z 회전1
0,1,0,0,
1,1,0,0,
1,0,0,0,
0,0,0,0,
//Z 회전2
1,1,0,0,
0,1,1,0,
0,0,0,0,
0,0,0,0,
//Z 회전3
0,1,0,0,
1,1,0,0,
1,0,0,0,
0,0,0,0,
//ㄱ회전0
1,1,0,0,
0,1,0,0,
0,1,0,0,
0,0,0,0,
//ㄱ회전1
0,0,1,0,
1,1,1,0,
0,0,0,0,
0,0,0,0,
//ㄱ회전2
0,1,0,0,
0,1,0,0,
0,1,1,0,
0,0,0,0,
//ㄱ회전3
0,0,0,0,
1,1,1,0,
1,0,0,0,
0,0,0,0,
//ㄴ회전0
0,1,1,0,
0,1,0,0,
0,1,0,0,
0,0,0,0,
//ㄴ회전1
0,0,0,0,
1,1,1,0,
0,0,1,0,
0,0,0,0,
//ㄴ회전2
0,1,0,0,
0,1,0,0,
1,1,0,0,
0,0,0,0,
//ㄴ회전3
1,0,0,0,
1,1,1,0,
0,0,0,0,
0,0,0,0,
//직선 회전0
0,1,0,0,
0,1,0,0,
0,1,0,0,
0,1,0,0,
//직선 회전1
0,0,0,0,
1,1,1,1,
0,0,0,0,
0,0,0,0,
//직선 회전2
0,1,0,0,
0,1,0,0,
0,1,0,0,
0,1,0,0,
//직선 회전3
0,0,0,0,
1,1,1,1,
0,0,0,0,
0,0,0,0,
//상자 회전0
1,1,0,0,
1,1,0,0,
0,0,0,0,
0,0,0,0,
//상자 회전1
1,1,0,0,
1,1,0,0,
0,0,0,0,
0,0,0,0,
//상자 회전2
1,1,0,0,
1,1,0,0,
0,0,0,0,
0,0,0,0,
//상자 회전3
1,1,0,0,
1,1,0,0,
0,0,0,0,
0,0,0,0
};
int GameOver;
int GamePoint;

//////////////////////////////////////////////////////////////
// 함수 정의 부분 
//////////////////////////////////////////////////////////////


void main()
{
	Start();  //게임 초기 상태 설정
	while (!GameOver)
	{
		Display(); //화면에 현재 상태 그리기
		checkKey(); //키보드 입력 처리
		Update(); //게임 객체 상태 업데이트 
		Sleep(40); //40ms 잠자기
	}
	recordSaving();
}
void Erase()
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			gotoXY(winX + x * 2 - 10, 6 + y);
			printf("  ");
		}
	}
}
//////////////////////////////////////////////////////////////
void gotoXY(int x, int y) //콘솔 화면 특정 위치로 이동
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//////////////////////////////////////////////////////////////
void Start() //게임 초기 상태 설정
{
	int x, y;
	srand(time(NULL)); //난수 발생 시작점 초기화
	GameOver = 0; //게임 종료 값 초기화
	GamePoint = 0; //게임 점수 초기화
	NewBrick(); //새 개체 만들기
	hideCursor();
	free_drop_count = free_drop_delay; //20 프레임에 1회 다운 
	//테트리스 윈도우 초기화
	for (x = 0; x < winWidth; x++)
	{
		for (y = 0; y < winHeight; y++)
		{
			if (x == 0 || x == winWidth - 1 ||
				y == 0 || y == winHeight - 1)
			{
				win[y][x] = TEDURI_WALL;
			}
			else
			{
				win[y][x] = 0;
			}
		}
	}
}

//////////////////////////////////////////////////////////////
int IsCollision() //게임 객체 충돌 검사
{
	int x, y;
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			if (brick[brick_shape][brick_rotation][y][x] == 1)
			{
				if (win[brick_y + y][brick_x + x] != 0)
				{
					return 1; //충돌 있음
				}
			}
		}
	}
	return 0; //충돌 없음
}

//////////////////////////////////////////////////////////////
void FixBrick() //게임 객체 고정
{
	int x, y;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), brick_shape + 1);
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			if (brick[brick_shape][brick_rotation][y][x] == 1)
			{
				if(isNotItem)
					// 원래는 win[brick_y + y][brick_x + x] = 1;
					win[brick_y + y][brick_x + x] = brick_shape + 1;
				else
					win[brick_y + y][brick_x + x] = ISITEM;
			}
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

//////////////////////////////////////////////////////////////
void NewBrick() //새로운 객체 만들기
{
	Erase();
	srand(time(NULL)); //난수 발생 시작점 초기화 
	brick_x = winWidth / 2; //객체의 x 위치
	brick_y = 1; //객체의 y 위치
	if (brick_number == 0) {
		brick_shape = rand() % 7; //모양 0 ~ 6 
		next_brick = rand() % 7;
		nextIsNotItem = rand() % 10;
		tmp_brick = next_brick;
	}
	else {
		brick_shape = tmp_brick;
		isNotItem = nextIsNotItem;
		next_brick = rand() % 7;
		tmp_brick = next_brick;
		nextIsNotItem = rand() % 10;
	}
	brick_rotation = 0; //회전 없음 
	brick_action = FREE_DROP;
	brick_number++;
}

//////////////////////////////////////////////////////////////
void BarCheck() //누적 블록 제거 점수 올리기
{
	int x, y, bar, i, j;
	for (y = 1; y < winHeight - 1; y++)
	{
		//한줄 검사 Loop 
		bar = 0;
		// bar : 그 줄에 얼마나 있냐 맞습니다.
		for (x = 1; x < winWidth - 1; x++)
		{
			if (win[y][x] >= 1) {
				bar++;
				if (win[y][x] == ISITEM) {
					therIsItem = 1;
				}
			}
		}
		if (bar == winWidth - 2)
		{
			PlaySound(TEXT("clearSound.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			GamePoint++;
			if(therIsItem)
				isGetItem = 1;
			if (GamePoint % 20 == 0) free_drop_delay--;
			if (free_drop_delay < 0) free_drop_delay = 0;
			for (i = y - 1; i > 0; i--)
			{
				for (j = 1; j < winWidth - 1; j++)
				{
					win[i + 1][j] = win[i][j];
				}
			}
		}
		therIsItem = 0;
	}
}


//////////////////////////////////////////////////////////////
void Display() //화면에 현재 상태 그리기
{
	int x, y;

	//창 그리기 
	for (y = 0; y < winHeight; y++)
	{
		gotoXY(winX, winY + y);
		for (x = 0; x < winWidth; x++)
		{
			// 차있는 블럭
			// win 1 -> 블럭
			// win 2 -> 테두리벽
			if (win[y][x] == ISITEM) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (numForShowItem % 2) + 6);
				printf("■");
			}
			else if (win[y][x] >= 1) {
				//이쁘다...
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), win[y][x]);
				printf("■");
			}
			else if (win[y][x] == TEDURI_WALL) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("□");
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("·");
			}
		}
		printf("\n");
	}
	numForShowItem++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	// 지금 컨트롤하는 블록 그리기
	if(!isNotItem)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (numForShowItem % 2) + 6);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), brick_shape + 1);
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			if (brick[brick_shape][brick_rotation][y][x] == 1)
			{
				gotoXY(winX + (brick_x + x) * 2, winY + brick_y + y);
				printf("■");
			}
		}
	}

	//다음 블록
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), next_brick + 1);
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			if (brick[next_brick][0][y][x] == 1)
			{
				gotoXY(winX + x * 2 - 10, 6 + y);
				printf("■");
			}
		}
	}
	//FixBrick();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoXY(winX + x * 2 - 19, y);
	printf("다음 블록");
	gotoXY(winX + x * 2 - 19, y + 5);
	if (isGetItem)
		printf("아이템O");
	else
		printf("아이템X");
	//점수 표시
	gotoXY(30, 25);
	printf("Point = %d | Level = %d", GamePoint, level);
}

//////////////////////////////////////////////////////////////
void Update() //게임 객체 상태 업데이트 
{
	switch (brick_action)
	{
	case MOVE_DROP:
		do {
			brick_y++;
		} while (!IsCollision());
		brick_y--;
		if (brick_y == 1) GameOver = 1;
		FixBrick(); //개체 고정
		BarCheck(); //누적 상태 확인 
		NewBrick(); //새 개체 만들기
		free_drop_count = free_drop_delay; //20 프레임에 1회 다운 
		brick_action = FREE_DROP;
		break;
	case MOVE_LEFT:
		brick_x--;
		if (IsCollision()) brick_x++;
		brick_action = FREE_DROP;
		break;
	case MOVE_RIGHT:
		brick_x++;
		if (IsCollision()) brick_x--;
		brick_action = FREE_DROP;
		break;
	case MOVE_DOWN:
		brick_y++;
		if (IsCollision())
		{
			brick_y--;
			if (brick_y == 1) GameOver = 1;
			FixBrick(); //개체 고정
			BarCheck(); //누적 상태 확인 
			NewBrick(); //새 개체 만들기
			free_drop_count = free_drop_delay; //20 프레임에 1회 다운 
		}
		brick_action = FREE_DROP;
		break;
	case FREE_DROP:
		free_drop_count--;
		if (free_drop_count < 0)
		{
			free_drop_count = free_drop_delay;
			brick_action = MOVE_DOWN;
		}
		break;
	case ROTATION:
		brick_rotation++;
		if (brick_rotation > 3) brick_rotation = 0;
		if (IsCollision())
		{
			brick_rotation--;
			if (brick_rotation < 0) brick_rotation = 3;
		}
		brick_action = FREE_DROP;
		break;
	default:
		break;
	}
}

void useItem() {
	int numOfLineDestroy = rand() % 3 + 1; //한번에 최대 3줄까지 제거

	for (int i = 0; i < numOfLineDestroy; i++) {
		GamePoint++;
		if (GamePoint % 20 == 0) free_drop_delay--;
		if (free_drop_delay < 0) free_drop_delay = 0;
		for (int k = winHeight - 3; k > 0; k--)
		{
			for (int j = 1; j < winWidth - 1; j++)
			{
				win[k + 1][j] = win[k][j];
			}
		}		
	}
	isGetItem = 0;
}

//////////////////////////////////////////////////////////////
void checkKey() //키보드 처리 담당 
{
	int x, y;
	int key;
	if (_kbhit() != 0) //키보드 눌림 확인 
	{
		key = _getch(); //일단 한 글자 읽기 
		if (key == 224) //키보드 스캔 코드 224이면 기능키 
		{
			key = _getch(); //다음 한 글자 추가 읽기
		}
		switch (key)
		{
		case ESC:
			GameOver = 1;
			break;
		case ENTER:
			break;
		case SPACE:
			brick_action = MOVE_DROP;
			break;
		case LEFT:
			brick_action = MOVE_LEFT;
			break;
		case RIGHT:
			brick_action = MOVE_RIGHT;
			break;
		case UP:
			brick_action = ROTATION;
			break;
		case DOWN:
			brick_action = MOVE_DOWN;
			break;
		case 'r':
			Start();
			break;
		case 'i':
			if(isGetItem)
				useItem();
			break;
		case 'h':
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), brick_shape + 1);
			if (state_hold == 0) {
				for (y = 0; y < 4; y++)
				{
					for (x = 0; x < 4; x++)
					{
						if (brick[brick_shape][brick_rotation][y][x] == 1)
						{
							gotoXY(winX + x * 2 + 30, 5 + y);
							printf("■");
						}
					}
				}
				state_hold = 1;
				state_brick = brick_shape;
				NewBrick();
			}
			else {
				brick_shape = state_brick;
				for (y = 0; y < 4; y++)
				{
					for (x = 0; x < 4; x++)
					{
						if (brick[brick_shape][brick_rotation][y][x] == 1)
						{
							gotoXY(winX + (brick_x + x) * 2, winY + brick_y + y);
							printf("■");
						}
					}
				}
				for (y = 0; y < 4; y++)
				{
					for (x = 0; x < 4; x++)
					{
						gotoXY(winX + x * 2 + 30, 5 + y);
						printf("  ");
					}
				}
				state_hold = 0;

			}
			gotoXY(winX + x * 2 + 20, y - 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("Holding");
			break;

		case 'R':
			Start();
			break;
		default:
			brick_action = FREE_DROP;
			break;
		}
		PlaySound(TEXT("keyboardSound.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
	}
}
////////////////////////////////////////////////////
void hideCursor() //커서 숨기기
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 20;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
////////////////////////
void recordSaving() {
	system("cls");
	char user_name[100];
	time_t now;
	struct tm* t;
	time(&now);
	t = (struct tm*)localtime(&now);
	int nowYear = t->tm_year + 1900;
	int nowMonth = t->tm_mon + 1;
	int nowDay = t->tm_mday;
	FILE* fp;

	printf("이름을 입력하세요(띄어쓰기 포함하지 마세요) : ");
	scanf("%s", user_name);

	fp = fopen("record.txt", "a");
	fprintf(fp, "Score %d / Name %s / Day %d-%d-%d / \n", GamePoint, user_name, nowYear, nowMonth, nowDay);
	fclose(fp);

	recordPrinting();
}

void recordPrinting() {
	system("cls");
	FILE* fp;
	char file_buff[300];

	fp = fopen("record.txt", "r");
	while (fgets(file_buff, sizeof(file_buff), fp) != NULL) {
		printf("%s", file_buff);
		memset(file_buff, 0, sizeof(file_buff));
	}
	fclose(fp);
}
