#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000 // Define a size

int matrix[SIZE][SIZE];

int main() {
    int i, j, dice, degree = 0, edge = 0;
    double computational_time_ns;

    for (i = 0; i <= SIZE; i++) {
        for (j = i; j <= SIZE; j++) {
            dice = rand() % 2;
            matrix[i][j] = dice;
            matrix[j][i] = dice;
        }
    }

    for (i = 0; i <= SIZE; i++) {
        for (j = 0; j <= SIZE; j++) {
            if (i == j && matrix[i][j] == 1) {
                degree++;
            }
            if (matrix[i][j] == 1) {
                degree++;
            }
        }
    }

    for (i = 0; i <= SIZE; i++) {
        for (j = i; j <= SIZE; j++) {
            if (matrix[i][j] == 1) {
                edge++;
            }
        }
    }

    printf("degree = %d\nedges = %d\n", degree, edge);

    return 0;
}
