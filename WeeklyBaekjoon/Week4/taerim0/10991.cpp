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
        for (int i = 1; i < N + a; i++) {
            if (i >= (N - a) + 1 && ((N + 1) % 2 ? ((i + a) % 2) : ((i + a + 1) % 2)))
                cout << "*";
            else
                cout << " ";
        }

        if (a <= N) a++;
        cout << "\n";
        if (a == N + 1) break;
    }
}