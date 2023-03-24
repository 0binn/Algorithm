#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cstring>
#define MAX 100
using namespace std;

struct point {
	int x;
	int y;
};

bool visited[MAX];
point fest;
bool happy;

void BFS(vector <point> stores, point home, int n) {
	queue <point> q;
	q.push(home);
	happy = false;
	while (!q.empty()) {
		int x_now = q.front().x;
		int y_now = q.front().y;

		//페스티벌까지의 거리가 1000이하
		if ((abs(fest.x - x_now) + abs(fest.y - y_now)) <= 1000) {
			happy = true;
			return;
		}
		for (int s = 0; s < n; s++) {
			if (!visited[s] && (abs(stores[s].x - x_now) + abs(stores[s].y - y_now)) <= 1000) {
				q.push(stores[s]);
				visited[s] = true;
			}
		}
		q.pop();
	}
	return;
}

int main()
{
	int t;
	cin >> t;
	vector<string>result;
	for (int tc = 0; tc < t; tc++) {
		int n;
		cin >> n; //편의점 개수
		point home;
		cin >> home.x >> home.y; //상근이 집 좌표

		vector <point> stores;
		point store;
		for (int i = 0; i < n; i++) {
			cin >> store.x >> store.y;
			stores.push_back(store); //편의점 좌표
		}
		cin >> fest.x >> fest.y; //페스티벌 좌표

		int dist = abs(fest.x - home.x) + abs(fest.y - home.y);

		//페스티벌까지 거리가 1000이하면 happy
		if (dist <= 1000) {
			result.push_back("happy");
		}
		else if (dist > 1000 && n == 0) { //길이가 1000넘는데 편의점 없는 경우
			result.push_back("sad");
		}
		else {
			BFS(stores, home, n);
			if (happy)
				result.push_back("happy");
			else
				result.push_back("sad");
		}
		memset(visited, false, sizeof(bool) * n);
	}
	vector<string>::iterator iter;
	for (iter = result.begin(); iter != result.end(); iter++)
		cout << *iter << endl;
	return 0;
}