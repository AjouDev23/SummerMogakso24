#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

#define ll long long
#define pii pair<int, int>

int N, ans;

vector<int> check(1000);
priority_queue<pii> assignments;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    while (N--) {
        int d, w;
        cin >> d >> w;

        assignments.push({ w, d });
    }

    while (!assignments.empty()) {
        pii assignment = assignments.top();
        assignments.pop();

        for (int i = assignment.second - 1; i >= 0; i--) {
            if (check[i] == 0) {
                check[i] = 1;
                ans += assignment.first;
                break;
            }
        }
    }

    cout << ans;
}