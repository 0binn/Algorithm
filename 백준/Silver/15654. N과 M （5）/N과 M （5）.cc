#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 9
using namespace std;

vector <int> vec;
bool visited[MAX];
vector <int> arr;
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
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			vec.push_back(arr[i]);
			DFS(cnt + 1);
			vec.pop_back();
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> N >> M;
	int num = 0;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	DFS(0);
	return 0;
}