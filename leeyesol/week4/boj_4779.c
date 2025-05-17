
#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고 방지
#pragma warning(disable: 4996)  // Visual Studio 경고 끄기

#include <stdio.h>
#include <math.h>

// 칸토어 집합을 재귀적으로 출력하는 함수
void cantor(int n)
{
	int size = pow(3, n - 1); // 공백의 개수: 전체 길이를 3등분할 때 가운데 공백 부분

	// 기본 조건: n이 0이면 '-' 하나만 출력하고 종료
	if (n == 0)
	{
		printf("-");
		return;
	}

	// 왼쪽 칸토어 부분 출력
	cantor(n - 1);

	// 가운데는 공백으로 채움
	for (int i = 0; i < size; i++)
	{
		printf(" ");
	}

	// 오른쪽 칸토어 부분 출력
	cantor(n - 1);
}

int main(void)
{
	int n;

	// 입력이 있는 동안 계속 실행
	while (scanf("%d", &n) != EOF)
	{
		cantor(n);      // 칸토어 집합 출력
		printf("\n");   // 줄 바꿈
	}

	return 0;
}

