//////////////////////////////////////////////////////////////
// C Ç¥ÁØ ¶óÀÌºê·¯¸® Çì´õ ÆÄÀÏ
//////////////////////////////////////////////////////////////
#include <stdio.h> //printf(), scanf()
#include <stdlib.h> //srand(), rand(), malloc()
#include <string.h> //¹®ÀÚ¿­
#include <ctype.h> //¹®ÀÚ
#include <time.h> //time(), clock()
#include <math.h> //¼öÇĞÇÔ¼ö
//////////////////////////////////////////////////////////////
// OS, Hardware Á¾¼Ó ¶óÀÌºê·¯¸® Çì´õ ÆÄÀÏ 
//////////////////////////////////////////////////////////////
#include <windows.h> //À©µµ¿ìÁî API
//SetConsoleCursorPosition(), GetStdHandle(), Sleep()
#include <conio.h> //getch(), kbhit()
//////////////////////////////////////////////////////////////
// °ÔÀÓ¿¡ ÀÚÁÖ »ç¿ëÇÏ´Â Å°º¸µå »ó¼ö 
//////////////////////////////////////////////////////////////
#define ESC 27 //°ÔÀÓ Å»Ãâ 
#define ENTER 13
#define SPACE 32 //ÃÑ¾Ë, Á¡ÇÁ 
#define LEFT 75 //224 ´ÙÀ½¿¡ 75
#define RIGHT 77 //224 ´ÙÀ½¿¡ 77
#define UP 72 //224 ´ÙÀ½¿¡ 72
#define DOWN 80 //224 ´ÙÀ½¿¡ 80
#define R 114 //¸®¼Â
#define SHIFT 16 //ÀÏ´Ü º¸·ù
//////////////////////////////////////////////////////////////
#define winX 30  //Ã¢ÀÇ ½ÃÀÛ À§Ä¡
#define winY 2  //Ã¢ÀÇ ½ÃÀÛ À§Ä¡
#define winWidth 10 //Ã¢ÀÇ Æø
#define winHeight 20 //Ã¢ÀÇ ³ôÀÌ
#define FREE_DROP 0 //¾Æ·¡ ÀÚÀ¯ ³«ÇÏ
#define MOVE_DOWN 1 //¾Æ·¡ °­Á¦ ÀÌµ¿
#define MOVE_LEFT 2 //ÁÂÃø ÀÌµ¿
#define MOVE_RIGHT 3 //¿ìÃø ÀÌµ¿
#define MOVE_DROP 4 //¶³¾î¶ß¸®±â
#define ROTATION 5 //¶³¾î¶ß¸®±â

