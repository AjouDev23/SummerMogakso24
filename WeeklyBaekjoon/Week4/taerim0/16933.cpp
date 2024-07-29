#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
#define ppi pair<pii, pii>
#define ppp pair<int, ppi>

using namespace std;

struct finder {
    int dis, k, y, x;
    bool isDay;

    bool operator<(const finder& d) const {
        return dis > d.dis;
    }
};

int N, M, K;
char maze[1000][1000];
pii check[1000][1000];

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

int Run() {
    priority_queue<finder> pq;
    pq.push({ 1, K, 0, 0, true });
    check[0][0] = { K, 2 };

    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if (now.y == N - 1 && now.x == M - 1)
            return now.dis;

        bool nearWall = false;

        for (int i = 0; i < 4; i++) {
            int dm = now.y + dy[i];
            int dn = now.x + dx[i];
            bool breakWall = false;

            if (dm >= N || dn >= M || dm < 0 || dn < 0)
                continue;

            if (check[dm][dn].first >= now.k && (check[dm][dn].second == 2 || (now.isDay && check[dm][dn].second == 1)))
                continue;

            if (maze[dm][dn] == '1') {
                nearWall = true;
                if (!now.isDay || now.k <= 0) continue;
                breakWall = true;
            }

            check[dm][dn] = { breakWall ? now.k - 1 : now.k, now.isDay ? 1 : 2 };
            pq.push({ now.dis + 1, breakWall ? now.k - 1 : now.k, dm, dn, !now.isDay });
        }

        if (nearWall && !now.isDay && (check[now.y][now.x].second == 1 || check[now.y][now.x].first < now.k)) {
            check[now.y][now.x] = { now.k, 2 };
            pq.push({ now.dis + 1, now.k, now.y, now.x, !now.isDay });
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];
        }
    }

    cout << Run();
}