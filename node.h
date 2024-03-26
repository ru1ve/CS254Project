//
// Created by fdb22128 on 29/02/2024.
//

#include <stdio.h>
#include <malloc.h>

#include "student.h"

#ifndef UNTITLED1_NODE_H
#define UNTITLED1_NODE_H



struct NODE {
    Student* value;
    struct NODE* next;
};

typedef struct NODE Node;

/// Function to allocate to simplify creating new node
/// \param value student struct
/// \return newly created node pointer
Node* new_node(Student* value);

#endif //UNTITLED1_NODE_H
