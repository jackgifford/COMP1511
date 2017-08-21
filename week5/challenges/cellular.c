// 1-dimensional cellular automaton
// Completed by ... (z0000000)
// Completed on 2017-??-??
// Tutor's name (dayHH-lab)

#include <stdio.h>
#include <stdlib.h>

#define WORLD_SIZE  80
#define GENERATIONS 31
#define ALIVE   '*'
#define DEAD    ' '

void initBuffer (char *buffer);
void swapBuffer (char **a, char **b);
void display (int num, char *generation);
void nextGeneration (char *curr, char *next);

// This is the main function.
// It controls the swapping of the two world buffers,
// and the generation looping.
int main (int argc, char *argv[]) {

    char alpha[WORLD_SIZE] = {0};
    char beta[WORLD_SIZE] = {0};

    char *curr = alpha;
    char *next = beta;

    // Initialise buffers
    initBuffer (alpha);
    initBuffer (beta);

    // Add life
    curr[WORLD_SIZE / 2] = ALIVE;
    curr[(WORLD_SIZE / 2) - 1] = ALIVE;

    int g = 0;
    while (g < GENERATIONS) {
        display (g, curr);
        nextGeneration (curr, next);
        swapBuffer (&curr, &next);
        g++;
    }

    return EXIT_SUCCESS;
}

// This initialises a world buffer,
// and sets all cells to DEAD.
void initBuffer (char *buffer) {
    int i = 0;
    while (i < WORLD_SIZE) {
        buffer[i] = DEAD;
        i++;
    }
}

// This swaps two world buffers.
void swapBuffer (char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// This displays a single generation of the world,
void display (int num, char *generation) {
    printf ("Gen %3d: ", num);

    int i = 0;
    while (i < WORLD_SIZE) {
        putchar (generation[i]);
        i++;
    }

    putchar ('\n');
}

// Generate the state of each cell for the new generation
// (This is the function that you should implement!)
void nextGeneration (char curr[WORLD_SIZE], char next[WORLD_SIZE]) {
    int cell = 0;
    while (cell < WORLD_SIZE) {
        // IMPLEMENT THE RULES HERE
        next[cell] = curr[cell];
        cell++;
    }
}