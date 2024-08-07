#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int N;
int ans;
priority_queue<int> cards;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    while (N--) {
        int card; cin >> card;
        cards.push(-card);
    }

    while (cards.size() != 1) {
        int cardA = -cards.top();
        cards.pop();
        int cardB = -cards.top();
        cards.pop();

        int cardC = cardA + cardB;
        ans += cardC;
        cards.push(-cardC);
    }

    cout << ans;
}