//
// Created by fdb22128 on 13/03/2024.
//

#include <string.h>
#include <stdbool.h>

#include "node.h"

#ifndef UNTITLED1_LIST_H
#define UNTITLED1_LIST_H

/// print all student records in list
/// \param head pointer to the start of the list
void print_List(Node* head);

/// insert a node in order
/// \param plist pointer to list
/// \param newNode pointer to new node
void insert_node(Node **plist, Node *newNode);

/// remove all nodes and clear memory
/// \param plist
void remove_all(Node **plist);

/// Method to remove student with specific id
/// \param plist pointer to list to remove
/// \param id id of the student to remove
void remove_node(Node **plist, char id[]);

/// Method that finds student in list and prints it using student method
/// \param list list of students
/// \param id id of the student to print
void print_student(Node *list, char id[]);

/// Replaces key of Node with key provided then reorders list
/// Decided not to just use remove node copy it to a new node and then insert
/// This would have been easier but less efficient as the method would be copying
/// \param plist list of Nodes
/// \param id old id that Node currently has
/// \param newid to change node to
void change_key(Node **plist, char id[], char newid[]);

// Helper methods

/// checks if student id in Node exists in list
/// \param head list to iterate over
/// \param newNode newNode to check studentId for
/// \return true if id exists in list
bool isExistingID(Node* head, char id[]);



#endif //UNTITLED1_LIST_H
