#include <iostream>
#include <queue>

using namespace std;

int main() {

	int n = 0;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;

	int input = 0;
	for (int i = 0; i < n; i++) {
		cin >> input;
		pq.push(input);
	}

	int a = 0;
	int b = 0;
	int result = 0;
	for (int i = 0; i < n - 1; i++) {
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		a = a + b;
		pq.push(a);
		result += a;
	}
	cout << result;
}