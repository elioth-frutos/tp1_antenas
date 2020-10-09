#include "./compute_functions/compute_functions.h"
#include "./print_functions/print_functions.h"
#include "./quarter/quarter.h"
#include "antenas.h"

int main(void)
{
    ////////////////////////////////////////////////
    ////// DEFINITION OF THE "ANTENAS" MATRIX //////
    ////////////////////////////////////////////////
    //
    // Definition of the matrix that describes the
    // configuration of the antennas.
    //
    // Definitions DO NOT go in header files.
    int antenas[N_ANTENAS][4] =
    {
        {0, 9, 0, 5},
        {0, 9, 0, 2},
        {9, 0, 3, 7},
        {9, 9, 3, 12},
    };
    
    // Matrix to store the coverage status of every
    // quarter of the city.
    quarter grid[TAM_CIUDAD][TAM_CIUDAD];

    // Initialize the matrix.
    initialize_grid(grid);

    // Compute the coverage.
    compute_coverage(grid, antenas);

    // Print the coverage map.
    print_coverage_map(grid, 0, 0);

    return 0;
}
