
//���α׷� ��� ���Ͽ��� ���̴� �κ��Դϴ�.
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

//(����)���콺 �Է� ����
/*
RECT test_Rect; //�� ������ cmd ���� ȭ�� �ȿ� ��ư �ϳ��� ����� ����.(���� ũ��� 0�̴�.)
Rectchange(&test_Rect, top, bottom, left, right); //�� �Լ��� ��ư�� ������ �����Ѵ�.
//top���� bottom����, left���� right������ ������ �Է� ������ �ȴ�(������ �������� ��ư �ϳ��� ����ٰ� ��������)
//���� ��ǥ��. top,bottom�� 0 �̻��� y��, left, right�� 0 �̻��� x���̴�.
while (1){
if (GetMouseClicked()){	//���콺�� Ŭ���ϸ�
if (Point_in_Rect(GetMousePoint(), test_Rect)){	//test_Rect��� ��ư�� �������� Ȯ���Ѵ�.
//���⿡ ��ư�� ������ �� ������ ������ ���´�.
}
}
}
*/

//sndPlaySound ����
/*
//sndplaySound(���ϰ��,�ɼ� || �ɼ� || �ɼ�);
//���ϰ�ο��� \�� \\�� �ؾߵ�. �Ʒ��� �ɼ� ���
// sndPlaySound �Լ����� wave ������ �����ų ��� ����
// SND_ASYNC : ������ wave ������ ����� �� �������� ������ų �� �ִ�.
// SND_LOOP : ������ wave ������ ���ѹݺ����� ����ȴ�.
// SND_MEMORY : ���尡 �޸𸮿� �ִ�.
// SND_NODEFAULT : ������ ��ο� wave ������ ��� ������� ������ �ʰ��Ѵ�.
// SND_NOSTOP : wave ������ ����� �� �ٸ� ����� ���� �����ų �� �ִ�.
// SND_SYNC   : ������ wave ������ ����� �� ������ų �� ����.
*/

//select_YN() �� �ƴϿ��� ��ư���� ����ϰ� ���콺�� �����ϸ� 1���� 0���� ��ȯ�ϴ� �Լ��Դϴ�.
int select_YN(int top, int bottom, int left, int right);
//rand_pro(): rand()�Լ��� ������. Ȯ���� �Է��ϸ�(�ۼ�Ʈ) 1���� 0���� �����
int rand_pro(int probablity);
//GetMousePoint(): ���� ���콺 ��ǥ�� ���� ȭ�� ��ġ�� ����ؼ� ��ȯ����
POINT GetMousePoint();
//Rectchange(): RECT����ü�� ���� ���ϰ� ��ȯ
void Rectchange(RECT* rec, int top, int bottom, int left, int right);
//Point_in_Rect(): POINT�� RECT �ȿ� ���ִ��� �Ǵ��ϴ� �Լ�
int Point_in_Rect(POINT p, RECT r);
//GetMouseClicked(): ���콺�� Ŭ���� �������� �ƴ����� ��ȯ
int GetMouseClicked();
//gotoxy(): �ܼ� ������ Ŀ�� �̵�
void gotoxy(int x, int y);
//Soundplay(): ���� ������ �Ҹ��� ����ϴ� �Լ�
void Soundplay(LPCSTR direction, int option);//����
//Print_Rect(): ª�� �ܾ �ִ� ����� ���콺 ��ư�� ���� ������ִ� �Լ�
void Print_Rect(RECT rect, const char arr[]);
//����
//RECT����ü ����ְ� arr�� ���ڿ� ��������� �˾Ƽ� �簢�� ������ְ� �ű� �ȿ� ���ڵ� ������ݴϴ�(�������)

//File_print(): ���ӿ��� ����� �ƽ�Ű ��Ʈ �̹��� ������ ������ִ� �Լ�
void File_print(char* direction);
void Save_Option();
void Load_Option();
