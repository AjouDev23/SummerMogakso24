#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

#define ll long long
#define pii pair<int, int>

using namespace std;

vector<int> edge[100001];
int check[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M, R; cin >> N >> M >> R;
    while (M--) {
        int a, b; cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    queue<int> q;
    q.push(R);
    while (q.size()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < edge[now].size(); i++) {
            int next = edge[now][i];
            if (check[next] || next == R) continue;
            check[next] = check[now] + 1;
            q.push(next);
        }
    }
    for (int i = 1; i <= N; i++) {
        if (i == R) cout << 0;
        else if (!check[i]) cout << -1;
        else cout << check[i];
        cout << "\n";
    }
}