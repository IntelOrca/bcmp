/*
    Copyright (C) 2023  MyName

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [-h] [-v] file1 file2\n", argv[0]);
        printf("-h for help, -v for version\n");
        return 1;
    }
    if(argc>3){
        if(strcmp(argv[1], "-h")==0){
            printf("This program compares two files byte by byte and print the byte address and the value of the two bytes for each difference all in hexdecimal.\n");
            return 0;
        }
        if(strcmp(argv[1], "-v")==0){
            printf("This program version is 1.0\n");
            return 0;
        }
    }

    // Open the two files
    FILE *file1 = fopen(argv[argc-2], "rb");
    FILE *file2 = fopen(argv[argc-1], "rb");
    if (file1 == NULL) {
        printf("Error: Could not open file %s\n", argv[argc-2]);
        return 1;
    }
    if (file2 == NULL) {
        printf("Error: Could not open file %s\n", argv[argc-1]);
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
