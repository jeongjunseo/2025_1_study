// 모든 입력 좌표 정렬
// 중복제거 해서 0부터 단계적 쌓기.
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
    /*입력속도 줄여주는 개꿀템*/
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /***********************/

    int N;
    cin >> N; // N개 받을거임임

    vector<int> input(N); // 입력 좌표 저장 벡터.
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }

    // 정렬될 벡터.
    vector<int> sorted = input;

    // 오름차순 정렬.
    sort(sorted.begin(), sorted.end());
    // 중복 제거
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    // 출력-일반 for문은 시간초과...
    for (int i = 0; i < N; i++) {
        int answer = lower_bound(sorted.begin(), sorted.end(), input[i]) - sorted.begin();
        cout << answer << ' ';
    }
    return 0;
}