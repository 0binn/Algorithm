#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <cstdio>

#define MAX 51
using namespace std;

int popul[MAX][MAX];
int N, L, R;
int dx[4] = { -1,1,0,0 }; //상하좌우
int dy[4] = { 0,0,-1,1 };
bool visited[MAX][MAX];
//bool check[MAX][MAX];
bool finish;//처음부터 안나눠도 되는 경우

void BFS(int r, int c)
{
	visited[r][c] = true;
	//check[r][c] = true;
	queue <pair<int, int> > q;
	vector <pair<int, int> > uni;
	q.push(make_pair(r, c));
	int sum_popul = popul[r][c];
	int sum_uni = 1;
	uni.push_back(make_pair(r, c));

	while (!q.empty())
	{
		int x_start = q.front().first;
		int y_start = q.front().second;
		for (int d = 0; d < 4; d++) {
			int x_next = x_start + dx[d];
			int y_next = y_start + dy[d];
			int chai; //두 나라의 인구 차이
			if (x_next >= 0 && x_next < N && y_next >= 0 && y_next < N) {
				if (!visited[x_next][y_next]) { //인접 국가
					chai = abs(popul[x_start][y_start] - popul[x_next][y_next]);
					if (chai >= L && chai <= R) {
						q.push(make_pair(x_next, y_next));
						uni.push_back(make_pair(x_next, y_next));
						visited[x_next][y_next] = true;
						//check[x_next][y_next] = true;
						sum_uni++;
						sum_popul += popul[x_next][y_next];
						finish = true;
					}
				}
			}
		}
		q.pop();
	}

	//uni안에 들어있는  애들끼리 인구 계산해주기
	int new_popul = sum_popul / sum_uni;

	for (int i = 0; i < uni.size(); i++) {
		popul[uni[i].first][uni[i].second] = new_popul;
	}
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		if (check[i][j])
	//		{
	//			popul[i][j] = new_popul;
	//		}
	//	}
	//}
	//memset(check, false, sizeof(check));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> popul[r][c];
		}
	}
	int day = 0;
	while (true) { 
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (!visited[r][c]) {
					BFS(r, c);
				}				
			}
		}
		if (!finish) {
			break;
		}
		else
			day++;
		memset(visited, false, sizeof(visited));
		finish = false;
	}
	cout << day;
	return 0;
}