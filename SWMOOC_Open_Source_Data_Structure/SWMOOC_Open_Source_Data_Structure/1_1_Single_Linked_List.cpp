/*		Open Source Data Structure		*/
/*		Lecture 1. Generic Linked List	*/
/*		Chapter 1. Single Linked List	*/	

#include <stdio.h>
#include <stdlib.h>

#define VIDEO 0

#if(VIDEO == 1)
typedef struct _node{
	int data;
	struct _node * next;
}NODE;

NODE * head;

void insert_data(int data){
	NODE * temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->next = head;
	head = temp;
}

int main(void){
	for (int i = 0; i < 7; i++){
		insert_data(i + 1);
	}
	return 0;
}

#elif(VIDEO == 2)
typedef struct _node{
	int data;
	struct _node * next;
}NODE;

NODE * head;

void insert_data(int data){
	NODE * temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->next = head;
	head = temp;
}

void display(void){
	NODE * temp;
	system("cls");
	printf("head");
	for (temp = head; temp != 0; temp = temp->next){
		
		printf("->[%d]", temp->data);
	}
	printf("\n");
	getchar();
}

int main(void){
	for (int i = 0; i < 7; i++){
		insert_data(i + 1);
		display();
	}
	return 0;
}

#elif(VIDEO == 3)
typedef struct _node{
	int data;
	struct _node * next;
}NODE;

void insert_data(int data, NODE * head){
	NODE * temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->next = head->next;
	head->next = temp;
}

void display(NODE * head){
	NODE * temp;
	system("cls");
	printf("[head]");
	for (temp = head->next; temp != 0; temp = temp->next){

		printf("->[%d]", temp->data);
	}
	printf("\n");
	getchar();
}

int main(void){
	NODE head = { 0, };
	for (int i = 0; i < 7; i++){
		insert_data(i + 1, &head);
		display(&head);
	}
	return 0;
}

#elif(VIDEO == 4)
typedef struct _node{
	int data;
	struct _node * next;
}NODE;

void insert_data(NODE * head, NODE *temp){
	temp->next = head->next;
	head->next = temp;
}

void display(NODE * head){
	NODE * temp;
	system("cls");
	printf("[head]");
	for (temp = head->next; temp != 0; temp = temp->next){

		printf("->[%d]", temp->data);
	}
	printf("\n");
	getchar();
}

int main(void){
	NODE head = { 0, };
	NODE nodes[7];
	
	for (int i = 0; i < 7; i++){
		nodes[i].data = i + 1;
		insert_data(&head, nodes + i);
		display(&head);
	}
	return 0;
}

#elif(VIDEO == 5)
typedef struct _node{
	int data;
	struct _node * next;
}NODE;

void insert_data(NODE * head, NODE *temp){
	temp->next = head->next;
	head->next = temp;
}

void display(NODE * head, NODE * tail){
	NODE * temp;
	system("cls");
	printf("[head]");
	for (temp = head->next; temp != tail; temp = temp->next){

		printf("->[%d]", temp->data);
	}
	printf("->[tail]\n");
	getchar();
}

int main(void){
	NODE tail = { 0, &tail };
	NODE head = { 0, &tail};
	NODE nodes[7];

	for (int i = 0; i < 7; i++){
		nodes[i].data = i + 1;
		insert_data(&head, nodes + i);
		display(&head, &tail);
	}
	return 0;
}

#elif(VIDEO == 6)
typedef struct _node{
	int data;
	struct _node * next;
}NODE;

void insert_data(NODE * head, NODE *temp){
	temp->next = head->next;
	head->next = temp;
}

void display(NODE * head){
	NODE * temp;
	system("cls");
	printf("[head]");
	for (temp = head->next; temp != head; temp = temp->next){

		printf("->[%d]", temp->data);
	}
	printf("->[head]\n");
	getchar();
}

int main(void){
	NODE head = { 0, &head };
	NODE nodes[7];

	for (int i = 0; i < 7; i++){
		nodes[i].data = i + 1;
		insert_data(&head, nodes + i);
		display(&head);
	}
	return 0;
}

#elif(VIDEO == 7)
typedef struct _node{
	int data;
	struct _node * next;
}NODE;

void insert_data(NODE * head, NODE *temp){
	temp->next = head->next;
	head->next = temp;
}

void reverse(NODE * head){
	NODE * prev = head;
	NODE * curr = prev->next;
	NODE * next;
	while (curr != head){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	curr->next = prev;
}

void display(NODE * head){
	NODE * temp;
	system("cls");
	printf("[head]");
	for (temp = head->next; temp != head; temp = temp->next){

		printf("->[%d]", temp->data);
	}
	printf("->[head]\n");
	getchar();
}


int main(void){
	NODE head = { 0, &head };
	NODE nodes[7];

	for (int i = 0; i < 7; i++){
		nodes[i].data = i + 1;
		insert_data(&head, nodes + i);
		display(&head);
	}
	reverse(&head);

	display(&head);

	reverse(&head);
	display(&head);

	return 0;
}

#else
#endif
