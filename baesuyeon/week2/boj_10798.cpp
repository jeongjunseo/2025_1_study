#include <iostream>
using namespace std;

char arr[5][15]; // 5단어, 최대15자

int main() {

    for (int i = 0; i < 5; i++)
        cin >> arr[i]; // 빈칸없이한줄이므로 한번에 받자!

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[j][i] != NULL)
                cout << arr[j][i];
        }
    }

    return 0;
}