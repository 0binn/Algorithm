#include <iostream>
#include <vector>
#include <cstring>
#define MAX 9
using namespace std;

vector <int> vec;
bool visited[MAX];
int N, M;

void DFS(int cnt, int curr) {
	if (cnt == M) {
		vector<int>::iterator iter;
		for (iter = vec.begin(); iter != vec.end(); iter++) {
			cout << *iter << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = curr; i <= N; i++) {
		vec.push_back(i);
		DFS(cnt + 1, i);
		vec.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	DFS(0, 1);
	return 0;
}