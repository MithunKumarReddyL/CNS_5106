#include <stdio.h>

int main() {
    char text[100];
    int a, b, i;

    scanf("%s", text);
    scanf("%d %d", &a, &b);

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = ((a * (text[i] - 'a') + b) % 26) + 'a';
        else if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = ((a * (text[i] - 'A') + b) % 26) + 'A';
    }

    printf("%s\n", text);

    return 0;
}

