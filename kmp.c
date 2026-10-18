#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t *build_next(const char *T) {
    size_t m = strlen(T);
    size_t *Next = malloc(m * sizeof *Next);
    if (Next == NULL && m > 0) return NULL;

    size_t prefix_length = 0;
    if (m > 0) Next[0] = 0;
    for (size_t i = 1; i < m; ++i) {
        while (prefix_length > 0 && T[i] != T[prefix_length])
            prefix_length = Next[prefix_length - 1];
        if (T[i] == T[prefix_length]) ++prefix_length;
        Next[i] = prefix_length;
    }
    return Next;
}

const char *kmp_search(const char *S, const char *T, const size_t *Next) {
    size_t n = strlen(S), m = strlen(T);
    size_t i = 0, j = 0;
    while (i < n && j < m) {
        if (S[i] == T[j]) {
            ++i;
            ++j;
        } else if (j > 0) {
            j = Next[j - 1];
        } else {
            ++i;
        }
    }
    return j == m ? S + (i - m) : NULL;
}

int main(void) {
    char text[1000], pattern[1000];
    if (scanf("%999s %999s", text, pattern) != 2) {
        fprintf(stderr, "请输入主串和模式串。\n");
        return EXIT_FAILURE;
    }

    size_t *Next = build_next(pattern);
    if (Next == NULL) {
        fprintf(stderr, "无法分配前缀表内存。\n");
        return EXIT_FAILURE;
    }

    const char *match = kmp_search(text, pattern, Next);
    if (match != NULL)
        printf("%d\n", (int)(match - text));
    else
        printf("-1\n");

    free(Next);
    return EXIT_SUCCESS;
}
