#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

int N, M;

int main()
{
	cin >> N >> M;

	cout << (N - 1) * (M - 1) * 2;
}
