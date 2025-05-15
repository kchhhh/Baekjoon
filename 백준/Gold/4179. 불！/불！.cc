#include <bits/stdc++.h>
using namespace std;

string board[1001];
int distF[1001][1001];
int distJ[1001][1001];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> Q;
    pair<int, int> jh;
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            distF[i][j] = -1; distJ[i][j] = -1;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char c = board[i][j];
            if (c == 'J') {
                distJ[i][j] = 0;
                jh = {i, j};
            }
            if (c == 'F') {
                distF[i][j] = 0;
                Q.push({i, j});
            }
        }
    }

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (distF[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            distF[nx][ny] = distF[cur.first][cur.second] + 1;
            Q.push({nx, ny});
        }
    }
    Q.push(jh);
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                if ((distJ[cur.first][cur.second] >= 0 && distF[cur.first][cur.second] == -1) || (distJ[cur.first][cur.second] < distF[cur.first][cur.second])) {
                    cout << distJ[cur.first][cur.second] + 1;
                    return 0;
                }
                continue;
            }
            if (distJ[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            distJ[nx][ny] = distJ[cur.first][cur.second] + 1;
            Q.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE\n";
}