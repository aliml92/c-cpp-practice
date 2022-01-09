#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void fail(void) {
    printf("Memory allocation failed\n");
    exit(1);
}

int main(void){

    // allocate 16 bytes on the heap to hold 16 characters
    char *name = malloc(sizeof(char) * 17);
    if (name == NULL) {
        fail();
    }
    // assign the characters to the name variable
    strcpy(name, "John and Jane Doe"); // string length is 16 but we needed 17 to include the null terminator

    // print size of name
    printf("Size of name: %lu\n", sizeof(name));


    // write a comment that gives a definition about how calloc works
    // calloc allocates memory on the heap and initializes it to 0
    // calloc(number of elements, size of each element)
    // calloc returns a pointer to the allocated memory
    // calloc returns NULL if the allocation fails
    // allocate 4 or 8 bytes on the heap to hold 2 integers using calloc
    int *age = calloc(2, sizeof(int));
    if (age == NULL) {
        fail();
    }
    // assign the integers to the age variable
    age[0] = 31;
    age[1] = 32;

    // reallocate the name variable to hold 28 characters
    name = realloc(name, sizeof(char) * 25);
    if (name == NULL) {
        fail();
    }
    
    strcat(name, " are couple");
    // print the name variable
    printf("Name: %s\n", name);
    // print size of name
    printf("Size of name: %lu\n", sizeof(name));

    // print the age variable
    printf("Age: %d\n", age[0]);
    printf("Age: %d\n", age[1]);

    // free the name variable
    free(name);
    // free the age variable
    free(age);


    exit (0);
}