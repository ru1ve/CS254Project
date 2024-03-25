#include <stdio.h>
#include <malloc.h>

#include "student.h"
#include "node.h"
#include "list.h"


int main ()
{
    Student s[4] = {
            {"John", "Smith", "00987654", 23, 1, {.point = 76}},
            {"Sue", "Kensington", "23489", 19, 2, {.scale = 'F'}},
            {"Mary", "Brown", "01234567", 35, 2, {.scale = 'D'}},
            {"David", "Williams", "90238748", 19, 1, {.point = 35}},
    };


    Node* node1 = new_node(&s[0]);
    Node* node2 = new_node(&s[1]);

    Node** listOfNodes = NULL;
    listOfNodes = &node1;

    insert_node(listOfNodes, node2);

    //(*listOfNodes)->value = &s[1];

    //print_student_detail(*(*listOfNodes)->value);

    //Using to stop window from closing everytime I run program

    remove_all(listOfNodes);

    int value;
    scanf( "%d", value );


    return 0;
}
