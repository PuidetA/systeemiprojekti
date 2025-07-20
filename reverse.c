// Made by: 
// Arlis Arto Puidet
// Miikka Kristian Niinikoski
// Date: 2025-07-20

// To run this program:
// gcc reverse.c -o reverse
// ./reverse input.txt



// How we reverse the file:
// 1. Open the file with fopen r.
// 2. Read the file line by line, storing each line in a dynamic data structure. (in this case: a doubly linked list)
// 3. Print out the lines in reverse from said array.
// 4. Free the memory and close the file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// used this tutorial to understand doubly linked lists: https://www.geeksforgeeks.org/c/linked-list-in-c/

typedef struct Node {
    char *line;
    struct Node *next;
    struct Node *prev;
} Node;



void reverse(char *filename) {
    // functionality to open the file from: https://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening the file. (No file found)");
        return 1; //error
    }



}