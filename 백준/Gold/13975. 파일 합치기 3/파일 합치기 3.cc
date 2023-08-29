#include <iostream>
#include <queue>

using namespace std;

int main() {

	int t = 0;
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		int k = 0;
		cin >> k;
		priority_queue<long long, vector<long long>, greater<long long>> pq;

		for (int j = 0; j < k; j++) {
			int input = 0;
			cin >> input;
			pq.push(input);
		}

		long long x = 0;
		long long y = 0;
		long long result = 0;
		for (int j = 0; j < k - 1; j++) {
			x = pq.top();
			pq.pop();
			y = pq.top();
			pq.pop();

			x += y;
			pq.push(x);
			result += x;
		}
		cout << result << "\n";
		
	}
}