#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

int N;

char map[100][100];

int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int mobis[5] = { 'M', 'O', 'B', 'I', 'S' };

int findCnt;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 8; k++) {
				int y = i, x = j;

				for (int c = 0; c < 5; c++) {
					if (map[y][x] != mobis[c])
						break;
					
					if (c == 4)
						findCnt++;

					y += dy[k], x += dx[k];

					if (y < 0 || x < 0 || y >= N || x >= N)
						break;
				}
			}
		}
	}

	cout << findCnt;
}
