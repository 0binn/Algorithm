#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
#define MAX 51
using namespace std;

int room[MAX][MAX];
bool visited[MAX][MAX];

//문제기준 북동남서 순으로
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int N, M;
int cnt;

void DFS(int x, int y, int dir)
{
	visited[x][y] = true;


	for (int i = 0; i < 4; i++) {
		int d_next = dir - i - 1;
		if (d_next < 0) {
			d_next += 4;
		}

		int x_next = x + dx[d_next];
		int y_next = y + dy[d_next];

		if (x_next >= 0 && y_next >= 0 && x_next < N && y_next < M) {
			if (room[x_next][y_next] == 0 && !visited[x_next][y_next]) {
				cnt++;
				DFS(x_next, y_next, d_next);
			}
		}
	}
	//후진하는 방향
	int backward = dir - 2;
	if (backward < 0) {
		backward += 4;
	}
	int x_back = x + dx[backward];
	int y_back = y + dy[backward];

	if (room[x_back][y_back] != 1 && x_back >= 0 && y_back >= 0 && x_back < N && y_back < M) {
		DFS(x_back, y_back, dir);
	}
	else {
		cout << cnt;
		exit(0);
	}

}

int main()
{
	cin >> N >> M;
	int x_vacc, y_vacc, dir_vacc;
	cin >> x_vacc >> y_vacc >> dir_vacc;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> room[i][j]; //만약에 여기서 1일경우에 다 visited 만들어버리면 더 효율적일까?
		}
	}
	cnt = 1;
	DFS(x_vacc, y_vacc, dir_vacc); //일단 초기 위치
	return 0;
}