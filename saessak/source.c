#define	_CRT_SECURE_NO_WARNINGS
//////////////////////////////////////////////////////////////
// C ǥ�� ���̺귯�� ��� ����
//////////////////////////////////////////////////////////////
#include <stdio.h> //printf(), scanf()
#include <stdlib.h> //srand(), rand(), malloc()
#include <string.h> //���ڿ�
#include <ctype.h> //����
#include <time.h> //time(), clock()
#include <math.h> //�����Լ�
//////////////////////////////////////////////////////////////
// OS, Hardware ���� ���̺귯�� ��� ���� 
//////////////////////////////////////////////////////////////
#include <windows.h> //�������� API
//SetConsoleCursorPosition(), GetStdHandle(), Sleep()
#include <conio.h> //getch(), kbhit()
//////////////////////////////////////////////////////////////
// ���ӿ� ���� ����ϴ� Ű���� ��� 
//////////////////////////////////////////////////////////////
#define ESC 27 //���� Ż�� 
#define ENTER 13
#define SPACE 32 //�Ѿ�, ���� 
#define LEFT 75 //224 ������ 75
#define RIGHT 77 //224 ������ 77
#define UP 72 //224 ������ 72
#define DOWN 80 //224 ������ 80
#define R 114 //����
#define SHIFT 16 //�ϴ� ����
//////////////////////////////////////////////////////////////
#define winX 30  //â�� ���� ��ġ
#define winY 2  //â�� ���� ��ġ
#define winWidth 10 //â�� ��
#define winHeight 20 //â�� ����
#define FREE_DROP 0 //�Ʒ� ���� ����
#define MOVE_DOWN 1 //�Ʒ� ���� �̵�
#define MOVE_LEFT 2 //���� �̵�
#define MOVE_RIGHT 3 //���� �̵�
#define MOVE_DROP 4 //����߸���
#define ROTATION 5 //����߸���

