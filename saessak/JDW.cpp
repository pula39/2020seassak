#include <iostream>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

enum {
    ROCK = 1,
    SCISSOR,
    PAPER,
    WIN = 1,
    LOSE,
    DRAW
};

int user_select() {
    int input;
    double start = clock() / CLOCKS_PER_SEC;
    while (true) {
        double now = clock() / CLOCKS_PER_SEC;
        if (_kbhit) {
            input = _getch();
            switch (input) {
            case 'r':
                return ROCK;
                break;
            case 's':
                return SCISSOR;
                break;
            case 'p':
                return PAPER;
                break;
            }
            break;
        }
        if (now - start > 5.0) {
            int input = rand() % 3 + 1;
            switch (input) {
            case 1:
                return ROCK;
                break;
            case 2:
                return SCISSOR;
                break;
            case 3:
                return PAPER;
                break;
            }
            break;
        }
    }
}

void PrintALLRsp(int user_rsp, int cpu_rsp) {
    printf("�� : ");

}
int is_winner(int user_rsp, int cpu_rsp) {
    switch (user_rsp) {
    case ROCK:
        if (cpu_rsp == SCISSOR) {
            printf("�� : ����, ��� : ����\n");
            return 1;
        }
        else if (cpu_rsp == PAPER) {
            printf("�� : ����, ��� : ��\n");
            return 2;
        }
        else {
            printf("�� : ����, ��� : ����\n");
            return 0;
        }
        break;
    case SCISSOR:
        if (cpu_rsp == ROCK) {
            printf("�� : ����, ��� : ����\n");
            return 2;
        }
        else if (cpu_rsp == PAPER) {
            printf("�� : ����, ��� : ��\n");
            return 1;
        }
        else {
            printf("�� : ����, ��� : ����\n");
            return 0;
        }
        break;
    case PAPER:
        if (cpu_rsp == ROCK) {
            printf("�� : ��, ��� : ����\n");
            return 1;
        }
        else if (cpu_rsp == SCISSOR) {
            printf("�� : ��, ��� : ����\n");
            return 2;
        }
        else {
            printf("�� : ��, ��� : ��\n");
            return 0;
        }
        break;
    }
}

