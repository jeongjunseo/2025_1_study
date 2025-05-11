#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int sum = a + b;
        a = b;
        b = sum;
    }

    cout << b << '\n';
    return 0;
}