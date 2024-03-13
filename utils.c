//
// Created by fdb22128 on 22/02/2024.
//
#include <stdio.h>

/// Helper file with various useful standard methods


/// Function to get integer and not char or charArray
/// \param message to display to user
/// \param value pointer to variable of the output
void getValidInt ( char* message, int* value )
{
    printf( "%s", message );
    int retVal = 0;
    while ( retVal != 1 )
    {
        retVal = scanf( "%d", value );
        if(retVal == 0)
        {
            printf("Invalid input!\n");
            printf( "%s", message );
            while(getchar() != '\n');
        }
        else
        {
            break;
        }
    }
}