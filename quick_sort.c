#include <stdio.h>

static void quick_sort(int values[], int left, int right)
{
    int i = left;
    int j = right;
    int pivot = values[left + (right - left) / 2];

    while (i <= j) {
        while (values[i] < pivot) {
            ++i;
        }
        while (values[j] > pivot) {
            --j;
        }

        if (i <= j) {
            int temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            ++i;
            --j;
        }
    }

    if (left < j) {
        quick_sort(values, left, j);
    }
    if (i < right) {
        quick_sort(values, i, right);
    }
}

int main(void)
{
    int values[] = { 8, 3, 5, 1, 9, 2, 7, 4, 6 };
    int count = (int)(sizeof(values) / sizeof(values[0]));

    quick_sort(values, 0, count - 1);

    printf("Sorted: ");
    for (int i = 0; i < count; ++i) {
        printf("%d%s", values[i], i + 1 == count ? "\n" : " ");
    }

    return 0;
}