#include <iostream>

void reverse(char a[]);
void delete_char(char a[], char c);
void pad_right(char a[], int n);
void pad_left(char a[], int n);
void truncate(char a[], int n);
bool is_palindrome(char a[]);
void trim_left(char a[]);
void trim_right(char a[]);

unsigned int length(char a[]) {
    unsigned int len = 0;
    while (a[len] != '\0') {
        len ++;
    }
    return len;
}

int main()
{
    char str[] = "Day la mot cai xau";
    //reverse(str);
    delete_char(str, 'a');
}


void reverse(char a[]) {
    int len = length(a);
    char rev[len];
    for (int  i = 0; i < len; i++)
    {
        rev[i] = a[len-1 - i];
    }
    for (char c : rev) std::cout << c;
}
void delete_char(char a[], char c) {
    int len = length(a);
    char afterDelete[len];
    
    int j = -1;
    for (int i = 0; i < len; i++) {
        if (a[i] != c) {
            j++;
            afterDelete[j] = a[i];
        }
    }

    for (char c : afterDelete) std::cout << c;
}
void pad_right(char a[], int n) {
    int len = length(a);
    char rev[len];

    for (char c : rev) std::cout << c;
}
void pad_left(char a[], int n) {}
void truncate(char a[], int n) {}
bool is_palindrome(char a[]) {return false;}
void trim_left(char a[]) {}
void trim_right(char a[]) {}