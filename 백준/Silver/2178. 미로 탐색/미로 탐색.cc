#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#define MAX 101
using namespace std;


int map[MAX][MAX];
int cnt[MAX][MAX];
bool visited[MAX][MAX];
int dir_x[4] = { -1,1,0,0 }; //열 기준 상하좌우
int dir_y[4] = { 0,0,-1,1 }; //행 기준 상화좌우

void BFS(int x,int y)
{
	queue <pair<int, int>> q;
	visited[x][y] = true;
	q.push(make_pair(x,y));
	while (!q.empty())
	{
		int x_start = q.front().first;
		int y_start = q.front().second;
		cnt[x_start][y_start] += 1;
		for (int i = 0; i < 4; i++) {
			//지금 좌표에서 다음 좌표 탐색해서 1인 경우->방문한 적 있는지
			int x_idx = x_start + dir_x[i];
			int y_idx = y_start + dir_y[i];

			if (map[x_idx][y_idx] == 1 && visited[x_idx][y_idx] == false) {
				q.push(make_pair(x_idx, y_idx));
				visited[x_idx][y_idx] = true;
				cnt[x_idx][y_idx] = cnt[x_start][y_start];
			}
		}
		q.pop();
	}
}

int main()
{
	int N;
	int M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string row;
		cin >> row;
		for (int j = 0; j < M; j++) {
			map[i][j] = row[j] - 48;
		}
	}
	BFS(0,0);
	cout << cnt[N - 1][M - 1];

	return 0;
}