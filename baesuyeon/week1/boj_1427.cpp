// 주어진 수를 자릿수마다 잘라 내림차순 정렬
#include <iostream>
using namespace std;

int main() {
    string a;
    cin >> a;

    // 선택정렬, 내림차순
    for (int i = 0; i < a.length(); i++) {         // 길이만큼만 반복
        int max = i;                               // 탐색범위중 최댓값index
        for (int j = i + 1; j < a.length(); j++) { // 최댓값 인덱스 찾기
            if (a[j] > a[max]) {
                max = j;
            }
        }
        // 최댓값을 앞으로 스왑
        int temp = a[i];
        a[i] = a[max];
        a[max] = temp;
    }

    cout << a << endl;

    return 0;
}