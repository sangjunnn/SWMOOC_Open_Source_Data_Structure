/*		Open Source Data Structure		*/
/*		Lecture 2. Generic Hash			*/
/*		Chapter 1. Generic Hash			*/

/*		Linked List는 search 시 성능 저하가 심함 - O(N)		*/	
/*		Hash는 분산배치를 통해서 search 시 속도 증가		*/
#include <stdio.h>
#include <stdlib.h>

#define VIDEO 0

#if(VIDEO == 1)
/*		No Code here*/
#elif(VIDEO == 2)
struct hlist_node{
	struct hlist_node * next, **pprev;
};

struct hlist_head{
	struct hlist_node * first;
};

void hlist_add_head(struct hlist_node * n, struct hlist_head * h){
	struct hlist_node * first = h->first;
	n->next = first;
	if (first){
		first->pprev = &n->next;
	}
	h->first = n;
	n->pprev = &h->first;
}

#define container_of(ptr, type, member) \
	(type*)((char*)ptr - (unsigned long)&((type*)0)->member);

/*****************************************************/

#define HASH_MAX 8

typedef struct{
	int sno;
	struct hlist_node hash;
}SAWON;
int hash_sno(int sno){
	return sno % HASH_MAX;
}

void display(struct hlist_head * heads){
	struct hlist_node * temp;
	SAWON * s;
	system("cls");
	for (int i = 0; i < HASH_MAX; i++){
		printf("[%d]", i);
		for (temp = heads[i].first; temp; temp = temp->next){
			s = container_of(temp, SAWON, hash);
			printf("<->[%d]", s->sno);
		}
		printf("\n");
	}
	getchar();
}

int main(void){
	SAWON s[30] = { 0, };
	struct hlist_head heads[HASH_MAX] = { 0, };
	int sno;
	for (int i = 0; i < 30; i++){
		sno = 1000 + i;
		s[i].sno = sno;
		hlist_add_head(&s[i].hash, &heads[hash_sno(sno)]);
		display(heads);
	}
	return 0;
}

#elif(VIDEO == 3)
struct hlist_node{
	struct hlist_node * next, **pprev;
};

struct hlist_head{
	struct hlist_node * first;
};

void hlist_add_head(struct hlist_node * n, struct hlist_head * h){
	struct hlist_node * first = h->first;
	n->next = first;
	if (first){
		first->pprev = &n->next;
	}
	h->first = n;
	n->pprev = &h->first;
}

#define container_of(ptr, type, member) \
	(type*)((char*)ptr - (unsigned long)&((type*)0)->member);

/*****************************************************/

#define HASH_MAX 8
#define GOLDEN_RATIO_PRIME_32 0x9e370001UL

unsigned int hash_32(unsigned int val, unsigned int bits){
	unsigned int hash = val * GOLDEN_RATIO_PRIME_32;
	return hash >> (32 - bits);
}

#define pid_hash(pid) hash_32(pid, 3)

typedef struct{
	int sno;
	struct hlist_node hash;
}SAWON;
int hash_sno(int sno){
	return hash_32(sno, 3);
}

void display(struct hlist_head * heads){
	struct hlist_node * temp;
	SAWON * s;
	system("cls");
	for (int i = 0; i < HASH_MAX; i++){
		printf("[%d]", i);
		for (temp = heads[i].first; temp; temp = temp->next){
			s = container_of(temp, SAWON, hash);
			printf("<->[%d]", s->sno);
		}
		printf("\n");
	}
	getchar();
}

int main(void){
	SAWON s[30] = { 0, };
	struct hlist_head heads[HASH_MAX] = { 0, };
	int sno;
	for (int i = 0; i < 30; i++){
		sno = 1000 + i;
		s[i].sno = sno;
		hlist_add_head(&s[i].hash, &heads[hash_sno(sno)]);
		display(heads);
	}
	return 0;
}

#else
#endif