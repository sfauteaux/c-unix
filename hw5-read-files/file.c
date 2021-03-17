#include <stdio.h>
#include <stdlib.h>
#include "fileTest.h"

/*
 * Sean Fauteaux
 * 3/16/2021
 * CSCD 240
 * HW5: String Matching and Empty Line Counting
 *
 * This assignment counts the occurrences of a given string within a given file,
 * as well as counting the amount of empty lines that appear within that file. 
 */

int main(int argc, char *argv[]){

    if (argc != 3){
        printf("Incorrect Parameters.\n");
        exit(0);
    }

    int word_count = countString(argv[1], argv[2]);
    int empty_line = countEmptyLines(argv[1]);

    printf("The string \"%s\" occurs %d times in File \"%s\".\n", argv[2],  word_count, argv[1]);
    printf("File \"%s\" has %d empty lines.\n", argv[1], empty_line);

    return 0;

}


