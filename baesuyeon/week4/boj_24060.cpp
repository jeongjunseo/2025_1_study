#include <iostream>
#include <vector>
using namespace std;

int N, K, countNum = 0, result = -1;
vector<int> A, tmp;

void merge(int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int t = left;

    while (i <= mid && j <= right) {
        if (A[i] <= A[j])
            tmp[t++] = A[i++];
        else
            tmp[t++] = A[j++];
    }

    while (i <= mid)
        tmp[t++] = A[i++];
    while (j <= right)
        tmp[t++] = A[j++];

    for (int k = left; k <= right; k++) {
        A[k] = tmp[k];
        countNum++;
        if (countNum == K)
            result = A[k];
    }
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main() {
    cin >> N >> K;
    A.resize(N);
    tmp.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    mergeSort(0, N - 1);

    cout << result << '\n';
    return 0;
}