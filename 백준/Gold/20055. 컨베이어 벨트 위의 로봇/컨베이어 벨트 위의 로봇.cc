#include <iostream>
#include <vector>
#define MAX 201

using namespace std;

int N, K;
int A[MAX]; //1부터 2N까지
int day = 1;
bool robot[201];


int main()
{
	cin >> N >> K;
	int end = 2 * N;
	for (int i = 0; i < end; i++) {
		cin >> A[i];
	}

	//로봇이 다음칸으로 이동하면 현재꺼 A[i]-1 됨
	//로봇은 N까지만

	while (true)
	{

		//회전
		int temp[MAX];
		bool temp_robot[MAX] = { false, };


		for (int i = 0; i < end - 1; i++) {
			temp[i + 1] = A[i];
			if (i <= N - 1) {
				temp_robot[i + 1] = robot[i];
			}
		}
		temp[0] = A[end - 1];

		//로봇+벨트 움직이기
		for (int i = 0; i < end; i++) {
			A[i] = temp[i];
			if (i <= N - 1) {
				robot[i] = temp_robot[i];
			}
		}

		if (robot[N - 1]) { //맨끝에 로봇 내려주기
			robot[N - 1] = false;
		}

		for (int i = N - 2; i >= 0; i--) {
			if (robot[i + 1] == false && robot[i] && A[i + 1] > 0) { //다음에 로봇이 없고, 내구도가 0 이상이면
				robot[i] = false;
				robot[i + 1] = true;
				A[i + 1]--;
			}
		}

		if (robot[N - 1]) { //맨끝에 로봇 내려주기
			robot[N - 1] = false;
		}

		if (robot[0] == false && A[0] > 0) { //로봇 올리기
			robot[0] = true;
			A[0]--;
		}

		//여기서 내구도가 0이되면 break
		int cnt = 0;
		for (int i = 0; i < end; i++) {
			if (A[i] == 0) {
				cnt++;
			}
		}
		if (cnt >= K)
			break;

		day++;
	}
	cout << day;
	return 0;
}