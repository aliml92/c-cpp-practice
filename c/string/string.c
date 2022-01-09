#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    
    // working with a single char

    char letter = 's';
    printf("%c\n", letter);
    printf("%p\n", &letter);
    
    letter = 't';
    printf("%c\n", letter);
    printf("%p\n", &letter);

    char *lpointer = &letter;
    *lpointer = 'u';
    printf("%c\n", letter);
    printf("%p\n", &letter);


    // working with an array of chars or strings
    char *name = "John Doe";
    printf("%s\n", name);
    printf("%lu\n", strlen(name));
    // the following prints different addresses
    printf("%p\n", name);  // prints the address of the first char in the array   
    printf("%p\n", &name); // prints the address of the pointer to the array


    char name2[] = "Jane Doe";
    printf("%s\n", name2);
    printf("%lu\n", strlen(name2));
    // the following prints the same address
    printf("%p\n", name2); // prints the address of the first char in the array
    printf("%p\n", &name2); // prints the address of the pointer to the array

    name2[0] = 'j';
    name2[5] = 'd';
    printf("%s\n", name2);

    char name3[] = {'J', 'a', 'm', 'e', 's', ' ', 'D', 'o', 'e', '\0'};
    printf("%s\n", name3);
    printf("%lu\n", strlen(name3));
    // the following prints the same address
    printf("%p\n", name3); // prints the address of the first char in the array
    printf("%p\n", &name3); // prints the address of the pointer to the array

    name3[0] = 'j';
    name3[6] = 'd';
    printf("%s\n", name3);

    char name4[32];

    strncpy(name4, "Jim Halpert", sizeof(name4));
    printf("%s\n", name4);
    printf("%lu\n", strlen(name4));

    // access elements of an array 
    // array[index] equals *(array + index)
    // get 5th element of an array
    printf("%c\n", name4[4]);
    // get 5th element of an array using pointer arithmetic
    printf("%c\n", *(name4 + 4));   


    // modify elements of an array
    // modify 5th element of an array
    name4[4] = 'h'; 
    printf("%s\n", name4);
    // modify 1st element of an array using pointer arithmetic
    *(name4 + 0) = 'j';
    printf("%s\n", name4);

    // first element can be modified using pointer to the array
    *name4 = 'J';
    printf("%s\n", name4);



    return 0;
}