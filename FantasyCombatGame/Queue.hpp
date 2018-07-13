/*********************************************************************
 ** Filename: Queue.hpp
 ** Author: Ju Hye An
 ** Date: 11/21/16
 ** Description: This is a Queue class declaration file.
 *********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstdlib>
#include <iostream>
#include "Creature.hpp"
using std::cin;
using std::cout;
using std::endl;

class Queue {
    
protected:
    struct QueueNode {
        Creature* ptrToCreature;
        QueueNode * next;
        QueueNode * previous;
        QueueNode(Creature* creature1, QueueNode * next1 = NULL, QueueNode * prev1 = NULL) {
            ptrToCreature = creature1;
            next = next1;
            previous = prev1;
            
        }
    };
    QueueNode * front;
    QueueNode * back;
    
public:
    bool isEmpty();
    Queue();
    ~Queue();
    void push(Creature*);
    Creature* pop();
    void print();
};


#endif
