// 못들어본->type1,못본->type2, 둘다->result type
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    set<string> type1;
    vector<string> result_types;

    for (int i = 0; i < N; i++) { // type1받기.
        string name;
        cin >> name;
        type1.insert(name);
    }

    for (int i = 0; i < M; i++) { // type2받기.
        string name;
        cin >> name;
        if (type1.count(name)) {          // 동일이 있으면 1, 없으면 0.
            result_types.push_back(name); // 있는거면 결과에 푸시.
        }
    }

    sort(result_types.begin(), result_types.end()); // 결과들 정렬

    cout << result_types.size() << '\n';
    for (const string &name : result_types) {
        cout << name << '\n';
    }

    return 0;
}