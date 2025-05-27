#include <stdio.h>
#include <math.h>

int main() {
    double total_keys = 1, unique_keys;
    int i;

    for (i = 1; i <= 25; i++)
        total_keys *= i;

    unique_keys = total_keys / (5 * 5);

    printf("Total possible keys: %.0f\n", total_keys);
    printf("Effectively unique keys: %.0f\n", unique_keys);
    printf("Approximate power of 2 (Total keys): 2^%.0f\n", log2(total_keys));
    printf("Approximate power of 2 (Unique keys): 2^%.0f\n", log2(unique_keys));

    return 0;
}

