#include "BasicHeader.h"
#define console_width
#define console_height
#define console_cwidth 80
#define console_cheight 25
#define GAP 2

//���� ��¿� ���
#pragma comment(lib, "kernel32.lib")

//���� ����� ���� �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�

//���콺 �Է� ������ ���
int titlebar_size = 35;
int bottombar_size = 10;
int leftbar_size = 10;
int rightbar_size = 20;

//Option.cpp���� �ַ� ���� ����
int Sound_enable = 1; //�Ҹ���� ���� ����
int Autosave_enable = 1; //�ڵ����̺� ���� ����

//select_YN() �� �ƴϿ��� ��ư���� ����ϰ� ���콺�� �����ϸ� 1���� 0���� ��ȯ�ϴ� �Լ��Դϴ�.
int select_YN(int top, int bottom, int left, int right) {

	//(����)left�� right�� Ȧ�� Ȧ�� �Ǵ� ¦�� ¦�� �� �Է�, right-left�� GAP*2���� �� Ŀ�߸� �ȴ�.

	//�� �ƴϿ� ��ư ���
	RECT Y_Rect, N_Rect;
	int center = left + ((right - left) / 2);
	Rectchange(&Y_Rect, top, bottom, left, center - GAP);
	Rectchange(&N_Rect, top, bottom, center + GAP, right);
	Print_Rect(Y_Rect, "��");
	Print_Rect(N_Rect, "�ƴϿ�");

	//���콺 �Է�
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

//GetMousePoint(): ���� ���콺 ��ǥ�� ���� ȭ�� ��ġ�� ����ؼ� ��ȯ����
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

//Rectchange(): RECT����ü�� ���� ���ϰ� ��ȯ
void Rectchange(RECT* rec, int top, int bottom, int left, int right)
{
	rec->bottom = bottom;
	rec->top = top;
	rec->left = left;
	rec->right = right;
}

//Point_in_Rect(): POINT�� RECT �ȿ� ���ִ��� �Ǵ��ϴ� �Լ�
int Point_in_Rect(POINT p, RECT r)
{
	if ((p.x >= r.left && p.x <= r.right && p.y >= r.top && p.y <= r.bottom)) {
		Soundplay("snd\\click.wav", SND_ASYNC || SND_NOSTOP);
		return 1;
	}

	return 0;
}

//GetMouseClicked(): ���콺�� Ŭ���� �������� �ƴ����� ��ȯ
int GetMouseClicked()
{
	HWND window = GetConsoleWindow();
	if (window == GetForegroundWindow())
	{
		if (GetAsyncKeyState(VK_LBUTTON) < 0) {
			//(����) GetMouseClicked�� ���� ���콺 Ŭ�� ��ư�� �����ٰ� ���� ���� ��ȯ�մϴ� �赿ȯ 11.24
			while (GetAsyncKeyState(VK_LBUTTON) < 0) {}
			return 1;
		}
	}
	return 0;
}

//gotoxy(): �ܼ� ������ Ŀ�� �̵�
void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//Soundplay(): ���� ������ �Ҹ��� ����ϴ� �Լ�
void Soundplay(LPCSTR direction, int option)
{
	if (Sound_enable) sndPlaySoundA(direction, option);
	else sndPlaySoundA(NULL, SND_ASYNC);
}

//Print_Rect(): ª�� �ܾ �ִ� ����� ���콺 ��ư�� ���� ������ִ� �Լ�
void Print_Rect(RECT rect, const char arr[])
{
	int i; //�ݺ��� ���� ����
	gotoxy(rect.left, rect.top);
	for (i = 0; i < (int)((rect.right - rect.left) / 2); i++)
	{
		if (i == 0) printf("��");
		else printf("��");
	}
	printf("��");
	gotoxy(rect.left, rect.bottom - 1);
	for (i = 0; i < rect.right - rect.left - 1; i += 2)
	{
		if (i == 0) printf("��");
		else printf("��");
	}
	printf("��");
	for (i = 1; i < rect.bottom - rect.top - 1; i++)
	{
		gotoxy(rect.left, rect.top + i);
		printf("��");
		gotoxy(rect.right - rect.right % 2, rect.top + i);
		printf("��");
	}
	gotoxy((((rect.right + rect.left) - strlen(arr)) / 2) + 1, (int)((rect.top + rect.bottom) / 2));
	printf("%s", arr);
}//print rect �Լ� ���� ����
//����
//RECT����ü ����ְ� arr�� ���ڿ� ��������� �˾Ƽ� �簢�� ������ְ� �ű� �ȿ� ���ڵ� ������ݴϴ�(�������)

void Save_Option()
{

	FILE* option = fopen("option.bin", "wb");
	//�̰� ��������� ��.
	fwrite((void*)&Sound_enable, sizeof(Sound_enable), 1, option);//�⺻���� 1
	fwrite((void*)&Autosave_enable, sizeof(Autosave_enable), 1, option);//�⺻���� 1
	fwrite((void*)&titlebar_size, sizeof(titlebar_size), 1, option);//�⺻���� 35
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
