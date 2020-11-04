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
    printf("나 : ");

}
int is_winner(int user_rsp, int cpu_rsp) {
    switch (user_rsp) {
    case ROCK:
        if (cpu_rsp == SCISSOR) {
            printf("나 : 바위, 상대 : 가위\n");
            return 1;
        }
        else if (cpu_rsp == PAPER) {
            printf("나 : 바위, 상대 : 보\n");
            return 2;
        }
        else {
            printf("나 : 바위, 상대 : 바위\n");
            return 0;
        }
        break;
    case SCISSOR:
        if (cpu_rsp == ROCK) {
            printf("나 : 가위, 상대 : 바위\n");
            return 2;
        }
        else if (cpu_rsp == PAPER) {
            printf("나 : 가위, 상대 : 보\n");
            return 1;
        }
        else {
            printf("나 : 가위, 상대 : 가위\n");
            return 0;
        }
        break;
    case PAPER:
        if (cpu_rsp == ROCK) {
            printf("나 : 보, 상대 : 바위\n");
            return 1;
        }
        else if (cpu_rsp == SCISSOR) {
            printf("나 : 보, 상대 : 가위\n");
            return 2;
        }
        else {
            printf("나 : 보, 상대 : 보\n");
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
    while (true) {              //게임 계속하기 선택시 반복

        printf("가위, 바위, 보를 선택하세요 (r : 바위, s : 가위, p : 보)\n");
        while (true) {          //묵찌빠
            int UserRsp = user_select();
            int CpuRsp = rand() % 3 + 1;
            winner = is_winner(UserRsp, CpuRsp);
            switch (UserRsp) {
            case ROCK:
                if (vic == 0) {
                    switch (winner) {
                    case 0:
                        printf("비겼습니다. 다음패는 ? \n");
                        break;
                    case 1:
                        printf("이겼습니다. 다음 패는? (같은 패를 내면 이깁니다)\n");
                        vic = 1;
                        break;
                    case 2:
                        printf("졌습니다. 다음 패는? (같은 패를 내면 집니다)\n");
                        vic = 2;
                        break;
                    }
                }
                else if (vic == 1) {
                    switch (winner) {
                    case 0:
                        printf("승리했습니다\n");
                        victory++;
                        exit = true;
                        break;
                    case 1:
                        printf("이겼습니다. 다음 패는? (같은 패를 내면 이깁니다)\n");
                        break;
                    case 2:
                        printf("졌습니다. 다음 패는? (같은 패를 내면 집니다)\n");
                        vic = 2;
                        break;
                    }
                }
                else {
                    switch (winner) {
                    case 0:
                        printf("패배했습니다\n");
                        defeat++;
                        exit = true;
                        break;
                    case 1:
                        printf("이겼습니다. 다음 패는? (같은 패를 내면 이깁니다)\n");
                        vic = 1;
                        break;
                    case 2:
                        printf("졌습니다. 다음 패는? (같은 패를 내면 집니다)\n");
                        break;
                    }
                }
                break;
            case SCISSOR:
                if (vic == 0) {
                    switch (winner) {
                    case 0:
                        printf("비겼습니다. 다음패는 ? \n");
                        break;
                    case 1:
                        printf("이겼습니다. 다음 패는? (같은 패를 내면 이깁니다)\n");
                        vic = 1;
                        break;
                    case 2:
                        printf("졌습니다. 다음 패는? (같은 패를 내면 집니다)\n");
                        vic = 2;
                        break;
                    }
                }
                else if (vic == 1) {
                    switch (winner) {
                    case 0:
                        printf("승리했습니다\n");
                        victory++;
                        exit = true;
                        break;
                    case 1:
                        printf("이겼습니다. 다음 패는? (같은 패를 내면 이깁니다)\n");
                        break;
                    case 2:
                        printf("졌습니다. 다음 패는? (같은 패를 내면 집니다)\n");
                        vic = 2;
                        break;
                    }
                }
                else {
                    switch (winner) {
                    case 0:
                        printf("패배했습니다\n");
                        defeat++;
                        exit = true;
                        break;
                    case 1:
                        printf("이겼습니다. 다음 패는? (같은 패를 내면 이깁니다)\n");
                        vic = 1;
                        break;
                    case 2:
                        printf("졌습니다. 다음 패는? (같은 패를 내면 집니다)\n");
                        break;
                    }
                }
                break;
            case PAPER:
                if (vic == 0) {
                    switch (winner) {
                    case 0:
                        printf("비겼습니다. 다음패는 ? \n");
                        break;
                    case 1:
                        printf("이겼습니다. 다음 패는? (같은 패를 내면 이깁니다)\n");
                        vic = 1;
                        break;
                    case 2:
                        printf("졌습니다. 다음 패는? (같은 패를 내면 집니다)\n");
                        vic = 2;
                        break;
                    }
                }
                else if (vic == 1) {
                    switch (winner) {
                    case 0:
                        printf("승리했습니다\n");
                        victory++;
                        exit = true;
                        break;
                    case 1:
                        printf("이겼습니다. 다음 패는? (같은 패를 내면 이깁니다)\n");
                        break;
                    case 2:
                        printf("졌습니다. 다음 패는? (같은 패를 내면 집니다)\n");
                        vic = 2;
                        break;
                    }
                }
                else {
                    switch (winner) {
                    case 0:
                        printf("패배했습니다\n");
                        defeat++;
                        exit = true;
                        break;
                    case 1:
                        printf("이겼습니다. 다음 패는? (같은 패를 내면 이깁니다)\n");
                        vic = 1;
                        break;
                    case 2:
                        printf("졌습니다. 다음 패는? (같은 패를 내면 집니다)\n");
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
        printf("게임이 끝났습니다. \n계속하기 : C  |  멈추기 : Q  | 기록보기 : R \n");
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
            printf("승리 : %d, 패배 : %d\n", victory, defeat);
            printf("계속하기 : C  |  멈추기 : Q\n");
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
    printf("\n나 %d : %d CPU\n\n", victory, defeat);
    printf("이용해주셔서 감사합니다. \n");
}