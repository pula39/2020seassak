#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>

enum rsp { rock, scissor, paper };
enum result { win = 1, lose, draw };

void startScreen() {
    int colorSelect = 1;
    while (true) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorSelect++ % 15 + 1);
        printf("\n===============\n");
        printf("<RSP GAME>\n");
        printf("===============\n\n\n\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf("press any key to start");

        Sleep(100);
        system("cls");
        if (_kbhit())
            return;
    }
}

void printRSP(int count, int changeMotionCpu) {
	if (count % 3 == 0) {
		if (changeMotionCpu % 3 == 0) {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||      □□■■■□■■■■□■■■□□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □□■■■■■■■■■■■■□□\n");
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("□□□□□□□□■■■□■■■□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□□□□□□□□■■■□■■■□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□□□□□□□□■■■□■■■□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□□□□□□□□■■■□■■■□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□□□□□□□□■■■□■■■□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□□■■■■■■■■■■■■■■        ||      □□■■■■■■■■■■■■■■\n");
			printf("□■■■■■■■■■■■■■■■        ||      □■■■■■■■■■■■■■■■\n");
			printf("□■■■■■■■■■■■■■■■        ||      □■■■■■■■■■■■■■■■\n");
			printf("□■■■■■■■■■■■■■■■        ||      □■■■■■■■■■■■■■■■\n");
			printf("□■■■■■■■■■■■■■■■        ||      □■■■■■■■■■■■■■■■\n");
			printf("□■■■■■■■■■■■■■■■        ||      □■■■■■■■■■■■■■■■\n");
			printf("□□■■■■■■■■■■■■■■        ||      □□■■■■■■■■■■■■■■\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("                                        ||      □□□□■■□■■□■■□□□□\n");
			printf("                                        ||      □■■□■■□■■□■■□□□□\n");
			printf("                                        ||      □■■□■■□■■□■■□□■■\n");
			printf("                                        ||      □■■□■■□■■□■■□■■■\n");
			printf("                                        ||      □■■□■■□■■□■■□■■■\n");
			printf("                                        ||      □■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■□\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □□■■■■■■■■■■■■□□\n");
		}
		else if (changeMotionCpu % 3 == 1) {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||      □□■■■□■■■■□■■■□□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □□■■■■■■■■■■■■□□\n");
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("□□□□□□□□□□□□□□□□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□□□□□□□□□□□□□□□□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□□■■■□■■■■□■■■□□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□■■■■■■■■■■■■■■□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□■■■■■■■■■■■■■■□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□■■■■■■■■■■■■■■□        ||      □□■■■■■■■■■■■■■■\n");
			printf("□■■■■■■■■■■■■■■□        ||      □■■■■■■■■■■■■■■■\n");
			printf("□■■■■■■■■■■■■■■□        ||      □■■■■■■■■■■■■■■■\n");
			printf("□■■■■■■■■■■■■■■□        ||      □■■■■■■■■■■■■■■■\n");
			printf("□■■■■■■■■■■■■■■□        ||      □■■■■■■■■■■■■■■■\n");
			printf("□□■■■■■■■■■■■■□□        ||      □■■■■■■■■■■■■■■■\n");
			printf("□□□□□□□□□□□□□□□□        ||      □□■■■■■■■■■■■■■■\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("                                        ||      □□□□■■□■■□■■□□□□\n");
			printf("                                        ||      □■■□■■□■■□■■□□□□\n");
			printf("                                        ||      □■■□■■□■■□■■□□■■\n");
			printf("                                        ||      □■■□■■□■■□■■□■■■\n");
			printf("                                        ||      □■■□■■□■■□■■□■■■\n");
			printf("                                        ||      □■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■□\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □□■■■■■■■■■■■■□□\n");
		}

		else {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||      □□■■■□■■■■□■■■□□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □□■■■■■■■■■■■■□□\n");
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("□□□□■■□■■□■■□□□□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□■■□■■□■■□■■□□□□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□■■□■■□■■□■■□□■■        ||      □□□□□□□□■■■□■■■□\n");
			printf("□■■□■■□■■□■■□■■■        ||      □□□□□□□□■■■□■■■□\n");
			printf("□■■□■■□■■□■■□■■■        ||      □□□□□□□□■■■□■■■□\n");
			printf("□■■■■■■■■■■■■■■■        ||      □□■■■■■■■■■■■■■■\n");
			printf("■■■■■■■■■■■■■■■■        ||      □■■■■■■■■■■■■■■■\n");
			printf("■■■■■■■■■■■■■■■■        ||      □■■■■■■■■■■■■■■■\n");
			printf("■■■■■■■■■■■■■■■□        ||      □■■■■■■■■■■■■■■■\n");
			printf("■■■■■■■■■■■■■■■□        ||      □■■■■■■■■■■■■■■■\n");
			printf("□■■■■■■■■■■■■■■□        ||      □■■■■■■■■■■■■■■■\n");
			printf("□□■■■■■■■■■■■■□□        ||      □□■■■■■■■■■■■■■■\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("                                        ||      □□□□■■□■■□■■□□□□\n");
			printf("                                        ||      □■■□■■□■■□■■□□□□\n");
			printf("                                        ||      □■■□■■□■■□■■□□■■\n");
			printf("                                        ||      □■■□■■□■■□■■□■■■\n");
			printf("                                        ||      □■■□■■□■■□■■□■■■\n");
			printf("                                        ||      □■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■□\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □□■■■■■■■■■■■■□□\n");
		}
	}
	else if (count % 3 == 1) {
		if (changeMotionCpu % 3 == 0) {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||      □□■■■□■■■■□■■■□□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □□■■■■■■■■■■■■□□\n");
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("□□□□□□□□■■■□■■■□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□□□□□□□■■■□■■■□\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□□□□□□□□■■■□■■■□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□□□□□□□■■■□■■■□\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□□□□□□□□■■■□■■■□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□□□□□□□■■■□■■■□\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□□□□□□□□■■■□■■■□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□□□□□□□■■■□■■■□\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□□□□□□□□■■■□■■■□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□□□□□□□■■■□■■■□\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□□■■■■■■■■■■■■■■        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□■■■■■■■■■■■■■■■        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □■■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□■■■■■■■■■■■■■■■        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □■■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□■■■■■■■■■■■■■■■        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □■■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□■■■■■■■■■■■■■■■        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □■■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□■■■■■■■■■■■■■■■        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □■■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□□■■■■■■■■■■■■■■        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("                                        ||      □□□□■■□■■□■■□□□□\n");
			printf("                                        ||      □■■□■■□■■□■■□□□□\n");
			printf("                                        ||      □■■□■■□■■□■■□□■■\n");
			printf("                                        ||      □■■□■■□■■□■■□■■■\n");
			printf("                                        ||      □■■□■■□■■□■■□■■■\n");
			printf("                                        ||      □■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■□\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □□■■■■■■■■■■■■□□\n");
		}
		else if (changeMotionCpu % 3 == 1) {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||      □□■■■□■■■■□■■■□□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □□■■■■■■■■■■■■□□\n");
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("□□□□□□□□□□□□□□□□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□□□□□□□■■■□■■■□\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□□□□□□□□□□□□□□□□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□□□□□□□■■■□■■■□\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□□■■■□■■■■□■■■□□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□□□□□□□■■■□■■■□\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□■■■■■■■■■■■■■■□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□□□□□□□■■■□■■■□\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□■■■■■■■■■■■■■■□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□□□□□□□■■■□■■■□\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□■■■■■■■■■■■■■■□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□■■■■■■■■■■■■■■□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □■■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□■■■■■■■■■■■■■■□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □■■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□■■■■■■■■■■■■■■□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □■■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□■■■■■■■■■■■■■■□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □■■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□□■■■■■■■■■■■■□□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □■■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□□□□□□□□□□□□□□□□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("                                        ||      □□□□■■□■■□■■□□□□\n");
			printf("                                        ||      □■■□■■□■■□■■□□□□\n");
			printf("                                        ||      □■■□■■□■■□■■□□■■\n");
			printf("                                        ||      □■■□■■□■■□■■□■■■\n");
			printf("                                        ||      □■■□■■□■■□■■□■■■\n");
			printf("                                        ||      □■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■□\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □□■■■■■■■■■■■■□□\n");
		}

		else {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||      □□■■■□■■■■□■■■□□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □□■■■■■■■■■■■■□□\n");
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("□□□□■■□■■□■■□□□□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□□□□□□□■■■□■■■□\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□■■□■■□■■□■■□□□□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□□□□□□□■■■□■■■□\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□■■□■■□■■□■■□□■■        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□□□□□□□■■■□■■■□\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□■■□■■□■■□■■□■■■        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□□□□□□□■■■□■■■□\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□■■□■■□■■□■■□■■■        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□□□□□□□■■■□■■■□\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□■■■■■■■■■■■■■■■        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("■■■■■■■■■■■■■■■■        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □■■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("■■■■■■■■■■■■■■■■        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □■■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("■■■■■■■■■■■■■■■□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □■■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("■■■■■■■■■■■■■■■□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □■■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□■■■■■■■■■■■■■■□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □■■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("□□■■■■■■■■■■■■□□        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      □□■■■■■■■■■■■■■■\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||\n");
			printf("                                        ||\n");

			printf("                                        ||      □□□□■■□■■□■■□□□□\n");
			printf("                                        ||      □■■□■■□■■□■■□□□□\n");
			printf("                                        ||      □■■□■■□■■□■■□□■■\n");
			printf("                                        ||      □■■□■■□■■□■■□■■■\n");
			printf("                                        ||      □■■□■■□■■□■■□■■■\n");
			printf("                                        ||      □■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■□\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □□■■■■■■■■■■■■□□\n");
		}
	}
	else {
		if (changeMotionCpu % 3 == 0) {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||      □□■■■□■■■■□■■■□□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □□■■■■■■■■■■■■□□\n");
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("□□□□□□□□■■■□■■■□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□□□□□□□□■■■□■■■□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□□□□□□□□■■■□■■■□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□□□□□□□□■■■□■■■□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□□□□□□□□■■■□■■■□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□□■■■■■■■■■■■■■■        ||      □□■■■■■■■■■■■■■■\n");
			printf("□■■■■■■■■■■■■■■■        ||      □■■■■■■■■■■■■■■■\n");
			printf("□■■■■■■■■■■■■■■■        ||      □■■■■■■■■■■■■■■■\n");
			printf("□■■■■■■■■■■■■■■■        ||      □■■■■■■■■■■■■■■■\n");
			printf("□■■■■■■■■■■■■■■■        ||      □■■■■■■■■■■■■■■■\n");
			printf("□■■■■■■■■■■■■■■■        ||      □■■■■■■■■■■■■■■■\n");
			printf("□□■■■■■■■■■■■■■■        ||      □□■■■■■■■■■■■■■■\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("                                        ||      □□□□■■□■■□■■□□□□\n");
			printf("                                        ||      □■■□■■□■■□■■□□□□\n");
			printf("                                        ||      □■■□■■□■■□■■□□■■\n");
			printf("                                        ||      □■■□■■□■■□■■□■■■\n");
			printf("                                        ||      □■■□■■□■■□■■□■■■\n");
			printf("                                        ||      □■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■□\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □□■■■■■■■■■■■■□□\n");
		}
		else if (changeMotionCpu % 3 == 1) {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||      □□■■■□■■■■□■■■□□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □□■■■■■■■■■■■■□□\n");
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("□□□□□□□□□□□□□□□□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□□□□□□□□□□□□□□□□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□□■■■□■■■■□■■■□□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□■■■■■■■■■■■■■■□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□■■■■■■■■■■■■■■□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□■■■■■■■■■■■■■■□        ||      □□■■■■■■■■■■■■■■\n");
			printf("□■■■■■■■■■■■■■■□        ||      □■■■■■■■■■■■■■■■\n");
			printf("□■■■■■■■■■■■■■■□        ||      □■■■■■■■■■■■■■■■\n");
			printf("□■■■■■■■■■■■■■■□        ||      □■■■■■■■■■■■■■■■\n");
			printf("□■■■■■■■■■■■■■■□        ||      □■■■■■■■■■■■■■■■\n");
			printf("□□■■■■■■■■■■■■□□        ||      □■■■■■■■■■■■■■■■\n");
			printf("□□□□□□□□□□□□□□□□        ||      □□■■■■■■■■■■■■■■\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("                                        ||      □□□□■■□■■□■■□□□□\n");
			printf("                                        ||      □■■□■■□■■□■■□□□□\n");
			printf("                                        ||      □■■□■■□■■□■■□□■■\n");
			printf("                                        ||      □■■□■■□■■□■■□■■■\n");
			printf("                                        ||      □■■□■■□■■□■■□■■■\n");
			printf("                                        ||      □■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■□\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □□■■■■■■■■■■■■□□\n");
		}

		else {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||      □□■■■□■■■■□■■■□□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □□■■■■■■■■■■■■□□\n");
			printf("                                        ||      □□□□□□□□□□□□□□□□\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("□□□□■■□■■□■■□□□□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□■■□■■□■■□■■□□□□        ||      □□□□□□□□■■■□■■■□\n");
			printf("□■■□■■□■■□■■□□■■        ||      □□□□□□□□■■■□■■■□\n");
			printf("□■■□■■□■■□■■□■■■        ||      □□□□□□□□■■■□■■■□\n");
			printf("□■■□■■□■■□■■□■■■        ||      □□□□□□□□■■■□■■■□\n");
			printf("□■■■■■■■■■■■■■■■        ||      □□■■■■■■■■■■■■■■\n");
			printf("■■■■■■■■■■■■■■■■        ||      □■■■■■■■■■■■■■■■\n");
			printf("■■■■■■■■■■■■■■■■        ||      □■■■■■■■■■■■■■■■\n");
			printf("■■■■■■■■■■■■■■■□        ||      □■■■■■■■■■■■■■■■\n");
			printf("■■■■■■■■■■■■■■■□        ||      □■■■■■■■■■■■■■■■\n");
			printf("□■■■■■■■■■■■■■■□        ||      □■■■■■■■■■■■■■■■\n");
			printf("□□■■■■■■■■■■■■□□        ||      □□■■■■■■■■■■■■■■\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("                                        ||      □□□□■■□■■□■■□□□□\n");
			printf("                                        ||      □■■□■■□■■□■■□□□□\n");
			printf("                                        ||      □■■□■■□■■□■■□□■■\n");
			printf("                                        ||      □■■□■■□■■□■■□■■■\n");
			printf("                                        ||      □■■□■■□■■□■■□■■■\n");
			printf("                                        ||      □■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■■\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■□\n");
			printf("                                        ||      ■■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □■■■■■■■■■■■■■■□\n");
			printf("                                        ||      □□■■■■■■■■■■■■□□\n");
		}
	}
}

int selectInFiveSec() {
    float check_start_second = clock() / CLOCKS_PER_SEC;
    int count = 999;
    int changeMotionCpu = 0;

    while (true) {
        int playerRsp = rand() % 3;

        Sleep(500);
        changeMotionCpu++;
        float now_second = clock() / CLOCKS_PER_SEC;
        float passed_second = now_second - check_start_second;

        if (passed_second > 5.0)
            return playerRsp;
        if (_kbhit()) {
            int player_pressed_key = _getch();

            if (player_pressed_key == 224) {
                player_pressed_key = _getch();

                switch (player_pressed_key) {
                case 72:
                    count--;
                    break;
                case 80:
                    count++;
                    break;
                }
            }
            else if (player_pressed_key == 13)
                return count % 3;
        }
		printRSP(count, changeMotionCpu);
	}
}

int main() {
	//git
	printf("Hello Hello");
    char rsp[3][8] = { "rock", "scissor", "paper" };
    startScreen();

    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);

    int cpuRsp;
    int playerRsp;
    int result = 0;
    bool beforePlayerWin = false;
    bool beforeCpuWin = false;
    //가위바위보
    while (true) {
        cpuRsp = rand() % 3;
        playerRsp = selectInFiveSec();

        switch (playerRsp) {
        case rock:
            switch (cpuRsp) {
            case rock:
                result = draw;
                break;
            case scissor:
                result = win;
                break;
            case paper:
                result = lose;
                break;
            }
            break;

        case scissor:
            switch (cpuRsp) {
            case rock:
                result = lose;
                break;
            case scissor:
                result = draw;
                break;
            case paper:
                result = win;
                break;
            }
            break;
        case paper:
            switch (cpuRsp) {
            case rock:
                result = win;
                break;
            case scissor:
                result = lose;
                break;
            case paper:
                result = draw;
                break;
            }
            break;
        }
        system("cls");
        printf("player : %s, CPU : %s", rsp[playerRsp], rsp[cpuRsp]);
        Sleep(1500);
        if (result == win) {
            beforePlayerWin = true;
            beforeCpuWin = false;
        }
        else if (result == lose) {
            beforePlayerWin = false;
            beforeCpuWin = true;
        }
        else {
            if (beforePlayerWin || beforeCpuWin)
                break;
            else
                continue;
        }
    }

    if (beforePlayerWin)
        printf("\nYou Win!");
    else
        printf("\nYou Lose!");
    return 0;
}
