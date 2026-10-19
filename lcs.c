#include <stdio.h>
#include <string.h>

static int max(int a, int b) {
    return a > b ? a : b;
}

int lcs(char *X, int n, char *Y, int m) {
    if (n == 0 || m == 0)
        return 0;
    else if (X[n-1] == Y[m-1])
        return lcs(X, n-1, Y, m-1) + 1;
    else
        return max(lcs(X, n-1, Y, m), lcs(X, n, Y, m-1));
}

int main(void) {
    char X[1000];
    char Y[1000];

    if (scanf("%999s %999s", X, Y) != 2) {
        fprintf(stderr, "Input error: enter two strings.\n");
        return 1;
    }

    int result = lcs(X, (int)strlen(X), Y, (int)strlen(Y));
    printf("LCS length: %d\n", result);
    return 0;
}
