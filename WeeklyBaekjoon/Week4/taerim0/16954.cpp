#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

#define ll long long
#define pii pair<int, int>

using namespace std;

struct finder {
    int dis, y, x;

    bool operator<(const finder& d) const {
        return dis > d.dis;
    }
};

int ans;

int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1, 0 };
int dx[] = { 1, -1, 0, 1, -1, -1, 0, 1, 0 };

char board[8][8];
bool check[8][8];

void Run() {
    queue<finder> q;
    q.push({ 0, 7, 0 });

    while (q.size()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 9; i++) {
            int dm = now.y + dy[i];
            int dn = now.x + dx[i];

            if (dm > 7 || dn > 7 || dm < 0 || dn < 0)
                continue;

            if (dm - now.dis > -1 && board[dm - now.dis][dn] == '#')
                continue;

            if (dm - now.dis - 1 > -1 && board[dm - now.dis - 1][dn] == '#')
                continue;

            if (dm == 0 && dn == 7) {
                ans = 1; return;
            }

            check[dm][dn] = true;
            q.push({ now.dis + 1, dm, dn });
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }

    Run();

    cout << ans;
}