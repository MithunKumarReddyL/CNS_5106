#include <stdio.h>
#include <string.h>

int main() {
    char plaintext[] = "sendmoremoney";
    int key[] = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    char ciphertext[100];
    int i, len = strlen(plaintext);

    for (i = 0; i < len; i++) {
        ciphertext[i] = ((plaintext[i] - 'a' + key[i]) % 26) + 'a';
    }
    ciphertext[len] = '\0';

    printf("Ciphertext: %s\n", ciphertext);

    char new_plaintext[] = "cashnotneeded";
    int new_key[100];

    for (i = 0; i < len; i++) {
        new_key[i] = (ciphertext[i] - 'a' - (new_plaintext[i] - 'a') + 26) % 26;
    }

    printf("New Key: ");
    for (i = 0; i < len; i++) {
        printf("%d ", new_key[i]);
    }
    printf("\n");

    return 0;
}

