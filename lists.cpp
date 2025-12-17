/*lista*/

#include<iostream>
using namespace std;

struct NODE{
    int dato;
    NODE *next;
};

int ins_head(NODE *&head, int n);
int ins_tail(NODE *&head, int n);
int ins_ordinato(NODE *&head, int n);
int del_head(NODE *&head);
int del_tail(NODE *&head);
int del(NODE *&head, int n);
void printList(NODE *&head);


int main (){
    NODE *head;
    head = new NODE;

    if(head == NULL){
        cout << "Spazio in memoria esaurito" << endl;
        exit(0);
    }
    return 0;
}

int ins_head(NODE *&head, int n){
    NODE *t = new NODE;

    if(t == NULL){
        cout << "Spazio in memoria esaurito" << endl;
        return 0;
    }

    t->dato = n;
    t->next = head;
    head = t;
    return 1;
}

int ins_tail(NODE *&head, int n){
    NODE *tail = new NODE;

    if(tail == NULL){
        cout << "Spazio in memoria esaurito" << endl;
        return 0;
    }
    tail->dato = n;
    tail->next = NULL;

    // if(head == NULL)
    //     return ins_head(head, n);
    // ...
    if(head == NULL){
        head = tail;
        return 1;
    }

    NODE *p = head;
    while(p->next != NULL){
        p = p->next;
    }

    p->next = tail;
    return 1;
}

int ins_ordinato(NODE *&head, int n) {
    // 1. Creo il nuovo nodo
    NODE* new_node = new NODE;
    if(new_node == NULL){
        cout << "Spazio in memoria esaurito" << endl;
        return 0;
    }
    new_node->dato = n;

    // 2. Lista vuota o inserimento in testa
    if (head == NULL || n < head->dato) {
        new_node->next = head;
        head = new_node;
        return 1;
    }

    // 3. Cerco la posizione corretta
    NODE *p = head;
    while (p->next != NULL && p->next->dato < n) {
        p = p->next;
    }

    // 4. Inserimento tra p e p->next (o in coda)
    new_node->next = p->next;
    p->next = new_node;
    return 1;
}

        //MIA verione
// int ins_ordinato(NODE *&head, int n){
//     NODE *new_node = new NODE;

//     if(new_node == NULL){
//         cout << "Spazio in memoria esaurito" << endl;
//         return 0;
//     }
//     new_node->dato = n;
//     new_node->next = NULL;

//     if(head == NULL){
//         head = new_node;
//         return 1;
//     }else if(head->dato > n){
//         new_node->next = head;
//         head = new_node;
//         return 1;
//     }

//     NODE *p = head;
//     while(p->next != NULL){
//         if(p->next->dato > n){
//             new_node->next = p->next;
//             break;
//         }
//         p = p->next;
//     }

//     p->next = new_node;
//     return 1;
// }

int del_head(NODE *&head){
    if(head == NULL){
        return 0; //lista vuota
    }

    NODE *t = head;
    head = head->next;
    delete t;

    return 1;
}

int del_tail(NODE *&head){
    if (head == NULL) {
        return 0; // lista vuota
    }
    else if (head->next == NULL) {
        delete head;
        head = NULL;
        return 1;
    }

    NODE *p = head;

    while (p->next->next != NULL) {
        p = p->next;
    }

    delete p->next;
    p->next = NULL;
    return 1;
}

int del(NODE *&head, int n){
    if(head == NULL){
        return 0;
    }
    NODE *t = head;
    if(head->dato == n){
        head = head->next;
        delete t;
        return 1;
    }

    NODE *p = t->next;
    while(p != NULL && p->dato != n){
        t = p;
        p = p->next;
    }

    if(p != NULL){
        t->next = p->next;
        delete p;
        return 1;
    }

    return 0;
}

void printList(NODE *&head){
    NODE *p = head;

    while(p != NULL){
        cout << p->dato << " ";
        p = p->next;
    }

    cout << endl;
}
