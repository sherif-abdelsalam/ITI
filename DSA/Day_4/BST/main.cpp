#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Employee {
public:
    int ID;
    string Name;
    int Age;

    Employee() {}

    Employee(int id, string name, int age) {
        ID = id;
        Name = name;
        Age = age;
    }
};


class Node {
public:
    Employee data;
    Node* left;
    Node* right;

    Node(Employee emp) {
        data = emp;
        left = right = NULL;
    }
};


class BST {
    Node* root;

    Node* insert(Node* node, Employee emp) {
        if (!node)
            return new Node(emp);

        if (emp.ID < node->data.ID)
            node->left = insert(node->left, emp);
        else
            node->right = insert(node->right, emp);

        return node;
    }

    Node* search(Node* node, int id) {
        if (!node || node->data.ID == id)
            return node;

        if (id < node->data.ID)
            return search(node->left, id);

        return search(node->right, id);
    }

    Node* getMinimum(Node* node) {
        while (node->left)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int id) {
        if (!node) return node;

        if (id < node->data.ID)
            node->left = deleteNode(node->left, id);

        else if (id > node->data.ID)
            node->right = deleteNode(node->right, id);

        else {
            /// Case 1: no child
            if (!node->left && !node->right) {
                delete node;
                return NULL;
            }

            /// Case 2: one child
            else if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            /// Case 3: two childs
            Node* minNode = getMinimum(node->right);
            node->data = minNode->data;
            node->right = deleteNode(node->right, minNode->data.ID);
        }
        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data.ID << " - " << node->data.Name << " - " << node->data.Age << endl;
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data.ID << " - " << node->data.Name << " - " << node->data.Age << endl;
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data.ID << " - " << node->data.Name << " - " << node->data.Age << endl;
    }

public:

    BST() { root = NULL; }

    void Insert(Employee emp) {
        root = insert(root, emp);
    }

    Employee* Search(int id) {
        Node* result = search(root, id);
        return (result ? &result->data : NULL);
    }

    void Delete(int id) {
        root = deleteNode(root, id);
    }

    Employee* GetMinimum() {
        if (!root) return NULL;
        return &getMinimum(root)->data;
    }

    Employee* GetMaximum() {
        if (!root) return NULL;

        Node* node = root;
        while (node->right)
            node = node->right;
        return &node->data;
    }

    void InOrder()  { inorder(root); }
    void PreOrder() { preorder(root); }
    void PostOrder(){ postorder(root); }
};


int main() {
    BST tree;

    tree.Insert(Employee(6, "Sherif", 22));
    tree.Insert(Employee(9, "Mohmmaed", 54));
    tree.Insert(Employee(8, "Mohmmaed", 88));
    tree.Insert(Employee(2, "Abdelsalam", 119));
    tree.Insert(Employee(1, "Ahmed", 25));
    tree.Insert(Employee(10, "Ali", 30));

    cout << "InOrder Traversal:\n";
    tree.InOrder();
    cout<<"\n==================\n";
    cout << "\nSearch for ID 8:\n";
    Employee* e = tree.Search(8);
    if (e)
        cout << e->ID << " " << e->Name << " " << e->Age << endl;
    else
        cout << "Not Found\n";
    cout<<"==================\n";

    cout<<"Delete Employee with iD: 2\n";
    tree.Delete(2);

    tree.InOrder();
    cout<<"==================\n";


    cout << "\nMinimum Employee Id: \n";
    e = tree.GetMinimum();
    cout << e->ID <<" " <<e->Name<< endl;
    e = tree.GetMaximum();
    cout << "\nMaximum Employee Id:\n";
    cout << e->ID <<" " <<e->Name<< endl;

    return 0;
}
