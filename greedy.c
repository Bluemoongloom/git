#include <limits.h>
#include <stdio.h>

int Select_Activity(const int *s, const int *f, int i, int j) {
    int m = i + 1;

    while (m < j && s[m] < f[i])
        ++m;

    if (m < j)
        return Select_Activity(s, f, m, j) + 1;
    return 0;
}

int Select_Activity_Iterative(const int *s, const int *f, int j,
                              int *selected) {
    int count = 0;
    int last = 0;

    while (last < j) {
        int next = last + 1;
        while (next < j && s[next] < f[last])
            ++next;

        if (next == j)
            break;

        selected[count++] = next;
        last = next;
    }

    return count;
}

int main(void) {
    /* Activities 1..11 are sorted by finishing time; activity 12 is a sentinel. */
    const int s[] = {
        0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12, INT_MAX
    };
    const int f[] = {
        0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, INT_MAX
    };
    const int last_activity = 12;
    int selected[11];
    int recursive_count;
    int iterative_count;
    int i;

    recursive_count = Select_Activity(s, f, 0, last_activity);
    iterative_count = Select_Activity_Iterative(
        s, f, last_activity, selected);

    printf("Recursive result (%d activities): ", recursive_count);
    /* Print the recursive choices by following the same greedy decisions. */
    {
        int current = 0;
        int printed = 0;
        while (current < last_activity) {
            int next = current + 1;
            while (next < last_activity && s[next] < f[current])
                ++next;
            if (next == last_activity)
                break;
            printf("%s%d", printed == 0 ? "" : " ", next);
            ++printed;
            current = next;
        }
    }
    putchar('\n');

    printf("Iterative result (%d activities): ", iterative_count);
    for (i = 0; i < iterative_count; ++i)
        printf("%s%d", i == 0 ? "" : " ", selected[i]);
    putchar('\n');

    return 0;
}