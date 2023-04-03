#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> score;
int DP[301];

//각 칸의 MAX를 구하는게 포인트
void climb(int n) {
	DP[0] = 0;
	DP[1] = score[1];
	DP[2] = score[2] + score[1]; //얘는 무조건 이게 맥스일 수밖에
	DP[3] = max((score[3] + score[2]), (score[3] + score[1]));

	for (int i = 4; i <= n; i++) {
		DP[i] = max(score[i] + DP[i - 2], score[i] + score[i - 1] + DP[i - 3]);//전꺼+내꺼 or 전전꺼+내꺼
	}
}

int main()
{
	int stair;
	cin >> stair;

	int input;
	score.push_back(0);
	for (int i = 0; i < stair; i++) {
		cin >> input;
		score.push_back(input);
	}
	if (stair <= 2) {
		for (int i = 1; i <= stair; i++) {
			DP[i] = score[i] + score[i - 1];
		}
	}
	else
		climb(stair);
	cout << DP[stair];
}