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


void print_line(Node *tail) {
    Node *current = tail; // Start from the very back of the list
    while (current != NULL){
        printf("%s", current->line);
        current = current->prev; // Move backwards through the entire list, if we finished (NULL), then we stop
    }
}

void reverse(char *filename) {
    // functionality to open the file from: https://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening the file. (No file found)");
        return 1; //error
    }
}

// a function to free up the list. Information from this page was used to understand how to free a list: https://stackoverflow.com/questions/6417158/c-how-to-free-nodes-in-the-linked-list
void free_list(Node *head) {
    Node *current = head; // Start from the head of the list
    while (current != NULL) {
        current = head; //Update current to match the new head
        head = head->next; //Move head up the list
        free(current);
    }
}