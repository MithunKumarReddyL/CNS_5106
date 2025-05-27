#include <stdio.h>
#include <string.h>

int main() {
    char text[100], key[26] = "CIPHERABDFGJKLMNOQSTUVWXYZ";
    int i;

    scanf("%s", text);

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = key[text[i] - 'a'];
        else if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = key[text[i] - 'A'];
    }

    printf("%s\n", text);

    return 0;
}

