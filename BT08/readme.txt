A01
    2 biến x, y này có cùng địa chỉ
    Sau khi chạy xong hàm f thì vùng bộ nhớ của hàm f đã được giải phóng. 
    Do đó khi chạy đến hàm g thì trương trình sẽ cấp phát đúng vùng bộ nhớ đã cấp cho hàm f trước đây
A02
    a. Chương trình in ra lần lượt các địa chỉ và giá trị của a[0], a[1], a[2], a[3]
    b. Ta thay đổi kiểu biển của a và cp từ char thành cp.
        Ngoài ra, để an toàn ta có thể thay đổi một chút ở điều kiện kết thúc của vòng for. Sử dụng std::end() hoặc sizeof()
            int main( )
            { 
            int a[4] = {1,2,3,4}; 
            for (int* cp = a; cp != &a[sizeof(a) / sizeof(a[0])]; cp++) {
                std::cout << (void*) cp << " : " << (*cp) << std::endl;
            } 
            return 0;
            }
    c. Tương tự b nhưng thay bằng double
    d. Thay cp++ bằng cp+=2 thì chỉ có 1 điều chắc chắn là trương trình sẽ in ra 2 phần tử là a[1] và a[3]
        Còn vòng lặp có dừng được không thì do may rủi. Chương trình sẽ tiếp tục in ra các giá trị không xác định cho đến khi gặp '\0' (NULL).
A03
    Để swap 2 con trỏ, ta cần phải truyền vào hàm swap còn trỏ trỏ đến con trỏ đó. Cụ thể:
        void swap_pointers(char* &x, char* &y);