#include <stdio.h>
#include <stdlib.h>
#include "func_antenas.h"
//#include "antenas.h"


void initialize_grid(quarter grid[TAM_CIUDAD][TAM_CIUDAD])
{
    for (int i = 0; i < TAM_CIUDAD; i++)
    {
        for (int j = 0; j < TAM_CIUDAD; j++)
        {
            grid[i][j] = disconnected;
        }
    }
}


void compute_coverage(
        quarter grid[TAM_CIUDAD][TAM_CIUDAD],
        int antennas[N_ANTENAS][4]
        )
{
    // Iterate through every antenna in the array.
    for (int i = 0; i < N_ANTENAS; i++)
    {
        int x = antennas[i][0];
        int y = antennas[i][1];
        direction dir = antennas[i][2];
        int power = antennas[i][3];
        // Calculate the coverage.
        change_coverage_status(grid, x, y, dir, power, x, y);
    }
}


static void change_coverage_status(
        quarter grid[TAM_CIUDAD][TAM_CIUDAD],
        int x, int y, direction dir, int power,
        int i, int j
        )
{
    // Change the coverage status of the current grid.
    if (grid[x+i][y] = disconnected)
        grid[x+i][y] = connected
    else
        grid[x+i][y] = disconnected

    // Base case.
    if (abs(x-i) == power-1)
    {
        return;
    }
    // Recursive cases.
    // Go to the next column.
    else if (abs(x-i) + abs(y-j) == power-1)
    {
        i = get_next_x(i, dir);
        return compute_coverage(grid, x, y, dir, power, i, y);
    }
    // Go to the next row.
    else
    {
        j = get_next_y(j, dir);
        return compute_coverage(grid, x, y, dir, power, i, j);
    }
}


static int get_next_x(int x, direction dir)
{
    if (dir == south_west || dir == north_west)
        return --x;
    else
        return ++x;
}


static int get_next_y(int y, direction dir)
{
    if (dir == south_west || dir == south_east)
        return --y;
    else
        return ++y;
}
