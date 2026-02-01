#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"
#include <iostream>
using namespace std;

class Queue {
private:
    LinkedList *ls;

    bool isEmpty() { return ls->getCount() == 0; }

public:
    Queue() {
        ls = new LinkedList();
    }

    void Enqueue(int value) {
        ls->add(value);
    }

    bool Dequeue(int &val) {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return false;
        }

        val = ls->getDataByIndex(0);
        ls->Delete(val);
        return true;
    }

    int Front() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return ls->getDataByIndex(0);
    }


    void Display() {
        ls->Display();
        cout << endl;
    }
};

#endif
