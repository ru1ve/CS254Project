//
// Created by fdb22128 on 29/02/2024.
//

#include <stdio.h>
#include <malloc.h>

#include "node.h"
#include "student.h"

void print_List(Node *head)
{
    if(head->value == NULL) //if list is empty
    {
        printf("List is empty!\n");
    }
    else
    {
        while (head != NULL)
        {
            print_student_detail(*head->value);
            head = head->next;
        }
    }

}

Node* new_node(Student* value)
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;

    return node;
}