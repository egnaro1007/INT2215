#include <iostream>

class Point {
public:
    int x;
    int y;
    Point(int p_x, int p_y) {
        x = p_x;
        y = p_y;
    }
};

void printPassByValue(Point p);
void printPassByReference(Point &p);
Point mid_point (const Point p1, const Point p2);
void printAddress(const Point &p);


int main() {
    Point p(1, 2);

    std::cout << "Address of p: \n";
    std::cout << &p << "\n";
    std::cout << "Pass by value: \n";
    printPassByValue(p);
    std::cout << "Pass by reference: \n";
    printPassByReference(p);

    printAddress(p); 
    // Ở đây t nhận thấy là địa chỉ của p chính là địa chỉ của biến đầu tiên ở trong p, ở đây tức là p1, các biến còn lại đuọc cấp phát bộ nhớ lần lượt
    return 0;
}


void printPassByValue(Point p) {
    std::cout << p.x << " " << p.y << "\n";
    std::cout << &p << "\n";
}

void printPassByReference(Point &p) {
    std::cout << p.x << " " << p.y << "\n";
    std::cout << &p << "\n";
}


Point mid_point (const Point p1, const Point p2) {
    int x = (p1.x + p2.x) / 2;
    int y = (p1.y + p2.y) / 2;
    return Point(x, y);
}


void printAddress(const Point &p) {
    std::cout << "Address of p:" << &p << "\n";
    std::cout << "Address of p.x:" << &p.x << "\n";
    std::cout << "Address of p.y:" << &p.y << "\n";
}


