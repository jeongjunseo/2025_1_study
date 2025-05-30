#include <deque>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    deque<int> d;
    int N;
    cin >> N;
    int x;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        switch (t) {
        case 1:
            cin >> x;
            d.push_front(x);
            break;
        case 2:
            cin >> x;
            d.push_back(x);
            break;
        case 3:
            if (d.empty()) {
                cout << "-1\n";
            } else {
                cout << d.front() << '\n';
                d.pop_front();
            }
            break;
        case 4:
            if (d.empty()) {
                cout << "-1\n";
            } else {
                cout << d.back() << '\n';
                d.pop_back();
            }
            break;
        case 5:
            cout << d.size() << '\n';
            break;
        case 6:
            cout << d.empty() << '\n';
            break;
        case 7:
            if (d.empty()) {
                cout << "-1\n";
            } else {
                cout << d.front() << '\n';
            }
            break;
        case 8:
            if (d.empty()) {
                cout << "-1\n";
            } else {
                cout << d.back() << '\n';
            }
            break;

        default:
            break;
        }
    }
    return 0;
}