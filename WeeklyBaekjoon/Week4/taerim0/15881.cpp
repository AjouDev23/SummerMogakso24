#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

#define ll long long

int N;

char ppap[] = { 'p', 'P', 'A', 'p' };

int iter, ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    while (N--) {
        char item;

        cin >> item;

        if (ppap[iter] == item) {
            iter++;
            if (iter == 4) ans++, iter = 0;
        }
        else {
            if (item == ppap[0]) iter = 1;
            else iter = 0;
        }
    }

    cout << ans;
}