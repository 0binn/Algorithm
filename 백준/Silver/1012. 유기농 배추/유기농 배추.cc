#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 51

using namespace std;

struct point {
	int x;
	int y;
};

int map[MAX][MAX];
vector<point> cabbage;
bool visited[MAX][MAX];
int n, m;


point dir[4] = { {-1,0},{1,0},{0,-1},{0,1} }; //상하좌우

void BFS(point first) {

	queue<point> q;
	visited[first.x][first.y] = true;
	q.push(first);

	while (!q.empty()) {

		point curr = q.front();

		for (int d = 0; d < 4; d++) {
			
			int nx = curr.x + dir[d].x;
			int ny = curr.y + dir[d].y;

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (!visited[nx][ny] && map[nx][ny]) {
					q.push({ nx,ny });
					visited[nx][ny] = true;
				}
			}
		}
		q.pop();

	}

}

int main() {
	int t, k;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> m >> n >> k;

		for (int j = 0; j < k; j++) {
			int a, b;
			cin >> a >> b;
			point point = { b,a }; //입력 받는게 반대임
			cabbage.push_back(point);
			map[b][a] = 1;
		}

		int result = 0;

		for (int j = 0; j < k; j++) {

			if (!visited[cabbage[j].x][cabbage[j].y]) {
				BFS(cabbage[j]);
				result++;
			}
		}

		cout << result << "\n";
		memset(visited, false, sizeof(visited));
		memset(map, 0, sizeof(map));
		cabbage.clear();
	}

	return 0;
}