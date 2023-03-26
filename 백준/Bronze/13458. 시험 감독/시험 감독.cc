#include <iostream>
#define MAX 1000001
using namespace std;
int A[MAX];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int B, C;
	cin >> B >> C;

	long long manager = N;

	for (int i = 0; i < N; i++) {
		A[i] -= B;
		if (A[i] > 0) {
			manager += A[i] / C;
			if (A[i] % C != 0)
				manager += 1;
		}
	}
	cout << manager;

	return 0;
}