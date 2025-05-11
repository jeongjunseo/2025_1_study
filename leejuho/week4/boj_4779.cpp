#include <iostream>
#include <string>
using namespace std;

void cantor(int start, int len, string &s) {
    if (len == 1) return; 
    int third = len / 3;

    
    for (int i = start + third; i < start + 2 * third; i++) {
        s[i] = ' ';
    }

    
    cantor(start, third, s);
    cantor(start + 2 * third, third, s);
}

int main() {
    int N;
    while (cin >> N) {
        int len = 1;
        for (int i = 0; i < N; i++) len *= 3;

        string s(len, '-');
        cantor(0, len, s);
        cout << s << '\n';
    }
    return 0;
}
