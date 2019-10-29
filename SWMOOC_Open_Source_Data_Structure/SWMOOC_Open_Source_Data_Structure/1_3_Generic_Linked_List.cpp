/*		Open Source Data Structure		*/
/*		Lecture 1. Generic Linked List	*/
/*		Chapter 3. Generic Linked List	*/

/*		Video 4,5번 안봄, 다시 보기		*/

#include <stdio.h>
#include <stdlib.h>

#define VIDEO 0

#if(VIDEO == 1)
typedef struct _node{
	void * data;
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

typedef struct{
	char name[20];
}SAWON;

void display(NODE * head){
	NODE * temp;
	SAWON * s;
	system("cls");
	printf("[head]");
	for (temp = head->next; temp != head; temp = temp->next){
		s = (SAWON*)temp->data;
		printf("<->[%s]", s->name);
	}
	printf("<->[head]]\n");
	getchar();
}

int main(void){
	NODE head = { 0, &head, &head };
	NODE nodes[2];
	SAWON sinib[2] = { { "name1" }, { "name2" } };
	display(&head);
	for (int i = 0; i < 2; i++){
		nodes[i].data = &sinib[i]; 
		insert_front(nodes + i, &head);
		display(&head);
	}
	return 0;
}

#elif(VIDEO == 2)
typedef struct _node{
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

typedef struct{
	char name[20];
	NODE list;
}SAWON;

void display(NODE * head){
	NODE * temp;
	SAWON * s;
	system("cls");
	printf("[head]");
	for (temp = head->next; temp != head; temp = temp->next){
		s = (SAWON*)((char*)temp - (sizeof(SAWON)-sizeof(NODE)));
		printf("<->[%s]", s->name);
	}
	printf("<->[head]]\n");
	getchar();
}

int main(void){
	NODE head = {&head, &head };
	SAWON sinib[2] = { { "name1" }, { "name2" } };
	display(&head);
	for (int i = 0; i < 2; i++){
		insert_front(&sinib[i].list, &head);
		display(&head);
	}
	return 0;
}

#elif(VIDEO == 3)
#define container_of(ptr, type, member) \
	(type*)((char*)ptr - (unsigned long)&((type*)0)->member);
typedef struct _node{
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

typedef struct{
	char name[20];
	NODE list1;
	NODE list2;
}SAWON;

void display(NODE * head){
	NODE * temp;
	SAWON * s;
	system("cls");
	printf("[head]");
	for (temp = head->next; temp != head; temp = temp->next){
		/*s = (SAWON*)((char*)temp - (unsigned long)&((SAWON*)0)->list1);*/
		s = container_of(temp, SAWON, list1);
		printf("<->[%s]", s->name);
	}
	printf("<->[head]]\n");
	getchar();
}

int main(void){
	NODE head = { &head, &head };
	SAWON sinib[2] = { { "name1" }, { "name2" } };
	display(&head);
	for (int i = 0; i < 2; i++){
		insert_front(&sinib[i].list1, &head);
		display(&head);
	}
	return 0;
}

#elif(VIDEO == 4)
#define container_of(ptr, type, member) \
	(type*)((char*)ptr - (unsigned long)&((type*)0)->member);
typedef struct _node{
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

typedef struct{
	char name[20];
	NODE list1;
	NODE list2;
}SAWON;

void display(NODE * head){
	NODE * temp;
	SAWON * s;
	system("cls");
	printf("[head]");
	for (temp = head->next; temp != head; temp = temp->next){
		/*s = (SAWON*)((char*)temp - (unsigned long)&((SAWON*)0)->list1);*/
		s = container_of(temp, SAWON, list1);
		printf("<->[%s]", s->name);
	}
	printf("<->[head]]\n");
	getchar();
}

int main(void){
	NODE head = { &head, &head };
	SAWON sinib[2] = { { "name1" }, { "name2" } };
	display(&head);
	for (int i = 0; i < 2; i++){
		insert_front(&sinib[i].list1, &head);
		display(&head);
	}
	return 0;
}

#elif(VIDEO == 5)
#else
#endif

