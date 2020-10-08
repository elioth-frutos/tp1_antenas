#include <stdio.h>
#include <stdlib.h>
#include "tp1_antenas.h"


int main(void)
{
    initialize_grid(grid);
    compute_coverage(grid, antenas);
    print_coverage_map(grid, 0, 0);
}
