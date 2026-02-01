#ifndef STACKARR_H
#define STACKARR_H


class StackArr
{
private:
        int stackSize;
        int top;
        int *arr;

    public:

        StackArr(int _stackSize)
        {
            this->stackSize = _stackSize;

            arr = new int[stackSize];
            // last filled cell
            top = -1;

        }

        bool Push(int val)
        {
            // O(1)
            // if stack full
            if(ISFull())
                return false;

            else
            {
                top++;
                arr[top] = val;
                return true;
            }

        }

        bool Pop(int &val)
        {
            //o(1)
            if(IsEmpty())
                return false;

            val = arr[top];
            --top;
            return true;
        }

        bool Peek(int &val)
        {
            //o(1)
            if(IsEmpty())
                return false;
            val = arr[top];
            return true;

        }

        bool ISFull()
        {
            return top == stackSize - 1;
        }


        bool IsEmpty()
        {
            return top == -1;
        }
};

#endif // STACKARR_H
