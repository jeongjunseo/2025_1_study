#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void cantor(string &line, int start, int length) {
    if (length == 1) return;

    int third = length / 3;

    for (int i = start + third; i < start + 2 * third; i++) {
        line[i] = ' ';
    }

    cantor(line, start, third);
    cantor(line, start + 2 * third, third);
}

int main() {
    int n;
    while (cin >> n) {
        int size = pow(3, n);
        string line(size, '-');

        cantor(line, 0, size);
        cout << line << '\n';
    }
    return 0;
}
