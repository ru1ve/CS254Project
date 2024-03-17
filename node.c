//
// Created by fdb22128 on 29/02/2024.
//

#include "node.h"


Node* new_node(Student* value)
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;

    return node;
}