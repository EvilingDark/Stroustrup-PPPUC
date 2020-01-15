#include <std_lib_facilities.h>

using namespace std;

bool is_palindrome(const char* s, int n)
{
    int first = 0;
    int last = n - 1;
    while (first, last) {
        if (s[first] != s[last])
            return false;
        ++first;
        --last;
    }
    return true;
}

istream& read_word(istream& is, char*& buffer, int max)
{
    is.width(max);
    is >> buffer;
    char ch;
    /*if (is.get(ch) && ch != '\n') {
        cout << "\nString is too long\n";
        cout << "\n\'" << ch << "\'\n";
    }*/
    while (is.get(ch) && ch != '\n') {
        max += 1;
        char* st = new char[max + 1];
        for (int i = 0; i < max - 2; ++i)
            st[i] = buffer[i];
        st[max - 2] = ch;
        st[max - 1] = 0;
        delete[] buffer;
        buffer = st;
    }
    return is;
}

int main()
{
    constexpr int max = 16;
    char* s = new char[max];
    read_word(cin, s, max);
    cout << s << " is";
    if (!is_palindrome(s, strlen(s)))
        cout << " not";
    cout << " a polindrome" << endl;
    return 0;
}
