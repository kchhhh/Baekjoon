#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[101];
bool vis1[101][101];
bool vis2[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    //정상인
    queue<pair<int, int>> Q1;
    int count1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis1[i][j]) continue;
            count1++;
            char c = board[i][j];
            vis1[i][j] = true;
            Q1.push({i, j});
            while (!Q1.empty()) {
                auto cur = Q1.front(); Q1.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (vis1[nx][ny] || board[nx][ny] != c) continue;
                    vis1[nx][ny] = true;
                    Q1.push({nx, ny});
                }
            }
        }
    }
    cout << count1 << " ";

    //색맹
    queue<pair<int, int>> Q2;
    int count2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis2[i][j]) continue;
            count2++;
            char c = board[i][j];
            vis2[i][j] = true;
            Q2.push({i, j});
            while (!Q2.empty()) {
                auto cur = Q2.front(); Q2.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (vis2[nx][ny] || (c == 'B' && board[nx][ny] != c)) continue;
                    if ((c != 'B') && board[nx][ny] == 'B') continue;
                    vis2[nx][ny] = true;
                    Q2.push({nx, ny});
                }
            }
        }
    }
    cout << count2 << " ";
}