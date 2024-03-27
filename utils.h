//
// Created by fdb22128 on 28/02/2024.
//

#include <stdio.h>

#ifndef UNTITLED1_UTILS_H
#define UNTITLED1_UTILS_H

/// Function to get integer and not char or charArray
/// \param message to display to user
/// \param value pointer to variable of the output
void getValidInt ( char* message, int* value );

/// Function to essentially get string of length 9 with \0 clears buffer after
/// \param message
/// \param value
void getValidID( const char* message, char* value);

#endif //UNTITLED1_UTILS_H
