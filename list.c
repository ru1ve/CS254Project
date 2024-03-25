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
    Node* previous = NULL;
    while(iterator != NULL)
    {
        previous = iterator;
        iterator = iterator->next;
        free(previous);
    }
    if(previous != NULL)
    {
        free(iterator);
    }

}

void remove_node(Node **plist, char id[])
{
    //find node
    Node* iterator = *plist;
    Node* previous = NULL;
    while( ( iterator->value->studentID != id ) && ( strcmp(iterator->value->studentID, id) < 0 ) && ( NULL != iterator ) )
    {
        previous = iterator;
        iterator = iterator->next;
    }

    // Check if next iterator value of id is smaller in ASCII
    // If true id doesn't exist in list
    // Further if iterator is NULL list is empty
    if(strcmp(iterator->value->studentID, id) < 0 || NULL == iterator )
    {
        printf("Id does not exist in list!\n");
        return;
    }
    // if previous is NULL only one item in list no need to repoint
    else if(previous == NULL)
    {
        free(iterator);
        return;
    }
    //else remove node iterator is pointing to
    previous->next = iterator->next;
    free(iterator);
}

void print_student(Node* list, char id[])
{
    //find node
    Node* previous = NULL;
    while( ( list->value->studentID != id ) && ( strcmp(list->value->studentID, id) < 0 ) && ( NULL != list ) )
    {
        previous = list;
        list = list->next;
    }

    // Check if student id has been found
    if(list->value->studentID != id )
    {
        print_student_detail(*list->value);
    }
    else // Student ID not found
    {
        printf("Student ID was not found!\n");
    }
}

void change_key(Node **plist, char id[], char newid[])
{
    //find node
    Node* iterator = *plist;
    Node* previous = NULL;
    while( ( iterator->value->studentID != id ) && ( strcmp(iterator->value->studentID, id) < 0 ) && ( NULL != iterator ) )
    {
        previous = iterator;
        iterator = iterator->next;
    }

    // Check if student id has been found
    if(iterator->value->studentID != id )
    {
        //iterator->value->studentID = newid;
    }
    else // Student ID not found
    {
        printf("Student ID was not found!\n");
    }
}

bool isExistingID(Node* head, const Node* newNode)
{
    Node* iterator = head; // reassign to be able to iterate without loosing place
    while(iterator != NULL)
    {
        if(0 == strcmp(iterator->value->studentID, newNode->value->studentID))
        {
            return true;
        }
    }
    return false;
}