#include <stdlib.h>
#include "functions.h"

// Enum datatype for the orientation of the antennas.
typedef enum direction {
    south_west = 0,
    south_east = 1,
    north_east = 2,
    north_west = 3
} direction;

// Static function declarations.
static void change_coverage_status(
        quarter grid[TAM_CIUDAD][TAM_CIUDAD],
        int x, int y, direction dir, int power,
        int i, int j);
static int get_next_x(int x, direction dir);
static int get_next_y(int y, direction dir);


// Functions definitions.
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
        int y = antennas[i][0];
        int x = antennas[i][1];
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
    // Base case.
    if (abs(x-i) == power)
    {
        return;
    }
    // Recursive case.
    // Go to the next column.
    else if (
            abs(x-i) + abs(y-j) == power ||
            j > TAM_CIUDAD-1 ||
            j < 0 ||
            i > TAM_CIUDAD-1 ||
            i < 0)
    {
        i = get_next_x(i, dir);
        return change_coverage_status(grid, x, y, dir, power, i, y);
    }

    // Change the coverage status of the current grid.
    if (grid[i][j] == disconnected)
        grid[i][j] = connected;
    else
        grid[i][j] = disconnected;

    // Recursive case.
    // Go to the next row.
    j = get_next_y(j, dir);
    return change_coverage_status(grid, x, y, dir, power, i, j);
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
        return ++y;
    else
        return --y;
}
