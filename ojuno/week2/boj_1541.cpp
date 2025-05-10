#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int num[51];
    char op[51];

    int numi = 0;
    int opi = 0;

    string temp = "";

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '+' || c == '-') {
            num[numi++] = stoi(temp);
            op[opi++] = c;
            temp = "";
        } else {
            temp += c;
        }
    }
    if (!temp.empty()) {
        num[numi++] = stoi(temp);
    }

    int result = num[0];
    bool minus = false;
    int k = 1;

    for (int i = 0; i < opi; i++) {
        if (op[i] == '-') {
            minus = true;
        }

        if (minus) {
            result -= num[k++];
        } 
        else {
            result += num[k++];
        }
    }

    cout << result;
    return 0;
}
