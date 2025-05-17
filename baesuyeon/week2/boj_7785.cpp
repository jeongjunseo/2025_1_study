// 비슷한 추가문제 풀이해봄-회사에 남은 사람 이름을 사전 역순으로 출력.
// enter / leave
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    set<string> in_office;

    for (int i = 0; i < n; i++) {
        string name, mode; // 이름과 출근과퇴근.
        cin >> name >> mode;

        if (mode == "enter") {
            in_office.insert(name);
        } else {
            in_office.erase(name);
        }
    }

    vector<string> final_list(in_office.begin(), in_office.end()); // 벡터의 역순정렬을 위해 set->vector.
    sort(final_list.rbegin(), final_list.rend());                  // 역순 정렬

    for (const string &name : final_list) {
        cout << name << '\n';
    }

    return 0;
}