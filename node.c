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

Node* new_node_withStudent()
{
    Node *node = malloc(sizeof(Node));
    Student* student = malloc(sizeof(Student));
    set_student(student); // fills struct with data
    node->value = student; // set pointer in node to pointer to struct of student
    node->next = NULL;

    return node;
}

void free_node(Node* node)
{
    if(node->value != NULL)
    {
        free(node->value); // free value first as
    }
    free(node);
}