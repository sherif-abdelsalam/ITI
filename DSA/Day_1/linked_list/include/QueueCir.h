#ifndef QUEUECIR_H
#define QUEUECIR_H

#include <iostream>
using namespace std;

class QueueCir {
private:
    int *Q;
    int size;
    int Head, Tail;
public:
    QueueCir(int size = 5) {
        this->size = size;
        Q = new int[size];
        Head = Tail = -1;
    }


    void EnQueue(int value) {
        if (IsFull()) {
            cout << "Queue is Full\n";
            return;
        }

        if (Head == -1) {
            Head = Tail = 0;
        }
        else {
            Tail = (Tail + 1) % size;
        }

        Q[Tail] = value;
    }

    bool DeQueue(int &val) {
        if (IsEmpty()) {
            cout << "Queue is Empty\n";
            return false;
        }

        val = Q[Head];
        if (Head == Tail) {
            Head = Tail = -1;
        }
        else {
            Head = (Head + 1) % size;
        }

        return true;
    }

    int Front() {
        return !IsEmpty() ? Q[Head] : -1;
    }

     bool IsEmpty() { return Head == -1; }

    bool IsFull() {
        return (Head == 0 && Tail == size - 1) || (Tail + 1 == Head);
    }

    void Print() {
        if (IsEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        int i = Head;
        while (true) {
            cout << Q[i] << " ";
            if (i == Tail) break;
            i = (i + 1) % size;
        }

        cout << "\n";
    }

    ~QueueCir() {
        delete[] Q;
    }
};

#endif
