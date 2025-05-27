#include <stdio.h>

int main() {
    char text[100];
    int a = 3, b = 15, a_inv = 9, i;

    scanf("%s", text);

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = ((a_inv * (text[i] - 'A' - b + 26)) % 26) + 'A';
        else if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = ((a_inv * (text[i] - 'a' - b + 26)) % 26) + 'a';
    }

    printf("%s\n", text);

    return 0;
}

