#include <iostream>
#include <queue>
#define MAX 1501

using namespace std;

int table[MAX][MAX];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> table[i][j];
			pq.push(table[i][j]);
			if (pq.size() > n) {
				pq.pop();
			}
		}
	}

	cout << pq.top();

	return 0;
}