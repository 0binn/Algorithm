#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 301
using namespace std;

int l;
bool visited[MAX][MAX];
int dx[8] = { -1,-2,-2,-1,1,2,2,1 };//나이트 기준 왼쪽위부터 시계방향
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
int cnt[MAX][MAX];

struct point {
	int x;
	int y;
};

int BFS(point night, point dest) {

	visited[night.x][night.y] = true;
	queue <point> q;
	q.push(night);

	while (!q.empty()) {
		point start = q.front();
		if (start.x == dest.x && start.y == dest.y) {
			return cnt[start.x][start.y];
		}
		for (int d = 0; d < 8; d++) {
			point next;
			next.x = start.x + dx[d];
			next.y = start.y + dy[d];
			if (next.x >= 0 && next.x < l && next.y >= 0 && next.y < l) {
				if (!visited[next.x][next.y]) {
					q.push(next);
					visited[next.x][next.y] = true;
					cnt[next.x][next.y] = cnt[start.x][start.y] + 1;
				}
			}
		}
		q.pop();
	}
	return 0;
}

int main()
{
	int t; //테케 횟수
	cin >> t;
	vector <int> result;
	for (int tc = 0; tc < t; tc++) {
		cin >> l;
		point night;
		point dest;
		cin >> night.x >> night.y;
		cin >> dest.x >> dest.y;
		result.push_back(BFS(night, dest));
		memset(visited, false, sizeof(visited));
		memset(cnt, false, sizeof(cnt));
	}
	vector<int>::iterator iter;
	for (iter = result.begin(); iter != result.end(); iter++) {
		cout << *iter << endl;
	}
}