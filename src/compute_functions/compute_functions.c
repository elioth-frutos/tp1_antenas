// In this file are contained the functions that do
// calculations but don't print anything to the console.

#include <stdlib.h>
#include "compute_functions.h"

// Enum datatype for the direction of the antennas.
typedef enum direction {
    south_west = 0,
    south_east = 1,
    north_east = 2,
    north_west = 3
} direction;

static void change_coverage_status(
        quarter grid[TAM_CIUDAD][TAM_CIUDAD],
        int x, int y, direction dir, int power,
        int i, int j);
static int get_next_x(int x, direction dir);
static int get_next_y(int y, direction dir);


// Initializes the coverage map with all values set to "disconnected".
//
// Arguments:
// A matrix, which represents the coverage map.
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


// Computes and changes the coverage status of every quarter
// of the city, according to the antennas.
//
// Arguments:
// A matrix, which represents the coverage map.
// Another matrix, which represents the position and configuration
// of the antennas.
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

        // Calculate the coverage status.
        change_coverage_status(grid, x, y, dir, power, x, y);
    }
}


// Changes the coverage status of every quarter of the city,
// according to just one antenna.
//
// Arguments:
// A matrix, which represents the coverage map.
// The four numbers which define an antenna; "x" position,
// "y" position, orientation and power.
// Two counters, "i" and "j", because the function is recursive.
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
    // Change nothing and go to the next column.
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
    // Recursive case.
    else
    {
        // Change the coverage status of the current quarter.
        if (grid[i][j] == disconnected)
            grid[i][j] = connected;
        else
            grid[i][j] = disconnected;

        // Go to the next row.
        j = get_next_y(j, dir);
        return change_coverage_status(grid, x, y, dir, power, i, j);
    }
}


// Gets the next value for "x" according to the orientation
// of the antenna.
//
// Arguments:
// The current "x" position.
// The orientation or direction of the antenna.
static int get_next_x(int x, direction dir)
{
    if (dir == south_west || dir == north_west)
        return --x;
    else
        return ++x;
}


// Gets the next value for "y" according to the orientation
// of the antenna.
//
// Arguments:
// The current "y" position.
// The orientation or direction of the antenna.
static int get_next_y(int y, direction dir)
{
    if (dir == south_west || dir == south_east)
        return ++y;
    else
        return --y;
}
