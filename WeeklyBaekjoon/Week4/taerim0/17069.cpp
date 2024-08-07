#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

#define ll long long
#define pii pair<int, int>
#define ppp pair<pii, pii>
#define piP pair<int, ppi>

using namespace std;

int N;
ll ans;
int house[32][32];
ll dp[32][32][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> house[i][j];
        }
    }

    dp[0][1][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 2; j < N; j++) {
            if (!house[i][j]) dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];
            if (i && !house[i][j - 1] && !house[i - 1][j] && !house[i][j]) dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
            if (i && !house[i][j]) dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2];
        }
    }

    cout << dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
}