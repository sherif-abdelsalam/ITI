#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <cstddef>
#include <iostream>
using namespace std;

class LinkedList{
public:

    LinkedList(){
        head = tail = NULL;
    }

   void add(int data) {
    Node* node = new Node(data);

    if (!head) {
        head = tail = node;
    }
    else if (data <= head->data) {
        node->next = head;
        head->prev = node;
        head = node;
    }
    else if (data >= tail->data) {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
    else {
        Node* curr = head;
        while (curr && curr->data < data) {
            curr = curr->next;
        }

        node->next = curr;
        node->prev = curr->prev;
        curr->prev->next = node;
        curr->prev = node;
    }
    cnt++;
    }


    void insertAfter(int data, int afterData){
        Node* node = getNode(afterData);
        if(!node){
            cout<<"After Data not Exists!!\n";
            return;
        }

        Node* newNode = new Node(data);

        newNode->prev = node;
        newNode->next = node->next;

        /// is the node is not tail
        if(node->next)
            node->next->prev = newNode;

        node->next = newNode;

        if(node == tail) tail = newNode;
        cnt++;

    }

    void insertBefore(int data, int beforeData) {
        Node* node = getNode(beforeData);
        if (!node) {
            cout << "Before Data not exists!!\n";
            return;
        }

        Node* newNode = new Node(data);

        newNode->next = node;
        newNode->prev = node->prev;

        /// if the node is not head
        if (node->prev)
            node->prev->next = newNode;

        node->prev = newNode;

        if (node == head) head = newNode;
        cnt++;
    }

    int getDataByIndex(int index) {
        if (index < 0 || index >= cnt) {
            cout << "Index is not correct!\n";
            return -1;
        }
        Node* curr = head;
        while (index--) {
            curr = curr->next;
        }
        return curr->data;
    }

    void Display(){
        Node* current = head;
        while (current != NULL)
        {
            cout << current->data << "  ";
            current = current->next;
        }
    }

    bool Search(int data){
        return getNode(data) != NULL;
    }

    bool Delete(int data){
        Node* node = getNode(data);
        if (node != NULL)
        {
            // Only element
            if (head == node && tail == node)
            {
                head = tail = NULL;
            }
            // Deleting head
            else if (node == head)
            {
                head = node->next;
                head->prev = NULL;
            }
            // Deleting tail
            else if (node == tail)
            {
                tail = node->prev;
                tail->next = NULL;
            }
            // In between
            else
            {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }

            delete node;
            cnt--;
            return true;
        }

        return false;
    }

    LinkedList* ReversInAnewList() {
        LinkedList *reversedList = new LinkedList();
        Node* curr = tail;

        while (curr) {
            reversedList->add(curr->data);  // add nodes to new list
            curr = curr->prev;
        }

        return reversedList;
    }


    void ReverseInPlace() {
        if (!head){
            cout<<"List is Empty!!\n";
            return;
        }
//        cout<<"\n"<<head->data <<endl;
//        cout<<"\n"<<tail->data <<endl;

        Node* curr = head;
        Node* temp = NULL;

        while (curr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            curr = curr->prev;
        }

        swap(head,tail);
    }


    int getCount() { return cnt;}

    void removeKthNode(int k){
        int temp = getCount();
        Node *curr = head;
        while(curr){
            Node* nextNode = curr->next;
            if(temp % k == 0) {
                this->Delete(curr->data);
            }
            temp--;
            curr = nextNode;
        }

    }


private:
    Node* head;
    Node* tail;
    int cnt = 0;

    Node* getNode(int data)
    {
        Node* current = head;

        while (current != NULL)
        {
            if (current->data == data)
                return current;

            current = current->next;
        }

        return NULL;
    }
};

#endif // LINKEDLIST_H
