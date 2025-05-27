#include <stdio.h>

int main() {
    int plaintext[2] = {7, 4}; // Example plaintext pair (H, E)
    int ciphertext[2] = {19, 10}; // Corresponding ciphertext pair (T, K)
    int key[2][2], inverse_key[2][2], i, j;

    key[0][0] = (ciphertext[0] - ciphertext[1]) * (plaintext[0] - plaintext[1]) % 26;
    key[0][1] = (ciphertext[0] - plaintext[0]) * (plaintext[1] - plaintext[0]) % 26;
    key[1][0] = (ciphertext[1] - plaintext[1]) * (plaintext[0] - plaintext[1]) % 26;
    key[1][1] = (ciphertext[1] - ciphertext[0]) * (plaintext[1] - plaintext[0]) % 26;

    printf("Recovered Key Matrix:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++)
            printf("%d ", key[i][j]);
        printf("\n");
    }

    return 0;
}

