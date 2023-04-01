#include <iostream>

class String {
private:
    unsigned int length;
    char *str;
public:
    String (const char *p_str);
    ~String();
    
    void print();
    void append(const char *p_str);
};

int main() {
    String s("Hello");
    s.print();
    s.append(" world");
    s.print();
    return 0;
}

// Constructor
String::String (const char *p_str) {
    // Độ dài của xâu
    length = 0;
    while (p_str[length] != '\0') {
        length++;
    }
    // Cấp phát bộ nhớ cho xâu
    str = new char[length + 1];
    // Copy xâu vào bộ nhớ vừa cấp phát
    for (int i = 0; i < length; i++) {
        str[i] = p_str[i];
    }
    str[length] = '\0'; // Kí tự kết thúc xâu
}

// Destructor
String::~String() {
    delete[] str;
}

void String::print() {
    std::cout << str << "\n";
}

void String::append(const char *p_str) {
    // Độ dài của xâu cần nối
    unsigned int appendLength = 0;
    while (p_str[appendLength] != '\0') {
        appendLength++;
    }
    // Cấp phát bộ nhớ mới cho xâu
    char *newString = new char[length + appendLength + 1];
    // Copy xâu cũ vào bộ nhớ mới
    for (int i = 0; i < length; i++) {
        newString[i] = str[i];
    }
    // Copy xâu cần nối vào bộ nhớ mới
    for (int i = 0; i < appendLength; i++) {
        newString[length + i] = p_str[i];
    }
    newString[length + appendLength] = '\0'; // Kí tự kết thúc xâu
    // Giải phóng bộ nhớ cũ
    delete[] str;
    // Cập nhật lại xâu
    str = newString;
    length += appendLength;
}