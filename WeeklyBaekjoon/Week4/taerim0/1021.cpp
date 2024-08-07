#include <iostream>
#include <queue>
#include <deque>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define ll long long
#define pii pair<int, int>

using namespace std;

int N, M;

int cnt;

deque<int> q;

int toLeft(deque<int> lq, int target) {
    int cnt = 0;
    while (1) {
        if (lq.front() == target) {
            return cnt;
        }
        cnt++;
        lq.push_front(lq.back());
        lq.pop_back();
    }
}

int toRight(deque<int> rq, int target) {
    int cnt = 0;
    while (1) {
        if (rq.front() == target) {
            return cnt;
        }
        cnt++;
        rq.push_back(rq.front());
        rq.pop_front();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;

    for (int i = 1; i <= N; i++) q.push_back(i);

    for (int i = 0; i < M; i++) {
        int target;  cin >> target;

        int goLeft = toLeft(q, target);
        int goRight = toRight(q, target);

        cnt += min(goLeft, goRight);

        while (1) {
            if (q.front() == target) {
                q.pop_front();
                break;
            }
            q.push_back(q.front());
            q.pop_front();
        }
    }

    cout << cnt;
}