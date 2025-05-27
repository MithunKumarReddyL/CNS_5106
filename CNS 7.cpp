#include <stdio.h>
#include <string.h>

int main() {
    char cipher[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83 (88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8* ;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";
    char plain[100];
    char mapping[256] = {0};
    int i;

    mapping['‡'] = 'E';
    mapping['8'] = 'T';
    mapping['4'] = 'H';
    mapping['6'] = 'O';
    mapping['5'] = 'A';
    mapping['2'] = 'N';
    mapping['0'] = 'I';
    mapping['1'] = 'S';
    mapping['9'] = 'R';
    mapping['3'] = 'D';

    for (i = 0; cipher[i] != '\0'; i++) {
        if (mapping[cipher[i]] != 0)
            plain[i] = mapping[cipher[i]];
        else
            plain[i] = cipher[i];
    }

    plain[i] = '\0';

    printf("%s\n", plain);

    return 0;
}

