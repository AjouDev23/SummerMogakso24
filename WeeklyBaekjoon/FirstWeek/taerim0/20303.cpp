#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

int N, M, K;

int candy[30001];
int friends_cnt[30001];
int parent[30001];

int waycnt;
pll way[30001];

int dp[30001][3001];

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	int px = Find(x);
	int py = Find(y);
	if (px != py) {
		parent[px] = py;
		friends_cnt[py] += friends_cnt[px];
		candy[py] += candy[px];
	}
}

int main()
{
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		cin >> candy[i];
		friends_cnt[i] = 1;
		parent[i] = i;
	}

	while (M--) {
		int a, b;
		cin >> a >> b;

		Union(a, b);
	}

	for (int i = 1; i <= N; i++) {
		if (i == parent[i]) {
			way[++waycnt].first = candy[i];
			way[waycnt].second = friends_cnt[i];
		}
	}

	for (int j = 1; j <= waycnt; j++) {
		for (int i = 1; i <= K; i++) {
			int candys = way[j].first;
			int friends = way[j].second;

			if (friends < i) {
				dp[j][i] = max(dp[j - 1][i - friends] + candys, dp[j - 1][i]);
			}
			else {
				dp[j][i] = dp[j - 1][i];
			}
		}
	}

	cout << dp[waycnt][K];
}