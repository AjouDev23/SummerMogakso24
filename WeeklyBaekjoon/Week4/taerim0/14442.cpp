#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

#define ll long long
#define pii pair<int, int>

using namespace std;

struct finder {
    int dis, y, x, k;

    bool operator<(const finder& d) const {
        return dis > d.dis;
    }
};

int N, M, K;
char maze[1000][1000];
int check[1000][1000];

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

int Run() {
    priority_queue<finder> pq;
    pq.push({ 1, 0, 0, K });
    check[0][0] = K + 1;

    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if (now.y == N - 1 && now.x == M - 1)
            return now.dis;

        for (int i = 0; i < 4; i++) {
            int dm = now.y + dy[i];
            int dn = now.x + dx[i];
            bool breakWall = false;

            if (dm >= N || dn >= M || dm < 0 || dn < 0)
                continue;

            if (check[dm][dn] >= now.k + 1)
                continue;

            if (maze[dm][dn] == '1') {
                if (now.k == 0) continue;
                breakWall = true;
            }

            check[dm][dn] = (breakWall ? now.k - 1 : now.k) + 1;
            pq.push({ now.dis + 1, dm, dn, breakWall ? now.k - 1 : now.k });
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