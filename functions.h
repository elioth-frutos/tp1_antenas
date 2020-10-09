#ifndef FUNCTIONS
#define FUNCTIONS

#include "antenas.h"

// Enum datatype for the coverage status of every quarter
// of the city.
typedef enum quarter {disconnected, connected} quarter;

// Function prototypes.
void initialize_grid(quarter grid[TAM_CIUDAD][TAM_CIUDAD]);
void compute_coverage(
        quarter grid[TAM_CIUDAD][TAM_CIUDAD],
        int antennas[N_ANTENAS][4]
        );

#endif
