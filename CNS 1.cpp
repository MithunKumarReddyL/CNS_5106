#include <stdio.h>

int main() {
    char text[100];
    int key, i;
    
    printf("Enter the plaintext: ");
    scanf("%s", text);
    
    printf("Enter the key (1-25): ");
    scanf("%d", &key);
    
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = ((text[i] - 'a' + key) % 26) + 'a';
        else if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = ((text[i] - 'A' + key) % 26) + 'A';
    }
    
    printf("Ciphertext: %s\n", text);
    
    return 0;
}

