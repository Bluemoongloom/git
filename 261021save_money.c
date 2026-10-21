#include <stdio.h>
#include <string.h>
#define N_MAX 2005
#define K_MAX 2005
#define INF 0xcfcfcfcfcfcfcfcfLL
long long dp[K_MAX];
long long pre[N_MAX];

long long maxll(long long a, long long b)
{
    return a > b ? a : b;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    memset(dp, 0xcf, sizeof(dp));
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int m;
        scanf("%d", &m);
        pre[0] = 0;
        for (int t = 1; t <= m; t++)
        {
            long long x;
            scanf("%lld", &x);
            pre[t] = pre[t - 1] + x;
        }

        for (int j = k; j >= 0; j--)
        {
            if (dp[j] == INF)
                continue;
            for (int take = 1; take <= m; take++)
            {
                int nj = j + take;
                if (nj > k)
                    break;
                dp[nj] = maxll(dp[nj], dp[j] + pre[take]);
            }
        }
    }
    printf("%lld\n", dp[k]);
    return 0;
}
