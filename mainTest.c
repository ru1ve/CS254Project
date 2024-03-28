//
// Created by fdb22128 on 22/02/2024.
//

#include <stdio.h>

#include "list.h"

/* !!! THIS IS NO LONGER VALID !!!
 * Note this doesn't compile because of the node_free() method this frees the memory for malloc of both the student struct and node
 * This was not implemented when the mainTest was being used, however the way main.c was designed requires a free() for the student struct
 * In hindsight I should have tested the program using a dynamic array size but due to time constraints I felt it more useful to go straight to proper testing
 * with the UI.
 */

/// FIXED the test program now works as it uses the same create new student method that allocated memory for each student the commented area was previously used

// Renamed to (M)ain temporarily as using CMAKE and is easier to rename rather than un include
int Main()
{
    /*Student* studentArray = malloc(sizeof(Student));
    if (studentArray == NULL)
    {
        printf("Memory allocation failed\n");
        return -9;
    }

    Student s[5] = {
            {"John", "Smith", "987654", 23, 1, {.point = 76}},
            {"Sue", "Kensington", "23489", 19, 2, {.scale = 'F'}},
            {"Mary", "Brown", "1234567", 35, 2, {.scale = 'D'}},
            {"David", "Williams", "090238748", 19, 1, {.point = 35}},
            {"David", "Williams", "090238748", 19, 1, {.point = 35}},
    };

    for (int i = 0; i < 5; i++) {
        strcpy(studentArray[i].fname,s[i].fname);
        strcpy(studentArray[i].lname, s[i].lname);
        strcpy(studentArray[i].studentID, s[i].studentID);
        studentArray[i].age = s[i].age;
        studentArray[i].markType = s[i].markType;
        studentArray[i].mark = s[i].mark;
    }


    Node* node1 = new_node(&studentArray[0]);
    Node* node2 = new_node(&studentArray[1]);
    Node* node3 = new_node(&studentArray[2]);
    Node* node4 = new_node(&studentArray[3]);
    Node* node5 = new_node(&studentArray[4]);

    Node** listOfNodes = NULL;*/

    Node** listOfNodes = NULL;
    Node* newNode = NULL;
    Node* firsNode = NULL;

    /// Test case using an empty list which points to NULL
    /// expected result No crashes + error messages e.g. list empty

    printf("expected List is empty error message no actions: ");
    change_key(listOfNodes, "987654", "111111111"); // expected List is empty error message no actions

    printf("expected List is empty error message no actions: ");
    remove_node(listOfNodes, "987654"); // expected List is empty error message no actions

    printf("No crash also no error message as removing from empty list is empty list: \n");
    remove_all(listOfNodes); // No crash also no error message as removing from empty list is empty list

    /// Test case inserting two different nodes into list
    printf("Can't insert into pointer pointing to NULL should print error message for each: ");
    newNode = new_node_withStudent();
    insert_node(listOfNodes, newNode);// Can't insert into pointer pointing to NULL
    newNode = new_node_withStudent();
    insert_node(listOfNodes, newNode);// Both should print error message and return

    /// Insert two nodes into list
    // Set listOfNodes to memory address of the first node ( Can't be done using insert_node() )
    newNode = new_node_withStudent();
    if(listOfNodes == NULL) // Same as main as listOfNodes is Null
    {
        firsNode = newNode;
        listOfNodes = &firsNode;
    }
    else
    {
        insert_node(listOfNodes, newNode);
    }

    /// Test cases with one Node in list
    /// expected result no crashes error message when using wrong ID

    printf("expected result(s) is error message  x 3 can't find student id: ");
    print_student(*listOfNodes, "23489"); // Student ID doesn't exist in list should cause error
    print_student(*listOfNodes, "000987654"); // Student ID doesn't exist in list error again (id is same but '0' at start
    print_student(*listOfNodes, "0000987654"); // Student ID doesn't exist in list error again ( id is longer than 10 char )

    /// Test cases inserting Nodes that have the same student ID

    printf("Inserting Nodes into list expect error message Student ID already exists: ");
    newNode = new_node_withStudent();
    insert_node(listOfNodes, newNode);
    newNode = new_node_withStudent();
    insert_node(listOfNodes, newNode);
    newNode = new_node_withStudent();
    insert_node(listOfNodes, newNode); // Node5 has the same ID as node4 should return and print error

    printf("Updated list containing 4 nodes: \n");
    print_List(*listOfNodes); // Should print 4 nodes

    /// Test cases changing id and ensuring the correct order

    printf("Updating ID of 090238748 to 999 should put at end of list\n");
    change_key(listOfNodes, "090238748", "999"); // Expect no errors
    print_List(*listOfNodes);

    printf("\nChanging ID of 987654 to 000000 should put at front of list\n");
    change_key(listOfNodes, "987654", "000000"); // No errors expected
    print_List(*listOfNodes);

    remove_all(listOfNodes); // clear all current nodes

    /// Test case listOfNode with empty Head node

    Node* emptyNode = NULL;
    listOfNodes = &emptyNode;

    printf("Printing list with empty head should cause error message: \n");
    print_List(*listOfNodes); // Should print error

    printf("Printing node with empty list should cause error: \n");
    print_student(*listOfNodes, "0");

    ///END OF PROGRAM
    remove_all(listOfNodes); // Free memory

    //Using to stop window from closing everytime I run program
    int value;
    scanf( "%d", value );


    return 0;
}
