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
//////////////////////////////////////////////////////////////
// �Լ� ������Ÿ�� 
//////////////////////////////////////////////////////////////
void gotoXY(int x, int y); //�ܼ� ȭ�� Ư�� ��ġ�� �̵�
void checkKey(); //Ű���� ó�� ��� 
void Display(); //ȭ�� ǥ�� ���, 1�ʿ� 25������ 
void Update(); //���� ��ü ���� ������Ʈ, �ùķ��̼� 
void Start(); //���� �ʱ� ���� ����
int IsCollision(); //�浹 �˻�
void FixBrick(); //��� �����ϱ�
void NewBrick(); //�� ��� �����
void BarCheck(); //������ ���� Ȯ�� ����, ���� ��� 
//////////////////////////////////////////////////////////////
// ���� ��ü�� ����ü 
//////////////////////////////////////////////////////////////
int brick_x, brick_y; //��ü�� ������ ���� ��ġ 
int brick_shape, brick_rotation; //��ü�� ���, ȸ��
int win[winHeight][winWidth]; //â�� ���빰 
int brick_action; //��ü�� �ൿ
int free_drop_delay = 20; //���� �ð� ���� 
int free_drop_count; //���� �ð� ī��Ʈ  
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
int GameOver = 0;
int GamePoint = 0;

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
	NewBrick(); //�� ��ü �����
	free_drop_count = free_drop_delay; //20 �����ӿ� 1ȸ �ٿ� 
	//��Ʈ���� ������ �ʱ�ȭ
	for (x = 0; x < winWidth; x++)
	{
		for (y = 0; y < winHeight; y++)
		{
			if (x == 0 || x == winWidth - 1 ||
				y == 0 || y == winHeight - 1)
			{
				win[y][x] = 2;
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
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			if (brick[brick_shape][brick_rotation][y][x] == 1)
			{
				win[brick_y + y][brick_x + x] = 1;
			}
		}
	}
}

//////////////////////////////////////////////////////////////
void NewBrick() //���ο� ��ü �����
{
	srand(time(NULL)); //���� �߻� ������ �ʱ�ȭ 
	brick_x = winWidth / 2; //��ü�� x ��ġ
	brick_y = 1; //��ü�� y ��ġ
	brick_shape = rand() % 7; //��� 0 ~ 6 
	brick_rotation = 0; //ȸ�� ���� 
	brick_action = FREE_DROP;
}

//////////////////////////////////////////////////////////////
void BarCheck() //���� ��� ���� ���� �ø���
{
	int x, y, bar, i, j;
	for (y = 1; y < winHeight - 1; y++)
	{
		bar = 0;
		for (x = 1; x < winWidth - 1; x++)
		{
			bar += win[y][x];
		}
		if (bar == winWidth - 2)
		{
			GamePoint++;
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
			if (win[y][x] == 1) printf("��");
			else if (win[y][x] == 2) printf("��");
			else printf("��");
		}
		printf("\n");
	}

	//��� �׸���
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

//////////////////////////////////////////////////////////////
void checkKey() //Ű���� ó�� ��� 
{
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
		default:
			brick_action = FREE_DROP;
			break;
		}
	}
}
