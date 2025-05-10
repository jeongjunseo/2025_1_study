#include <iostream>
#include <string>
using namespace std;

int main() {
    string arr[5];
    int max_len = 0;

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        if (arr[i].length() > max_len)
            max_len = arr[i].length();
    }

    for (int i = 0; i < max_len; i++) {
        for (int j = 0; j < 5; j++) {
            if (i < arr[j].length())
                cout << arr[j][i];
        }
    }

    return 0;
}
