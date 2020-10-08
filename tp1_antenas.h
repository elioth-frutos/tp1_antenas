#ifndef MAIN_DECLAR
#define MAIN_DECLAR

// Enum datatype for the coverage status of
// every quarter in the city grid.
enum quarter
{
    disconnected = 0,
    connected = 1
} quarter;

// Matrix to store the coverage status of every
// quarter of the city.
quarter grid[TAM_CIUDAD][TAM_CIUDAD];


#endif
