#include <iostream>
using namespace std;

class Stack{
private:
    int* stk;
    int size;
    int top;

public:
    Stack() {
        this->size = 5;
        this->top = 0;
        this->stk = new int[this->size];
        cout << "Parameterless Constructor\n";
    }

    Stack(int size) {
        this->size = size;
        this->top = 0;
        this->stk = new int[this->size];
        cout << "Parameterized Constructor\n";
    }

    Stack(const Stack& S) {
        this->size = S.size;
        this->top  = S.top;
        this->stk  = new int[this->size];
        for(int i = 0; i < this->top; i++)
            this->stk[i] = S.stk[i];
        cout << "Copy Constructor\n";
    }

    ~Stack() {
        for (int i = 0; i < this->top; i++)
            this->stk[i] = -1;
        delete[] this->stk;
        cout << "Destructor\n";
    }

    bool isEmpty() { return top == 0; }
    bool isFull()  { return top == size; }

    int Peak() {
        return this->isEmpty()? -1 : stk[top - 1];
    }

    void Push(int e) {
        if(isFull()) {
            cout << "Stack is full\n";
            return;
        }
        stk[top++] = e;
    }

    int Pop() {
        if(this->isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return stk[--top];
    }

    Stack Reverse() {
        Stack revStk(top);
        for(int i = top - 1; i >= 0; i--)
            revStk.Push(stk[i]);
        return revStk;
    }

    void PrintStack() {
        for(int i = 0; i < top; i++)
            cout << stk[i] << " ";
        cout << endl;
    }

    friend void viewContent(Stack S);
};

void viewContent(Stack S) {
    for(int i = 0; i < S.top; i++)
        cout << S.stk[i] << " ";
    cout << endl;
}

int main() {
    Stack S1;

    S1.Push(10);
    S1.Push(20);
    S1.Push(30);
    S1.Push(40);

    viewContent(S1);

    cout<<"Num = "<<S1.Pop()<<endl;
    cout<<"Num = "<<S1.Pop()<<endl;

    return 0;
}
