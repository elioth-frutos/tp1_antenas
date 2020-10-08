#include <stdio.h>
#include <stdlib.h>
#include "antenas.h"

// Enum datatype for every quarter in the city grid.
static enum quarter
{
    uncovered = 0,
    covered = 1
} quarter;

// Matrix to store the coverage status of every quarter of the city.
static char city_grid[TAM_CIUDAD][TAM_CIUDAD];

void compute_coverage(
        char city_grid[TAM_CIUDAD][TAM_CIUDAD],
        int antennas[][4]
        )
{
    for (int i = 0; i < TAM_CIUDAD; i++)
    {
        int x = antennas[i][0];
        int y = antennas[i][1];
        int dir = antennas[i][2];
        int power = antennas[i][3];
        for (int j = 0; j < TAM_CIUDAD; j++)
        {
            printf("")
        }
        printf('\n');
    }
}
