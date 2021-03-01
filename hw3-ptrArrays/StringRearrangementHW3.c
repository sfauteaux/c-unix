#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortString(char *s[], int count);
void swap(char** s, char** t);
void printList(char** s, int c);

/*
 * Sean Fauteaux
 * 3/1/2021
 * CSCD 240
 * HW3: Dynamic Array of Pointers
 *
 * This program reads in strings from the user and stores each string into a pointer that is dynamically allocated
 * at runtime. After the user presses CTRL+D to stop inputting strings, the program sorts the array of strings
 * by using the strcmp function. Once sorted, the array of strings is printed and then all allocated memory is freed.
 */
int main() {

    int i;
    char buff[BUFSIZ];

    int count;
    // 's' is a pointer to a char pointer, initially 's' is allocated storage for one char pointer
    char **s = malloc(sizeof(char *));

    printf("Here is the list of unsorted names: \n\n");

    // Keep on reading unlimited number of names until EOF (Ctrl + D) is reached
    for (count = 0; fgets(buff, sizeof(buff), stdin); count++) {
        //Step 1: allocate sufficient storage for s[count] to store the content in buff plus one byte for '\0'
        s[count] = malloc(strlen(buff) + 1); //length of buff content + 1

        //Step 2: copy the contents of 'buff' to 's[count]'
        strcpy(s[count],buff);

        //Step 3: resize the array of pointers pointed to by 's' to increase its size for the next pointer
        s = realloc(s, (count+2)*sizeof(char *)); //count is 1 less than what we have because of
        //0 based indexing, and s needs to prepare for the next pointer, so it's count+2
    }

    // EOF reached. Now count the number of strings read

    printf("\nCount is %d\n\n", count);

    // Now sort string using sortString function

    // Step 4: implement sortString function for the above-mentioned function declaration
    sortString(s, count);

    // Step 5: print the list of sorted names.

    printList(s,count);

    // Step 6:free the allocated memory.

    for(i=0;i<count;i++){ //frees all string arrays that were created at runtime
        free(s[i]);
    }
    free(s); //frees the array of pointers


    return 0;
}

//Uses basic selection sort ( O(n^2) ) to iterate through the list of names
//and uses the built in String Compare function strcmp to compare each element of the list of pointers
void sortString(char *s[], int count) {
    int i, j;
    for(i = 0;i<count-1;i++){
        for(j = 0;j<count-1;j++)
            if(strcmp(s[j],s[j+1])>0){ //strcmp is positive when left element is greater than right element
                swap(&s[j],&s[j+1]);
            }
    }
}

//swaps two strings in the array
void swap(char** s, char** t){
    char* temp = *s; //copy string s into temp
    *s = *t;
    *t = temp;
}

//Prints the list of strings
void printList(char** s, int c){
    int i;
    for(i=0;i<c;i++){
        printf("%s",s[i]);
    }
}