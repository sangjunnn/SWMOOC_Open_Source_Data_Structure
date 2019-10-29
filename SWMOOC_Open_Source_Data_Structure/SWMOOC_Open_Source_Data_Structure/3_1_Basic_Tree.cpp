/*		Open Source Data Structure		*/
/*		Lecture 3. Binary Search Tree	*/
/*		Chapter 1. Binary Tree			*/

/*		Node, Edge로 구성됨				*/
/*		Root/Leaf Node					*/
/*		하나의 노드에서 다른 노드로 가는 방법은 반드시 1개	*/

#include <stdio.h>
#include <stdlib.h>

#define VIDEO 0

#if(VIDEO == 1)
typedef struct _node{
	int data;
	struct _node * left;
	struct _node * right;
}NODE;

NODE * root; 

typedef enum {LEFT, RIGHT} FLAG;

void insert_data(int data, NODE * s, FLAG flag){
	NODE * temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->left = 0;
	temp->right = 0;
	if (root == 0){
		root = temp;
		return;
	}
	if (flag == LEFT){
		s->left = temp;
	}
	else if (flag == RIGHT){
		s->right = temp;
	}
}

/*****************************************************/

int main(void){
	insert_data(1, root, LEFT);
	insert_data(2, root, LEFT);
	insert_data(3, root, RIGHT);
	insert_data(4, root->left, LEFT);
	insert_data(5, root->left, RIGHT);
	insert_data(6, root->right, LEFT);
	insert_data(7, root->right, RIGHT);

	return 0;
}

#elif(VIDEO == 2)
typedef struct _node{
	int data;
	struct _node * left;
	struct _node * right;
}NODE;

NODE * root;

typedef enum { LEFT, RIGHT } FLAG;

void insert_data(int data, NODE * s, FLAG flag){
	NODE * temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->left = 0;
	temp->right = 0;
	if (root == 0){
		root = temp;
		return;
	}
	if (flag == LEFT){
		s->left = temp;
	}
	else if (flag == RIGHT){
		s->right = temp;
	}
}

/*		pre-order : root -> left -> right	*/
void pre_order(NODE * temp){
	if (temp == 0){
		return;
	}
	printf("%d\n", temp->data);
	pre_order(temp->left);
	pre_order(temp->right);
}

/*		in-order : left -> root -> right	*/
void in_order(NODE * temp){
	if (temp == 0){
		return;
	}
	
	in_order(temp->left);
	printf("%d\n", temp->data);
	in_order(temp->right);
}

/*		post-order : left -> right -> root	*/
void post_order(NODE * temp){
	if (temp == 0){
		return;
	}

	post_order(temp->left);
	post_order(temp->right);
	printf("%d\n", temp->data);
}

/*****************************************************/

int main(void){
	insert_data(1, root, LEFT);
	insert_data(2, root, LEFT);
	insert_data(3, root, RIGHT);
	insert_data(4, root->left, LEFT);
	insert_data(5, root->left, RIGHT);
	insert_data(6, root->right, LEFT);
	insert_data(7, root->right, RIGHT);

	/*pre_order(root);*/
	/*in_order(root);*/
	post_order(root);

	return 0;
}

#elif(VIDEO == 3)
typedef struct _node{
	int data;
	struct _node * left;
	struct _node * right;
}NODE;

NODE * root;

typedef enum { LEFT, RIGHT } FLAG;

void insert_data(int data, NODE * s, FLAG flag){
	NODE * temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->left = 0;
	temp->right = 0;
	if (root == 0){
		root = temp;
		return;
	}
	if (flag == LEFT){
		s->left = temp;
	}
	else if (flag == RIGHT){
		s->right = temp;
	}
}

/*		pre-order : root -> left -> right	*/
void pre_order(NODE * temp){
	if (temp == 0){
		return;
	}
	printf("%d\n", temp->data);
	pre_order(temp->left);
	pre_order(temp->right);
}

/*		in-order : left -> root -> right	*/
void in_order(NODE * temp){
	if (temp == 0){
		return;
	}

	in_order(temp->left);
	printf("%d\n", temp->data);
	in_order(temp->right);
}

/*		post-order : left -> right -> root	*/
void post_order(NODE * temp){
	if (temp == 0){
		return;
	}

	post_order(temp->left);
	post_order(temp->right);
	printf("%d\n", temp->data);
}

/*****************************************************/

void display(NODE * temp){
	static int indent = -1;
	if (temp == 0){
		return;
	}
	++indent;
	display(temp->right);
	for (int i = 0; i < indent; i++){
		printf("%4c", ' ');
	}
	printf("%d\n", temp->data);
	display(temp->left);
	--indent;
}

int main(void){
	insert_data(1, root, LEFT);
	insert_data(2, root, LEFT);
	insert_data(3, root, RIGHT);
	insert_data(4, root->left, LEFT);
	insert_data(5, root->left, RIGHT);
	insert_data(6, root->right, LEFT);
	insert_data(7, root->right, RIGHT);

	display(root);

	return 0;
}

#elif(VIDEO == 4)
typedef struct _node{
	int data;
	struct _node * left;
	struct _node * right;
}NODE;

NODE * root;

typedef enum { LEFT, RIGHT } FLAG;

void insert_data(int data, NODE * s, FLAG flag){
	NODE * temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->left = 0;
	temp->right = 0;
	if (root == 0){
		root = temp;
		return;
	}
	if (flag == LEFT){
		s->left = temp;
	}
	else if (flag == RIGHT){
		s->right = temp;
	}
}

/*		pre-order : root -> left -> right	*/
void pre_order(NODE * temp){
	if (temp == 0){
		return;
	}
	printf("%d\n", temp->data);
	pre_order(temp->left);
	pre_order(temp->right);
}

/*		in-order : left -> root -> right	*/
void in_order(NODE * temp){
	if (temp == 0){
		return;
	}

	in_order(temp->left);
	printf("%d\n", temp->data);
	in_order(temp->right);
}

/*		post-order : left -> right -> root	*/
void post_order(NODE * temp){
	if (temp == 0){
		return;
	}

	post_order(temp->left);
	post_order(temp->right);
	printf("%d\n", temp->data);
}

/*****************************************************/
void __display(NODE * temp, int(*a)[10], int * row, int * col){
	if (temp == 0){
		return;
	}
	++*row;
	__display(temp->left, a, row, col);
	a[*row][(*col)++] = temp->data;
	__display(temp->right, a, row, col);
	--*row;
}

void display(NODE * temp){
	int row = -1;
	int col = 0;
	int a[10][10] = { 0, };

	__display(temp, a, &row, &col);
	system("cls");
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (a[i][j]){
				printf("%4d", a[i][j]);
			}
			else{
				printf("%4c", ' ');
			}
		}
		printf("\n");
	}
	getchar();
}

int main(void){
	insert_data(1, root, LEFT);
	display(root);
	insert_data(2, root, LEFT);
	display(root);
	insert_data(3, root, RIGHT);
	display(root);
	insert_data(4, root->left, LEFT);
	display(root);
	insert_data(5, root->left, RIGHT);
	display(root);
	insert_data(6, root->right, LEFT);
	display(root);
	insert_data(7, root->right, RIGHT);
	display(root);

	return 0;
}

#else
#endif