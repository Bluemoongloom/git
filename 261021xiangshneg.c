#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 105
bool dp[MAXN][MAXN][2];
bool check(const char *s, const char *t, const char *r)
{
    int ls = strlen(s);
    int lt = strlen(t);
    int lr = strlen(r);
    if (ls + lt != lr) return false;
    memset(dp, 0, sizeof(dp));
    for (int k = 1; k <= ls; k++)
    {
        if (strncmp(s, r, k) == 0)
        {
            dp[k][0][1] = true; 
        }
    }
    for (int k = 1; k <= lt; k++)
    {
        if (strncmp(t, r, k) == 0)
        {
            dp[0][k][0] = true; 
        }
    }

    for (int i = 0; i <= ls; i++)
    {
        for (int j = 0; j <= lt; j++)
        {
            if (dp[i][j][0])
            {
                for (int k = 1; i + k <= ls; k++)
                {
                    if (strncmp(s + i, r + i + j, k) == 0)
                    {
                        dp[i + k][j][1] = true;
                    }
                }
            }
            if (dp[i][j][1])
            {
                for (int k = 1; j + k <= lt; k++)
                {
                    if (strncmp(t + j, r + i + j, k) == 0)
                    {
                        dp[i][j + k][0] = true;
                    }
                }
            }
        }
    }
    return dp[ls][lt][0] || dp[ls][lt][1];
}

int main()
{
    char s[MAXN], t[MAXN], r[2 * MAXN];
    fgets(s, MAXN, stdin);
    fgets(t, MAXN, stdin);
    fgets(r, 2*MAXN, stdin);
    s[strcspn(s, "\n")] = '\0';
    t[strcspn(t, "\n")] = '\0';
    r[strcspn(r, "\n")] = '\0';

    bool ok = check(s, t, r);
    puts(ok ? "True" : "False");
    return 0;
}
