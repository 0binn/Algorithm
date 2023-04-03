#include <iostream>

#define MAX 91
using namespace std;

long long result[MAX];

long long fibo(int n) {

	if (n <= 1) {
		result[n] = n;
		return n;
	}

	if (result[n] != 0) {
		return result[n];
	}
	else
		result[n] = fibo(n - 1) + fibo(n - 2);
	return result[n];
}

int main()
{
	int n;
	cin >> n;
	cout << fibo(n);
}