#define TEDURI_WALL -1 //º®
//////////////////////////////////////////////////////////////
// ÇÔ¼ö ÇÁ·ÎÅäÅ¸ÀÔ 
//////////////////////////////////////////////////////////////
void gotoXY(int x, int y); //ÄÜ¼Ö È­¸é Æ¯Á¤ À§Ä¡·Î ÀÌµ¿
void checkKey(); //Å°º¸µå Ã³¸® ´ã´ç 
void Display(); //È­¸é Ç¥½Ã ´ã´ç, 1ÃÊ¿¡ 25ÇÁ·¹ÀÓ 
void Erase();
void Update(); //°ÔÀÓ °´Ã¼ »óÅÂ ¾÷µ¥ÀÌÆ®, ½Ã¹Ä·¹ÀÌ¼Ç 
void Start(); //°ÔÀÓ ÃÊ±â »óÅÂ ¼³Á¤
int IsCollision(); //Ãæµ¹ °Ë»ç
void FixBrick(); //ºí·Ï °íÁ¤ÇÏ±â
void NewBrick(); //»õ ºí·Ï ¸¸µé±â
void BarCheck(); //´©ÀûµÈ ¸·´ë È®ÀÎ Á¦°Å, Á¡¼ö »ó½Â 
void hideCursor(); //Ä¿¼­ ¼û±â±â
//////////////////////////////////////////////////////////////
// °ÔÀÓ °´Ã¼ÀÇ ±¸Á¶Ã¼ 
//////////////////////////////////////////////////////////////
int brick_x, brick_y; //°´Ã¼ÀÇ À©µµ¿ì ¾ÈÀÇ À§Ä¡ 
int brick_shape; //°´Ã¼ÀÇ ¸ğ¾ç
int brick_rotation; //°´Ã¼ÀÇ È¸Àü
int next_brick, save_next, tmp_brick;
int brick_number = 0;
int win[winHeight][winWidth]; //Ã¢ÀÇ ³»¿ë¹° 
int brick_action; //°´Ã¼ÀÇ Çàµ¿
int free_drop_delay = 20; //³«ÇÏ ½Ã°£ °£°İ 
int free_drop_count; //³«ÇÏ ½Ã°£ Ä«¿îÆ®  
int state_hold = 0;
int state_brick, state_next = 0;
// °´Ã¼ÀÇ ¸ğ¾ç 7°³, È¸Àü 4°³, y, x
char brick[7][4][4][4] = {
// ¤Ç È¸Àü 0
0,1,0,0,
1,1,1,0,
0,0,0,0,
0,0,0,0,
// ¤¿ È¸Àü 1
0,1,0,0,
0,1,1,0,
0,1,0,0,
0,0,0,0,
// ¤Ì È¸Àü 2
0,0,0,0,
1,1,1,0,
0,1,0,0,
0,0,0,0,
// ¤Ã È¸Àü 3
0,1,0,0,
1,1,0,0,
0,1,0,0,
0,0,0,0,
//Z È¸Àü0
0,1,1,0,
1,1,0,0,
0,0,0,0,
0,0,0,0,
//Z È¸Àü1
0,1,0,0,
0,1,1,0,
0,0,1,0,
0,0,0,0,
//Z È¸Àü2
0,1,1,0,
1,1,0,0,
0,0,0,0,
0,0,0,0,
//Z È¸Àü3
0,1,0,0,
0,1,1,0,
0,0,1,0,
0,0,0,0,
//Z È¸Àü0
1,1,0,0,
0,1,1,0,
0,0,0,0,
0,0,0,0,
//Z È¸Àü1
0,1,0,0,
1,1,0,0,
1,0,0,0,
0,0,0,0,
//Z È¸Àü2
1,1,0,0,
0,1,1,0,
0,0,0,0,
0,0,0,0,
//Z È¸Àü3
0,1,0,0,
1,1,0,0,
1,0,0,0,
0,0,0,0,
//¤¡È¸Àü0
1,1,0,0,
0,1,0,0,
0,1,0,0,
0,0,0,0,
//¤¡È¸Àü1
0,0,1,0,
1,1,1,0,
0,0,0,0,
0,0,0,0,
//¤¡È¸Àü2
0,1,0,0,
0,1,0,0,
0,1,1,0,
0,0,0,0,
//¤¡È¸Àü3
0,0,0,0,
1,1,1,0,
1,0,0,0,
0,0,0,0,
//¤¤È¸Àü0
0,1,1,0,
0,1,0,0,
0,1,0,0,
0,0,0,0,
//¤¤È¸Àü1
0,0,0,0,
1,1,1,0,
0,0,1,0,
0,0,0,0,
//¤¤È¸Àü2
0,1,0,0,
0,1,0,0,
1,1,0,0,
0,0,0,0,
//¤¤È¸Àü3
1,0,0,0,
1,1,1,0,
0,0,0,0,
0,0,0,0,
//Á÷¼± È¸Àü0
0,1,0,0,
0,1,0,0,
0,1,0,0,
0,1,0,0,
//Á÷¼± È¸Àü1
0,0,0,0,
1,1,1,1,
0,0,0,0,
0,0,0,0,
//Á÷¼± È¸Àü2
0,1,0,0,
0,1,0,0,
0,1,0,0,
0,1,0,0,
//Á÷¼± È¸Àü3
0,0,0,0,
1,1,1,1,
0,0,0,0,
0,0,0,0,
//»óÀÚ È¸Àü0
1,1,0,0,
1,1,0,0,
0,0,0,0,
0,0,0,0,
//»óÀÚ È¸Àü1
1,1,0,0,
1,1,0,0,
0,0,0,0,
0,0,0,0,
//»óÀÚ È¸Àü2
1,1,0,0,
1,1,0,0,
0,0,0,0,
0,0,0,0,
//»óÀÚ È¸Àü3
1,1,0,0,
1,1,0,0,
0,0,0,0,
0,0,0,0
};
int GameOver;
int GamePoint;

