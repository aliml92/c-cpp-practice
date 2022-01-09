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

    // create a student variable with struct type Student
    struct Student student;

    // assign values to the student variable
    student.age = 31;
    student.gpa = 3.9;
    student.name = "Alisher Muzaffarov"; // i don't know why this is working
    student.major = "Computer Science";  // i don't know why this is working
    

    struct Student freshman;
    freshman.age = 19;
    freshman.gpa = 3.9;
    freshman.name = malloc(sizeof(char) * 50);
    freshman.major = malloc(sizeof(char) * 50);
    strcpy(freshman.name, "Alisher Muzaffarov");
    strcpy(freshman.major, "Computer Science");

    // print the freshman variable
    printStudent(&freshman);

    // print the student variable
    printStudent(&student);

    return 0;
}