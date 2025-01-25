#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc != 2) { 
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Seek to end to determine size
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fclose(file);

    if (filesize == -1) {
        perror("Error determining file size");
        return EXIT_FAILURE;
    }

    printf("File size: %ld bytes\n", filesize);
    return EXIT_SUCCESS;
}
