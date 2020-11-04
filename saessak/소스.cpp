#include <iostream>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

typedef enum RSP {
    ROCK,
    SCISSOR,
    PAPER
} RSP;

typedef enum RSP_RESULT {
    WIN,
    LOSE,
    DRAW
} RSP_RESULT;

RSP_RESULT GetPlayerWin(RSP playerRsp, RSP cpuRsp) {
    if (playerRsp == cpuRsp) {
        return DRAW;
    }

    switch (playerRsp)
    {
    case ROCK:
        return cpuRsp == PAPER ? LOSE : WIN;
    case SCISSOR:
        return cpuRsp == ROCK ? LOSE : WIN;
    case PAPER:
        return cpuRsp == SCISSOR ? LOSE : WIN;
    }

    //도달할 일 없음.
    return WIN;
}

RSP GetRandomRSP() {
    switch (rand() % 3) {
		case 0: return ROCK;
		case 1: return SCISSOR;
		case 2: return PAPER;
    }
    return ROCK;
}

string GetRSPString(RSP rsp) {
    switch (rsp) {
    case ROCK: return "주먹"; break;
    case SCISSOR: return  "가위"; break;
    case PAPER: return"보자기"; break;
    }
}

RSP GetPlayerRSP() {
    cout << "유저입력" << endl;
    float check_start_second = clock() / CLOCKS_PER_SEC;
    while (true) {
        Sleep(60);
        cout << "가위바위보";
        int player_pressed_key = 0;
        float now_second = clock() / CLOCKS_PER_SEC;
        float passed_second = now_second - check_start_second;
        // 예를 들어 now_second = 5.5;check_start_second = 3.5;
        if (passed_second > 5.0) {
            //5초가 지나면 랜덤으로 player 패를 선택
            cout << endl << "랜덤으로 선택됨" << endl;
            return GetRandomRSP();
        }
        if (_kbhit()) {
            player_pressed_key = _getch();
            // 근데 그 유저 입력이 유효한 유저입력이면?
            // 유효한? -> r s p 셋 중 하나.
            switch (player_pressed_key)
            {
            case 'r':
                cout << endl << "주먹을 선택함" << endl;
                return ROCK;
            case 's':
                cout << endl << "가위를 선택함" << endl;
                return SCISSOR;
            case 'p':
                cout << endl << "보자기를 선택함" << endl;
                return PAPER;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int win_flag = 0;

    int cpuWinCount = 0;
    int playerWinCount = 0;

    while (true) {
        while (true) {
            RSP cpuRSP = GetRandomRSP();
            RSP playerRSP = GetPlayerRSP();

            RSP_RESULT rspPlayerResult = GetPlayerWin(playerRSP, cpuRSP);

            bool shouldExitGame = false;

            cout << "씨피유는" << GetRSPString(cpuRSP) << "유저는" << GetRSPString(playerRSP) << endl;
            switch (rspPlayerResult)
            {
            case WIN:
            {
                bool playerWinBefore = (win_flag == 1);
                if (playerWinBefore) {
                    cout << "플레이어 2번 이김" << endl;
                    shouldExitGame = true;
                    playerWinCount++;
                }
                else {
                    cout << "플레이어 1번 이김" << endl;
                    win_flag = 1;
                }
                // 플레이어 우승처리
                // 플레이어가 2번 이기면
            }
            break;
            case LOSE:
            {
                bool cpuWinBefore = win_flag == -1;
                if (cpuWinBefore) {
                    cout << "컴터 2번 이김" << endl;
                    cpuWinCount++;
                    shouldExitGame = true;
                }
                else {
                    cout << "컴터 1번 이김" << endl;
                    win_flag = -1;
                }
                // cpu 우승처리
            }
            break;
            case DRAW:
                cout << "다시" << endl;
                // 다시 한번
                break;
            }
            Sleep(1000);

            if (shouldExitGame) {
                break;
            }
        }

        while (true) {
            char command;
            cout << "기록보기 : r, 다시하기 c, 멈추기 q";
            cin >> command;
            bool exitLoop = false;
            switch (command)
            {
            case 'r':
                cout << "플레이어 : " << playerWinCount << "컴퓨터 : " << cpuWinCount << endl;
                break;
            case 'c':
                exitLoop = true;
                break;
            case 'q':
                // 원래 이렇게 하면 안되긴 하는데 그냥 함.
                return 0;
            }

            if (exitLoop) {
                break;
            }
        }
    }

    //제대로 끝내자
    return 0;
}