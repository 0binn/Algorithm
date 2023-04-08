#include <iostream>
#include <vector>
#include <cstdlib>

#define MAX 51
using namespace std;


struct point {
	int x;
	int y;
};

int N, M;
int map[MAX][MAX];

bool visited[14];
vector <point> chicken;
vector <point> house;
vector <point> survive;
int length;
int min_dist = 1000000000;


void Distance() {
	//거리 측정하기

	//먼저 각 집들이랑 치킨집이랑 거리재고 최소 값들 저장
	int sum = 0;
	int house_len = house.size();

	for (int i = 0; i < house_len; i++) {

		int chai = abs(house[i].x - survive[0].x) + abs(house[i].y - survive[0].y);//첫번째 치킨집
		for (int j = 1; j < M; j++) {
			chai = min(chai, abs(house[i].x - survive[j].x) + abs(house[i].y - survive[j].y));
		}
		sum += chai;
	}

	min_dist = min(min_dist, sum);
}

//DFS로 3개 골라서 거리 계산하기
void DFS(int cnt, int curr) {
	if (cnt == M) {
		Distance();
		return;
	}

	for (int i = curr; i < length; i++) {
		if (!visited[i]) {
			visited[i] = true;
			survive.push_back(chicken[i]);
			DFS(cnt + 1, i + 1);
			visited[i] = false;
			survive.pop_back();
		}
	}
	return;
}

int main()
{
	cin >> N >> M;

	int input;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> input;
			map[r][c] = input;
			point coor = { r,c };
			if (input == 2) {
				chicken.push_back(coor); //치킨집을 벡터에 다 넣어주기
			}
			else if (input == 1) {
				house.push_back(coor);
			}

		}
	}
	length = chicken.size();
	DFS(0, 0);
	cout << min_dist;
}