#include <bits/stdc++.h>
using namespace std;

bool board[2200][2200];
void func(int i, int j, int size) {
    if (size == 1) {board[i][j] = true; return;}
    int m = size / 3;
    for (int di = 0; di < size; di += m) {
        for (int dj = 0; dj < size; dj += m) {
            if (di == m && dj == m) continue;
            func(i + di, j + dj, m);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int  N;
    cin >> N;
    func(0, 0, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << "\n";
    }
}