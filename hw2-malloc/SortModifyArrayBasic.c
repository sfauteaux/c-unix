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
 */
void swapElements(int *a, int *b);
void sortArray(int *array, const int size);
void printArray(int *array, const int size);
double findMean(int *array, const int size);
double findMedian(int *array, const int size);
double findStandardDeviation( int *array, const int size, double average);

int main(){

    int  n, *x;
    double mean = 0.0, median = 0.0, stdDev = 0.0;

    printf("\nRead using scanf how many integers you would like to type:\n");
    scanf("%d", &n);

    x = (int*) malloc(n * sizeof(int));


    printf("Please type 'n' integers: \n");

    int i = 0;
    while(i<n){
        scanf("%d", &x[i]);
        i++;
    }

    printf("Displaying the numbers:\n");

    printArray(x,n);

    mean = findMean(x,n);

    printf("Mean of the numbers is: %f\n", mean);

    sortArray(x,n);

    median = findMedian(x,n);

    printf("Median of the numbers is: %f\n", median);

    stdDev = findStandardDeviation(x,n,mean);

    printf("Standard deviation of the numbers is: %f\n", stdDev);

    free(x);


    return 0;
}





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

void swapElements( int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}



double findMean(int *array, const int size){
    double sum = 0;
    int i;
    for(i = 0;i<size;i++){
        sum += array[i];
    }
    return sum/size;
}

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


double findStandardDeviation( int *array, const int size, double average){
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
