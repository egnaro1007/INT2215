#include <iostream>

int f (int* arr) {
    int size = sizeof(arr);
    return size;
}

int main() {
    int a[] = {0,1,2,3,4,5,6,7,8};

    std::cout << sizeof(a) << "\n";
    // Lệnh sizeof này trả ra giá trị là 36 = 4*9. 
    // Trong mảng có 9 biển kiểu int, mỗi biến 4 byte


    std::cout << f(a) << "\n";
    // Lệnh sizeof này trả ra giá trị là 8. 
    // Chính là kích thước của con trỏ trỏ đến phần tử đầu tiên của mảng a.
    // Kích thước đó là 8 byte cho máy 64 bit và 4 bit cho máy 32 bit.
}