/*********************************************************************
 ** Filename: Stack.cpp
 ** Author: Ju Hye An
 ** Date: 11/21/16
 ** Description: This is a Stack class implementation file.
 *********************************************************************/

#include "Stack.hpp"

/*********************************************************************
 ** Function: Stack::Stack()
 ** Description: Constructs a new Stack object.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: top pointer is set to NULL
 *********************************************************************/
Stack::Stack() {
    
    top = NULL;
    
}


/*********************************************************************
 ** Function: Stack::~Stack()
 ** Description: Destructor for a Stack object.
 ** Parameters: none
 ** Pre-Conditions: Called when the Stack is destroyed
 ** Post-Conditions: none
 *********************************************************************/
Stack::~Stack() {
    if (top != NULL) {
        
        
        while (top->next != NULL) {
            StackNode *newPtr = top;
            delete (top->ptrToCreature);
            top = top->next;
            newPtr->next = NULL;
            delete newPtr;
            newPtr = NULL;
        }
        delete (top->ptrToCreature);
        delete top;
        top = NULL;
        
        
    }
}

/*********************************************************************
 ** Function: Stack::push()
 ** Description: Adds a new StackNode containing Creature to the top of
 **              the Stack.
 ** Parameters: Creature* c1
 ** Pre-Conditions: A number input by the user is passed into this 
 **                 function from main.
 ** Post-Conditions: The Stack continues an additional node.
 *********************************************************************/
void Stack::push(Creature* c1) {
    
    if (top == NULL) {
        StackNode *temp = new StackNode(c1);
        top = temp;
        temp = NULL;
        
    }
    
    else {
        StackNode *temp = new StackNode(c1, top);
        top = temp;
        temp = NULL;
    }
    
}

/*********************************************************************
 ** Function: Stack::pop()
 ** Description: This function deletes the last Node added in 
 **               the add function.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: The stack contains one less node and the function 
 **                  returns the integer value contained in the deleted node.
 *********************************************************************/
void Stack::pop() {
    
    if (top == NULL) {
        cout << "Not applicable!" << endl;
        
    }
    
    else if (top->next == NULL) {
        string removedCreature = (top->ptrToCreature)->getName();
        cout << removedCreature << " ";
        string removedCreatureType = (top->ptrToCreature)->getType();
        cout << removedCreatureType << " " << endl;
        delete (top->ptrToCreature);
        delete top;
        top = NULL;
        
    }
    
    else {
        StackNode *remove = top;
        string removedCreature = (top->ptrToCreature)->getName();
        cout << removedCreature	<< " ";
        string removedCreatureType = (top->ptrToCreature)->getType();
        cout << removedCreatureType << " " << endl;
        delete (top->ptrToCreature);
        top = top->next;
        remove->next = NULL;
        delete remove;
        remove = NULL;
        
    }
}

/*********************************************************************
 ** Function: Stack::print()
 ** Description: This function displays the integers in each node of 
 **              the Stack at the time it is called.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions:none
 *********************************************************************/
void Stack::print() {
    
    if (top == NULL) {
        cout << "Nothing to display!" << endl;
    }
    
    StackNode * nodePtr = top;
    
    while (nodePtr != NULL) {
        cout << (nodePtr->ptrToCreature)->getName() << " ";
        cout << (nodePtr->ptrToCreature)->getType() << " " << endl;
        nodePtr = nodePtr->next;
    }
    
    delete (nodePtr);
    nodePtr = NULL;
}
