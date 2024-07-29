#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

#define ll long long
#define pii pair<int, int>

using namespace std;

int w, b;

int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

char board[4][4];
bool check[4][4];
string findWord;
int find_idx = INT32_MAX;

vector<string> word(300000);

bool comp_word(string a, string b)
{
    if (a.length() == b.length()) {
        return a < b;
    }
    return a.length() > b.length();
}

void dfs(int now_check, int level, pii pos, vector<bool>& check_word, int& find_cnt, int& point)
{
    if (level == word[now_check].length()) {
        find_cnt++;
        if (level == 3 || level == 4)
            point++;
        if (level == 5)
            point += 2;
        if (level == 6)
            point += 3;
        if (level == 7)
            point += 5;
        if (level == 8)
            point += 11;
        if (now_check < find_idx) {
            find_idx = now_check;
            findWord = word[find_idx];
        }
        check_word[now_check] = true;
        return;
    }

    for (int i = 0; i < 8; i++) {
        int dm = pos.first + dy[i];
        int dn = pos.second + dx[i];

        if (dm > 3 || dn > 3 || dm < 0 || dn < 0)
            continue;

        if (check[dm][dn])
            continue;

        if (board[dm][dn] != word[now_check][level])
            continue;

        check[dm][dn] = true;
        dfs(now_check, level + 1, { dm, dn }, check_word, find_cnt, point);
        check[dm][dn] = false;
        if (check_word[now_check]) return;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> w;

    for (int i = 0; i < w; i++) {
        cin >> word[i];
    }

    sort(word.begin(), word.end(), comp_word);

    cin >> b;

    while (b--) {
        vector<bool> check_word(300000, false);
        int point = 0, find_cnt = 0;
        find_idx = INT32_MAX;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> board[i][j];
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < w; k++) {
                    if (check_word[k]) continue;
                    if (board[i][j] == word[k][0]) {
                        check[i][j] = true;
                        dfs(k, 1, { i, j }, check_word, find_cnt, point);
                        check[i][j] = false;
                    }
                }
            }
        }

        cout << point << " " << findWord << " " << find_cnt << "\n";
    }
}