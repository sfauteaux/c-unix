#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 * Sean Fauteaux
 * 2/18/2021
 * CSCD 240
 * HW2: Dynamically Allocating Memory
 *
 * This program asks the user for the size of their data set, then
 * allocates enough space for each of their entries. After reading the
 * data into the allocated memory, program finds Mean, Median, and STD Deviation.
 * Each value is printed to console, then the memory is freed.
 *
 * This version allows for continued inputs, until the program is terminated from
 * the console with CTRL + D
 */
void swapElements(int *a, int *b);
void sortArray(int *array, const int size);
void printArray(int *array, const int size);
double findMean(int *array, const int size);
double findMedian(int *array, const int size);
double findStandardDeviation( int *array, const int size, double average);

int main(){

    int  n = 0, *x;
    double mean = 0.0, median = 0.0, stdDev = 0.0;

    x = (int*) malloc(0);//initial allocation

    int c;
    printf("Please type your integer: \n");

    while(scanf("%d", &c) == 1) {
        n++;
        x = (int *)realloc(x, n*sizeof(int));

        x[n-1] = c;

        printf("Displaying the numbers typed so far:\n");

        printArray(x, n);

        mean = findMean(x, n);

        printf("Mean of the numbers is: %f\n", mean);

        sortArray(x, n);

        median = findMedian(x, n);

        printf("Median of the numbers is: %f\n", median);

        stdDev = findStandardDeviation(x, n, mean);

        printf("Standard deviation of the numbers is: %f\n", stdDev);

        printf("Please type your integer: \n");

    }
    free(x); //Free Memory
    x = NULL; //Set pointer to NULL

    return 0;
}


//Prints every element of the array thus far
void printArray( int *array, const int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

//basic selection sort algorithm, didn't want to try too much
//since I'm still learning the syntax and functionality of C
void sortArray(int *array, const int size){
    int i,j;
    for(i=0;i<size;i++){
        int low = array[i];
        int index = i;
        for(j=i;j<size;j++){
            if(array[j] < array[i]){
                low = array[j];
                index = j;
            }
        }
        swapElements(&array[i],&array[index]);
    }
}

//Used for sorting the array
void swapElements( int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Calculates mean by adding all elements, dividing by size
double findMean(int *array, const int size){
    double sum = 0;
    int i;
    for(i = 0;i<size;i++){
        sum += array[i];
    }
    return sum/size;
}

//Finds middle point of array. If array is evenly sized, finds two middle
//values and returns the number halfway between them
double findMedian(int *array, const int size){
    int s = size % 2; //check for remainder when dividing by 2
    double med;
    double one, two;
    if(s==0){
        one = array[(size/2)-1];
        two = array[(size/2)];
        med = (one + two)/2;
    }
    else{
        med = array[size/2];
    }

    return med;
}

//Uses the steps given in the Simple Stats PDF to calculate the STD Dev
double findStandardDeviation( int *array, const int size, double average){
    if(size == 1){
        return 0;
    }
    double mean = average;
    double curr = 0;
    int i;
    for(i = 0;i<size;i++){ //this completes steps 1-4 from the Simple Stats PDF
        double j = array[i] - mean;
        j = j*j;
        curr += j;
    }
    curr = sqrt(curr/(size-1)); //steps 5 and 6
    return curr;
}

