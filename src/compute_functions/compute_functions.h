#ifndef FUNCTIONS
#define FUNCTIONS

#include "../quarter/quarter.h"
#include "../antenas.h"

void initialize_grid(quarter grid[TAM_CIUDAD][TAM_CIUDAD]);
void compute_coverage(
        quarter grid[TAM_CIUDAD][TAM_CIUDAD],
        int antennas[N_ANTENAS][4]);

#endif
