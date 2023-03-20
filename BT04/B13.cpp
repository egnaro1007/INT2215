// https://www.hackerrank.com/challenges/sherlock-and-array/problem
#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n+1];
		for(int i = 1; i <= n; i++)
			cin >> a[i];

		int i = 1;
		while (i <= n){
			long long sum1 = 0, sum2 = 0;
			for(int j = 1; j < i; j++)
				sum1 = sum1 + a[j];
			for(int j = i+1; j < n + 1; j++)
				sum2 = sum2 + a[j];
			if(sum1 == sum2){
				cout << "YES" << endl;
				break;
			}
			i++;
		}
		if(i == n + 1) cout << "NO" << endl;
	}
}
