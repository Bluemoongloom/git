#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int i, j;
    int *numbers;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of elements.\n");
        return EXIT_FAILURE;
    }

    numbers = malloc((size_t)n * sizeof *numbers);
    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; ++i) {
        if (scanf("%d", &numbers[i]) != 1) {
            fprintf(stderr, "Invalid input.\n");
            free(numbers);
            return EXIT_FAILURE;
        }
    }

    for (i = 0; i < n - 1; ++i) {
        int swapped = 0;
        for (j = 0; j < n - 1 - i; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }

    printf("Sorted: ");
    for (i = 0; i < n; ++i)
        printf("%s%d", i == 0 ? "" : " ", numbers[i]);
    putchar('\n');

    free(numbers);
    return EXIT_SUCCESS;
}