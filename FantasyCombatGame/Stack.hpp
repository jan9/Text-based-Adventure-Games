/*********************************************************************
 ** Filename: Stack.hpp
 ** Author: Ju Hye An
 ** Date: 11/21/16
 ** Description: This is a Stack class declaration file.
 *********************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#include <cstdlib>
#include <iostream>
#include "Creature.hpp"
using std::cin;
using std::cout;
using std::endl;

class Stack {
    
protected:
    struct StackNode {
        Creature* ptrToCreature;
        StackNode * next;
        StackNode(Creature*c1, StackNode* next1 = NULL ) {
            ptrToCreature = c1;
            next = next1;
        }
    };
    StackNode * top;
    
public:
    Stack();
    ~Stack();
    void push(Creature*);
    void pop();
    void print();
    
    
    
};

#endif
