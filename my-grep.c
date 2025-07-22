#include <stdio.h>
#include <stdlib.h>

int main(int argc, char argv[]) {

    if (argc == 0) {
        fprintf("my-grep: searchterm [file...]\n");
        exit(1);
    }

    //Using  a while loop to move through the provided files
    int i = 2 //The value of i is set to 2, as the first argument represents the search term rather than a file
    while (i < argc) {
        FILE *currentfile = fopen(argv[i], "r");
        if (currentfile == NULL) {
            fprintf(stderr, "Cannot open file.");
            exit(1); //If a file can't be opened, the program exits.
        }
    }
}
