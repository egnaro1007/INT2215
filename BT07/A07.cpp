#include <iostream>
#include <cstring>

int countOccurrences(std::string needle, std::string haystack) {
    int count = 0;
    int needle_len = needle.length();
    int haystack_len = haystack.length();

    for (int i = 0; i <= haystack_len - needle_len; i++) {
        std::string sub = haystack.substr(i, needle_len);
        if (needle.compare(sub) == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    std::string needle = "abc";
    std::string haystack = "abcabcabc";
    int count = countOccurrences(needle, haystack);
    std::cout << count;

    return 0;
}
