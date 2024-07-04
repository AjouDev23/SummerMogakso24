#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

int T, N;

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++) {
		
		cin >> N;

		int value = 1;

		for (int i = 1; i <= N; i++) {
			value *= i;
		}

		cout << value % 10 << "\n";
	}
}
