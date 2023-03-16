#include <iostream>

char* weird_string() { 
    char c[] = "123345";

    // warning: address of local variable ‘c’ returned [-Wreturn-local-addr]
    // Ta trả về con trỏ trỏ đến vùng bộ nhớ của xâu c.
    // Nhưng sau khi hàm weird_string kết thúc, vùng bộ nhớ này đã bị thu hồi.
    return c; 
}

int main()
{
    std::cout << weird_string();
}