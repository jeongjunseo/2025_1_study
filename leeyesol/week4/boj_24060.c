#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고 방지용
#pragma warning(disable: 4996)  // Visual Studio에서 경고 끄기

#include <stdio.h>

int N, K; // N: 배열의 크기, K: 저장 횟수 중 찾고 싶은 번호
int A[500001]; // 입력 배열
int tmp[500001]; // 병합 시 사용할 임시 배열

int count = 0; // 병합 과정에서 저장된 총 횟수
int result = -1; // K번째 저장된 값을 저장할 변수, 초기값은 -1

// 배열 A[p..r]을 병합하는 함수
void merge(int* A, int p, int q, int r)
{
	int i = p;        // 왼쪽 부분 배열의 시작 인덱스
	int j = q + 1;    // 오른쪽 부분 배열의 시작 인덱스
	int t = 1;        // tmp 배열의 인덱스 (1부터 시작)

	// 두 부분 배열을 비교하여 작은 값을 tmp에 저장
	while (i <= q && j <= r)
	{
		if (A[i] <= A[j])
			tmp[t++] = A[i++];
		else
			tmp[t++] = A[j++];
	}

	// 왼쪽에 남은 요소 저장
	while (i <= q)
		tmp[t++] = A[i++];

	// 오른쪽에 남은 요소 저장
	while (j <= r)
		tmp[t++] = A[j++];

	// tmp 배열의 내용을 다시 A[p..r]에 복사하면서 저장 횟수 증가
	i = p;
	t = 1;
	while (i <= r)
	{
		A[i++] = tmp[t++];
		count++; // 저장할 때마다 count 증가

		// 저장 횟수가 K번째일 때 해당 값을 result에 저장
		if (count == K)
		{
			result = A[i - 1]; // 현재 저장한 값이 K번째
			break; // 더 이상 진행할 필요 없음
		}
	}
}

// 병합 정렬 함수 (분할 정복)
void merge_sort(int* A, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;         // 중간 지점 계산
		merge_sort(A, p, q);         // 왼쪽 절반 정렬
		merge_sort(A, q + 1, r);     // 오른쪽 절반 정렬
		merge(A, p, q, r);           // 병합
	}
}

int main(void)
{
	scanf("%d %d", &N, &K); // 배열 크기 N, 찾을 저장 순서 K 입력

	// 배열 A에 입력 값 저장
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	// 병합 정렬 수행
	merge_sort(A, 0, N - 1);

	// 결과 출력 (K번째 저장된 값 또는 -1)
	printf("%d", result);
	return 0;
}
