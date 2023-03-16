#include <iostream>

int count_even(int* array, int size) {
    int countEven = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(array+i) % 2 == 0) countEven++;
    }
    return countEven;
}

int main()
{
    int a[] = {0,1,2,3,4,8,6,7,8,2};

    // 10 số bắt đầu từ vị trí 0
    std::cout << count_even(a, 10) << '\n';

    // 4 số bắt đầu từ vị trí 4
    std::cout << count_even(a+4, 4) << '\n';
}