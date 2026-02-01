#include <iostream>
using namespace std;

class Stack {
private:
    int* stk;
    int size;
    int top;

    static int counter;

public:
    Stack() {
        size = 5;
        top = 0;
        stk = new int[size];
        counter++;
//        cout << "Parameterless Constructor\n";
    }

    Stack(int size) {
        this->size = size;
        top = 0;
        stk = new int[size];
        counter++;
//        cout << "Parameterized Constructor\n";
    }

    Stack(const Stack& S) {
        size = S.size;
        top = S.top;
        stk = new int[size];
        for(int i = 0; i < top; i++)
            stk[i] = S.stk[i];
        counter++;
//        cout << "Copy Constructor\n";
    }

    ~Stack() {
        delete[] stk;
        counter--;
//        cout << "Destructor\n";
    }

    static int getCounter() { return counter; }

    bool isEmpty() { return top == 0; }
    bool isFull()  { return top == size; }

    int Peak() { return isEmpty() ? -1 : stk[top - 1]; }

    void Push(int e) {
        if(isFull()) { cout << "Stack is full\n"; return; }
        stk[top++] = e;
    }

    int Pop() {
        if(isEmpty()) { cout << "Stack is empty\n"; return -1; }
        return stk[--top];
    }

    Stack Reverse() {
        Stack rev(top);
        for(int i = top - 1; i >= 0; i--)
            rev.Push(stk[i]);
        return rev;
    }

    void PrintStack() {
        for(int i = 0; i < top; i++)
            cout << stk[i] << " ";
        cout << endl;
    }

    Stack& operator=(const Stack& S){
            delete[] this->stk;
            size = S.size;
            top = S.top;
            stk = new int[size];
            for(int i = 0; i < top; i++)
                stk[i] = S.stk[i];

        return *this;
    }

    Stack operator+(const Stack& S) {
        Stack result(top + S.top);
        for(int i = 0; i < top; i++)
            result.Push(stk[i]);
        for(int i = 0; i < S.top; i++)
            result.Push(S.stk[i]);
        return result;
    }

    int& operator[](int idx) { return stk[idx]; }

    friend void viewContent(Stack S);
};

int Stack::counter = 0;

void viewContent(Stack S) {
    for(int i = 0; i < S.top; i++)
        cout << S.stk[i] << " ";
    cout << endl;
}

int main() {
    Stack S1;
    S1.Push(10); S1.Push(20); S1.Push(30); S1.Push(40);

    Stack S2;
    S2.Push(1); S2.Push(2);

    cout << "S1 + S2\n";
    Stack S3 = S1 + S2;
    S3.PrintStack();

    cout << "Before Modifying" << S3[2] << endl;
    S3[2] = 99;
    cout << "Before Modifying" << S3[2] << endl;

    cout << "Number of stacks: " << Stack::getCounter() << endl;

    return 0;
}
