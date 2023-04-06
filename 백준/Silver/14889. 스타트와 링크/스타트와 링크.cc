#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define MAX 21
using namespace std;

int N;
int stats[MAX][MAX];
int sub;
bool visited[MAX];

void Compare() {

	int start = 0;
	int link = 0;
	int vec = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j && visited[i] && visited[j]) { //스타트
				start += stats[i][j];
			}
			else if (i != j && !visited[i] && !visited[j]) { //링크
				link += stats[i][j];
			}
		}

	}
	if (sub < 0) {
		sub = abs(start - link);
	}
	else
		sub = min(sub, abs(start - link));
	return;
}

void DFS(int cnt, int next) {
	if (cnt == N / 2) {
		Compare();
		return;
	}

	for (int i = next; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			DFS(cnt + 1, i + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> N;
	sub = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> stats[i][j];
		}
	}
	DFS(0, 1);
	cout << sub;
}