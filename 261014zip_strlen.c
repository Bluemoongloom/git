#define MAXN 1005
#include<stdio.h>
#include <string.h>
int main(void)
{
    char str[MAXN];
    scanf("%s", str);
    int length = (int)strlen(str);
    int i = 0;
    while (i < length) {
        char current = str[i];
        int count = 0; /*统计当前字符连续出现的次数*/
        while (i < length && str[i] == current) {
            count++;
            i++;
        }
        if (count == 1) {
            /*只出现一次，直接输出字符*/
            printf("%c", current);
        } else {
            /*出现多次，输出次数和字符*/
            printf("%d%c", count, current);
        }
    }
    printf("\n");
    return 0;
}
