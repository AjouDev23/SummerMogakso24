#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

#define ll long long
#define pii pair<int, int>

using namespace std;

int R, C;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

char pasture[500][500];

vector<pii> wolves;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> pasture[i][j];
            if (pasture[i][j] == 'W')
                wolves.push_back({ i, j });
        }
    }

    for (auto wolf : wolves) {
        auto [y, x] = wolf;

        for (int i = 0; i < 4; i++) {
            int dm = y + dy[i];
            int dn = x + dx[i];

            if (dm >= R || dm < 0 || dn >= C || dn < 0)
                continue;

            if (pasture[dm][dn] == 'S') {
                cout << 0;
                return 0;
            }
            else if (pasture[dm][dn] == '.') {
                pasture[dm][dn] = 'D';
            }
        }
    }

    cout << "1\n";
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << pasture[i][j];
        }
        cout << "\n";
    }
}