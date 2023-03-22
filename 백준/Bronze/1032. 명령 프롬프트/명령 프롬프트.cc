#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	char arr[50];

	for (int i = 0; i < str.length(); i++) {
		arr[i] = str[i];
	}

	for (int i = 1; i < n; i++) {
		string str2;
		cin >> str2;

		for (int j = 0; j < str.length(); j++) {
			if (str2[j] != arr[j]) {
				arr[j] = '?';
			}
		}
	}

	for (int i = 0; i < str.length(); i++) {		
		cout << arr[i];
	}
	return 0;
}