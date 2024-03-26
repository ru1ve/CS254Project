//
// Created by fdb22128 on 22/02/2024.
//

#include <stdio.h>

#include "utils.h"

#ifndef UNTITLED1_STUDENT_H
#define UNTITLED1_STUDENT_H

/// Used enum to define type of mark used in student
/// Using enum instead of preprocessor as it is safer
enum markType{
    ePOINT_TYPE = 1,
    eSCALE_TYPE = 2
};

union mark{
    int point;
    char scale;
};

struct STUDENT{
    char fname[51]; //first name of student 51 leaving space for null terminator
    char lname[51]; //last name of student 51 leaving space for null terminator
    char studentID[10]; //studentID of student 10 leaving space for null terminator
    int age;
    enum markType markType; // enum value of mark type point/scale
    union mark mark; // union to store mark
};

/// typedef to simplify struct usage
typedef struct STUDENT Student;

/// Prompts user for student information and fills student struct
/// \return returns struct of student
Student set_student();

///
/// \param student
void print_student_detail(Student student);

#endif //UNTITLED1_STUDENT_H
