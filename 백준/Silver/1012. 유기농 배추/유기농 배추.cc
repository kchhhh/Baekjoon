#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int board[50][50] = {0};
        bool vis[50][50] = {false};

        int n, m, k;
        cin >> m >> n >> k;
        while (k--) {
            int x, y;
            cin >> y >> x;
            board[x][y] = 1;
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] && !vis[i][j]) {
                    count++;
                    queue<pair<int, int>> Q;
                    Q.push({i, j});
                    vis[i][j] = true;
                    while (!Q.empty()) {
                        auto cur = Q.front(); Q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if (vis[nx][ny] || board[nx][ny] != 1) continue;
                            vis[nx][ny] = true;
                            Q.push({nx, ny});
                        }
                    }
                }
            }
        }
        cout << count << "\n";
    }


    
}