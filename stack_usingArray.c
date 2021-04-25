//using array to implement stack 
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
struct stack
{
	int top;
	int items[MAX];
};
typedef struct stack st;
int count = 0;

void createEmptyStack(st *s){
	s->top = -1;
}

int isEmpty(st *s)
{
	if (s->top == -1)
		return 1;
	else 
		return 0;
}

int isFull(st *s)
{
	if (s->top == MAX-1)
		return 1;
	else 
		return 0;
}

void push(int newitem , st *s)
{
	if(isFull(s) == 1)
		printf("Stack is full!\n");
	else 
		{
		s->top++;
		s->items[s->top] = newitem ; 
		count++;
		}
}

void pop(st *s)
{
	if(isEmpty(s) == 1)
		{
		printf("Stack is empty!");
		return;
		}
	else 
	{
		printf("Item popped = %d",s->items[s->top]); 
		s->top--;
		count--;
	}
	printf("\n"); 
	return;
}


void printStack(st *s)
{
	int i ;
	printf("Stack:");
	for(i=0;i<count;i++)
		printf("%d ",s->items[i]);
	printf("\n");
	return;
}
void peek(st *s)
{
	printf("now the index of stack  is %d ,values =%d\n",s->top,s->items[s->top]);
	return ;
} 
int main()
{
	
	st *s = (st *)malloc(sizeof(st));
	
	createEmptyStack(s);
	
	push(1,s);
	push(2,s);
	push(3,s);
	push(4,s);
	printStack(s);
	push(5,s);
	
	peek(s);
	
	pop(s);
	pop(s);
	printf("\nAfter popping out\n");
	printStack(s);
	return 0;
}
