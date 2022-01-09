#include <stdio.h>

#include "functions.h"

int main(void){

    // using a function
    printf("%d\n", add(8, 14));


    // using macro
    printf("%d\n", ADD(7, 12));

    // using typedef
    person developer;
    developer.age = 31;
    printf("develeper's age is %d\n", developer.age);
}