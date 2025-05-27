#include <stdio.h>
#include <string.h>
#include <openssl/des.h>

#define BLOCK_SIZE 8  

int main() {
    unsigned char key1[8] = {0x13, 0x34, 0x57, 0x79, 0x9B, 0xBC, 0xDF, 0xF1};
    unsigned char key2[8] = {0x24, 0x56, 0x68, 0x7A, 0xAC, 0xBD, 0xEF, 0x12};
    unsigned char key3[8] = {0x35, 0x67, 0x79, 0x8B, 0xCD, 0xDE, 0xF1, 0x23};
    unsigned char iv[BLOCK_SIZE] = {0xFF, 0xEE, 0xDD, 0xCC, 0xBB, 0xAA, 0x99, 0x88};
    unsigned char plaintext[BLOCK_SIZE] = "Example!";
    unsigned char ciphertext[BLOCK_SIZE];

    DES_key_schedule ks1, ks2, ks3;
    DES_set_key((DES_cblock*)key1, &ks1);
    DES_set_key((DES_cblock*)key2, &ks2);
    DES_set_key((DES_cblock*)key3, &ks3);

    DES_ede3_cbc_encrypt(plaintext, ciphertext, BLOCK_SIZE, &ks1, &ks2, &ks3, (DES_cblock*)iv, DES_ENCRYPT);

    printf("Encrypted Text: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n");

    return 0;
}

