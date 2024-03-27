//
// Created by fdb22128 on 13/03/2024.
//

#include "list.h"

void print_List(Node* head)
{
    if(head == NULL) //if list is empty
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
    // If list is completely empty and points to NULL
    if(NULL == plist)
    {
        printf("List is Empty can't insert into!\n");
        return;
    }

    if(isExistingID(*plist, newNode->value->studentID)) // Check if student ID already exists in list
    {
        printf("Student ID already exists, not inserted\n");
        free_node(newNode); // frees memory for newNode as can't be used any longer
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
    // If list is empty do nothing but prevent segmentation fault
    if(NULL == plist)
    {
        return;
    }

    Node* iterator = *plist;
    Node* previous = NULL;
    while(iterator != NULL)
    {
        previous = iterator;
        iterator = iterator->next;
        free_node(previous);
    }

    if(previous == NULL)
    {
        free_node(iterator);
    }

}

void remove_node(Node **plist, char id[])
{
    // If list is empty print error and return
    if(NULL == plist)
    {
        printf("List is empty can't change key!\n");
        return;
    }

    //find node
    Node* iterator = *plist;
    Node* previous = NULL;
    while( ( NULL != iterator ) && ( 0 != strcmp(iterator->value->studentID,id) ) && ( strcmp(iterator->value->studentID, id) < 0 ) )
    {
        previous = iterator;
        iterator = iterator->next;
    }

    // Check if next iterator value of id is smaller in ASCII
    // If true id doesn't exist in list
    // Further if iterator is NULL list is empty
    if( NULL == iterator || strcmp(iterator->value->studentID, id) < 0 )
    {
        printf("Id does not exist in list!\n");
        return;
    }
    // if previous is NULL only one item in list no need to repoint
    else if(previous == NULL)
    {

        *plist = iterator->next;
    }
    else //remove node iterator is pointing to
    {
        previous->next = iterator->next;
    }
    free_node(iterator);
}

void print_student(Node* list, char id[])
{
    //find node
    Node* previous = NULL;
    while( ( NULL != list ) && ( 0 != strcmp(list->value->studentID,id) ) && ( strcmp(list->value->studentID, id) < 0 )  )
    {
        previous = list;
        list = list->next;
    }

    // Check if student id has been found
    if( NULL == list )
    {
        printf("Student ID was not found!\n");
    }
    else if(strcmp(list->value->studentID, id) > 0)
    {
        printf("Student ID was not found!\n");
    }
    else if ( 0 == strcmp(list->value->studentID,id) )
    {
        print_student_detail(*list->value);
    }
}

void change_key(Node **plist, char id[], char newid[])
{
    if(NULL == plist)
    {
        printf("List is empty can't change key!\n");
        return;
    }

    // Check if student ID exists
    if (isExistingID(*plist, newid))
    {
        printf("New Student ID already exists in list!\n");
        return;
    }

    Node *iterator = *plist;
    Node *previous = NULL;
    Node *nodeToChange = NULL;

    // Find the node to change
    while (iterator != NULL)
    {
        if (strcmp(iterator->value->studentID, id) == 0)
        {
            nodeToChange = iterator;
            break;
        }
        previous = iterator;
        iterator = iterator->next;
    }

    // Check if student id has been found
    if (nodeToChange == NULL)
    {
        printf("Student ID was not found!\n");
        return;
    }

    // Update the ID
    strcpy(nodeToChange->value->studentID, newid);

    // Remove node from its current position
    if (previous == NULL)
    {
        *plist = nodeToChange->next; // Update head if node was first in the list
    } else
    {
        previous->next = nodeToChange->next;
    }

    // Re-insert node at appropriate position in the list
    // (Assuming the list is sorted by student ID)
    iterator = *plist;
    previous = NULL;
    while (iterator != NULL && strcmp(iterator->value->studentID, newid) < 0)
    {
        previous = iterator;
        iterator = iterator->next;
    }

    if (previous == NULL)
    {
        // Insert at the beginning of the list
        nodeToChange->next = *plist;
        *plist = nodeToChange;
    } else
    {
        // Insert in the middle or at the end of the list
        previous->next = nodeToChange;
        nodeToChange->next = iterator;
    }
}

bool isExistingID(Node* head, char id[])
{
    Node* iterator = head; // reassign to be able to iterate without loosing place
    while(iterator != NULL)
    {
        if(0 == strcmp(iterator->value->studentID, id))
        {
            return true;
        }
        iterator = iterator->next;
    }
    return false;
}