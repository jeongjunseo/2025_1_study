// n명중, 상위k번쨰의 점수
#include <iostream>
using namespace std;

int main() {
    int N, k;
    int arr[1001] = {0}; // 1000명이하의 입력 점수
    int temp;            // 스왑에서 사용할 입시 저장소

    cin >> N >> k; // 학생수와 뽑는 수 입력
    for (int i = 0; i < N; i++) {
        cin >> arr[i]; // arr[0]부터 차례대로 저장
    }

    // 선택정렬, 내림차순
    for (int i = 0; i < k; i++) {         // k번만 반복
        int max = i;                      // 탐색범위중 최댓값index
        for (int j = i + 1; j < N; j++) { // 최댓값 인덱스 찾기
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        // 최댓값을 앞으로 스왑
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }

    cout << arr[k - 1] << endl;
    return 0;
}