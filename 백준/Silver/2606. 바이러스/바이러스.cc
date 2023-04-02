#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

vector <int> graph[MAX];
bool visited[MAX];
int cnt;

void DFS(int start)
{
	visited[start] = true;

	for (int i = 0; i < graph[start].size(); i++) {
		if (visited[graph[start][i]] == false) {
			DFS(graph[start][i]);
			cnt++;
		}
	}
}

int main()
{
	int n;
	int v;
	cin >> n;
	cin >> v;

	for (int i = 1; i <= v; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	DFS(1);
	cout << cnt;
}