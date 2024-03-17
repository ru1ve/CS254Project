//
// Created by fdb22128 on 13/03/2024.
//
#include <string.h>
#include <stdbool.h>

#include "node.h"

#ifndef UNTITLED1_LIST_H
#define UNTITLED1_LIST_H

void print_List(Node* head);

void insert_node(Node **plist, Node *newNode);

void remove_all(Node **plist);

void remove_node(Node **plist, char id[]);

void print_student(Node *list, char id[]);

void change_key(Node **plist, char id[], char newid[]);

// Helper methods

bool isExistingID(const Node* head, const Node* newNode);

#endif //UNTITLED1_LIST_H
