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
// 3. Print out the lines in reverse from said doubly linked list.
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
        // Print a newline if line doesn't end with it.
        size_t len = strlen(current->line); //source used: 
        if (len == 0 || current->line[len - 1] != '\n') {
            printf("\n");
        }
        current = current->prev; // Move backwards through the entire list, if we finished (NULL), then we stop
    }
}



// Nothing explicitly copied, but used to understand how doubly linked list saving works and how I could possibly implement it: https://youtu.be/KFbm6lkMhgw
// Also used this to understand doubly linked lists: https://medium.com/@Dev_Frank/c-linked-list-doubly-linked-list-561851cd732a
Node* save_lines(FILE *file) { // I'll comment this in detail line-by-line, since it's the most difficult part.
    char *line = NULL; // We hold each line that we get from the file.
    size_t len = 0; // Initialize the length of the line to 0, so getline can allocate memory for it.
    ssize_t read; // Return of getline.
    Node *head = NULL; // This will be the head of the list
    Node *tail = NULL; // This will be the tail of the list

    while ((read = getline(&line, &len, file)) != -1) {
        char *line_copy = malloc(read + 1);
        if (line_copy == NULL) {
            fprintf(stderr, "Malloc line copying failed.");
            exit(1);
        }

        strncpy(line_copy, line, read);
        line_copy[read] = '\0';
        Node *new_node = malloc(sizeof(Node));
        if (new_node == NULL) {
            fprintf(stderr, "Malloc failed for node allocation.");
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
    
    // Free the line buffer allocated by getline
    free(line);
    return tail;
}

// a function to free up the list. Information from this page was used to understand how to free a list: https://stackoverflow.com/questions/6417158/c-how-to-free-nodes-in-the-linked-list
void free_list(Node *tail) {
    Node *current = tail;
    while (current != NULL) {
<<<<<<< HEAD
        Node *prev = current->prev;
        free(current->line);
        free(current);
        current = prev;
=======
        Node *prev = current->prev; 
        free(current);
        current = prev; //Updating current to match new tail
>>>>>>> 131ea736890905a1352178d7e7d7006a6a49dd02
    }
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./reverse input.txt\n");
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
        return 0;
}