#include <stdio.h>
#define MAXN 5000
int small[MAXN];    //小于x的队伍
int large[MAXN];    //大于等于x的队伍
int result[MAXN * 2]; //保存乘法结果
int smallLen = 0;
int largeLen = 0;

int main(void)
{
    int n, x;
    scanf("%d", &n);
    scanf("%d", &x);
    //按照x分成两个队伍
    for (int i = 0; i < n; i++) {
        int digit;
        scanf("%d", &digit);
        if (digit < x) {
            small[smallLen++] = digit;
        } else {
            large[largeLen++] = digit;
        }
    }

    //模拟竖式乘法
    for (int i = 0; i < smallLen; i++) {
        //从右到左逐位相乘，并将结果累加到result数组中
        int digit1 = small[smallLen - 1 - i];
        int carry = 0;
        for (int j = 0; j < largeLen || carry > 0; j++) {
            int digit2 = 0;
            if (j < largeLen) {
                digit2 = large[largeLen - 1 - j];
            }
            int value = result[i + j] + digit1 * digit2 + carry;
            result[i + j] = value % 10;
            carry = value / 10;
        }
    }

    //找到结果的最高位
    int highest = smallLen + largeLen;
    while (highest > 0 && result[highest] == 0) {
        highest--;
    }
    //从最高位到最低位输出
    for (int i = highest; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
    return 0;
}
