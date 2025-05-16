#include <iostream>
#include <string>
using namespace std;

void cantor(string &s, int start, int length) {
    if (length == 1)
        return;

    int third = length / 3;

    for (int i = start + third; i < start + 2 * third; i++) {
        s[i] = ' ';
    }

    cantor(s, start, third);
    cantor(s, start + 2 * third, third);
}

int main() {
    int n;
    while (cin >> n) {
        int len = 1;
        for (int i = 0; i < n; i++)
            len *= 3;

        string s(len, '-');
        cantor(s, 0, len);

        cout << s << '\n';
    }

    return 0;
}