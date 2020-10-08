#include <stdio.h>
#include <stdlib.h>
#include "print_antenas.h"
//#include "antenas.h"


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
        print_horizontal_separators(0);
        return print_coverage_grid(grid, 0, ++j);
    }
    else
    {
        if (grid[i][j] == connected)
            printf("| c ");
        else
            printf("| - ");
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
            printf("+---+");
        else
            printf("+---");
        return print_horizontal_separators(++j);
    }
}
