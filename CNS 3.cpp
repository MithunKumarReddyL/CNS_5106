#include <stdio.h>
#include <string.h>

int main() {
    char key[25] = "MUSTSEEYOUOVERCADOGANWEST";
    char matrix[5][5], text[100];
    int i, j, k = 0, used[26] = {0};

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++) {
            while (used[key[k] - 'A']) k++;
            matrix[i][j] = key[k];
            used[key[k] - 'A'] = 1;
            k++;
        }

    scanf("%s", text);
    
    for (i = 0; text[i] != '\0'; i += 2) {
        char a = text[i], b = text[i + 1];
        int row1, col1, row2, col2;

        for (j = 0; j < 5; j++)
            for (k = 0; k < 5; k++) {
                if (matrix[j][k] == a) { row1 = j; col1 = k; }
                if (matrix[j][k] == b) { row2 = j; col2 = k; }
            }

        if (row1 == row2) {
            text[i] = matrix[row1][(col1 + 1) % 5];
            text[i + 1] = matrix[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            text[i] = matrix[(row1 + 1) % 5][col1];
            text[i + 1] = matrix[(row2 + 1) % 5][col2];
        } else {
            text[i] = matrix[row1][col2];
            text[i + 1] = matrix[row2][col1];
        }
    }

    printf("%s\n", text);

    return 0;
}

