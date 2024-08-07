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
ll lt, rt, nt;
ll ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    lt = 1, rt = 1, nt = 1;
    ans = 3;

    for (int i = 2; i <= N; i++) {
        ll nlt, nrt, nnt;
        nnt = (nt + rt + lt) % 9901;
        nlt = (rt + nt) % 9901;
        nrt = (lt + nt) % 9901;
        nt = nnt; lt = nlt; rt = nrt;
    }

    cout << (nt + lt + rt) % 9901;
}