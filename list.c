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

    if(isExistingID(*plist, newNode->value->studentID)) // Check if student ID already exists in list
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
    // Check if student ID exists
    if(isExistingID(*plist, newid))
    {
        printf("New Student ID already exists in list!");
        return;
    }

    //find node
    Node* iterator = *plist;
    Node* previous = NULL;
    Node* iteratorOldId = NULL;
    Node* previousOldId = NULL;
    Node* iteratorNewId = NULL;
    Node* previousNewId = NULL;
    while((NULL != iterator ) && ( 0 != strcmp( iterator->value->studentID, id) ) && ( strcmp( iterator->value->studentID, id) < 0 ))
    {
        if(strcmp(iterator->value->studentID, id) <= 0 && (NULL == previous || strcmp(previous->value->studentID, id) > 0))
        {
            iteratorOldId = iterator;
            previousOldId = previous;
        }

        if(strcmp(iterator->value->studentID, newid) <= 0 && (NULL == previous || strcmp(previous->value->studentID, newid) > 0))
        {
            iteratorNewId = iterator;
            previousNewId = previous;
        }

        previous = iterator;
        iterator = iterator->next;
    }

    // Check if student id has been found
    if( NULL == iteratorOldId || strcmp( iteratorOldId->value->studentID, id) > 0)
    {
        printf("Student ID was not found!\n");
    }
    else if ( 0 == strcmp( iteratorOldId->value->studentID, id) )
    {
        // replace new ID in list
        strcpy( iteratorOldId->value->studentID, newid);
        // remove node from list and store
        Node* tempHolder = NULL;

        if(NULL == previousOldId)
        {
            tempHolder = iteratorOldId;
            *plist = iteratorOldId->next;
        }
        else
        {
            tempHolder = iteratorOldId;
            previousOldId->next = iteratorOldId->next;
        }

        if( previousNewId == NULL) // at start of list
        {
            tempHolder->next = *plist;
            *plist = tempHolder;
        }
        else // is in middle or end of list
        {
            previousNewId->next = tempHolder;
            tempHolder->next = iteratorNewId;
        }
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