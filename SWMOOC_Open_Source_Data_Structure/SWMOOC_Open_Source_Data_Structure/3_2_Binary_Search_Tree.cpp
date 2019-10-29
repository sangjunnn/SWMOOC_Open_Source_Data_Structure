/*		Open Source Data Structure		*/
/*		Lecture 3. Binary Search Tree	*/
/*		Chapter 2. Binary Search Tree	*/

/*		추가되는 node가 기존의 node 보다 크다면/작다면	*/
/*		상황을 나누어서 노드의 삽입을 진행				*/
/*		검색 복잡도 O(log2N)							*/

#include <stdio.h>
#include <stdlib.h>

#define VIDEO 0

#if(VIDEO == 1)
/*		No code here		*/
#elif(VIDEO == 2)
typedef struct _node{
	int data;
	struct _node * left;
	struct _node * right;
}NODE;

NODE * root;

void insert_data(int data){
	NODE * temp;
	NODE * p = root;
	NODE * prev = p;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->left = 0;
	temp->right = 0;
	if (root == 0){
		root = temp;
		return;
	}
	while (p){
		prev = p;
		if (p->data > data){
			p = p->left;
		}
		else if (p->data < data){
			p = p->right;
		}
		else{
			return;
		}
	}
	if (prev->data > data){
		prev->left = temp;
	}
	else{
		prev->right = temp;
	}
}

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
	int a[] = { 4, 2, 1, 3, 6, 5, 7 };
	display(root);
	for (int i = 0; i < 7; i++){
		insert_data(a[i]);
		display(root);
	}
}

#elif(VIDEO == 3)
typedef struct _node{
	int data;
	struct _node * left;
	struct _node * right;
}NODE;

NODE * root;

void insert_data(int data){
	NODE * temp;
	NODE ** p = &root;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->left = 0;
	temp->right = 0;
	while (*p){
		if ((*p)->data > data){
			p = &(*p)->left;
		}
		else if ((*p)->data < data){
			p = &(*p)->right;
		}
		else{
			return;
		}
	}
	*p = temp;
}

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
	int a[] = { 4, 2, 1, 3, 6, 5, 7 };
	display(root);
	for (int i = 0; i < 7; i++){
		insert_data(a[i]);
		display(root);
	}
}

#elif(VIDEO == 4)
typedef struct _node{
	int data;
	struct _node * left;
	struct _node * right;
}NODE;

NODE * root;

void insert_data(int data){
	NODE * temp;
	NODE ** p = &root;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->left = 0;
	temp->right = 0;
	while (*p){
		if ((*p)->data > data){
			p = &(*p)->left;
		}
		else if ((*p)->data < data){
			p = &(*p)->right;
		}
		else{
			return;
		}
	}
	*p = temp;
}

void __fill(NODE * temp, int * a, int * n){
	if (temp == 0){
		return;
	}
	__fill(temp->left,a,n);
	a[(*n)++] = temp->data;
	__fill(temp->right,a,n);
}

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
NODE* __bal(int *a, int n){
	int mid;
	NODE * temp;
	temp = (NODE*)malloc(sizeof(NODE));
	if (n <= 0){
		return 0;
	}
	mid = n / 2;
	
	temp->data = a[mid];

	temp->left = __bal(a, mid);
	temp->right = __bal(a + mid + 1, n - mid - 1);

	return temp;
}

void bal(NODE * temp){
	int a[100] = { 0, };
	int n = 0;
	__fill(temp, a, &n);
	root = __bal(a, n);
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
	int a[] = { 1, 2, 3, 4, 5, 6, 7 };
	for (int i = 0; i < 7; i++){
		insert_data(a[i]);
	}
	display(root);
	bal(root);
	display(root);
	
	return 0;
}
#else
#endif