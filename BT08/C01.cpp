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
    char pr[len];

    for (int i = 0; i < len; i++) {
        pr[i] = a[i];
    }
    for (int i = len; i < n; i++) {
        pr[i] = ' ';
    }

    for (char c : pr) std::cout << c;
}
void pad_left(char a[], int n) {
    int len = length(a);
    char pl[n];

    for (int i = 0; i < n - len; i++) {
        pl[i] = ' ';
    }
    for (int i = n - len; i < n; i++) {
        pl[i] = a[i - n + len];
    }

    for (char c : pl) std::cout << c;
}
void truncate(char a[], int n) {
    int len = length(a);
    char tr[n];

    for (int i = 0; i < n; i++) {
        tr[i] = a[i];
    }

    for (char c : tr) std::cout << c;
}
bool is_palindrome(char a[]) {
    int len = length(a);
    char rev[len];
    for (int  i = 0; i < len; i++)
    {
        rev[i] = a[len-1 - i];
    }

    for (int i = 0; i < len; i++) {
        if (a[i] != rev[i]) {
            return false;
        }
    }
    return true;
}
void trim_left(char a[]) {
    int len = length(a);
    int i = 0;
    while (a[i] == ' ') {
        i++;
    }
    char tl[len - i];
    for (int j = 0; j < len - i; j++) {
        tl[j] = a[i + j];
    }

    for (char c : tl) std::cout << c;
}
void trim_right(char a[]) {
    int len = length(a);
    int i = len - 1;
    while (a[i] == ' ') {
        i--;
    }
    char tr[i + 1];
    for (int j = 0; j < i + 1; j++) {
        tr[j] = a[j];
    }

    for (char c : tr) std::cout << c;
}