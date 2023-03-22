#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#define MAX 101
using namespace std;

int box[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int M, N, H;
int dir_h[6] = { 1,-1,0,0,0,0 }; //위, 아래, 왼쪽, 오른쪽, 앞, 뒤
int dir_x[6] = { 0,0,0,0,-1,1 }; //위, 아래, 왼쪽, 오른쪽, 앞, 뒤
int dir_y[6] = { 0,0,-1,1,0,0 };
int cnt[MAX][MAX][MAX];
bool check;
int result;
queue <tuple<int, int, int>> q;

void BFS(int num)
{
	int x_start;
	int y_start;
	int h_start;
	int day = 0;
	while (!q.empty())
	{
		x_start = get<1>(q.front());
		y_start = get<2>(q.front());
		h_start = get<0>(q.front());

		for (int dir = 0; dir < 6; dir++) {
			int h_next = h_start + dir_h[dir];
			int x_next = x_start + dir_x[dir];
			int y_next = y_start + dir_y[dir];

			if (h_next >= 0 && h_next < H && x_next >= 0 && x_next < N && y_next >= 0 && y_next < M) {
				if (!visited[h_next][x_next][y_next] && box[h_next][x_next][y_next] == 0) {
					if (cnt[h_next][x_next][y_next] == 0 || cnt[h_next][x_next][y_next] > cnt[h_start][x_start][y_start] + 1) {
						q.push(make_tuple(h_next, x_next, y_next));
						visited[h_next][x_next][y_next] = true;
						cnt[h_next][x_next][y_next] = cnt[h_start][x_start][y_start] + 1;
					}
				}
			}
		}
		q.pop();
	}

	//사과가 다 안익을 경우
	for (int z = 0; z < H; z++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (cnt[z][x][y] == 0 && box[z][x][y] == 0 && !visited[z][x][y]) {
					check = true;
					return;
				}
				if (cnt[z][x][y] > day) {
					day = cnt[z][x][y];
				}
			}
		}
	}
	result = day;
}

int main()
{
	cin >> M >> N >> H;
	result = -1;
	int max = -1;
	int min = 1;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> box[h][i][j];
				if (max < box[h][i][j]) {
					max = box[h][i][j];
				}
				if (min > box[h][i][j]) {
					min = box[h][i][j];
				}
			}
		}
	}

	if (max == min) {
		if (max == 1) {
			result = 0;
		}
		else if (max == -1) {
			result = -1;
		}
	}
	else if (max == 0) {
		result = -1;
	}
	else {
		for (int h = 0; h < H; h++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (box[h][i][j] == 1) {
						q.push(make_tuple(h, i, j));
					}
				}
			}
		}
		BFS(0);

		if (check) {
			cout << result;
			return 0;
		}
	}
	cout << result;

	return 0;
}