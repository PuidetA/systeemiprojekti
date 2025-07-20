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
// and https://www.geeksforgeeks.org/c/how-to-create-a-doubly-linked-list-in-c/

typedef struct Node { // used https://www.geeksforgeeks.org/c/how-to-create-a-doubly-linked-list-in-c/ to figure out typedef
    char *line;
    struct Node *next;
    struct Node *prev;
} Node;


void print_lines(Node *tail) {
    Node *current = tail; // Start from the very back of the list
    while (current != NULL){
        printf("%s", current->line);
        current = current->prev; // Move backwards through the entire list, if we finished (NULL), then we stop
    }
}


Node* save_lines(FILE *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    Node *head = NULL;
    Node *tail = NULL;
    Node *new_node = (Node *)malloc(sizeof(Node)); // memory allocate next line

    while ((read = getline(&line, &len, file)) != -1) {
        char *line_copy = malloc(read + 1);
        if (line_copy == NULL) {
            fprintf(stderr, "Malloc line copying failed.");
            exit(1);
        }

        strcpy(line_copy, line);
        Node *new_node = malloc(sizeof(Node));
        if (new_node == NULL) {
            fprintf(stderr, "Malloc failed.");
            exit(1);
        }

        new_node->line = line_copy;
        new_node->next = NULL;
        new_node->prev = tail;
        
        if (tail) {
            tail->next = new_node; // Link the new node to the end of the list
        }
        else {
            head = new_node; // Update the head to the new node
        }
        tail = new_node; // Update the tail to the new node
    }
}

// a function to free up the list. Information from this page was used to understand how to free a list: https://stackoverflow.com/questions/6417158/c-how-to-free-nodes-in-the-linked-list
void free_list(Node *tail) {
    Node *current = tail; // Start from the tail of the list
    while (current != NULL) {
        current = tail; //Update current to match the new tail
        tail = tail->prev; //Move tail down the list
        free(current);
    }
}
int main(int argc, char *argv[]) {
    if (argc != 2) {
        perror("To use this program: ./reverse input.txt\n");
        exit(1);
    }
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
        exit(1); //error
    }

    Node *tail = save_lines(file);
    fclose(file);
    print_lines(tail);
    free_list(tail);
    return 0;}