//////////////////////////////////////////////////////////////
// ÇÔ¼ö Á¤ÀÇ ºÎºĞ 
//////////////////////////////////////////////////////////////


void main()
{
	Start();  //°ÔÀÓ ÃÊ±â »óÅÂ ¼³Á¤
	while (!GameOver)
	{
		Display(); //È­¸é¿¡ ÇöÀç »óÅÂ ±×¸®±â
		checkKey(); //Å°º¸µå ÀÔ·Â Ã³¸®
		Update(); //°ÔÀÓ °´Ã¼ »óÅÂ ¾÷µ¥ÀÌÆ® 
		Sleep(40); //40ms ÀáÀÚ±â
	}
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
void gotoXY(int x, int y) //ÄÜ¼Ö È­¸é Æ¯Á¤ À§Ä¡·Î ÀÌµ¿
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//////////////////////////////////////////////////////////////
void Start() //°ÔÀÓ ÃÊ±â »óÅÂ ¼³Á¤
{
	int x, y;
	srand(time(NULL)); //³­¼ö ¹ß»ı ½ÃÀÛÁ¡ ÃÊ±âÈ­ 
	GameOver = 0; //°ÔÀÓ Á¾·á °ª ÃÊ±âÈ­
	GamePoint = 0; //°ÔÀÓ Á¡¼ö ÃÊ±âÈ­
	NewBrick(); //»õ °³Ã¼ ¸¸µé±â
	hideCursor();
	free_drop_count = free_drop_delay; //20 ÇÁ·¹ÀÓ¿¡ 1È¸ ´Ù¿î 
	//Å×Æ®¸®½º À©µµ¿ì ÃÊ±âÈ­
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
int IsCollision() //°ÔÀÓ °´Ã¼ Ãæµ¹ °Ë»ç
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
					return 1; //Ãæµ¹ ÀÖÀ½
				}
			}
		}
	}
	return 0; //Ãæµ¹ ¾øÀ½
}

//////////////////////////////////////////////////////////////
void FixBrick() //°ÔÀÓ °´Ã¼ °íÁ¤
{
	int x, y;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), brick_shape + 1);
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			if (brick[brick_shape][brick_rotation][y][x] == 1)
			{
				// ¿ø·¡´Â win[brick_y + y][brick_x + x] = 1;
				win[brick_y + y][brick_x + x] = brick_shape + 1;
			}
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

//////////////////////////////////////////////////////////////
void NewBrick() //»õ·Î¿î °´Ã¼ ¸¸µé±â
{
<<<<<<< HEAD
	Erase();
	srand(time(NULL)); //³­¼ö ¹ß»ı ½ÃÀÛÁ¡ ÃÊ±âÈ­ 
=======
>>>>>>> origin/sub_ì •ë™ì›
	brick_x = winWidth / 2; //°´Ã¼ÀÇ x À§Ä¡
	brick_y = 1; //°´Ã¼ÀÇ y À§Ä¡
	if (brick_number == 0) {
		brick_shape = rand() % 7; //¸ğ¾ç 0 ~ 6 
		next_brick = rand() % 7;
		tmp_brick = next_brick;
	}
	else {
		brick_shape = tmp_brick;
		next_brick = rand() % 7;
		tmp_brick = next_brick;
	}
	brick_rotation = 0; //È¸Àü ¾øÀ½ 
	brick_action = FREE_DROP;
	brick_number++;
}

