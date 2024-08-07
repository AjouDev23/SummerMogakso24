#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

#define ll long long
#define pii pair<int, int>

int N;

ll min_gasoline, ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<ll> road(N - 1);

    for (int i = 0; i < N - 1; i++) {
        cin >> road[i];
    }

    for (int i = 0; i < N; i++) {
        if (i) ans += min_gasoline * road[i - 1];

        ll gasoline;
        cin >> gasoline;

        min_gasoline = min(min_gasoline, gasoline);
        if (!i) min_gasoline = gasoline;
    }

    cout << ans;
}