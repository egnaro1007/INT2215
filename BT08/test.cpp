#include <iostream>
using namespace std;
int main() 
{
   char* s = new char; // Bỏ 1 dấu * để s là 1 con trỏ
   char foo[] = "Hello World";

   s = foo; // *s là giá trị của biến mà con trỏ s trỏ tới, không thể gán bằng foo được 
   std::cout << "s is " << s << std::endl;

   s = foo; // s[0] là một giá trị, không thể gán bằng foo được
   std::cout << "s is " << s << std::endl;

   return 0;
}