//
// Created by fdb22128 on 13/03/2024.
//

#include "list.h"

void print_List(Node* head)
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

void insert_node(Node** plist, Node* newNode)
{
    if(isExistingID(*plist, newNode)) // Check if student ID already exists in list
    {
        printf("Student ID already exists, not inserted");
        free(newNode); // frees memory for newNode as can't be used any more
        return;
    }

    Node* iterator = *plist;
    Node* previous = NULL;
    int comparatorResult;
    while(iterator != NULL && strcmp(iterator->value->studentID, newNode->value->studentID) < 0)
    {
        previous = iterator;
        iterator = iterator->next;
    }

    if( previous == NULL) // at start of list
    {
        newNode->next = *plist;
        *plist = newNode;
    }
    else // is in middle or end of list
    {
        previous->next = newNode;
        newNode->next = iterator;
    }
}

void remove_all(Node **plist)
{
    Node* iterator = *plist;
    while(iterator != NULL)
    {
        iterator = iterator->next;
    }
}

void remove_node(Node **plist, char id[])
{

}

void print_student(Node *list, char id[])
{

}

void change_key(Node **plist, char id[], char newid[])
{

}

bool isExistingID(const Node* head, const Node* newNode)
{
    Node* iterator = head; // reassign to be able to modify pointer
    while(head != NULL)
    {
        if(iterator->value->studentID == newNode->value->studentID)
        {
            return true;
        }
    }
    return false;
}