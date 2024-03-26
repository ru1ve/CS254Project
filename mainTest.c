#include <stdio.h>
#include <malloc.h>

#include "student.h"
#include "node.h"
#include "list.h"


int main ()
{
    Student s[4] = {
            {"John", "Smith", "000987654", 23, 1, {.point = 76}},
            {"Sue", "Kensington", "000023489", 19, 2, {.scale = 'F'}},
            {"Mary", "Brown", "001234567", 35, 2, {.scale = 'D'}},
            {"David", "Williams", "090238748", 19, 1, {.point = 35}},
    };


    Node* node1 = new_node(&s[0]);
    Node* node2 = new_node(&s[1]);

    Node** listOfNodes = NULL;
    listOfNodes = &node1;

    insert_node(listOfNodes, node2);

    print_student(*listOfNodes, "000023489");

    change_key(listOfNodes, "000987654", "111111111");

    print_student(*listOfNodes, "111111111");

    remove_node(listOfNodes, "11111111");

    print_student(*listOfNodes, "111111111");


    ///END OF PROGRAM
    remove_all(listOfNodes); // Free memory

    //Using to stop window from closing everytime I run program
    int value;
    scanf( "%d", value );


    return 0;
}
