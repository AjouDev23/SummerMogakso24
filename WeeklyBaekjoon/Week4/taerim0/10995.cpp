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

    int a = 0;

    while (1) {
        for (int i = 0; i < N * 2 - ((a + 1) % 2); i++) {
            if ((a + i + 1) % 2) cout << "*";
            else cout << " ";
        }

        if (a < N) a++;
        if (a == N) break;
        cout << "\n";
    }
}