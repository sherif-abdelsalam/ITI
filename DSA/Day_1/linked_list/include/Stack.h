#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"
#include <iostream>
using namespace std;

class Stack {
private:
    LinkedList *ls;
public:
    Stack() {
        ls = new LinkedList();
    }

    void push(int value) {
        ls->add(value);
    }

    bool pop(int &popped) {
        if (isEmpty()) {
            cout << "Stack is empty! \n";
            return false;
        }
        popped = ls->getDataByIndex(ls->getCount()-1);
        ls->Delete(popped);
        return true;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return ls->getDataByIndex(ls->getCount()-1);
    }
    bool isEmpty() {
        return ls->getCount() == 0;
    }

    void display() {
        ls->Display();
        cout << endl;
    }
};

#endif
