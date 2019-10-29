/*		Open Source Data Structure		*/
/*		Lecture 1. Generic Linked List	*/
/*		Chapter 3. Generic Linked List	*/
/*		Practice - Container of			*/	

#include <stdio.h>

#define PRACTICE 0
#define container_of(ptr, type, member) \
	(type*)((char*)ptr - (unsigned long)&((type*)0)->member);

#if(PRACTICE == 1)
typedef struct{
	int a;
	int b;
	int c;
}AAA;

int main(void){
	AAA aaa = { 1, 2, 3 };
	int * temp = &aaa.c;
	AAA * p;
	/*p = (AAA*)((char*)temp - (unsigned long)&((AAA*)0)->c);*/
	p = container_of(temp, AAA, c);
	printf("a : %d\nb : %d\nc : %d\n", p->a, p->b, p->c);
	return 0;
}
#else
#endif