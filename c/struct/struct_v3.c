#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char *name;
    char *major;
    int age;
    double gpa;
};


// create a function that prints a Student instance
void printStudent(struct Student *s) {
    printf("Name: %s\n", s->name);
    printf("Major: %s\n", s->major);
    printf("Age: %d\n", s->age);
    printf("GPA: %.2f\n", s->gpa);
}

int main(){


    struct Student student;
    student.age = 31;
    student.gpa = 3.9;
    student.name = malloc(sizeof(char) * 10);
    student.major = malloc(sizeof(char) * 10);

    strcpy(student.name, "Alisher Muzaffarov");
    strcpy(student.major, "Computer Science");

    printStudent(&student);

    // note 
    // when we first create a pointer, we put a * in front of the pointer name
    // and then its value will be the address of another variable
    // when we pass that pointer to some function, we just use variable name of the pointer without *
    // but when we get or set the value of the variable this pointer points to, we use *variable_name
    // this is called dereferencing
    // or instead we can use arrow operator ->


    struct Student *freshman = &student;

    (*freshman).age = 29;
    (*freshman).gpa = 4.05;
    (*freshman).name = malloc(sizeof(char) * 50);
    (*freshman).major = malloc(sizeof(char) * 50);
    strcpy((*freshman).name, "John Doe");
    strcpy((*freshman).major, "Math");
    
    // print the student name using the pointer
    printf("Name: %s\n", (*freshman).name);
    printf("Major: %s\n", (*freshman).major);
    printf("Age: %d\n", (*freshman).age);
    printf("GPA: %.2f\n", (*freshman).gpa);

    // print the student name using the pointer , but this time we use arrow operator
    printf("Name: %s\n", freshman->name);
    printf("Major: %s\n", freshman->major);
    printf("Age: %d\n", freshman->age);
    printf("GPA: %.2f\n", freshman->gpa);

  
    
    printStudent(freshman); // freshman is a pointer to student

    return 0;
}