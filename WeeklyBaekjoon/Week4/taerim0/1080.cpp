#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

#define ll long long

int N, M, ans;

vector<vector<char>> matrix(50, vector<char>(50));

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char elem;
            cin >> elem;

            if (matrix[i][j] != elem) {
                if (i > N - 3 || j > M - 3) {
                    ans = -1;
                    break;
                }

                ans++;
                for (int a = 0; a < 3; a++) {
                    for (int b = 0; b < 3; b++) {
                        matrix[i + a][j + b] = matrix[i + a][j + b] == '1' ? '0' : '1';
                    }
                }
            }
        }
        if (ans == -1) break;
    }

    cout << ans;
}