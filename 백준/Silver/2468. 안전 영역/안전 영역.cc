#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAX 101
using namespace std;

int map[MAX][MAX];
bool visited[MAX][MAX];
vector <int>cnt;
int N;
int dir_x[4] = { -1,1,0,0 };
int dir_y[4] = { 0,0,-1,1 };

void BFS(int x, int y, int rain)
{
	visited[x][y] = true;
	queue <pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {

		int x_start = q.front().first;
		int y_start = q.front().second;

		for (int dir = 0; dir < 4; dir++) {
			int x_next = x_start + dir_x[dir];
			int y_next = y_start + dir_y[dir];
			if (x_next >= 0 && x_next < N && y_next >= 0 && y_next < N) {
				if (!visited[x_next][y_next] && map[x_next][y_next] > rain) {
					visited[x_next][y_next] = true;
					q.push(make_pair(x_next, y_next));
				}
				else
					visited[x_next][y_next] = true;
			}
		}
		q.pop();
	}
}

int main()
{
	cin >> N;
	int max = 0;
	int min = MAX;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (max < map[i][j])
				max = map[i][j];
			if (min > map[i][j])
				min = map[i][j];
		}
	}

	for (int rain = 0; rain <= MAX; rain++) {
		int area = 0;
		if (min > rain)
			area = 1;
		else {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (!visited[i][j] && map[i][j] > rain) {
						BFS(i, j, rain);
						area++;
					}
					else
						visited[i][j] = true;
				}
			}
			for (int i = 0; i < N; i++) {
				memset(visited[i], false, sizeof(bool) * N);
			}
		}
		cnt.push_back(area);
	}
	int result = *max_element(cnt.begin(), cnt.end());
	cout << result;
	return 0;
}