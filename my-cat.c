#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //Checking to see if any files have actually been provided to read
    if (argc == 0) {
        fprintf(stderr, "Please provide files to search.\n");
        exit(1);
    }

    //Opening and reading out the files
    int i = 1;
    while (i < argc) {
        FILE *currentfile = fopen(argv[i], "r");
        //Check if the program can open the file
        if (currentfile == NULL) {
            fprintf(stderr, "Cannot open file.");
            exit(1); //If a file can't be opened, the program exits.
        }
        //Printing out the file; help for code courtesy of https://www.geeksforgeeks.org/c/c-program-print-contents-file/
        char buffer[1000];
        while (fgets(buffer, sizeof(buffer), currentfile) != NULL) {
            printf("%s", buffer);
        }
        fclose(currentfile); //Closing the file
        i++;
    }
    return 0;
}