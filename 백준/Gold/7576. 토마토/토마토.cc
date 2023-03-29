#include <iostream>
#include <queue>
#include <vector>
#define MAX 1000
using namespace std;

int box[MAX][MAX];
bool visited[MAX][MAX];
int cnt[MAX][MAX];
int dx[4] = { -1,1,0,0, }; //위아래왼오
int dy[4] = { 0,0,-1,1 };
int M, N;

int BFS(queue <pair<int, int>> q) {


	while (!q.empty()) {
		int x_start = q.front().first;
		int y_start = q.front().second;
		visited[x_start][y_start] = true;
		for (int d = 0; d < 4; d++) {
			int x_next = x_start + dx[d];
			int y_next = y_start + dy[d];
			if (x_next >= 0 && x_next < N && y_next >= 0 && y_next < M) {
				if (box[x_next][y_next] == 0) {
					if (!visited[x_next][y_next] || cnt[x_next][y_next] > cnt[x_start][y_start] + 1) {//방문여부 or 카운트가 더 작으면 진입
						visited[x_next][y_next] = true;
						q.push(make_pair(x_next, y_next));
						cnt[x_next][y_next] = cnt[x_start][y_start] + 1;
					}
				}
			}
		}
		q.pop();
	}
	int max = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && box[i][j] == 0) {
				return -1;
			}

			if (max < cnt[i][j]) {
				max = cnt[i][j];
			}
		}
	}

	return max;
}

int main()
{
	cin >> M >> N;
	int max = -1;
	int min = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (max < box[i][j]) {
				max = box[i][j];
			}
			if (min > box[i][j]) {
				min = box[i][j];
			}
		}
	}
	if (max != 1) {
		cout << -1;
		return 0;
	}
	else if (max == 1 && min == 1) {
		cout << 0;
		return 0;
	}
	queue <pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}
	int result = BFS(q);

	cout << result;

	return 0;
}