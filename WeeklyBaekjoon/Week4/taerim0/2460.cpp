#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
#define pip pair<int, pii>

using namespace std;

int N, ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 10; i++) {
        int a, b; cin >> a >> b;

        N += b - a;
        ans = max(ans, N);
    }

    cout << ans;
}