#include <iostream>
using namespace std;

class QueueShift {
private:
    int *Q;
    int size;
    int Head, Tail;

public:
    QueueShift(int size = 5) {
        this->size = size;
        Q = new int[size];
        Head = 0;
        Tail = 0;
        cout<<"Constructor called"<<endl;
    }

    ~QueueShift() {
        delete[] Q;
    }

    bool IsEmpty() {
        return Tail == 0;
    }

    bool IsFull() {
        return Tail == size;
    }

    void EnQueue(int value) {
        if (IsFull()) {
            cout << "Queue is full\n";
            return;
        }
        Q[Tail++] = value;
    }

    int DeQueue() {
        if (IsEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        int value = Q[0];
        for (int i = 1; i < Tail; i++)
            Q[i - 1] = Q[i];

        Tail--;
        return value;
    }

    void Print() {
        for (int i = 0; i < Tail; i++)
            cout << Q[i] << " ";
        cout << "\n";
    }
};


class QueueCir {
private:
    int *Q;
    int size;
    int Head, Tail;

public:
    QueueCir() {
        size = 5;
        Q = new int[size];
        Head = Tail = 0;
    }

    QueueCir(int size) {
        this->size = size;
        Q = new int[this->size];
        Head = Tail = 0;
    }

    bool IsEmpty() { return Head == Tail; }
    bool IsFull()  { return (Tail + 1) % size == Head; }

    void EnQueue(int value) {
        if (IsFull()) {
            cout << "Queue is Full\n";
            return;
        }
        Q[Tail] = value;
        Tail = (Tail + 1) % size;
    }

    int DeQueue() {
        if (IsEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        int value = Q[Head];
        Head = (Head + 1) % size;
        return value;
    }

    void Print() {
        int i = Head;
        cout<<"Queue Elements: ";
        while (i != Tail) {
            cout << Q[i] << " ";
            i = (i + 1) % size;
        }
        cout << "\n";
    }

    ~QueueCir() { delete[] Q;}

};
/// 10 20 30 ---
/// h         t

int main()
{

    /// circular
    QueueCir qc(5);

    qc.EnQueue(10);
    qc.EnQueue(20);
    qc.EnQueue(30);

    qc.Print();

    cout << "DeQueue = " << qc.DeQueue() << "\n";
    cout << "DeQueue = " << qc.DeQueue() << "\n";
//    cout << "DeQueue = " << qc.DeQueue() << "\n";
//    cout << "DeQueue = " << qc.DeQueue() << "\n";
//    cout << "DeQueue = " << qc.DeQueue() << "\n";

    qc.Print();

    qc.EnQueue(40);
    qc.EnQueue(50);
    qc.Print();
    qc.EnQueue(60);
    qc.EnQueue(100);
    qc.Print();


    cout<<"====================================\n";
    /// shifting
    QueueCir qs(5);

    qs.EnQueue(10);
    qs.EnQueue(20);
    qs.EnQueue(30);

    qs.Print();

    cout << "DeQueue = " << qs.DeQueue() << "\n";
    cout << "DeQueue = " << qs.DeQueue() << "\n";
//    cout << "DeQueue = " << qs.DeQueue() << "\n";
//    cout << "DeQueue = " << qs.DeQueue() << "\n";
//    cout << "DeQueue = " << qs.DeQueue() << "\n";

    qs.Print();

    qs.EnQueue(40);
    qs.EnQueue(50);
    qs.Print();
    qs.EnQueue(60);
    qs.EnQueue(100);
    qs.Print();

    return 0;
}
