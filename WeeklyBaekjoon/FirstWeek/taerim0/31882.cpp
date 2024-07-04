#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

int N;

char str[1000000];

ll geunCnt;
ll geunPlus;
ll point;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str[i];

		if (str[i] == '2') {
			if (i > 0 && str[i - 1] == '2')
				point += 2;
			point++;

			geunCnt++;

			if (geunCnt > 2)
				geunPlus += geunCnt, point += geunPlus;
		}
		else {
			geunCnt = 0, geunPlus = 0;
		}
	}

	cout << point;
}
