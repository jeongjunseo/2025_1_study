#include <iostream>
#include <stack>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        switch (t) {
        case 1:
            int x;
            cin >> x;
            s.push(x);
            break;
        case 2:
            if (s.empty()) {
                cout << "-1\n";
            } else {
                cout << s.top() << '\n';
                s.pop();
            }
            break;
        case 3:
            cout << s.size() << '\n';
            break;
        case 4:
            cout << s.empty() << '\n';
            break;
        case 5:
            if (s.empty()) {
                cout << "-1\n";
            } else {
                cout << s.top() << '\n';
            }
            break;

        default:
            break;
        }
    }

    return 0;
}