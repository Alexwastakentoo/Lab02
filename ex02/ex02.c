//
// Created by skyle on 20/10/2021.
//
#include <stdio.h>

#define ERR_FIL_NAM -1

#define MAX_LINE_SIZE 100 + 2
#define SEQ_SIZE 5

int main(){

    char  linebuffer[MAX_LINE_SIZE];
    int hLine = 0, hLineCount = 0;
    int vLine[MAX_LINE_SIZE] = {0}, vLineCount = 0;

    FILE *inputFile = fopen("input_lab02_ex02.txt", "r"); // open input file

    if(inputFile == NULL){
        fprintf(stderr,"Error invalid file name");
        return ERR_FIL_NAM;
    }

    while(fgets(linebuffer, MAX_LINE_SIZE, inputFile) != NULL){ // read line by line, fgets returns NULL when no new line available
        for(int i = 0; linebuffer[i] != '\0'; i++){
        // horizontal h line checking
        printf("%c", linebuffer[i]);
        fflush(stdout);
        if((linebuffer[i] == 'h') && (i <= MAX_LINE_SIZE - SEQ_SIZE) && (hLine < 5)){ // check if the element is an 'h' if so increment the counter
                hLine++;
        } else if(linebuffer[i] != 'h'){ // if the element is not an 'h' then increment the line counter iff hLine is big enough
            if(hLine == 5){
                hLineCount++;
            }
            hLine = 0; // reset hLine
        }

        // vertical v line checking
        if(linebuffer[i] == 'v' && vLine[i] < 5){ // check if the element is a 'v' if so we need to mark the index to check it in the next line
            vLine[i]++;
           } else if(linebuffer[i] != 'v' ){
            vLine[i] = 0;
           }
            if(vLine[i] == 5) {
                vLineCount++;
                vLine[i] = 0;
            }
        }
    }
    fclose(inputFile);

    printf("\nNumber of horizontal lines: %d\n", hLineCount);
    printf("Number of vertical lines: %d", vLineCount);

    return 0;
}

