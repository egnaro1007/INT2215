#include <bits/stdc++.h>
using namespace std;

int binarySearch(int* arr, int size, int x)
{
    int l = 0;
    int r = size;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (*(arr+m) == x)
			return m;

		else if (*(arr+m) < x)
			l = m + 1;

		else if (*(arr+m) > x)
			r = m - 1;
	}
	return -1;
}

int main(void)
{
	int arr[] = { 1, 2, 3, 4, 10, 40 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, n - 1, x);
	if (result == -1)
	    cout << "Not found!";
    else 
        cout << "Element at: " << result;
	return 0;
}
