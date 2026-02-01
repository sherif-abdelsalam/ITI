#include <iostream>
using namespace std;

class Stack{
private:
	int *stk;;
	int size = 0;
	int top = 0;
public:
    Stack(){
        this->size = 5;
        stk = new int[this->size];
    }
    Stack(int size){
        this->size = size;
        stk = new int[this->size];
    }

    bool isEmpty(){ return top == 0;}
    bool isFull() {return top == this->size;}

	int Peak(){
        return this->isEmpty()? -1 : stk[this->top-1];
	}

	void Push(int e){
        if(this->isFull()) {
            cout<<"Stack is Already full!!"<<endl;
            return;
        }
        stk[top++] = e;
	}

	int Pop(){
        if(this->isEmpty()) {
            cout<<"Stack is Empty full!!"<<endl;
            return -1;
        }
        return stk[--top];
	}

	Stack Reverse(){
        Stack revStk(top);
        for (int i = top - 1; i >= 0; i--) {
            revStk.Push(stk[i]);
        }
        return revStk;
	}

	void PrintStack(){
        if (this->isEmpty()) {
            cout << "Stack is empty\n";
                return;
        }

        for (int i = 0; i < top; i++) {
            cout << stk[i] << " ";
        }


        cout << endl;
    }
};


int main()
{
	Stack S1(5);

	S1.Push(10);
	S1.Push(20);
	S1.Push(30);

	cout<< S1.Peak()<<endl; //30
	cout<< S1.Peak()<<endl; //30

	cout<< S1.Pop() <<endl; //30
	cout<< S1.Pop() <<endl; //20

	Stack S2(5);

	S2.Push(3);
	S2.Push(4);
	S2.Push(5);
	S2.Push(6);

	cout<< S2.Reverse().Pop() <<endl; // 3
}
