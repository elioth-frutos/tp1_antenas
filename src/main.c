#include "./compute_functions/compute_functions.h"
#include "./print_functions/print_functions.h"
#include "./quarter/quarter.h"
#include "antenas.h"

int main(void)
{
    // Definition of the matrix that defines the
    // configuration of the antennas.
    int antenas[N_ANTENAS][4] =
    {
        {0, 0, 1, 4},
        {1, 4, 0, 4},
        {1, 4, 0, 4},
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
