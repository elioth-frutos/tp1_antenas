// In this file are contained the functions that print
// to the console.

#include <stdio.h>
#include <stdlib.h>
#include "print_functions.h"

static void print_horizontal_separators(int j);


// Prints the entire coverage map to the console.
//
// Arguments:
// A matrix, which represents the coverage map.
// Two counters, "i" and "j", because the function is recursive.
void print_coverage_map(
        quarter grid[TAM_CIUDAD][TAM_CIUDAD],
        int i, int j
        )
{
    // Base case.
    // End of map. Print the separators and terminate.
    if (j == TAM_CIUDAD)
    {
        print_horizontal_separators(0);
        return;
    }

    // Recursive case.
    // End of line. Progress to the next line.
    else if (i == TAM_CIUDAD)
    {
        printf("|\n");
        return print_coverage_map(grid, 0, ++j);
    }

    // Recursive case.
    // Print the corresponding status and go to the next column.
    else
    {
        if (i == 0)
            print_horizontal_separators(0);
        if (grid[i][j] == connected)
            printf("| c ");
        else
            printf("| - ");
        return print_coverage_map(grid, ++i, j);
    }
}


// Prints the horizontal separators for the corresponding
// coverage map.
//
// Arguments:
// A counter, "j", because this is a recursive function.
static void print_horizontal_separators(int j)
{
    // Base case.
    // End of the grid.
    if (j == TAM_CIUDAD)
    {
        return;
    }

    // Recursive case.
    // Print the corresponding separator and go to the
    // next column.
    else
    {
        if (j == TAM_CIUDAD-1)
            printf("+---+\n");
        else
            printf("+---");
        return print_horizontal_separators(++j);
    }
}
