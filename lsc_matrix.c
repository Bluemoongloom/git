#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int max(int a, int b) {
    return a > b ? a : b;
}

int lcs(char *X, int n, char *Y, int m, int **XY) {
    int i, j;
    /* 初始化第0列：i从0到n */
    for (i = 0; i <= n; i++)
        XY[i][0] = 0;
    /* 初始化第0行：j从0到m */
    for (j = 0; j <= m; j++)
        XY[0][j] = 0;

    /* 填充DP表 */
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (X[i - 1] == Y[j - 1]) {
                /* 字符相等，左上角+1 */
                XY[i][j] = XY[i - 1][j - 1] + 1;
            } else {
                /* 字符不等，取上方、左方最大值 */
                XY[i][j] = max(XY[i - 1][j], XY[i][j - 1]);
            }
        }
    }
    return XY[n][m];
}

int main(void) {
    char X[1000], Y[1000];
    int n, m, length, i, j;
    int **XY;
    int *matrix;

    if (scanf("%999s %999s", X, Y) != 2) {
        fprintf(stderr, "Input error: enter two strings.\n");
        return EXIT_FAILURE;
    }

    n = (int)strlen(X);
    m = (int)strlen(Y);
    XY = malloc((size_t)(n + 1) * sizeof *XY);
    matrix = calloc((size_t)(n + 1) * (size_t)(m + 1),
                    sizeof *matrix);
    if (XY == NULL || matrix == NULL) {
        free(XY);
        free(matrix);
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    for (i = 0; i <= n; ++i)
        XY[i] = matrix + (size_t)i * (size_t)(m + 1);

    length = lcs(X, n, Y, m, XY);

    printf("    ");
    for (j = 0; j <= m; ++j)
        printf("%4c", j == 0 ? '-' : Y[j - 1]);
    putchar('\n');

    for (i = 0; i <= n; ++i) {
        printf("%4c", i == 0 ? '-' : X[i - 1]);
        for (j = 0; j <= m; ++j)
            printf("%4d", XY[i][j]);
        putchar('\n');
    }

    printf("LCS length: %d\n", length);

    free(matrix);
    free(XY);
    return EXIT_SUCCESS;
}
