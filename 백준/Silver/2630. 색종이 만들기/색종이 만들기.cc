#include <bits/stdc++.h>
using namespace std;

int paper[128][128];
int cnt[2];

bool check(int x, int y, int size) {
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[i][j] != paper[x][y]) return false;
        }
    }
    return true;
}

void func(int x, int y, int size) {
    bool ok = check(x, y, size);
    if (ok) {
        cnt[paper[x][y]]++; return;
    }
    int n = size / 2;
    int offs[] = {0, n};
    for (int di : offs) {
        for (int dj : offs) {
            func(x + di, y + dj, n);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> paper[i][j];
    }
    func(0, 0, n);
    for (auto e : cnt) cout << e << "\n";
}