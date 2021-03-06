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
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||      กเกเกแกแกแกเกแกแกแกแกเกแกแกแกเกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ\n");
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("                                        ||      กเกเกเกเกแกแกเกแกแกเกแกแกเกเกเกเ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกเกเกเ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกเกแกแ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ\n");
		}
		else if (changeMotionCpu % 3 == 1) {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||      กเกเกแกแกแกเกแกแกแกแกเกแกแกแกเกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ\n");
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกเกแกแกแกเกแกแกแกแกเกแกแกแกเกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("                                        ||      กเกเกเกเกแกแกเกแกแกเกแกแกเกเกเกเ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกเกเกเ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกเกแกแ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ\n");
		}

		else {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||      กเกเกแกแกแกเกแกแกแกแกเกแกแกแกเกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ\n");
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("กเกเกเกเกแกแกเกแกแกเกแกแกเกเกเกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกแกแกเกแกแกเกแกแกเกแกแกเกเกเกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกแกแกเกแกแกเกแกแกเกแกแกเกเกแกแ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("                                        ||      กเกเกเกเกแกแกเกแกแกเกแกแกเกเกเกเ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกเกเกเ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกเกแกแ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ\n");
		}
	}
	else if (count % 3 == 1) {
		if (changeMotionCpu % 3 == 0) {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||      กเกเกแกแกแกเกแกแกแกแกเกแกแกแกเกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ\n");
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("                                        ||      กเกเกเกเกแกแกเกแกแกเกแกแกเกเกเกเ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกเกเกเ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกเกแกแ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ\n");
		}
		else if (changeMotionCpu % 3 == 1) {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||      กเกเกแกแกแกเกแกแกแกแกเกแกแกแกเกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ\n");
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกเกแกแกแกเกแกแกแกแกเกแกแกแกเกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("                                        ||      กเกเกเกเกแกแกเกแกแกเกแกแกเกเกเกเ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกเกเกเ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกเกแกแ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ\n");
		}

		else {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||      กเกเกแกแกแกเกแกแกแกแกเกแกแกแกเกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ\n");
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("กเกเกเกเกแกแกเกแกแกเกแกแกเกเกเกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกแกแกเกแกแกเกแกแกเกแกแกเกเกเกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกแกแกเกแกแกเกแกแกเกแกแกเกเกแกแ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ        ||");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||\n");
			printf("                                        ||\n");

			printf("                                        ||      กเกเกเกเกแกแกเกแกแกเกแกแกเกเกเกเ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกเกเกเ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกเกแกแ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ\n");
		}
	}
	else {
		if (changeMotionCpu % 3 == 0) {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||      กเกเกแกแกแกเกแกแกแกแกเกแกแกแกเกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ\n");
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("                                        ||      กเกเกเกเกแกแกเกแกแกเกแกแกเกเกเกเ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกเกเกเ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกเกแกแ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ\n");
		}
		else if (changeMotionCpu % 3 == 1) {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||      กเกเกแกแกแกเกแกแกแกแกเกแกแกแกเกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ\n");
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกเกแกแกแกเกแกแกแกแกเกแกแกแกเกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("                                        ||      กเกเกเกเกแกแกเกแกแกเกแกแกเกเกเกเ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกเกเกเ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกเกแกแ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ\n");
		}

		else {
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||      กเกเกแกแกแกเกแกแกแกแกเกแกแกแกเกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ\n");
			printf("                                        ||      กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			printf("กเกเกเกเกแกแกเกแกแกเกแกแกเกเกเกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกแกแกเกแกแกเกแกแกเกแกแกเกเกเกเ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกแกแกเกแกแกเกแกแกเกแกแกเกเกแกแ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ        ||      กเกเกเกเกเกเกเกเกแกแกแกเกแกแกแกเ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||\n");
			printf("                                        ||\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("                                        ||      กเกเกเกเกแกแกเกแกแกเกแกแกเกเกเกเ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกเกเกเ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกเกแกแ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ\n");
			printf("                                        ||      กเกแกแกเกแกแกเกแกแกเกแกแกเกแกแกแ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกแกแกแกแกแกแกแกแกแกแกแกแกแกแกเ\n");
			printf("                                        ||      กเกเกแกแกแกแกแกแกแกแกแกแกแกแกเกเ\n");
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
    char rsp[3][8] = { "rock", "scissor", "paper" };
    startScreen();

    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);

    int cpuRsp;
    int playerRsp;
    int result = 0;
    bool beforePlayerWin = false;
    bool beforeCpuWin = false;
    //ฐกภงนูภงบธ
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