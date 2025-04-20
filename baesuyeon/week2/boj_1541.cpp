// 입력: 55-66+77-22라면 55-(66+77)-22 = 55-(66+77+22), 처음 나온 -뒤의 것을 전부합쳐 앞에 것에 빼주면 됨
#include <iostream>
#include <string>
using namespace std;

//
int ret_sum(const string &calcul) {
    int sum = 0;
    string num = "";

    for (int i = 0; i <= calcul.size(); i++) {
        if (calcul[i] == '+' || calcul[i] == '\0') {
            sum += stoi(num); // String TO Int
            num = "";
        } else {
            num += calcul[i];
        }
    }
    return sum;
}

int min_sum(string s) {
    int result = 0;
    string part = ""; //+-나오기전 숫자 담는곳.
    bool first = true;

    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == '-' || s[i] == '\0') {
            int val = ret_sum(part); //- 나오기 전 것들이 +로 쌓여있음.
            if (first) {             // 처음-나오기 전거는 항상 +.
                result += val;
                first = false;
            } else { // 처음 아닌 -가 나올떄 빼주기.
                result -= val;
            }
            part = "";
        } else {
            part += s[i]; // 처음 - 나온 후 것들 저장해놓기.
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    cin >> input;

    cout << min_sum(input) << '\n';
    return 0;
}