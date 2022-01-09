#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Employee {
    char name[50]; // 50 is the size of the array
    char team[50];  // 50 is the size of the array
    int age;
    double salary;
};


// create a function that prints a Employee instance
void printEmployeeByPassingPointer(struct Employee *e) {
    printf("Name: %s\n", e->name);
    printf("Team: %s\n", e->team);
    printf("Age: %d\n", e->age);
    printf("Salary: %.2f\n", e->salary);
}

// create a function that prints a Employee instance by passing the struct by value
void printEmployeeByPassingValue(struct Employee e) {
    printf("Name: %s\n", e.name);
    printf("Team: %s\n", e.team);
    printf("Age: %d\n", e.age);
    printf("Salary: %.2f\n", e.salary);
}


int main() {

    // create a student variable with struct type Student
    struct Employee employee;

    // assign values to the student variable
    employee.age = 31;
    employee.salary = 140.0;
    strcpy(employee.name, "John Doe");
    strcpy(employee.team, "Google Brain");

    // print the student variable
    
    printEmployeeByPassingPointer(&employee);
    printEmployeeByPassingValue(employee);

    return 0;
}