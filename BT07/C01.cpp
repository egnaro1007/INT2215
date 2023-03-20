#include <bits/stdc++.h>
#include <conio.h>

unsigned int doXucSac() {
    unsigned int randomNumber = rand();
    unsigned int xucSac = (randomNumber % 20) + 1;
    return xucSac;
}
int main()
{
    srand(time(NULL));

    int diemNguoiThuNhat = 0;
    int diemNguoiThuHai = 0;

    bool running = true;
    bool player1 = true;
    while(running) {
        getch();
        system("cls");
        unsigned int xucSac = doXucSac();
        if (player1) {
            std::cout << "[ ]" << "Diem nguoi thu nhat: " << diemNguoiThuNhat << "\n";
            std::cout << "[*]" << "Diem nguoi thu hai: " << diemNguoiThuHai << "\n";
            diemNguoiThuNhat += xucSac;
            if (diemNguoiThuNhat >= 100) running = false;
            player1 = false;
        }
        else {
            std::cout << "[*]" << "Diem nguoi thu nhat: " << diemNguoiThuNhat << "\n";
            std::cout << "[ ]" << "Diem nguoi thu hai: " << diemNguoiThuHai << "\n";
            diemNguoiThuHai += xucSac;
            if (diemNguoiThuHai >= 100) running = false;
            player1 = true;
        }
        std::cout << "-------------------------------\n";
        std::cout << "Do xuc sac: " << xucSac << "\n";
    }

    system("cls");
    std::cout << "[ ]" << "Diem nguoi thu nhat: " << diemNguoiThuNhat << "\n";
    std::cout << "[ ]" << "Diem nguoi thu hai: " << diemNguoiThuHai << "\n";
    std::cout << "-------------------------------\n";
    if (diemNguoiThuNhat >= 100) std::cout << "Nguoi chien thang la nguoi thu nhat!";
    else if (diemNguoiThuHai >= 100) std::cout << "Nguoi chien thang la nguoi thu hai!";
    std::cout << "\n";
}