#define TEDURI_WALL -1 //��
#define ISITEM 8 //������
//////////////////////////////////////////////////////////////
// �Լ� ������Ÿ�� 
//////////////////////////////////////////////////////////////
void gotoXY(int x, int y); //�ܼ� ȭ�� Ư�� ��ġ�� �̵�
void checkKey(); //Ű���� ó�� ��� 
void Display(); //ȭ�� ǥ�� ���, 1�ʿ� 25������ 
void Erase();
void Update(); //���� ��ü ���� ������Ʈ, �ùķ��̼� 
void Start(); //���� �ʱ� ���� ����
int IsCollision(); //�浹 �˻�
void FixBrick(); //��� �����ϱ�
void NewBrick(); //�� ��� �����
void BarCheck(); //������ ���� Ȯ�� ����, ���� ��� 
void hideCursor(); //Ŀ�� �����
//////////////////////////////////////////////////////////////
// ���� ��ü�� ����ü 
//////////////////////////////////////////////////////////////
int isNotItem = 1;
int nextIsNotItem;
int isGetItem = 0;
int therIsItem = 0;
int numForShowItem = 0;
int brick_x, brick_y; //��ü�� ������ ���� ��ġ 
int brick_shape; //��ü�� ���
int brick_rotation; //��ü�� ȸ��
int next_brick, save_next, tmp_brick;
int brick_number = 0;
int win[winHeight][winWidth]; //â�� ���빰 
int brick_action; //��ü�� �ൿ
int free_drop_delay = 20; //���� �ð� ���� 
int free_drop_count; //���� �ð� ī��Ʈ  
int state_hold = 0;
int state_brick, state_next = 0;
void use_Item();  //������ ���
void recordSaving(); //�̸�/��¥/���� ����
void recordPrinting(); //�̸�/��¥/���� ���
// ��ü�� ��� 7��, ȸ�� 4��, y, x
char brick[7][4][4][4] = {
	// �� ȸ�� 0
	0,1,0,0,
	1,1,1,0,
	0,0,0,0,
	0,0,0,0,
	// �� ȸ�� 1
	0,1,0,0,
	0,1,1,0,
	0,1,0,0,
	0,0,0,0,
	// �� ȸ�� 2
	0,0,0,0,
	1,1,1,0,
	0,1,0,0,
	0,0,0,0,
	// �� ȸ�� 3
	0,1,0,0,
	1,1,0,0,
	0,1,0,0,
	0,0,0,0,
	//Z ȸ��0
	0,1,1,0,
	1,1,0,0,
	0,0,0,0,
	0,0,0,0,
	//Z ȸ��1
	0,1,0,0,
	0,1,1,0,
	0,0,1,0,
	0,0,0,0,
	//Z ȸ��2
	0,1,1,0,
	1,1,0,0,
	0,0,0,0,
	0,0,0,0,
	//Z ȸ��3
	0,1,0,0,
	0,1,1,0,
	0,0,1,0,
	0,0,0,0,
	//Z ȸ��0
	1,1,0,0,
	0,1,1,0,
	0,0,0,0,
	0,0,0,0,
	//Z ȸ��1
	0,1,0,0,
	1,1,0,0,
	1,0,0,0,
	0,0,0,0,
	//Z ȸ��2
	1,1,0,0,
	0,1,1,0,
	0,0,0,0,
	0,0,0,0,
	//Z ȸ��3
	0,1,0,0,
	1,1,0,0,
	1,0,0,0,
	0,0,0,0,
	//��ȸ��0
	1,1,0,0,
	0,1,0,0,
	0,1,0,0,
	0,0,0,0,
	//��ȸ��1
	0,0,1,0,
	1,1,1,0,
	0,0,0,0,
	0,0,0,0,
	//��ȸ��2
	0,1,0,0,
	0,1,0,0,
	0,1,1,0,
	0,0,0,0,
	//��ȸ��3
	0,0,0,0,
	1,1,1,0,
	1,0,0,0,
	0,0,0,0,
	//��ȸ��0
	0,1,1,0,
	0,1,0,0,
	0,1,0,0,
	0,0,0,0,
	//��ȸ��1
	0,0,0,0,
	1,1,1,0,
	0,0,1,0,
	0,0,0,0,
	//��ȸ��2
	0,1,0,0,
	0,1,0,0,
	1,1,0,0,
	0,0,0,0,
	//��ȸ��3
	1,0,0,0,
	1,1,1,0,
	0,0,0,0,
	0,0,0,0,
	//���� ȸ��0
	0,1,0,0,
	0,1,0,0,
	0,1,0,0,
	0,1,0,0,
	//���� ȸ��1
	0,0,0,0,
	1,1,1,1,
	0,0,0,0,
	0,0,0,0,
	//���� ȸ��2
	0,1,0,0,
	0,1,0,0,
	0,1,0,0,
	0,1,0,0,
	//���� ȸ��3
	0,0,0,0,
	1,1,1,1,
	0,0,0,0,
	0,0,0,0,
	//���� ȸ��0
	1,1,0,0,
	1,1,0,0,
	0,0,0,0,
	0,0,0,0,
	//���� ȸ��1
	1,1,0,0,
	1,1,0,0,
	0,0,0,0,
	0,0,0,0,
	//���� ȸ��2
	1,1,0,0,
	1,1,0,0,
	0,0,0,0,
	0,0,0,0,
	//���� ȸ��3
	1,1,0,0,
	1,1,0,0,
	0,0,0,0,
	0,0,0,0
};
int GameOver;
int GamePoint;

//////////////////////////////////////////////////////////////
// �Լ� ���� �κ� 
//////////////////////////////////////////////////////////////


void main()
{
	Start();  //���� �ʱ� ���� ����
	while (!GameOver)
	{
		Display(); //ȭ�鿡 ���� ���� �׸���
		checkKey(); //Ű���� �Է� ó��
		Update(); //���� ��ü ���� ������Ʈ 
		Sleep(40); //40ms ���ڱ�
	}
	recordSaving();
}
void Erase()
{
	int x, y;
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			gotoXY(winX + x * 2 - 10, 6 + y);
			printf("  ");
		}
	}
}
//////////////////////////////////////////////////////////////
void gotoXY(int x, int y) //�ܼ� ȭ�� Ư�� ��ġ�� �̵�
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//////////////////////////////////////////////////////////////
void Start() //���� �ʱ� ���� ����
{
	int x, y;
	srand(time(NULL)); //���� �߻� ������ �ʱ�ȭ 
	GameOver = 0; //���� ���� �� �ʱ�ȭ
	GamePoint = 0; //���� ���� �ʱ�ȭ
	NewBrick(); //�� ��ü �����
	hideCursor();
	free_drop_count = free_drop_delay; //20 �����ӿ� 1ȸ �ٿ� 
	//��Ʈ���� ������ �ʱ�ȭ
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
int IsCollision() //���� ��ü �浹 �˻�
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
					return 1; //�浹 ����
				}
			}
		}
	}
	return 0; //�浹 ����
}

