#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

#define ll long long

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    while (N--) {
        string left, right;
        cin >> left >> right;

        int dif01 = 0, dif10 = 0;

        for (int i = 0; i < left.length(); i++) {
            if (left[i] == '0' && right[i] == '1') dif01++;
            if (left[i] == '1' && right[i] == '0') dif10++;
        }

        cout << max(dif01, dif10) << "\n";
    }
}