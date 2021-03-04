#include <stdio.h>
#include <stdlib.h>

/*
 * Sean Fauteaux
 * CSCD 240
 * Lab 5: structConversionLab5.c
 */

struct Person{
    char name[BUFSIZ];
    char ssn[BUFSIZ];
    int age;
    float height;
    float weight;
};

struct Person readData() {

    struct Person x;

    char buff[BUFSIZ]; //reusable array buff
    fgets(x.name, BUFSIZ, stdin);
    fgets(x.ssn, BUFSIZ, stdin);

    fgets(buff, BUFSIZ, stdin);
    x.age = atoi(buff);

    fgets(buff, BUFSIZ, stdin);
    x.height = atof(buff);

    fgets(buff, BUFSIZ,stdin);
    x.weight = atof(buff);

    return x;
}


void printData(struct Person x) {

    printf("%s\n%s\nAge = %d\nHeight(cm) = %g\nWeight(kg) = %g\n",
           x.name, x.ssn, x.age, x.height, x.weight);

}


int main() {

    struct Person p;

    printf("Reading data ......\n");
    p = readData();
    printf("\n");
    printf("Printing data ....\n");
    printData(p);

    return 0;
}

