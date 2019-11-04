/*		Open Source Data Structure		*/
/*		Lecture 4. Red Black Tree		*/
/*		Chapter 1. Red Black Tree Basic	*/

#include <stdio.h>
#include <stdlib.h>

#define VIDEO 3

#if(VIDEO == 1)
/*		No code here		*/
#elif(VIDEO == 2)
/*	RB Tree�� ���� ��										*/
/*	0. �뷱���� root ���κ��� ��� �ܸ� ���� ���� �����		*/
/*		���� ����� ���� ������ �뷱���� �´� ������ ����		*/
/*	1. root ���� ������ ����								*/
/*	2. ���ο� ���� ����										*/
/*	3. �θ� ����, ���̵� �����̸� color flip					*/
/*		color flip :										*/
/*			parent, uncle =>BLACK							*/
/*			gparent => RED									*/
/*	4. �θ� �����̸� ȸ�� (gparent - parent - node)			*/
/*		color flip :										*/
/*			parent => BLACK									*/
/*			gparent => RED									*/
/*															*/
/*		R-R ���(Right-Right)�� ���:							*/
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
