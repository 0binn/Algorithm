#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001];

int make_one(int x)
{
	if (x == 1) {
		arr[x] = 0;
		return 0;
	}
	if (arr[x] > 0) {
		return arr[x];
	}
	int result = make_one(x - 1) + 1; //3과 2로 안나눠지는 것들
	if (x % 3 == 0) {
		result = min(result, make_one(x / 3) + 1);
	}
	if (x % 2 == 0) {
		result = min(result, make_one(x / 2) + 1);
	}
	arr[x] = result;

	return result;
}

int main() {
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	cout << make_one(N);
}