//////////////////////////////////////////////////////////////
void BarCheck() //´©Àû ºí·Ï Á¦°Å Á¡¼ö ¿Ã¸®±â
{
	int x, y, bar, i, j;
	for (y = 1; y < winHeight - 1; y++)
	{
		//ÇÑÁÙ °Ë»ç Loop 
		bar = 0;
		// bar : ±× ÁÙ¿¡ ¾ó¸¶³ª ÀÖ³Ä ¸Â½À´Ï´Ù.
		for (x = 1; x < winWidth - 1; x++)
		{
			if (win[y][x] >= 1) {
				bar++;
			}
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
void Display() //È­¸é¿¡ ÇöÀç »óÅÂ ±×¸®±â
{
	int x, y;

	//Ã¢ ±×¸®±â 
	for (y = 0; y < winHeight; y++)
	{
		gotoXY(winX, winY + y);
		for (x = 0; x < winWidth; x++)
		{
			// Â÷ÀÖ´Â ºí·°
			// win 1 -> ºí·°
			// win 2 -> Å×µÎ¸®º®
			if (win[y][x] >= 1) {
				//ÀÌ»Ú´Ù...
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), win[y][x]);
				printf("¡á");
			}
			else if (win[y][x] == TEDURI_WALL) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("¡à");
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("¡¤");
			}
		}
		printf("\n");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	// Áö±İ ÄÁÆ®·ÑÇÏ´Â ºí·Ï ±×¸®±â
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), brick_shape + 1);
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			if (brick[brick_shape][brick_rotation][y][x] == 1)
			{
				gotoXY(winX + (brick_x + x) * 2, winY + brick_y + y);
				printf("¡á");
			}
		}
	}

	//´ÙÀ½ ºí·Ï
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), next_brick + 1);
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			if (brick[next_brick][0][y][x] == 1)
			{
				gotoXY(winX + x * 2 - 10, 6 + y);
				printf("¡á");
			}
		}
	}
	//FixBrick();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoXY(winX + x * 2 - 19, y);
	printf("´ÙÀ½ ºí·Ï");
	//Á¡¼ö Ç¥½Ã
	gotoXY(30, 25);
	printf("Point = %d", GamePoint);
}

//////////////////////////////////////////////////////////////
void Update() //°ÔÀÓ °´Ã¼ »óÅÂ ¾÷µ¥ÀÌÆ® 
{
	switch (brick_action)
	{
	case MOVE_DROP:
		do {
			brick_y++;
		} while (!IsCollision());
		brick_y--;
		if (brick_y == 1) GameOver = 1;
		FixBrick(); //°³Ã¼ °íÁ¤
		BarCheck(); //´©Àû »óÅÂ È®ÀÎ 
		NewBrick(); //»õ °³Ã¼ ¸¸µé±â
		free_drop_count = free_drop_delay; //20 ÇÁ·¹ÀÓ¿¡ 1È¸ ´Ù¿î 
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
			FixBrick(); //°³Ã¼ °íÁ¤
			BarCheck(); //´©Àû »óÅÂ È®ÀÎ 
			NewBrick(); //»õ °³Ã¼ ¸¸µé±â
			free_drop_count = free_drop_delay; //20 ÇÁ·¹ÀÓ¿¡ 1È¸ ´Ù¿î 
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
void checkKey() //Å°º¸µå Ã³¸® ´ã´ç 
{
	int key;
	if (_kbhit() != 0) //Å°º¸µå ´­¸² È®ÀÎ 
	{
		key = _getch(); //ÀÏ´Ü ÇÑ ±ÛÀÚ ÀĞ±â 
		if (key == 224) //Å°º¸µå ½ºÄµ ÄÚµå 224ÀÌ¸é ±â´ÉÅ° 
		{
			key = _getch(); //´ÙÀ½ ÇÑ ±ÛÀÚ Ãß°¡ ÀĞ±â
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
<<<<<<< HEAD
		case 'r':
			Start();
			break;
		case 'h':
			int x, y;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), brick_shape + 1);
			if (state_hold == 0) {
				for (y = 0; y < 4; y++)
				{
					for (x = 0; x < 4; x++)
					{
						if (brick[brick_shape][brick_rotation][y][x] == 1)
						{
							gotoXY(winX + x * 2 + 30, 5 + y);
							printf("¡á");
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
							printf("¡á");
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
			gotoXY(winX + x * 2 + 20, y-1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("Holding");
			break;

=======
		case R:
			Start();
			break;
>>>>>>> origin/sub_ì •ë™ì›
		default:
			brick_action = FREE_DROP;
			break;
		}
	}
}
////////////////////////////////////////////////////
void hideCursor() //Ä¿¼­ ¼û±â±â
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 20;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
