#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "QueueCir.h"
#include "StackArr.h"
using namespace std;

void ReverseQueue(QueueCir &q) {
    Stack s;
    while (!q.IsEmpty()) {
        int x;
        q.DeQueue(x);
        s.push(x);
    }

    while (!s.isEmpty()) {
        int x;
        s.pop(x);
        q.EnQueue(x);
    }
}

void LinkedListMain()
{
    LinkedList *ls = new LinkedList();

    ls->add(33);
    ls->add(24);
    ls->add(10);
    ls->add(3);
    ls->add(9);
    ls->add(12);

    cout << "\nList: ";
    ls->Display();
    cout<<"\n=================================\n";

    ls->insertAfter(60,30);
    ls->Display();
    cout<<"\n--------\n";
    ls->insertAfter(20,30);
    ls->Display();

    cout<<"\n=================================\n\n";

    ls->insertBefore(44,10);
    ls->Display();
    cout<<"\n--------\n";

    ls->insertBefore(55,60);
    ls->Display();
    cout<<"\n--------\n";
    cout<<"\n=================================\n\n";

    cout << "\nList Count: "<< ls->getCount();
    cout<<"\n=================================\n\n";

    cout << "\nGet Data By Index: "<< ls->getDataByIndex(4);
    cout<<"\n=================================\n\n";


    LinkedList* reversedList = ls->ReversInAnewList();
    cout << "\nReverse in a new one : ";
    reversedList->Display();
    cout<<"\n=================================\n\n";


    ls->ReverseInPlace();
    cout << "\nReverse In Place : ";
    ls->Display();
    cout << endl;


    cout<<"\n=================================\n\n";
    cout<<"Delete Kth Node: ";
    ls->removeKthNode(2);
    ls->Display();
    cout << endl;
}


void StackMain()
{
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Stack elements: ";
    st.display();

    cout << "Top = " << st.top() << endl;
    int poppedVal;
    if(st.pop(poppedVal))
        cout << "Pooped val: " << poppedVal << endl;
    if(st.pop(poppedVal))
        cout << "Pooped val: " << poppedVal << endl;
    if(st.pop(poppedVal))
        cout << "Pooped val: " << poppedVal << endl;
    if(st.pop(poppedVal))
        cout << "Pooped val: " << poppedVal << endl;

    st.push(99);
    cout << "After push 99: ";
    st.display();

    cout << "Top = " << st.top() << endl;
}


void QueueMain()
{
    Queue q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    cout << "Queue elements: ";
    q.Display();
//    cout << "Queue elements Reversed: ";
//    q.Display();

    cout << "Front = " << q.Front() << endl;

    int val;
    if (q.Dequeue(val))
        cout << "Dequeued val: " << val << endl;

    if (q.Dequeue(val))
        cout << "Dequeued val: " << val << endl;

    if (q.Dequeue(val))
        cout << "Dequeued val: " << val << endl;

    if (q.Dequeue(val))
        cout << "Dequeued val: " << val << endl;

    q.Enqueue(44);
    q.Display();

    cout << "Front = " << q.Front() << endl;
}

void QueueCirMain()
{
    QueueCir q;

    q.EnQueue(10);
    q.EnQueue(20);
    q.EnQueue(30);
    q.EnQueue(40);
    q.EnQueue(50);
    q.EnQueue(60);

    cout << "Queue elements: ";
    q.Print();

    cout << "Front = " << q.Front() << endl;

    int val;
    if (q.DeQueue(val))
        cout << "Dequeued val: " << val << endl;

    if (q.DeQueue(val))
        cout << "Dequeued val: " << val << endl;

    if (q.DeQueue(val))
        cout << "Dequeued val: " << val << endl;

    if (q.DeQueue(val))
        cout << "Dequeued val: " << val << endl;

    if (q.DeQueue(val))
        cout << "Dequeued val: " << val << endl;

    if (q.DeQueue(val))
        cout << "Dequeued val: " << val << endl;

    q.EnQueue(44);
    q.Print();
}


void QueueReverseMain(){

    QueueCir qc;
    qc.EnQueue(1);
    qc.EnQueue(2);
    qc.EnQueue(3);
    qc.EnQueue(4);
    qc.EnQueue(8);

    qc.Print();
    ReverseQueue(qc);
    qc.Print();
}

void NextGreateElement(){
       int arr[] = { 6, 8, 0, 1, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int nextGrater[n];

    StackArr s(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int val = arr[i];

        int topVal;
        while (!s.IsEmpty() && s.Peek(topVal) && topVal <= val)
            s.Pop(topVal);

        if (s.IsEmpty())
            nextGrater[i] = -1;
        else
        {
            s.Peek(topVal);
            nextGrater[i] = topVal;
        }

        s.Push(val);
    }

    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++)
        cout << nextGrater[i] << " ";
    cout << "\n";
}

int main()
{
    LinkedList *ls = new LinkedList();

    ls->add(33);
    ls->add(24);
    ls->add(10);
    ls->add(3);
    ls->add(9);
    ls->add(12);

    ls->Display();

    return 0;
}
