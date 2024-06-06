#include <iostream>
#include <vector>
#include <string>
#include <graphics.h>
using namespace std;

// N 个皇后
int N = 0;

// 放入皇后之后，对应位置数组元素变为1，表示不可放置
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

// k 代表处理的第k行 
void backtrack(int k, vector<vector<int>>& attack, vector<string>& Queen, vector<vector<string>>& solve) {
    if (k == N) {
        solve.push_back(Queen); // 记录解法
        return;
    }

    for (int i = 0; i < N; i++) {
        if (attack[k][i] == 0) {
            vector<vector<int>> temp = attack; // 备份以便回溯
            Queen[k][i] = 'Q'; // 将该位置的字符换成 Q
            place_Queen(k, i, attack); // 将对应位置置为 1

            // 回溯
            backtrack(k + 1, attack, Queen, solve);

            attack = temp;
            Queen[k][i] = '.'; // 将该位置的字符换回 .
        }
    }
}

vector<vector<string>> N_Queen_problem() {
    vector<vector<string>> solve; // 记录最后的所有结果
    vector<vector<int>> attack(N, vector<int>(N, 0)); // 记录可选位置
    vector<string> Queen(N, string(N, '.')); // 记录皇后位置

    backtrack(0, attack, Queen, solve);

    return solve;
}

void show_solutions(vector<vector<string>>& solve) {
    cout << N << " 皇后问题一共有 " << solve.size() << " 种解法:" << endl;
    for (int i = 0; i < solve.size(); i++) {
        cout << "--------------------------" << endl;
        cout << "第 " << i + 1 << " 种解法：" << endl;

        for (int k = 0; k < N; k++) {
            cout << solve[i][k] << endl;
        }
    }
}

void VisualizeSolution(vector<string>& solution) {
    int cell_size = 50; // 每个格子的大小
    int window_size = N * cell_size; // 窗口大小

    initgraph(window_size, window_size); // 初始化图形窗口

    // 绘制棋盘
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

    // 绘制皇后
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (solution[i][j] == 'Q') {
                setfillcolor(RED);
                // 确保矩形在格子中央
                int centerX = j * cell_size + cell_size / 2;
                int centerY = i * cell_size + cell_size / 2;
                int size = cell_size / 2;
                solidrectangle(centerX - size / 2, centerY - size / 2, centerX + size / 2, centerY + size / 2);
            }
        }
    }

    getchar(); // 等待用户按键
    closegraph(); // 关闭图形窗口
}

void menu() {
    cout << "-----------------------" << endl;
    cout << "------1 N皇后游戏------" << endl;
    cout << "------0 退出 游戏------" << endl;
    cout << "-----------------------" << endl;
}

int main() {
    int select = 0;
    do {
        menu();
        cin >> select;

        if (select == 1) {
            system("cls");
            cout << "请输入阶数：";
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