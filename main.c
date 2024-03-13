#include <stdio.h>
#include <malloc.h>

#include "student.h"
#include "node.h"

int main ()
{
    Student s[4] = {
            {"John", "Smith", "00987654", 23, 1, {.point = 76}},
            {"Sue", "Kensington", "23489", 19, 2, {.scale = 'F'}},
            {"Mary", "Brown", "01234567", 35, 2, {.scale = 'D'}},
            {"David", "Williams", "90238748", 19, 1, {.point = 35}},
    };

    Node *empty = new_node(NULL);
    print_List( empty);
    free(empty);

    Node *student1 = new_node(&s[0]);
    Node *student2 = new_node(&s[1]);
    Node *student3 = new_node(&s[2]);
    Node *student4 = new_node(&s[3]);

    student1->next = student2;
    student2->next = student3;
    student3->next = student4;

    print_List(student1);

    set_student();

    free(student1);
    free(student2);
    free(student3);
    free(student4);


    return 0;
}
