/*********************************************************************
 ** Filename: Queue.cpp
 ** Author: Ju Hye An
 ** Date: 11/21/16
 ** Description: This is a Queue class implementation file.
 *********************************************************************/

#include "Queue.hpp"

/*********************************************************************
 ** Member Function: Queue()
 ** Description: This is a Queue object constructor. It sets NULL ptr to
 the front and back
 ** Parameters: n/a
 *********************************************************************/
Queue::Queue() {
    
    front = NULL;
    back = NULL;
    
}

/*********************************************************************
 ** Member Function: ~Queue
 ** Description: This is a desctructor. It deallocates unwanted memory.
 ** Parameters: n/a
 *********************************************************************/
Queue::~Queue() {
    
    if (front == NULL) {
        return;
    }
    
    while (front != NULL) {
        if (front == back) {
            QueueNode *temp = front;
            delete front->ptrToCreature;
            front = NULL;
            back = NULL;
            delete temp;
            temp = NULL;
            
        }
        
        else {
            QueueNode *temp = front;
            delete (front->ptrToCreature);
            front = front->previous;
            front->next = NULL;
            temp->previous= NULL;
            delete temp;
            temp = NULL;
            
        }
    }
}


/*********************************************************************
 ** Member Function: Queue::push()
 ** Description: This function creates a new Linked Node and adds it 
 ** to the Queue.
 ** Parameters: Creature* c1
 *********************************************************************/
void Queue::push(Creature* c1) {
    
    if (front == NULL && back == NULL) {
        QueueNode *ptr = new QueueNode(c1);
        back = ptr;
        front = ptr;
        ptr = NULL;
        
    }
    
    else {
        QueueNode * ptr = new QueueNode(c1, back, NULL);
        back->previous = ptr;
        back = ptr;
        ptr = NULL;
    }
    
}


/*********************************************************************
 ** Member Function: pop()
 ** Description: This function deletes the first Node added in the push() 
 ** function. The queue contains one less node and the function returns the
 ** Creature pointer in the deleted node.
 ** Parameters: n/a
 *********************************************************************/
Creature* Queue::pop() {
    
    if (front == NULL) {
        cout << "Nothing to remove!" << endl;
        return NULL;
    }
    
    else if (front == back) {
        QueueNode *temp = front;
        Creature* removedCreature = (front->ptrToCreature) ;
        front = NULL;
        back = NULL;
        delete temp;
        return removedCreature;
        
    }
    
    else {
        QueueNode *temp = front;
        Creature* removedCreature = (front->ptrToCreature);
        front = front->previous;
        front->next = NULL;
        temp->previous = NULL;
        delete temp;
        temp = NULL;
        return removedCreature;
        
    }
    
    return 0;
}


/*********************************************************************
 ** Member Function: print()
 ** Description: This function displays the Creature pointers in each 
 ** node of the queue without deleting them, allowing the user
 ** to "peak" at the queue.
 ** Parameters: n/a
 *********************************************************************/
void Queue::print() {
    
    if (front == NULL) {
        cout << "No players are left!" << endl;
    }
    
    QueueNode * nodePtr = back;
    
    while (nodePtr != NULL) {
        cout << (nodePtr->ptrToCreature)->getName() << " ";
        cout << (nodePtr->ptrToCreature)->getType() << " " << endl;
        nodePtr = nodePtr->next;
    }
    
    nodePtr = NULL;
    
    
}


/*********************************************************************
 ** Member Function: isEmpty()
 ** Description: This function validates whether the Queue is empty and returns the
 **		corresponding bool value.
 ** Parameters: n/a
 *********************************************************************/
bool Queue ::isEmpty() {
    
    if ((front == NULL) && (back == NULL)) {
        return true;
    }
    else {
        return false;
    }
    
}
