#include <stdio.h>
#include <stdlib.h>

//A program to copy the functionality of the "cat" command
int main(int argc, char *argv[]) {
    //Checking to see if any files have actually been provided to read
    if (argc < 2) {
        perror("Error: please provide files to search.\n");
        exit(1);
    }

    //Opening and reading out the files
    int i = 1; //Setting the value of i to one, this is used to move through all the given files with a loop
    while (i < argc) {
        FILE *currentfile = fopen(argv[i], "r");
        //Check if the program can open the file
        if (currentfile == NULL) {
            perror("Error: cannot open file.");
            exit(1); //If a file can't be opened, the program exits.
        }
        //Printing out the file; help for code courtesy of https://www.geeksforgeeks.org/c/c-program-print-contents-file/
        char buffer[16*1024];
        while (fgets(buffer, sizeof(buffer), currentfile) != NULL) {
            printf("%s", buffer);

            size_t len = strlen(buffer); // If no newline is detected at the end of each line, it will print a newline.
            if (len > 0 && buffer[len-1] == "\n") {
                printf("\n");
            }
        }
        fclose(currentfile); //Closing the file
        i++; //Increasing the value of i to move to the next file
    }
    return 0;
}