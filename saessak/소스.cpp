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

    //������ �� ����.
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
    case ROCK: return "�ָ�"; break;
    case SCISSOR: return  "����"; break;
    case PAPER: return"���ڱ�"; break;
    }
}

RSP GetPlayerRSP() {
    cout << "�����Է�" << endl;
    float check_start_second = clock() / CLOCKS_PER_SEC;
    while (true) {
        Sleep(60);
        cout << "����������";
        int player_pressed_key = 0;
        float now_second = clock() / CLOCKS_PER_SEC;
        float passed_second = now_second - check_start_second;
        // ���� ��� now_second = 5.5;check_start_second = 3.5;
        if (passed_second > 5.0) {
            //5�ʰ� ������ �������� player �и� ����
            cout << endl << "�������� ���õ�" << endl;
            return GetRandomRSP();
        }
        if (_kbhit()) {
            player_pressed_key = _getch();
            // �ٵ� �� ���� �Է��� ��ȿ�� �����Է��̸�?
            // ��ȿ��? -> r s p �� �� �ϳ�.
            switch (player_pressed_key)
            {
            case 'r':
                cout << endl << "�ָ��� ������" << endl;
                return ROCK;
            case 's':
                cout << endl << "������ ������" << endl;
                return SCISSOR;
            case 'p':
                cout << endl << "���ڱ⸦ ������" << endl;
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

            cout << "��������" << GetRSPString(cpuRSP) << "������" << GetRSPString(playerRSP) << endl;
            switch (rspPlayerResult)
            {
            case WIN:
            {
                bool playerWinBefore = (win_flag == 1);
                if (playerWinBefore) {
                    cout << "�÷��̾� 2�� �̱�" << endl;
                    shouldExitGame = true;
                    playerWinCount++;
                }
                else {
                    cout << "�÷��̾� 1�� �̱�" << endl;
                    win_flag = 1;
                }
                // �÷��̾� ���ó��
                // �÷��̾ 2�� �̱��
            }
            break;
            case LOSE:
            {
                bool cpuWinBefore = win_flag == -1;
                if (cpuWinBefore) {
                    cout << "���� 2�� �̱�" << endl;
                    cpuWinCount++;
                    shouldExitGame = true;
                }
                else {
                    cout << "���� 1�� �̱�" << endl;
                    win_flag = -1;
                }
                // cpu ���ó��
            }
            break;
            case DRAW:
                cout << "�ٽ�" << endl;
                // �ٽ� �ѹ�
                break;
            }
            Sleep(1000);

            if (shouldExitGame) {
                break;
            }
        }

        while (true) {
            char command;
            cout << "��Ϻ��� : r, �ٽ��ϱ� c, ���߱� q";
            cin >> command;
            bool exitLoop = false;
            switch (command)
            {
            case 'r':
                cout << "�÷��̾� : " << playerWinCount << "��ǻ�� : " << cpuWinCount << endl;
                break;
            case 'c':
                exitLoop = true;
                break;
            case 'q':
                // ���� �̷��� �ϸ� �ȵǱ� �ϴµ� �׳� ��.
                return 0;
            }

            if (exitLoop) {
                break;
            }
        }
    }

    //����� ������
    return 0;
}