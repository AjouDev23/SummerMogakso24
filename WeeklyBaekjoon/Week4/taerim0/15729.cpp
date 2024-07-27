#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

#define ll long long

int N, ans;

vector<int> buttons(1000000);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int nextButton;
        cin >> nextButton;

        if (buttons[i] != nextButton) {
            ans++;
            if (i < N - 1)
                buttons[i + 1] = (buttons[i + 1] + 1) % 2;
            if (i < N - 2)
                buttons[i + 2] = (buttons[i + 2] + 1) % 2;
        }
    }

    cout << ans;
}