#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

vector<int>graph[1001];
bool visited[1001];

void DFS(int start)
{
	visited[start] = true;
	cout << start << " ";
	for (int i = 0; i < graph[start].size(); i++)
	{
		if (visited[graph[start][i]] == false) {
			DFS(graph[start][i]);
		}
	}
}

void BFS(int start)
{
	visited[start] = true;
	queue<int>q;
	q.push(start);
	while (!q.empty()) {
		int front = q.front();
		cout << front << " ";
		for (int i = 0; i < graph[front].size(); i++)
		{
			if (visited[graph[front][i]] == false)
			{
				q.push(graph[front][i]);
				visited[graph[front][i]] = true;
			}
		}
		q.pop();
	}



	if (!q.empty()) {
		BFS(q.front());
	}
}

int main()
{
	int N;
	int M;
	int V;
	cin >> N >> M >> V;

	for (int i = 1; i <= M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}

	for (int i = 1; i <= N; i++){
		sort(graph[i].begin(), graph[i].end());
	}
	DFS(V);
	cout << "\n";
	memset(visited, false, sizeof(visited));
	BFS(V);
}