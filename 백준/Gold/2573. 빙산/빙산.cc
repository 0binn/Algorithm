#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 300
using namespace std;
int ice[MAX][MAX];
bool visited[MAX][MAX];
int N, M;
int dx[4] = { -1,1,0,0 }; //상하좌우
int dy[4] = { 0,0,-1,1 };
int max_ice = 0;

void BFS(int x, int y)
{
	queue <pair<int, int>> q;
	visited[x][y] = true;
	q.push(make_pair(x, y));
	int x_start;
	int y_start;
	int temp_max = 0;
	while (!q.empty()) {
		x_start = q.front().first;
		y_start = q.front().second;

		for (int d = 0; d < 4; d++) {
			int x_next = dx[d] + x_start;
			int y_next = dy[d] + y_start;

			if (ice[x_next][y_next] == 0 && !visited[x_next][y_next] && ice[x_start][y_start] > 0) {
				ice[x_start][y_start]--;
			}
			else if (!visited[x_next][y_next] && ice[x_next][y_next] != 0) {
				q.push(make_pair(x_next, y_next));
				visited[x_next][y_next] = true;
			}
		}
		if (temp_max < ice[x_start][y_start]) {
			temp_max = ice[x_start][y_start];
		}
		q.pop();
	}
	max_ice = temp_max;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ice[i][j];
			if (max_ice < ice[i][j]) {
				max_ice = ice[i][j];
			}
		}
	}

	int day = 0;
	while (max_ice != 0) {
		bool one = false; //섬 하나이상
		for (int i = 1; i < N - 1; i++) {
			for (int j = 1; j < M - 1; j++) {
				if (ice[i][j] > 0 && visited[i][j] == false) {
					if (one) {
						cout << day;
						return 0;
					}
					BFS(i, j);
					one = true;
				}
			}
		}
		memset(visited, false, sizeof(visited));
		day++;
	}
	cout << 0;
	return 0;
}