#include <stdio.h>
#include <stdlib.h>
#include "print_functions.h"

// Function declarations.
static void print_horizontal_separators(int j);

void print_coverage_map(quarter grid[TAM_CIUDAD][TAM_CIUDAD], int i, int j)
{
    if (j == TAM_CIUDAD)
    {
        print_horizontal_separators(0);
        return;
    }
    else if (i == TAM_CIUDAD)
    {
        printf("|\n");
        return print_coverage_map(grid, 0, ++j);
    }
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


static void print_horizontal_separators(int j)
{
    if (j == TAM_CIUDAD)
    {
        return;
    }
    else
    {
        if (j == TAM_CIUDAD-1)
            printf("+---+\n");
        else
            printf("+---");
        return print_horizontal_separators(++j);
    }
}
