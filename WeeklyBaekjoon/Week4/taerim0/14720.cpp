#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

#define ll long long

int N;

int iter, ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    while (N--) {
        int store;

        cin >> store;

        if (store == iter) {
            ans++;
            iter = (iter + 1) % 3;
        }
    }

    cout << ans;
}