//
// Created by skyle on 23/10/2021.
//

#include <stdio.h>
#include <string.h>

#define ERR_WRONG_INPUT -1
#define ERR_FILE_NAME -2
#define MAX_LINE_SIZE  100 + 2
#define MAX_STRING_SIZE 20 + 1

int main(int argc, char *argv[]){

    char linebuffer[MAX_LINE_SIZE], string1[MAX_STRING_SIZE], string2[MAX_STRING_SIZE], string2cpy[MAX_STRING_SIZE],
         marker = 0, linebuffercpy_left[MAX_LINE_SIZE] = {'\0'}, linebuffercpy_right[MAX_LINE_SIZE];
    int stringFound, str1Len;


    // check if argc == 1 (file name) + n° elements passed, in this case 5
    if(argc != 5){
        fprintf(stderr,"%s: Error incorrect number of parameters (%d)", argv[0],argc-1);
        return ERR_WRONG_INPUT;
    }

    printf( "Running with\n string1: %s\n Input file: %s\n string2: %s\n Output file: %s\n", argv[1], argv[2], argv[3], argv[4]);
    strcpy( string1 ,argv[1]);
    strcpy(string2, argv[3]);


    // open file 1 to read line by line
    FILE *inputFile = fopen(argv[2], "r");

    // check if file opening failed
    if(inputFile == NULL){
        fprintf(stderr, "%s: Error failed to open file %s", argv[0], argv[2]);
        return ERR_FILE_NAME;
    }

    // open file 2 to write and read line by line
    FILE *outputFile = fopen(argv[4], "w");

    // check if file opening failed
    if(outputFile == NULL){
        fprintf(stderr, "%s: Error failed to open file %s", argv[0], argv[4]);
        return ERR_FILE_NAME;
    }


    //read file line by line

    stringFound = 0;
    str1Len = (int) strlen(string1);

    printf("\n");
    printf("Input file:\n");
    while(fgets(linebuffer, MAX_LINE_SIZE, inputFile) != NULL){
        // print the input file to console
        printf("%s\n", linebuffer);

        // loop through the buffered line until the string we're searching can't be found
        for(int i = 0; linebuffer[i] != '\n'; i++){
            // check if the string is present when the first element of it is found in the buffer
            if(linebuffer[i] == string1[0]){
                // loop through both to check if we have a match
                for(int j = 0; j < str1Len; j++){
                    if(linebuffer[i + j] == string1[j]){
                        stringFound++;
                        // on last iteration if the string is present we enter this if and mark the index for later
                        if(stringFound == str1Len) {
                            marker = 1;
                            stringFound = 0;
                        }
                    }
                }
                stringFound = 0;
            }


            // check if the internal loop has marked the index, if so replace the elements in the buffer with the string2

            if(marker == 1){
                // make a copy of string 2 to use later in strcat
                // strncpy doesn't add \0 terminator, we need to add it ourselves
                strcpy(string2cpy, string2);
                string2cpy[MAX_STRING_SIZE - 1] = '\0';
                // copy "left part" of linebuffer
                strncpy(linebuffercpy_left, linebuffer, i);
                linebuffercpy_left[i] = '\0';
                // copy "right part" of linebuffer
                strncpy(linebuffercpy_right, &linebuffer[i+str1Len], MAX_LINE_SIZE - (i+str1Len));
                // concatenate all the pieces together --> left + string2cpy + right
                strcat(linebuffercpy_left, string2cpy);
                strcat(linebuffercpy_left, linebuffercpy_right);
                // copy final result into linebuffer to iterate again to look for other matches on the same line
                strcpy(linebuffer, linebuffercpy_left);

            }

            marker = 0;

        }

        // after reading everything and possibly replacing print into the output file the linebuffer
        fprintf(outputFile,"%s\n" ,linebuffer);

    }
    fclose(inputFile);
    fclose(outputFile);


    printf("\n");

    printf("Output file:\n");

    outputFile = fopen(argv[4], "r");
    while(fgets(linebuffer, MAX_LINE_SIZE, outputFile) != NULL){
        printf("%s\n", linebuffer);
    }

    fclose(outputFile);


    return 0;
}