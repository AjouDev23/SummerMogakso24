#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define pii pair<int, int>
#define data pair<int, pair<unsigned char, pii>>
// distance, key_status, position

int N, M;

char map[50][50];

int dist[64][50][50];

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

pii start;

int ans = -1;

void find_distance(data ini) {
    queue<data> q;
    q.push(ini);

    while (!q.empty()) {
        data dat = q.front();
        q.pop();
        auto [dis, nd] = dat;
        auto [key, pos] = nd;
        auto [y, x] = pos;

        for (int i = 0; i < 4; i++) {
            int dn = y + dy[i];
            int dm = x + dx[i];

            if (dn >= N || dm >= M || dn < 0 || dm < 0)
                continue;
            
            if (map[dn][dm] == '#')
                continue;

            if (map[dn][dm] >= 'A' && map[dn][dm] <= 'F')
                if (!((key >> map[dn][dm] - 'A') & 1u))
                    continue;

            if (dist[key][dn][dm] != 0 && dist[key][dn][dm] <= dis + 1)
                continue;
            dist[key][dn][dm] = dis + 1;

            if (map[dn][dm] >= 'a' && map[dn][dm] <= 'f') {
                if ((key >> (map[dn][dm] - 'a')) & 1u)
                    q.push({ dis + 1, { key, { dn, dm } } });
                else
                    q.push({ dis + 1, { key | (1u << (map[dn][dm] - 'a')), { dn, dm } } });
            }
            else
                q.push({ dis + 1, { key, { dn, dm } } });

            if (map[dn][dm] == '1') {
                ans = dis + 1;
                return;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];

            if (map[i][j] == '0') {
                start = { i, j };
                dist[0][i][j] = -1;
            }
        }
    }

    find_distance({ 0, { 0, start } });

    cout << ans;

    return 0;
}