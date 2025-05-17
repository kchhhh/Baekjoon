#include <bits/stdc++.h>
using namespace std;

int N;
bool board[3200][6200];

void func(int i, int j, int size) {
    if (size == 3) {
        board[i][j] = true;
        board[i + 1][j - 1] = true; board[i + 1][j + 1] = true;
        for (int dj : {-2, -1, 0, 1, 2}) board[i + 2][j + dj] = true;
        return;
    }
    int m = size / 2;
    func(i, j, m);
    func(i + m, j - m, m);
    func(i + m, j + m, m);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    func(0, N - 1, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++) {
            if (board[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << "\n";
    }
}