//////////////////////////////////////////////////////////////
void FixBrick() //���� ��ü ����
{
	int x, y;
	//�� �ִ��� �𸣰���
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), brick_shape + 1);

	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			if (brick[brick_shape][brick_rotation][y][x] == 1)
			{
				if(isNotItem)
					// ������ win[brick_y + y][brick_x + x] = 1;
					win[brick_y + y][brick_x + x] = brick_shape + 1;
				else
					win[brick_y + y][brick_x + x] = ISITEM;
			}
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

//////////////////////////////////////////////////////////////
void NewBrick() //���ο� ��ü �����
{
	Erase();
	srand(time(NULL)); //���� �߻� ������ �ʱ�ȭ 
	brick_x = winWidth / 2; //��ü�� x ��ġ
	brick_y = 1; //��ü�� y ��ġ
	if (brick_number == 0) {
		brick_shape = rand() % 7; //��� 0 ~ 6 
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
	brick_rotation = 0; //ȸ�� ���� 
	brick_action = FREE_DROP;
	brick_number++;
}

//////////////////////////////////////////////////////////////
void BarCheck() //���� ��� ���� ���� �ø���
{
	int x, y, bar, i, j;
	for (y = 1; y < winHeight - 1; y++)
	{
		//���� �˻� Loop 
		bar = 0;
		// bar : �� �ٿ� �󸶳� �ֳ� �½��ϴ�.
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
void Display() //ȭ�鿡 ���� ���� �׸���
{
	int x, y;

	//â �׸��� 
	for (y = 0; y < winHeight; y++)
	{
		gotoXY(winX, winY + y);
		for (x = 0; x < winWidth; x++)
		{
			// ���ִ� ��
			// win 1 -> ��
			// win 2 -> �׵θ���
			if (win[y][x] == ISITEM) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (numForShowItem % 2) + 6);
				printf("��");
			}
			else if (win[y][x] >= 1) {
				//�̻ڴ�...
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), win[y][x]);
				printf("��");
			}
			else if (win[y][x] == TEDURI_WALL) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("��");
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("��");
			}
		}
		printf("\n");
	}
	numForShowItem++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	// ���� ��Ʈ���ϴ� ��� �׸���
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
				printf("��");
			}
		}
	}

	//���� ���
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), next_brick + 1);
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			if (brick[next_brick][0][y][x] == 1)
			{
				gotoXY(winX + x * 2 - 10, 6 + y);
				printf("��");
			}
		}
	}
	//FixBrick();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoXY(winX + x * 2 - 19, y);
	printf("���� ���");
	gotoXY(winX + x * 2 - 19, y + 5);
	if (isGetItem)
		printf("������O");
	else
		printf("������X");
	//���� ǥ��
	gotoXY(30, 25);
	printf("Point = %d", GamePoint);
}

//////////////////////////////////////////////////////////////
void Update() //���� ��ü ���� ������Ʈ 
{
	switch (brick_action)
	{
	case MOVE_DROP:
		do {
			brick_y++;
		} while (!IsCollision());
		brick_y--;
		if (brick_y == 1) GameOver = 1;
		FixBrick(); //��ü ����
		BarCheck(); //���� ���� Ȯ�� 
		NewBrick(); //�� ��ü �����
		free_drop_count = free_drop_delay; //20 �����ӿ� 1ȸ �ٿ� 
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
			FixBrick(); //��ü ����
			BarCheck(); //���� ���� Ȯ�� 
			NewBrick(); //�� ��ü �����
			free_drop_count = free_drop_delay; //20 �����ӿ� 1ȸ �ٿ� 
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
	int numOfLineDestroy = rand() % 3 + 1; //�ѹ��� �ִ� 3�ٱ��� ����

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
void checkKey() //Ű���� ó�� ��� 
{
	int x, y;
	int key;
	if (_kbhit() != 0) //Ű���� ���� Ȯ�� 
	{
		key = _getch(); //�ϴ� �� ���� �б� 
		if (key == 224) //Ű���� ��ĵ �ڵ� 224�̸� ���Ű 
		{
			key = _getch(); //���� �� ���� �߰� �б�
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
							printf("��");
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
							printf("��");
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
	}
}
////////////////////////////////////////////////////
void hideCursor() //Ŀ�� �����
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

	printf("�̸��� �Է��ϼ���(���� �������� ������) : ");
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
