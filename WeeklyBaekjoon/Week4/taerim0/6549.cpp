#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

int n;

vector<int> sq(100000);

ll merge_sqs(int l, int r, int m, ll lm, ll rm)
{
    int lft = m - 1, rht = m + 1;
    ll height = sq[m], area = sq[m];

    while (lft >= l && rht <= r) {
        if (sq[rht] > sq[lft]) {
            if (sq[rht] < height)
                height = sq[rht];
            area = max(area, height * (rht - lft));
            rht++;
        }
        else {
            if (sq[lft] < height)
                height = sq[lft];
            area = max(area, height * (rht - lft));
            lft--;
        }
    }
    
    while (l <= lft) {
        if (sq[lft] < height)
            height = sq[lft];
        area = max(area, height * (rht - lft));
        lft--;
    }
    while (r >= rht) {
        if (sq[rht] < height)
            height = sq[rht];
        area = max(area, height * (rht - lft));
        rht++;
    }

    return max(area, lm > rm ? lm : rm);
}

ll find_Largest_sq(int l, int r)
{
    int m;

    if (l < r) {
        m = (l + r) / 2;
        ll lm = find_Largest_sq(l, m);
        ll rm = find_Largest_sq(m + 1, r);
        return merge_sqs(l, r, m, lm, rm);
    }
    return sq[l];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (1) {
        cin >> n;
        if (!n) break;

        for (int i = 0; i < n; i++) {
            cin >> sq[i];
        }

        cout << find_Largest_sq(0, n - 1) << "\n";
    }
}