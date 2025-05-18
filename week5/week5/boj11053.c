#include <stdio.h>
int arr[1001];
int dp[1001];
int main() {
	int n, max = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		dp[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
			}
		}
		if (max < dp[i]) 
			max = dp[i];
	}
	printf("%d\n", max);
}
