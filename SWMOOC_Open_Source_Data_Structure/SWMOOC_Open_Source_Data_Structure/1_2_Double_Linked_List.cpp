/*		Open Source Data Structure		*/
/*		Lecture 1. Generic Linked List	*/
/*		Chapter 2. Double Linked List	*/

#include <stdio.h>
#include <stdlib.h>

#define VIDEO 0

#if(VIDEO == 1)
typedef struct _node{
	int data;
	struct _node * next;
	struct _node * prev;
}NODE;

void __insert_data(NODE * temp, NODE * prev, NODE * next){
	temp->next = next;
	prev->next = temp;
	temp->prev = prev;
	next->prev = temp;
}

void insert_front(NODE * temp, NODE * head){
	__insert_data(temp, head, head->next);
}

void insert_rear(NODE * temp, NODE * head){
	__insert_data(temp, head->prev, head);
}

void display(NODE * head){
	NODE * temp;
	system("cls");
	printf("[head]");
	for (temp = head->next; temp != head; temp = temp->next){
		printf("<->[%d]", temp->data);
	}
	printf("<->[head]]\n");
	getchar();
}

int main(void){
	NODE head = { 0, &head, &head };
	NODE nodes[7];
	display(&head);
	for (int i = 0; i < 7; i++){
		nodes[i].data = i + 1;
		insert_front(nodes + i, &head);
		display(&head);
	}
	return 0;
}

#else
#endif