// my-zip.c
// Made by:
// Arlis Arto Puidet, 000422358
// Miikka Kristian Niinikoski,
// Date: 2025-07-22


// To run this program:
// gcc -o my_zip my-zip.c -Wall -Werror
// ./my_zip source_file [source_file_2 source_file_3 ...] > destination_file


// How we implemented the zipping function:
// 1. Open file with fopen.
// 2. Read the file line by line.
// 3. We count each consecutive character and write the count + the character in question to stdout.
// 4. Close the file after reading.
// 5. Repeat until all files that were given are read and zipped into the stdout stream.



// Instructions are included in the readme.md file.
#include <stdio.h> // fwrite, fread, fopen, fclose
#include <stdlib.h> // perror, exit
#include <string.h> // NULL
#include <stdint.h> // size_t, uint32_t




// Due to how fread and fwrite work, this is not guaranteed to make files that work on other computers, even if the same function is used according to application usage in: https://man7.org/linux/man-pages/man3/fwrite.3p.html
// Ergo, assumption: we execute this code on files from the same system that we read from as well.
void zipping(FILE *fp) {
    if (fp == NULL) {
        perror("Error: unable to access content of file.");
        exit(1);
    }
    
    char buffer[16*1024]; // Assumption: 16KB buffer size is sufficient for the txt file. Inspiration from: https://stackoverflow.com/questions/57763223/why-use-1024-for-a-buffer
    char prev_char = EOF;
    uint32_t count = 0; // Counter for the number of characters read. Assumption: we don't go over 4294967295 characters. Used: https://doc.embedded-wizard.de/uint-type to understand which one to pick for my unsigned int.



    while (fgets(buffer, sizeof(buffer), fp)) { // I'm not entirely sure why sizeof(buffer) is there, but all I know is that the size of it has to be in it according to the example in: https://pubs.opengroup.org/onlinepubs/009696699/functions/fgets.html
        size_t len = strlen(buffer);
        for (size_t i = 0; i < len; i++) {
            int cur_char = buffer[i];
            if (cur_char == prev_char) {
                count++;
            } else {
                if (count > 0) {
                    fwrite(&count, sizeof(uint32_t), 1, stdout); // Number of characters
                    fwrite(&prev_char, sizeof(char), 1, stdout); // Character in question
                }
                prev_char = cur_char; // Update the previous character
                count = 1; // Reset the count for the new character
            }
        }
        if (count > 0) {
            fwrite(&count, sizeof(uint32_t), 1, stdout); // Write the count of the last character
            fwrite(&prev_char, sizeof(int), 1, stdout); // Write the last character
        }
    }
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) { // Assumption: One could assume from the wording in Moodle that need to be able to use more than 1 txt file in zipping and only 1 for the zip itself.
        perror("How to use the program: ./my_zip source_file [source_file_2 source_file_3 ...] > destination_file");
        exit(1);
    } else {
        for (int i = 1; i < argc; i++) {
            FILE *fp = fopen(argv[i], "r"); // Assumption: the files are all .txt files.
            if (fp == NULL) {
                perror("Error: unable to open 1 or more source files; ending the program.");
                exit(1);
            }
            zipping(fp);
        }
    }
    return 0;
}