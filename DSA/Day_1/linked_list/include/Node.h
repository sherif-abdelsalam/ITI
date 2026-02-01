#ifndef NODE_H
#define NODE_H
#include <cstddef>  // <-- THIS defines NULL


class Node{
    public:
       int data;
       Node * next;
       Node * prev;

       Node(int _data)
       {
           // set data
           data = _data;
           next = prev = NULL;
       }

};

#endif // NODE_H
