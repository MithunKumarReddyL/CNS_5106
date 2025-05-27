#include <stdio.h>
#include <string.h>

int main() {
    char ciphertext[100];
    char frequency_order[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    char mapping[26] = {0};
    int letter_count[26] = {0}, i, max_index;

    scanf("%s", ciphertext);

    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z')
            letter_count[ciphertext[i] - 'A']++;
        else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z')
            letter_count[ciphertext[i] - 'a']++;
    }

    for (i = 0; i < 26; i++) {
        max_index = 0;
        for (int j = 1; j < 26; j++)
            if (letter_count[j] > letter_count[max_index])
                max_index = j;

        mapping[max_index] = frequency_order[i];
        letter_count[max_index] = -1;
    }

    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z')
            ciphertext[i] = mapping[ciphertext[i] - 'A'];
        else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z')
            ciphertext[i] = mapping[ciphertext[i] - 'a'];
    }

    printf("Decrypted Text: %s\n", ciphertext);

    return 0;
}

