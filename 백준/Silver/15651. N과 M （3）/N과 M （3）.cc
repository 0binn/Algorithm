#include <iostream>
#include <vector>
#include <cstring>
#define MAX 8
using namespace std;

vector <int> vec;
bool visited[MAX];
int N, M;

void DFS(int cnt) {
	if (cnt == M) {
		vector<int>::iterator iter;
		for (iter = vec.begin(); iter != vec.end(); iter++) {
			cout << *iter << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		vec.push_back(i);
		DFS(cnt + 1);
		vec.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	DFS(0);
	return 0;
}