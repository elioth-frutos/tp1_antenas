#ifndef FUNC_ANT
#define FUNC_ANT

// Enum datatype for the orientation of the antennas.
static enum direction
{
    south_west = 0,
    south_east = 1,
    north_east = 2,
    north_west = 3
} direction;

// Function prototypes.
void initialize_grid(quarter grid[TAM_CIUDAD][TAM_CIUDAD]);
void compute_coverage(
        quarter grid[TAM_CIUDAD][TAM_CIUDAD],
        int antennas[N_ANTENAS][4]
        );
static void change_coverage_status(
        quarter grid[TAM_CIUDAD][TAM_CIUDAD],
        int x, int y, direction dir, int power,
        int i, int j
        );
static int get_next_x(int x, direction dir);
static int get_next_y(int y, direction dir);


#endif
