#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    int shift, i;

    scanf("%s", text);

    for (shift = 1; shift <= 25; shift++) {
        for (i = 0; text[i] != '\0'; i++) {
            if (text[i] >= 'A' && text[i] <= 'Z')
                text[i] = ((text[i] - 'A' - shift + 26) % 26) + 'A';
            else if (text[i] >= 'a' && text[i] <= 'z')
                text[i] = ((text[i] - 'a' - shift + 26) % 26) + 'a';
        }
        printf("Shift %d: %s\n", shift, text);
    }

    return 0;
}

