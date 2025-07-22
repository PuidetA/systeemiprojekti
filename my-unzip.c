// my-zip.c
// Made by:
// Arlis Arto Puidet, 000422358
// Miikka Kristian Niinikoski,
// Date: 2025-07-22

// To run this program:
// gcc -o my_unzip my-unzip.c -Wall -Werror
// ./my_unzip zipped_file.z

// How we implemented the unzipping function:
// 1. Open the zipped file with fopen.
// 2. We take pairs of character count, and the character itself from the zipped file.
// 3. For each pair, we printf the character for the number of times specified in the pair in the count.
// 4. We do this until EOF and then close the file.

#include <stdio.h> // fwrite, fread, fopen, fclose
#include <stdlib.h> // perror, exit
#include <stdint.h> // uint32_t
#include <string.h> // strlen

void unzipping(FILE *fp) {
    if (fp == NULL) {
        perror("Error: unable to open the zip file.");
        exit(1);
    }
    // Assumption: We don't need more than 4294967295 characters.
    // Assumption: The unzipping works on the same system as the zipping. Differing architectures could cause issues as stated in the fwrite documentation: https://man7.org/linux/man-pages/man3/fwrite.3p.html
    uint32_t char_count;
    char char_to_write; // The character we need to write out.
    while (fread(&char_count, sizeof(uint32_t), 1, fp) == 1 && fread(&char_to_write, sizeof(char), 1, fp) == 1) { // We read them in pairs.
        for (uint32_t i = 0; i < char_count; i++) {
            printf("%c", char_to_write); // As requested in the Moodle page, I used fread and printf for this function.
        }
    }
    fclose(fp);
}




int main(int argc, char *argv[]) {
    if (argc < 2) {
        perror("How to use the program: ./my_unzip zipped_file");
        exit(1);
    }
    unzipping(fopen(argv[1], "r"));
    return 0;
}
