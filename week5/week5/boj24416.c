#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int str[41] = { 0 };
    str[3] = 2;
    str[4] = 3;
    int i = 5;
    while (str[n] == 0)
    {
        str[i] = str[i - 1] + str[i - 2];
        i++;
    }
    printf("%d %d", str[n], n - 2);
}