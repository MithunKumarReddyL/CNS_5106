#include <stdio.h>
#include <string.h>

#define KEY_SIZE 56  
#define SUBKEY_SIZE 48  
#define NUM_ROUNDS 16  

int main() {
    unsigned char initialKey[KEY_SIZE] = {
        0x13, 0x34, 0x57, 0x79, 0x9B, 0xBC, 0xDF
    };
    unsigned char subkeys[NUM_ROUNDS][SUBKEY_SIZE];

    for (int round = 0; round < NUM_ROUNDS; round++) {
        for (int i = 0; i < 24; i++) {
            subkeys[round][i] = initialKey[i % 28];  
        }
        for (int i = 24; i < SUBKEY_SIZE; i++) {
            subkeys[round][i] = initialKey[(i % 28) + 28];  
        }
    }

    printf("Generated Subkeys:\n");
    for (int round = 0; round < NUM_ROUNDS; round++) {
        printf("Round %d: ", round + 1);
        for (int i = 0; i < SUBKEY_SIZE; i++) {
            printf("%02X ", subkeys[round][i]);
        }
        printf("\n");
    }

    return 0;
}

