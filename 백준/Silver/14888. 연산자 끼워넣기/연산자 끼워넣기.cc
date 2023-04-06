#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 12
using namespace std;

int N;
int seq[MAX];
int oper[4];
int min_result = 1000000000;
int max_result = -1000000000;
vector<int> oper_list; //+ = 0 , - = 1, x = 2. ÷ = 4
bool visited[MAX];
vector<int> oper_order;

int num = 0;

void Calculation() {
	//배열과 연산자로 계산
	int result = seq[0];
	for (int i = 1; i < N; i++) {
		if (oper_order[i - 1] == 0) { //+
			result += seq[i];
		}
		else if (oper_order[i - 1] == 1) { //-
			result -= seq[i];
		}
		else if (oper_order[i - 1] == 2) { //x
			result *= seq[i];
		}
		else if (oper_order[i - 1] == 3) { //÷
			result /= seq[i];
		}
	}
	min_result = min(min_result, result);
	max_result = max(max_result, result);

	return;
}

void DFS(int cnt) {
	if (cnt == N - 1) {
		Calculation();
		return;
	}

	for (int i = 0; i < N - 1; i++) {
		if (!visited[i]) {
			visited[i] = true;
			oper_order.push_back(oper_list[i]);
			DFS(cnt + 1);
			oper_order.pop_back();
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> seq[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];;
		for (int j = 1; j <= oper[i]; j++) {
			oper_list.push_back(i);
		}
	}
	DFS(0);
	cout << max_result << "\n" << min_result;
}