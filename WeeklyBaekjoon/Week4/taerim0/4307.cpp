#include <iostream>
#include <queue>
#include <deque>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define ll long long
#define pii pair<int, int>

using namespace std;

int t, n, l;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;

    while (t--) {
        cin >> n >> l;
        int min_ant, max_ant;
        for (int i = 0; i < l; i++) {
            int ant; cin >> ant;
            if (!i) min_ant = ant, max_ant = ant;
            if (abs(n / 2 - ant) > abs(n / 2 - min_ant)) min_ant = ant;
            if (abs(n / 2 - ant) < abs(n / 2 - max_ant)) max_ant = ant;
        }

        abs(max_ant) > abs(n - max_ant) ? cout << abs(n - max_ant) : cout << abs(max_ant);
        cout << " ";
        abs(min_ant) < abs(n - min_ant) ? cout << abs(n - min_ant) : cout << abs(min_ant);
        cout << "\n";
    }
}