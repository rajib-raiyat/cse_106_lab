//  The code and commit(s) are available at this Git repository.
//  https://github.com/rajib-raiyat/cse_106_lab

//  Import some libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000 // Define a size

int main() {
    int matrix[SIZE][SIZE]; // Define a 2D matrix.
    int i, j, dice, degree = 0, edge = 0;  // Declare some integer type variable.
    double computational_time_ns; // Declare double type variable to calculate program run time.

    // This program will create different sequence of random numbers on every program run.
    srand(time(0)); // Use current time as seed for random generator

    // This for loop helps to create a SIZE * SIZE matrix.
    for (i = 0; i < SIZE; i++) {
        for (j = i; j < SIZE; j++) {
            dice = rand() % 2;
            matrix[i][j] = dice;
            matrix[j][i] = dice;
        }
    }

    clock_t begin = clock(); // Start counting program run time.

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (i == j && matrix[i][j] == 1) {
                degree++;
            }
            if (matrix[i][j] == 1) {
                degree++;
            }
        }
    }

    for (i = 0; i < SIZE; i++) {
        for (j = i; j < SIZE; j++) {
            if (matrix[i][j] == 1) {
                edge++;
            }
        }
    }

    clock_t end = clock(); // End counting program run time.

    if (degree % (edge * 2) == 0) {
        printf("Handshake Logic proved.\n");
    } else {
        printf("Handshake Logic not proved.\n");
        exit(0);
    }

    printf("degree = %d\nedges = %d\n", degree, edge);

    computational_time_ns = ((double) (end - begin) / CLOCKS_PER_SEC);
    printf("Program runtime = %.3lf second or %.2lf nano second.\n", computational_time_ns,
           computational_time_ns * 1000000000);

    return 0;
}
