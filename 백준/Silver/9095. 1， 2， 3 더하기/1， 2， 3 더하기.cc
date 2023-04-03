#include <iostream>
#include <vector>
#define MAX 11
using namespace std;

int cnt[MAX];

int OneTwoThree(int n) {

	if (cnt[n] != 0) {
		return cnt[n];
	}
	else
		cnt[n] = OneTwoThree(n - 1) + OneTwoThree(n - 2) + OneTwoThree(n - 3);
	return cnt[n];
}

int main()
{
	int T;
	cin >> T;
	vector <int> n;
	vector <int> result;

	int num;
	for (int i = 0; i < T; i++) {
		cin >> num;
		n.push_back(num);
	}
	cnt[0] = 0;
	cnt[1] = 1;
	cnt[2] = 2;
	cnt[3] = 4;
	for (int i = 0; i < T; i++) {
		result.push_back(OneTwoThree(n[i]));
	}

	vector<int>::iterator iter;
	for (iter = result.begin(); iter != result.end(); iter++) {
		cout << *iter << endl;
	}
}