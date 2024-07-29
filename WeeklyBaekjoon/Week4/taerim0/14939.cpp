#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

#define ll long long
#define pii pair<int, int>

using namespace std;

bool swch[10][10];

int ans = INT32_MAX;

void click_swch(pii pos)
{
    swch[pos.first][pos.second] = !swch[pos.first][pos.second];
    if (pos.first) swch[pos.first - 1][pos.second] = !swch[pos.first - 1][pos.second];
    if (pos.second) swch[pos.first][pos.second - 1] = !swch[pos.first][pos.second - 1];
    if (pos.first < 9) swch[pos.first + 1][pos.second] = !swch[pos.first + 1][pos.second];
    if (pos.second < 9) swch[pos.first][pos.second + 1] = !swch[pos.first][pos.second + 1];
    return;
}

void Run(pii pos, int cnt)
{
    if (pos.first != 10) 
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0 && j == 0)
                i = pos.first, j = pos.second;

            if (!i) {
                click_swch({ i, j });
                if (j == 9) Run({ i + 1, 0 }, cnt + 1);
                else Run({ i, j + 1 }, cnt + 1);
                click_swch({ i, j });
            }
            else if (swch[i - 1][j]) {
                click_swch({ i, j });
                if (j == 9) Run({ i + 1, 0 }, cnt + 1);
                else Run({ i, j + 1 }, cnt + 1);
                click_swch({ i, j });
                return;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (swch[i][j]) return;
        }
    }

    ans = min(cnt, ans);

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char s; cin >> s;
            s == 'O' ? swch[i][j] = true : swch[i][j] = false;
        }
    }

    Run({ 0, 0 }, 0);

    cout << ans;
}