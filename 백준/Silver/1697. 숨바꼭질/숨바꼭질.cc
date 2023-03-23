#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 100001
using namespace std;

vector<int> graph[MAX];
bool visited[MAX];
int cnt[MAX];
int result;

void BFS(int x, int y)
{
	queue <int> q;
	q.push(x);
	visited[x] = true;

	while (!q.empty()) {
		int start = q.front();
		int dir[3] = { start - 1,start + 1,2 * start };

		for (int i = 0; i < 3; i++) {
			int next = dir[i];
			if (next >= 0 && next <= 100000) {
				if (next == y) {
					result = cnt[start] + 1;
					return;
				}
				else if (!visited[next]) {
					q.push(next);
					visited[next] = true;
					cnt[next] = cnt[start] + 1;
				}
			}
		}
		q.pop();
	}

}

int main()
{
	int N, K;
	cin >> N >> K;
	if (N == K) {
		cout << 0;
	}
	else {
		BFS(N, K);
		cout << result;
	}

}