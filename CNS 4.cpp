#include <stdio.h>
#include <string.h>

int main() {
    char text[100], key[100];
    int i, j, keyLength;

    scanf("%s", text);
    scanf("%s", key);

    keyLength = strlen(key);

    for (i = 0; text[i] != '\0'; i++) {
        j = i % keyLength;
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = ((text[i] - 'a' + (key[j] - 'a')) % 26) + 'a';
        else if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = ((text[i] - 'A' + (key[j] - 'A')) % 26) + 'A';
    }

    printf("%s\n", text);

    return 0;
}

