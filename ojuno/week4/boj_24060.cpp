#include <iostream>
using namespace std;

const int MAX = 500000;
int tmp[MAX];
int countVal = 0;
int result = -1;

void merge(int A[], int p, int q, int r, int k) {
    int i = p, j = q + 1, t = 0;

    while (i <= q && j <= r) {
        if (A[i] <= A[j])
            tmp[t++] = A[i++];
        else
            tmp[t++] = A[j++];
    }

    while (i <= q) tmp[t++] = A[i++];
    while (j <= r) tmp[t++] = A[j++];

    for (int l = 0; l < t; l++) {
        A[p + l] = tmp[l];
        countVal++;
        if (countVal == k) {
            result = A[p + l];
        }
    }
}

void merge_sort(int A[], int p, int r, int k) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q, k);
        merge_sort(A, q + 1, r, k);
        merge(A, p, q, r, k);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    merge_sort(arr, 0, n - 1, k);

    cout << result << '\n'; 
    return 0;
}
