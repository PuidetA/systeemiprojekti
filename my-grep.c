#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// This function searches the file for lines matching the search term and prints them
// How this was done was learned mostly from https://man7.org/linux/man-pages/man3/getline.3.html and https://man7.org/linux/man-pages/man3/strstr.3.html
void grep_file(FILE currentfile, char search_term) {
    char *line = NULL;
    size_t len = 0;
    // The function will go through all the lines to see if they match the search term
    while (getline(&line, &len, currentfile) != -1) {
        if (strstr(line, search_term)) { // If a substring matching the search term is found, line is printed
            fprintf(line);
            if (len == 0 || current->line[len - 1] != '\n') { // If a line does not end in a newline, one is added
                fprintf('\n');
            }
        }
    }
    free(line); // Any memory allocated to line is freed at the end
}

// Main function
int main(int argc, char argv[]) {

    // Checking to see if any arguments have been given
    if (argc == 0) {
        fprintf("my-grep: searchterm [file...]\n");
        exit(1); // If there are no arguments the program exits with error code 1
    }
    //Using  a while loop to move through the provided files
    int i = 2; //The value of i is set to 2, as the first argument represents the search term rather than a file
    char search_term = argv[1];
    while (i < argc) {
        FILE *currentfile = fopen(argv[i], "r");
        if (currentfile == NULL) {
            fprintf(stderr, "Cannot open file.");
            exit(1); //If a file can't be opened, the program exits.
        grep_file(currentfile, search_term);
        fclose(currentfile)
        i++; // i is incremented
        }
    }
}
