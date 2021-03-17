#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fileTest.h"
/*
 * Sean Fauteaux
 * Source file for the fileTest.h header file.
 */


//uses tolower to convert each char of the string to lowercase
void lowercase(char* str){
    int size = strlen(str);
    int i;
    for(i = 0; i<size ;i++){
        str[i] = tolower(str[i]);
    }
}

/*
 * Counts all the string occurrences within a file, returns int value of the count
 */
int countString(const char* fileName, char *str){

    int word_count = 0;
    char word[100];

    //Open file, read each word into the array "word"
    FILE *f1 = fopen(fileName,"r");
    if(f1==NULL){
        perror("No such file found.\n");
        exit(0);
    }
    //convert our comparing string to lowercase
    lowercase(str);

    while((fscanf(f1, "%s",word)) != -1){
        lowercase(word); //convert each new word we read in to lowercase
        if(strstr(word,str)!=NULL){
            word_count++;
        }
    }
    //Close file, return count
    fclose(f1);
    return word_count;
}



int countEmptyLines(const char *fileName){

    //Open file, read each line into the array "line"
    int emptyLine = 0;
    char line[256];
    int i,j;

    FILE *f2 = fopen(fileName,"r");
    if(f2==NULL){
        perror("No such file found.\n");
        exit(0);
    }

    //read each line into "line"
    while(fgets(line, sizeof(line),f2) != NULL){
        j = 0;
        //compare each char to see if it's whitespace or not
        for(i = 0;i<strlen(line);i++){
            if(line[i] != ' ' && line[i] != '\n' && line[i] != '\t'){
                j = 1;
                i = strlen(line); //break for loop, this line isn't empty
            }
        }
        //j == 0 then the line is empty
        if(j == 0){
            emptyLine++;
        }
    }

    return emptyLine;
}



