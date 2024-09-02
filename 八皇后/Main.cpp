#include <iostream>
#include <vector>
#include <string>
#include <graphics.h>
using namespace std;

// N ���ʺ�
int N = 0;

// ����ʺ�֮�󣬶�Ӧλ������Ԫ�ر�Ϊ1����ʾ���ɷ���
void place_Queen(int& k, int& i, vector<vector<int>>& attack) {
    for (int R = 0; R < N; R++) {
        attack[k][R] = 1;
    }

    for (int L = 0; L < N; L++) {
        attack[L][i] = 1;
    }

    for (int LD = 1; k - LD >= 0 && i - LD >= 0; LD++) {
        attack[k - LD][i - LD] = 1;
    }
    for (int LD = 1; k + LD < N && i + LD < N; LD++) {
        attack[k + LD][i + LD] = 1;
    }

    for (int RD = 1; k + RD < N && i - RD >= 0; RD++) {
        attack[k + RD][i - RD] = 1;
    }
    for (int RD = 1; k - RD >= 0 && i + RD < N; RD++) {
        attack[k - RD][i + RD] = 1;
    }
}

// k ������ĵ�k�� 
void backtrack(int k, vector<vector<int>>& attack, vector<string>& Queen, vector<vector<string>>& solve) {
    if (k == N) {
        solve.push_back(Queen); // ��¼�ⷨ
        return;
    }

    for (int i = 0; i < N; i++) {
        if (attack[k][i] == 0) {
            vector<vector<int>> temp = attack; // �����Ա����
            Queen[k][i] = 'Q'; // ����λ�õ��ַ����� Q
            place_Queen(k, i, attack); // ����Ӧλ����Ϊ 1

            // �ݹ�
            backtrack(k + 1, attack, Queen, solve);

            attack = temp;
            Queen[k][i] = '.'; // ����λ�õ��ַ����� .
        }
    }
}

vector<vector<string>> N_Queen_problem() {
    vector<vector<string>> solve; // ��¼�������н��
    vector<vector<int>> attack(N, vector<int>(N, 0)); // ��¼��ѡλ��
    vector<string> Queen(N, string(N, '.')); // ��¼�ʺ�λ��

    backtrack(0, attack, Queen, solve);

    return solve;
}

void show_solutions(vector<vector<string>>& solve) {
    cout << N << " �ʺ�����һ���� " << solve.size() << " �ֽⷨ:" << endl;
    for (int i = 0; i < solve.size(); i++) {
        cout << "--------------------------" << endl;
        cout << "�� " << i + 1 << " �ֽⷨ��" << endl;

        for (int k = 0; k < N; k++) {
            cout << solve[i][k] << endl;
        }
    }
}

void VisualizeSolution(vector<string>& solution) {
    int cell_size = 50; // ÿ�����ӵĴ�С
    int window_size = N * cell_size; // ���ڴ�С

    initgraph(window_size, window_size); // ��ʼ��ͼ�δ���

    // ��������
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int left = j * cell_size;
            int top = i * cell_size;
            int right = left + cell_size;
            int bottom = top + cell_size;

            if ((i + j) % 2 == 0) {
                setfillcolor(WHITE);
            }
            else {
                setfillcolor(LIGHTGRAY);
            }
            solidrectangle(left, top, right, bottom);
        }
    }

    // ���ƻʺ�
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (solution[i][j] == 'Q') {
                setfillcolor(RED);
                // ȷ�������ڸ�������
                int centerX = j * cell_size + cell_size / 2;
                int centerY = i * cell_size + cell_size / 2;
                int size = cell_size / 2;
                solidrectangle(centerX - size / 2, centerY - size / 2, centerX + size / 2, centerY + size / 2);
            }
        }
    }

    getchar(); // �ȴ��û�����
    closegraph(); // �ر�ͼ�δ���
}

void menu() {
    cout << "-----------------------" << endl;
    cout << "------1 N�ʺ���Ϸ------" << endl;
    cout << "------0 �˳� ��Ϸ------" << endl;
    cout << "-----------------------" << endl;
}

int main() {
    int select = 0;
    do {
        menu();
        cin >> select;

        if (select == 1) {
            system("cls");
            cout << "�����������";
            cin >> N;

            vector<vector<string>> solve = N_Queen_problem();
            show_solutions(solve);

            for (auto& solution : solve) {
                VisualizeSolution(solution);
            }

        }
    } while (select != 0);

    return 0;
}