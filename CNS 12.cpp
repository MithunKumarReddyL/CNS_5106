#include <stdio.h>
#include <string.h>

int main() {
    int key[2][2] = {{9, 4}, {5, 7}};
    int inverse_key[2][2] = {{7, -4}, {-5, 9}};
    char text[] = "meetmeattheusualplaceattenratherthaneightoclock";
    int i, j, len = strlen(text);
    int encrypted[len], decrypted[len];

    for (i = 0; i < len; i += 2) {
        encrypted[i] = (key[0][0] * (text[i] - 'a') + key[0][1] * (text[i + 1] - 'a')) % 26;
        encrypted[i + 1] = (key[1][0] * (text[i] - 'a') + key[1][1] * (text[i + 1] - 'a')) % 26;
    }

    printf("Encrypted Text: ");
    for (i = 0; i < len; i++)
        printf("%c", encrypted[i] + 'a');
    printf("\n");

    for (i = 0; i < len; i += 2) {
        decrypted[i] = (inverse_key[0][0] * encrypted[i] + inverse_key[0][1] * encrypted[i + 1]) % 26;
        decrypted[i + 1] = (inverse_key[1][0] * encrypted[i] + inverse_key[1][1] * encrypted[i + 1]) % 26;
    }

    printf("Decrypted Text: ");
    for (i = 0; i < len; i++)
        printf("%c", decrypted[i] + 'a');
    printf("\n");

    return 0;
}

