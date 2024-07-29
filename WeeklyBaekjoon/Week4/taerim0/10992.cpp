#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
#define pip pair<int, pii>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int a = 1, b = N;

    while (1) {
        if (a == N) {
            for (int i = 0; i < N * 2 - 1; i++) cout << "*";
            break;
        }

        for (int i = 0; i < (N - a); i++) {
            cout << " ";
        }
        if (a > 1) cout << "*";
        for (int i = 0; i < (a - 1) * 2 - 1; i++) {
            cout << " ";
        }

        if (a <= N) a++;
        cout << "*\n";
        if (a == N + 1) break;
    }
}