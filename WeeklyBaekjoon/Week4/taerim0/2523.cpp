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
        for (int i = 0; i < (a - (b - N)); i++) {
            cout << "*";
        }

        if (a < N) a++;
        else b++;
        if (b == N * 2) break;
        cout << "\n";
    }
}