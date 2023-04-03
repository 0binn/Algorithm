#include <iostream>
#include <algorithm>
#define MAX 16

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int T[MAX];
	int P[MAX];

	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	int DP[MAX + 1] = { 0, };
	int money = 0;
	for (int i = 1; i <= N; i++) {
		int next_day = i + T[i];
		if (DP[i] == 0) { //최대니까 기존 상담 최대가 연결되는걸,,
			DP[i] = DP[i - 1];
		}
		else {
			DP[i] = max(DP[i],DP[i - 1]);
		}
		if (next_day <= N + 1) {
			DP[next_day] = max(DP[next_day], (DP[i] + P[i]));//원래 내꺼랑 지금 오는거 비교
			money = max(money, DP[next_day]);
		}
	}

	cout << money;
}