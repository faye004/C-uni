/*
Given a binary tree, we need to write a program (with recursive function)
to print all leaf nodes
of the given binary tree from left to right.
Main steps:
1) Check if the given node is null. If null, then return from the function.
2) Check if it is a leaf node. If the node is a leaf node, then print its data.
3) If in the above step, the node is not a leaf node then check if the
left and right children of node exist. If yes then call the function
or left and right child of the node recursively.


Example of struct for a node:
typedef struct node
{
    int data;
    Node *left, *right;
} Node;


Utility function to create a new tree node:
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;    return temp;}
*/

#include <iostream>
using namespace std;

struct NODE {
    int data;
    NODE *left, *right;
};

NODE* newNode(int data);
void ins(NODE *&node, int data); //head for start
void printAllLeafNodes(NODE *&node); //head for start

int main(){
    // NODE *head = newNode(6);
    // head->left = newNode(4);
    // head->right = newNode(8);
    // head->right->left = newNode(7);
    // head->left->right = newNode(5);
    // head->right->right = newNode(10);
    // head->right->right->right = newNode(13);
    NODE *head = NULL;
    int n = 1;
    while(n != 0){
        cout << "Inserisci un numero nell'albero binario (n != 0): ";
        cin >> n;
        if(n != 0)
            ins(head, n);
    };

    cout << endl << "foglie dell'albero: " << endl;
    printAllLeafNodes(head);
    return 0;
}

NODE* newNode(int data){
    NODE *temp = new NODE;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void ins(NODE *&node, int data){
    if(node == NULL){
        node = newNode(data);
        return;
    }

    if(data > node->data)
        ins(node->right, data);
    else
        ins(node->left, data);
    return;
}

void printAllLeafNodes(NODE *&node){ //recursive
    //1) Check if the given node is null. If null, then return from the function.
    if(node == NULL)
        return;
    
    //2) Check if it is a leaf node. If the node is a leaf node, then print its data.
    if((node->right == NULL) && (node->left == NULL)){
        cout << node->data << endl;
        return;
    }
    
    /*3) If in the above step, the node is not a leaf node then check if the
left and right children of node exist. If yes then call the function
or left and right child of the node recursively.*/
    if(node->left != NULL)
        printAllLeafNodes(node->left);

    if(node->right != NULL)
        printAllLeafNodes(node->right);

    return;
}