int main() {
    int victory = 0, defeat = 0;
    srand(time(NULL));
    int winner = 0;
    bool exit = false;
    int vic = 0;
    while (true) {              //���� ����ϱ� ���ý� �ݺ�

        printf("����, ����, ���� �����ϼ��� (r : ����, s : ����, p : ��)\n");
        while (true) {          //�����
            int UserRsp = user_select();
            int CpuRsp = rand() % 3 + 1;
            winner = is_winner(UserRsp, CpuRsp);
            switch (UserRsp) {
            case ROCK:
                if (vic == 0) {
                    switch (winner) {
                    case 0:
                        printf("�����ϴ�. �����д� ? \n");
                        break;
                    case 1:
                        printf("�̰���ϴ�. ���� �д�? (���� �и� ���� �̱�ϴ�)\n");
                        vic = 1;
                        break;
                    case 2:
                        printf("�����ϴ�. ���� �д�? (���� �и� ���� ���ϴ�)\n");
                        vic = 2;
                        break;
                    }
                }
                else if (vic == 1) {
                    switch (winner) {
                    case 0:
                        printf("�¸��߽��ϴ�\n");
                        victory++;
                        exit = true;
                        break;
                    case 1:
                        printf("�̰���ϴ�. ���� �д�? (���� �и� ���� �̱�ϴ�)\n");
                        break;
                    case 2:
                        printf("�����ϴ�. ���� �д�? (���� �и� ���� ���ϴ�)\n");
                        vic = 2;
                        break;
                    }
                }
                else {
                    switch (winner) {
                    case 0:
                        printf("�й��߽��ϴ�\n");
                        defeat++;
                        exit = true;
                        break;
                    case 1:
                        printf("�̰���ϴ�. ���� �д�? (���� �и� ���� �̱�ϴ�)\n");
                        vic = 1;
                        break;
                    case 2:
                        printf("�����ϴ�. ���� �д�? (���� �и� ���� ���ϴ�)\n");
                        break;
                    }
                }
                break;
            case SCISSOR:
                if (vic == 0) {
                    switch (winner) {
                    case 0:
                        printf("�����ϴ�. �����д� ? \n");
                        break;
                    case 1:
                        printf("�̰���ϴ�. ���� �д�? (���� �и� ���� �̱�ϴ�)\n");
                        vic = 1;
                        break;
                    case 2:
                        printf("�����ϴ�. ���� �д�? (���� �и� ���� ���ϴ�)\n");
                        vic = 2;
                        break;
                    }
                }
                else if (vic == 1) {
                    switch (winner) {
                    case 0:
                        printf("�¸��߽��ϴ�\n");
                        victory++;
                        exit = true;
                        break;
                    case 1:
                        printf("�̰���ϴ�. ���� �д�? (���� �и� ���� �̱�ϴ�)\n");
                        break;
                    case 2:
                        printf("�����ϴ�. ���� �д�? (���� �и� ���� ���ϴ�)\n");
                        vic = 2;
                        break;
                    }
                }
                else {
                    switch (winner) {
                    case 0:
                        printf("�й��߽��ϴ�\n");
                        defeat++;
                        exit = true;
                        break;
                    case 1:
                        printf("�̰���ϴ�. ���� �д�? (���� �и� ���� �̱�ϴ�)\n");
                        vic = 1;
                        break;
                    case 2:
                        printf("�����ϴ�. ���� �д�? (���� �и� ���� ���ϴ�)\n");
                        break;
                    }
                }
                break;
            case PAPER:
                if (vic == 0) {
                    switch (winner) {
                    case 0:
                        printf("�����ϴ�. �����д� ? \n");
                        break;
                    case 1:
                        printf("�̰���ϴ�. ���� �д�? (���� �и� ���� �̱�ϴ�)\n");
                        vic = 1;
                        break;
                    case 2:
                        printf("�����ϴ�. ���� �д�? (���� �и� ���� ���ϴ�)\n");
                        vic = 2;
                        break;
                    }
                }
                else if (vic == 1) {
                    switch (winner) {
                    case 0:
                        printf("�¸��߽��ϴ�\n");
                        victory++;
                        exit = true;
                        break;
                    case 1:
                        printf("�̰���ϴ�. ���� �д�? (���� �и� ���� �̱�ϴ�)\n");
                        break;
                    case 2:
                        printf("�����ϴ�. ���� �д�? (���� �и� ���� ���ϴ�)\n");
                        vic = 2;
                        break;
                    }
                }
                else {
                    switch (winner) {
                    case 0:
                        printf("�й��߽��ϴ�\n");
                        defeat++;
                        exit = true;
                        break;
                    case 1:
                        printf("�̰���ϴ�. ���� �д�? (���� �и� ���� �̱�ϴ�)\n");
                        vic = 1;
                        break;
                    case 2:
                        printf("�����ϴ�. ���� �д�? (���� �и� ���� ���ϴ�)\n");
                        break;
                    }
                }
                break;
            }
            if (exit) {
                break;
            }
        }
        char will;
        printf("������ �������ϴ�. \n����ϱ� : C  |  ���߱� : Q  | ��Ϻ��� : R \n");
        scanf_s("%c", &will);
        getchar();
        if (will == 'C') {
            exit = false;
            continue;
        }
        else if (will == 'Q') {
            break;
        }
        else if (will == 'R') {
            char will2;
            printf("�¸� : %d, �й� : %d\n", victory, defeat);
            printf("����ϱ� : C  |  ���߱� : Q\n");
            scanf_s("%c", &will2);
            getchar();
            if (will2 == 'C') {
                exit = false;
                continue;
            }
            else if (will2 == 'Q') {
                break;
            }
        }

    }
    printf("\n�� %d : %d CPU\n\n", victory, defeat);
    printf("�̿����ּż� �����մϴ�. \n");
}