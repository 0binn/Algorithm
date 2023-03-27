#include <iostream>
#include <vector>
using namespace std;

int fibo[41];

int fibonacci(int n) {
    if (n == 0) {
        fibo[0] = 0;
        return 0;
    }
    else if (n == 1) {
        fibo[1] = 1;
        return 1;
    }
    if (fibo[n] != 0) {
        return fibo[n];
    }

    fibo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return fibo[n];
    
}

int main()
{
	int T;
    cin >> T;
	vector <int> N;

	int num;
    for (int i = 0; i < T; i++) {
        cin >> num;
        N.push_back(num);
    }

    for (int i = 0; i < T; i++) {
        if (N[i] == 0) {
            cout << "1 0" << endl;
        }
        else
        {
            fibonacci(N[i]);
            cout << fibo[N[i] - 1] << " " << fibo[N[i]] << endl;
        }
    }
}