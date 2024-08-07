#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

#define ll long long
#define pii pair<int, int>

using namespace std;

struct finder {
    int dis, city;
    vector<int> path;

    bool operator<(const finder& d) const {
        return dis > d.dis;
    }
};

int n, m;

vector<vector<pii>> bus(1001);
int dist[1001];
vector<int> paths[1001];
int from, to;

void dijkstra()
{
    priority_queue<finder> pq;
    dist[from] = 0;
    paths[from] = { from };
    pq.push({ 0, from, { from } });

    while (pq.size()) {
        auto [base, now, pathV] = pq.top();
        pq.pop();

        if (dist[now] < -base)
            continue;

        for (int i = 0; i < bus[now].size(); i++) {
            auto [next, cost] = bus[now][i];

            if (-base + cost < dist[next]) {
                dist[next] = -base + cost;
                pathV.push_back(next);
                paths[next] = pathV;
                pq.push({ base - cost, next, pathV });
                pathV.pop_back();
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) dist[i] = INT32_MAX;

    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        bus[a].push_back({ b, c });
    }

    cin >> from >> to;

    dijkstra();

    cout << dist[to] << "\n";
    cout << paths[to].size() << "\n";
    for (auto city : paths[to])
        cout << city << " ";
}