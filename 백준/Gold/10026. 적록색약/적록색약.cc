#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 100
using namespace std;

char area[MAX][MAX];
bool visited[MAX][MAX];
int N;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void BFS(int x, int y, bool abnormal) {
	visited[x][y] = true;
	char color = area[x][y];
	bool RG = false;
	if (abnormal) {
		if (color == 'R' || color == 'G')
			RG = true;
	}
	queue <pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int x_start = q.front().first;
		int y_start = q.front().second;
		for (int d = 0; d < 4; d++) {
			int x_next = x_start + dx[d];
			int y_next = y_start + dy[d];

			if (x_next >= 0 && x_next < N && y_next >= 0 && y_next < N && !visited[x_next][y_next]) {
				if (abnormal) {
					if (RG) {
						if (area[x_next][y_next] == 'R' || area[x_next][y_next] == 'G'){
							q.push(make_pair(x_next, y_next));
							visited[x_next][y_next] = true;
						}
					}
					else if (color == area[x_next][y_next]) {
						q.push(make_pair(x_next, y_next));
						visited[x_next][y_next] = true;
					}
				}
				else if (color == area[x_next][y_next]) {
					q.push(make_pair(x_next, y_next));
					visited[x_next][y_next] = true;
				}
			}
		}
		q.pop();
	}
}

int main() {
	cin >> N;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			area[i][j] = str[j];
		}
	}
	int normal = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				BFS(i, j, false);
				normal++;
			}
		}
	}
	memset(visited, false, sizeof(visited));
	int ab = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				BFS(i, j, true);
				ab++;
			}
		}
	}
	cout << normal << " " << ab;
	return 0;
}