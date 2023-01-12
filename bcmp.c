#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        return 1;
    }

    // Open the two files
    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");
    if (file1 == NULL || file2 == NULL) {
        printf("Error: Could not open files\n");
        return 1;
    }

    // Determine the length of the two files
    fseek(file1, 0, SEEK_END);
    long file1Len = ftell(file1);
    fseek(file2, 0, SEEK_END);
    long file2Len = ftell(file2);

    // Reset the file pointers to the beginning of the files
    rewind(file1);
    rewind(file2);

    // Find the smallest file
    long smallestLen = file1Len < file2Len ? file1Len : file2Len;

    // Iterate through the bytes of the two files
    for (long i = 0; i < smallestLen; i++) {
        // Read a byte from each file
        unsigned char byte1 = (unsigned char)fgetc(file1);
        unsigned char byte2 = (unsigned char)fgetc(file2);

        // Compare the bytes
        if (byte1 != byte2) {
            printf("0x%08lX: 0x%02X 0x%02X\n", i, byte1, byte2);
        }
    }

    // Close the files
    fclose(file1);
    fclose(file2);

    return 0;
}
