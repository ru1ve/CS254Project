//
// Created by fdb22128 on 22/03/2024.
//

#include "list.h"

/// Purpose of the enum is it is simple to keep track of what the program is intending to do while Debugging
enum state
{
    eQUIT = 0,
    eADDNEWSTUDENT,
    eREMOVESTUDENT,
    ePRINTSTUDENT,
    eCHANGESTUDENT,
    ePRINTLIST,
    eREMOVELIST,
    eGETUSERINPUT = 7,
};

int main()
{
    const char* userMessage = "\nChoose an option:\n 1. Add a new student record\n 2. Remove a student\n 3. Print a student record with a given id\n 4. Change a student ID\n 5. Print all student record\n 6. Remove all student records\n\n 0. Quit\n";
    // Initialise variables for state machine
    bool keepLooping = true;
    enum state programState = 7;
    int reassignToState = 0;
    // Initialise for data handling
    Node** listOfNodes = NULL;
    Node* newNode = NULL;
    Node* firsNode = NULL;
    char tempID[10]; // Doesn't need to be initialised
    char tempNewID[10];
    while(keepLooping)
    {
        // State machine to go through states of program
        // After every state other than getuserinput or quit return to state eGETUSERINPUT
        switch ( programState )
        {
            case eGETUSERINPUT:
                getValidInt(userMessage, &reassignToState);
                programState = reassignToState;
                break;
            case eADDNEWSTUDENT:
                newNode = new_node_withStudent();
                if(listOfNodes == NULL)
                {
                    firsNode = newNode;
                    listOfNodes = &firsNode;
                }
                else
                {
                    insert_node(listOfNodes, newNode);
                }
                programState = eGETUSERINPUT;
                break;
            case eREMOVESTUDENT:
                getValidID("Enter the id of student to remove: ", tempID);
                remove_node(listOfNodes, tempID);
                programState = eGETUSERINPUT;
                break;
            case ePRINTSTUDENT:
                if(listOfNodes == NULL)
                {
                    printf("List is empty!\n");
                }
                else
                {
                    getValidID("Enter the id of student to print: ", tempID);
                    print_student(*listOfNodes, tempID);
                }
                programState = eGETUSERINPUT;
                break;
            case eCHANGESTUDENT:
                getValidID("Enter the id to change: ", tempID);
                getValidID("Enter the id to update the student to: ", tempNewID);
                change_key(listOfNodes, tempID, tempNewID);
                programState = eGETUSERINPUT;
                break;
            case ePRINTLIST:
                if(listOfNodes == NULL)
                {
                    printf("List is empty!\n");
                }
                else
                {
                    print_List( *listOfNodes );
                }
                programState = eGETUSERINPUT;
                break;
            case eREMOVELIST:
                remove_all(listOfNodes);
                listOfNodes = NULL;
                firsNode = NULL;
                programState = eGETUSERINPUT;
                break;
            case eQUIT: // exit program
                remove_all(listOfNodes); // free all memory allocated
                keepLooping = false;
                break;
        }
    }
}