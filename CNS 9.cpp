#include <stdio.h>
#include <string.h>

int main() {
    char matrix[5][5] = {
        {'P', 'L', 'A', 'Y', 'F'},
        {'I', 'R', 'C', 'H', 'E'},
        {'B', 'D', 'G', 'K', 'M'},
        {'N', 'O', 'Q', 'S', 'T'},
        {'U', 'V', 'W', 'X', 'Z'}
    };
    char text[100];
    int i, j, k, row1, col1, row2, col2;

    scanf("%s", text);

    for (i = 0; text[i] != '\0'; i += 2) {
        char a = text[i], b = text[i + 1];

        for (j = 0; j < 5; j++)
            for (k = 0; k < 5; k++) {
                if (matrix[j][k] == a) { row1 = j; col1 = k; }
                if (matrix[j][k] == b) { row2 = j; col2 = k; }
            }

        if (row1 == row2) {
            text[i] = matrix[row1][(col1 + 4) % 5];
            text[i + 1] = matrix[row2][(col2 + 4) % 5];
        } else if (col1 == col2) {
            text[i] = matrix[(row1 + 4) % 5][col1];
            text[i + 1] = matrix[(row2 + 4) % 5][col2];
        } else {
            text[i] = matrix[row1][col2];
            text[i + 1] = matrix[row2][col1];
        }
    }

    printf("%s\n", text);

    return 0;
}

