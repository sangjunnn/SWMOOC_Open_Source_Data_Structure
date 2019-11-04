/*		Open Source Data Structure		*/
/*		Lecture 4. Red Black Tree		*/
/*		Chapter 1. Red Black Tree Basic	*/

#include <stdio.h>
#include <stdlib.h>

#define VIDEO 3

#if(VIDEO == 1)
/*		No code here		*/
#elif(VIDEO == 2)
/*	RB Tree의 삽입 룰										*/
/*	0. 밸런스는 root 노드로부터 모든 단말 노드로 가는 경로의		*/
/*		검정 노드의 수가 같으면 밸런스가 맞는 것으로 간주		*/
/*	1. root 노드는 언제나 검정								*/
/*	2. 새로운 노드는 빨강										*/
/*	3. 부모도 빨강, 삼촌도 빨강이면 color flip					*/
/*		color flip :										*/
/*			parent, uncle =>BLACK							*/
/*			gparent => RED									*/
/*	4. 부모가 빨강이면 회전 (gparent - parent - node)			*/
/*		color flip :										*/
/*			parent => BLACK									*/
/*			gparent => RED									*/
/*															*/
/*		R-R 경사(Right-Right)인 경우:							*/
/*			rotate_left(gparent);							*/

#elif(VIDEO == 3)
typedef struct _node {
	int sid;
	struct rb_node node
}SAWON;

void my_insert(struct rb_root* root, SAWON* s) {
	struct rb_node** p = &root->rb_node;
	struct rb_node* parent = 0;

	while (*p) {
		SAWON* temp = rb_entry(*p, SAWON, node);
		parent = *p;
		if (parent->sid > temp->sid) {
			p = &(*p)->left;
		}
		else if (parent->sid < temp->sid) {
			p = &(*p)->right;
		}
		else {
			return 0;
		}
		rb_link_node(&s->node, parent, p);
		return l;
	}
}

int main() {
	struct rb_root root = { 0 };
	int a[] = { 1,2,3,4,5,6,7,8 };
	SAWON sawon[8];
	display(&root);
	for (int i = 0; i < 8; i++) {
		sawon[i].sid = a[i];
		my_insert(&root, sawon+i);
		display(&root);
	}

	return 0;
}


#elif(VIDEO == 4)

#elif(VIDEO == 5)
