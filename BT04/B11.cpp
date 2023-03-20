// http://www.hackerearth.com/problem/algorithm/password-1/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int main() {
	int n;
	std::vector<std::string> passwordList;

	std::cin >> n;
	for (int i = 0; i < n; i++){
		std::string password;
		std::cin >> password;
		passwordList.push_back(password);
	}

	for(int j = 0; j < n; j++){
		int x = passwordList[j].size();
		std::reverse(passwordList[j].begin(), passwordList[j].end());
		for(int k = 0; k < n; k++)
			if(passwordList[k] == passwordList[j])
				if(j != k){
					cout << passwordList[k].size() << " " << passwordList[k][x/2];
					break;
				}
	}
}
