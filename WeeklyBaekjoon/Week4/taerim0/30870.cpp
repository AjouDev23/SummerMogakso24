#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
#define pip pair<int, pii>

using namespace std;

struct edge {
    int x, y;
    int deltime;

    bool operator<(const edge& d) const {
        return deltime > d.deltime;
    }
};

int N, M, K;
int a, b;

vector<int> v[200001];
int delete_time[200001];
queue<int> q;
vector<edge> edges;

bool check[200001];
int parent[200001];

void go_delete()
{
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        check[now] = true;

        for (int i = 0; i < v[now].size(); i++) {
            if (check[v[now][i]]) continue;

            if (delete_time[v[now][i]]) {
                edges.push_back({ now, v[now][i], delete_time[now] });
                continue;
            }

            edges.push_back({ now, v[now][i], delete_time[now] });
            delete_time[v[now][i]] = delete_time[now] + 1;
            q.push(v[now][i]);
        }
    }
}

int Find(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y) return false;
    parent[y] = x;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) parent[i] = i;


    while (M--) {
        cin >> a >> b;
        v[a].push_back(b); v[b].push_back(a);
    }

    while (K--) {
        cin >> a;
        delete_time[a] = 1;
        q.push(a);
    }

    go_delete();
    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++) {
        auto [x, y, time] = edges[i];

        if (!Union(x, y)) {
            cout << time;
            break;
        }
    }
}