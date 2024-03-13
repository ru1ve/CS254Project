//
// Created by fdb22128 on 22/02/2024.
//

#include <stdio.h>

#include "student.h"
#include "utils.c"

Student set_student ()
{
    Student result;

    printf( "What is your first name? " );
    scanf( " %50s", result.fname );
    while ((getchar() != '\n'));

    printf( "What is your last name? ");
    scanf( " %50s", result.lname );
    while ((getchar() != '\n'));

    printf("What is the student ID? ");
    scanf( " %9s", result.studentID );
    while ((getchar() != '\n'));

    do
    {
        getValidInt("Enter the students age: ", &result.age);
        if ( result.age < 0 )
        {
            printf( "Invalid input!\n" );
            result.age = -1;
        }
    } while ( result.age < 0 );

    char charInputted;
    do
    {
        printf("What type of mark will you use (P)oint or (S)cale: ");
        scanf(" %c", &charInputted);
        if(charInputted != 'P' && charInputted != 'S')
        {
            printf( "Invalid input!\n" );
        }
    }while( charInputted != 'P' && charInputted != 'S');
    /// If the char inputted is p it's point type else it's a scale type
    /// Get input according to point or scale
    if(charInputted == 'P')
    {
        result.markType = ePOINT_TYPE;
        do
        {
            getValidInt( "Please enter a numeric mark: ", &( result.mark.point ));
            if( result.mark.point > 100 || result.mark.point < 0)
            {
                printf( "Invalid input!\n" );
            }
        }while(result.mark.point > 100 || result.mark.point < 0);
    }else
    {
        result.markType = eSCALE_TYPE;
        do
        {
            printf("Please enter a alphabetic mark: ");
            scanf(" %c", &(result.mark.scale));
            if( (result.mark.scale < 65 || result.mark.scale > 68 ) && result.mark.scale != 70)
            {
                printf( "Invalid input!\n" );
            }
        }while((result.mark.scale < 65 || result.mark.scale > 68 ) && result.mark.scale != 70);
    }
    while ((getchar() != '\n'));
    return result;
}

void print_student_detail(Student student)
{
    char* gradeResult = "Pass";
    if(student.markType == ePOINT_TYPE)
    {
        if(student.mark.point < 40)
        {
            gradeResult = "Fail";
        }
        printf("%s, %s, %s, %d, %d, %s\n", student.studentID, student.fname, student.lname, student.age, student.mark.point, gradeResult);
    }
    else //markType == eSCALE_TYPE
    {
        if(student.mark.scale == 70 )
        {
            gradeResult = "Fail";
        }
        printf("%s, %s, %s, %d, %c, %s\n", student.studentID, student.fname, student.lname, student.age, student.mark.scale, gradeResult);
    }
}
