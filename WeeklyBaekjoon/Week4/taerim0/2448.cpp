#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

#define ll long long
#define pii pair<int, int>

using namespace std;

int N;

bool star[3072][6144];

void Run(int n, pii pos)
{
    if (n == 3) {
        star[pos.first][pos.second + 2] = true;
        star[pos.first + 1][pos.second + 1] = true;
        star[pos.first + 1][pos.second + 3] = true;
        star[pos.first + 2][pos.second] = true;
        star[pos.first + 2][pos.second + 1] = true;
        star[pos.first + 2][pos.second + 2] = true;
        star[pos.first + 2][pos.second + 3] = true;
        star[pos.first + 2][pos.second + 4] = true;
    }
    else {
        Run(n / 2, { pos.first, pos.second + n / 2 });
        Run(n / 2, { pos.first + n / 2 , pos.second });
        Run(n / 2, { pos.first + n / 2, pos.second + n });
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;

    Run(N, { 0, 0 });

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N * 2; j++) {
            if (star[i][j]) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
}