/*		Open Source Data Structure		*/
/*		Lecture 3. Binary Search Tree	*/
/*		Chapter 1. Binary Tree			*/
/*		Practice - Tree Order Traverse	*/	
#include <stdio.h>
#include <stdlib.h>

#define PRACTICE 0

#if(PRACTICE == 1)
typedef struct _node{
	int data;
	struct _node * left;
	struct _node * right;
}NODE;

/*		pre-order : root -> left -> right	*/

void pre_order(NODE * temp){
	if (temp == 0){
		return;
	}
	printf("%d\n", temp->data);
	pre_order(temp->left);
	pre_order(temp->right);
}

#endif
