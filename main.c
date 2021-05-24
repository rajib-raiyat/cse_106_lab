//  The code and commit(s) are available at this Git repository.
//  https://github.com/rajib-raiyat/cse_106_lab

//  Import some libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000 // Define a global size.
int matrix[SIZE][SIZE]; // Define a global 2D matrix.

int main() {
    clock_t time_start, time_end;
    int i, j, dice, degree = 0, edge = 0;  // Declare some integer type variable.
    double program_run_time; // Declare double type variable to calculate program run time.

    // This program will create a different sequence of random numbers on every program run.
    srand(time(0)); // Use current time(in second) as seed for random generator.

    // Randomly generating a directed graph with adjacency Matrix.
    for (i = 0; i < SIZE; i++) {
        for (j = i; j < SIZE; j++) {
            dice = rand() % 2; // Generate random value and take the reminder value.
            matrix[i][j] = dice; // Put the remainder value in row.
            matrix[j][i] = dice; // Put the remainder value in column.
        }
    }

    time_start = clock(); // Start counting program run time.

    // calculating the sum  degree
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

    // calculating the sum of edge
    for (i = 0; i < SIZE; i++) {
        for (j = i; j < SIZE; j++) {
            if (matrix[i][j] == 1) {
                edge++;
            }
        }
    }

    time_end = clock(); // End counting program run time.

    // By this logic we can prove handshake logic.
    if (degree == (edge * 2)) { // We know if degree is equal to 2 times of edge then handshake is proved.
        printf("Handshake Logic proved.\n\n");
    } else {
        printf("Handshake Logic not proved.\n");
        exit(0);
    }

    printf("n = %d\n", SIZE);
    printf("sum of degree = %d\nsum of edges = %d\n", degree, edge);

    // CLOCKS_PER_SEC is a constant which is declared in <time.h>.
    // To get the CPU time used by a task within a C application
    program_run_time = ((double) (time_end - time_start) / CLOCKS_PER_SEC) * 1000000000;
    printf("Total Computing time (except printing) = %.2lf ns.\n", program_run_time);

    return 0;
}
