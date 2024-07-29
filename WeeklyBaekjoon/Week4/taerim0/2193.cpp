#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int N;

ll dp[91];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[N];
}