#include<iostream>
using namespace std;

struct NODE{
	int data;
	NODE *next;
};

struct ALBERGO{
	char codice[11];
	char nome[21];
};

int ins_head(NODE *&head, ALBERGO x);
int cerca_albergo(char *alberghi[], int size, char albergo); //-1 se non trova niente

NODE *crea_lista_b(char *listaA[], char *alberghi[], int size){
	NODE *listaB = NULL;
	
	while(listaA->next != NULL){
		if(cerca_albergo(alberghi, size, listaA->info.codice) != -1){
			if(ins_testa(listaB, listaA->info) == -1){
				return NULL;
			}
		}
		listaA = listaA->next;
	}
	
	return listaB;
}


int main(){
	NODE *head = new NODE;
	
	if(head == NULL){
		cout << "Memoria esaurita" << endl;
		exit(0);
	}	
	
	return 0;
}

int ins_head(NODE *&head, ALBERGO x){
	NODE *t = new NODE;
	if(t == NULL){
		cout << "Memoria esaurita" << endl;
		return -1;
	}
	
	t->info = x;
	t->next = head;
	head = t;
	return 0;
}

int ins_tail(NODE *&head, ALBERGO x){
	
	NODE *t = new NODE;
	if(t == NULL){
		cout << "Memoria esaurita" << endl;
		return -1;
	}
	
	t->info = x;
	t->next = NULL;
	if(head == NULL){
		head = t;
		return 0;
	}
	NODE *p = head;
	while(p->next != NULL){
		p = p->next;
	}
	p->next = t;
	return 0;
}
