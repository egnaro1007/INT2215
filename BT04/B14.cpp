// https://www.hackerrank.com/contests/101hack31/challenges/naughty-number
#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int a[n+1];
	int b[n+2];
	int dem[1000] = {0};
	for(int i = 0; i < n; i++){
		std::cin >> a[i];
		dem[a[i]]++;
	}
	for(int i = 0; i < n+1; i++)
		std::cin >> b[i];


	for(int i = 0; i < n+1; i++)
		if(dem[b[i]] == 0){
			std::cout << b[i];
			break;
		}
}
