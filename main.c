//  The code and commit(s) are available at this Git repository.
//  https://github.com/rajib-raiyat/cse_106_lab

//  Import some libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000 // Define a global size.
int matrix[SIZE][SIZE]; // Define a global 2D matrix.

int main() {
    int i, j, dice, degree = 0, edge = 0;  // Declare some integer type variable.
    double program_run_time; // Declare double type variable to calculate program run time.

    // This program will create different sequence of random numbers on every program run.
    srand(time(0)); // Use current time(in second) as seed for random generator.

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

    // By this logic we can prove handshake logic.
    if (degree == (edge * 2)) { // We know if degree is equal to 2 times of edge then handshake is proved.
        printf("Handshake Logic proved.\n\n");
    } else {
        printf("Handshake Logic not proved.\n");
        exit(0);
    }

    printf("n = %d\n", SIZE);
    printf("degree = %d\nedges = %d\n", degree, edge);

    program_run_time = ((double) (end - begin) / CLOCKS_PER_SEC) * 1000000000;
    printf("Program runtime = %.2lf nano second.\n", program_run_time);

    return 0;
}
