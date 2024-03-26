//
// Created by fdb22128 on 22/02/2024.
//

#include <stdio.h>

#include "student.h"
#include "node.h"
#include "list.h"


int main ()
{
    Student s[5] = {
            {"John", "Smith", "987654", 23, 1, {.point = 76}},
            {"Sue", "Kensington", "23489", 19, 2, {.scale = 'F'}},
            {"Mary", "Brown", "1234567", 35, 2, {.scale = 'D'}},
            {"David", "Williams", "090238748", 19, 1, {.point = 35}},
            {"David", "Williams", "090238748", 19, 1, {.point = 35}},
    };


    Node* node1 = new_node(&s[0]);
    Node* node2 = new_node(&s[1]);
    Node* node3 = new_node(&s[2]);
    Node* node4 = new_node(&s[3]);
    Node* node5 = new_node(&s[4]);

    Node** listOfNodes = NULL;
    listOfNodes = &node1;

    insert_node(listOfNodes, node2);

    print_student(*listOfNodes, "23489");

    change_key(listOfNodes, "987654", "111111111");

    print_student(*listOfNodes, "111111111");

    remove_node(listOfNodes, "11111111");

    print_student(*listOfNodes, "111111111");

    remove_node(listOfNodes, "23489");

    print_List(*listOfNodes);

    insert_node(listOfNodes, node3);
    insert_node(listOfNodes, node4);
    insert_node(listOfNodes, node5); // Node5 has the same ID as node4 should return and cause error


    print_List(*listOfNodes);


    ///END OF PROGRAM
    remove_all(listOfNodes); // Free memory

    //Using to stop window from closing everytime I run program
    int value;
    scanf( "%d", value );


    return 0;
}
