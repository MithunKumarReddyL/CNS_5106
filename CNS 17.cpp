#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 8  
#define KEY_SIZE 8     
#define NUM_ROUNDS 16  

int main() {
    unsigned char ciphertext[BLOCK_SIZE] = {0xAF, 0xD2, 0x34, 0x67, 0x89, 0xAB, 0xCD, 0xEF}; 
    unsigned char keys[NUM_ROUNDS][KEY_SIZE] = {
        {0x13, 0x34, 0x57, 0x79, 0x9B, 0xBC, 0xDF, 0xF1}, 
        {0x24, 0x56, 0x68, 0x7A, 0xAC, 0xBD, 0xEF, 0x12}, 
    };
    unsigned char plaintext[BLOCK_SIZE] = {0};
    unsigned char block[BLOCK_SIZE];

    for (int i = 0; i < BLOCK_SIZE; i++) {
        block[i] = ciphertext[i];
    }

    for (int round = 0; round < NUM_ROUNDS / 2; round++) {
        unsigned char temp[KEY_SIZE];
        memcpy(temp, keys[round], KEY_SIZE);
        memcpy(keys[round], keys[NUM_ROUNDS - 1 - round], KEY_SIZE);
        memcpy(keys[NUM_ROUNDS - 1 - round], temp, KEY_SIZE);
    }

    for (int i = 0; i < BLOCK_SIZE; i++) {
        plaintext[i] = block[i] ^ 0x5A;
    }

    for (int round = 0; round < NUM_ROUNDS; round++) {
        for (int i = 0; i < BLOCK_SIZE; i++) {
            block[i] ^= keys[round][i % KEY_SIZE]; 
        }
    }

    for (int i = 0; i < BLOCK_SIZE; i++) {
        plaintext[i] = block[i] ^ 0xA5;
    }

    printf("Decrypted Text: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%c", plaintext[i]);
    }
    printf("\n");

    return 0;
}

