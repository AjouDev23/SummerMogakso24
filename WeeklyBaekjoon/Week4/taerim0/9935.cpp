#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

string target, bomb;
string stk;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> target >> bomb;

    for (auto word : target) {
        stk.push_back(word);
        if (word == bomb.back()) {
            bool isBomb = true;
            for (int i = 0; i < bomb.length(); i++) {
                if (bomb[bomb.length() - 1 - i] != stk[stk.length() - 1 - i]) {
                    isBomb = false; break;
                }
            }
            if (isBomb) {
                for (int i = 0; i < bomb.length(); i++)
                    stk.pop_back();
            }
        }
    }

    if (!stk.length()) cout << "FRULA";
    else cout << stk;
}