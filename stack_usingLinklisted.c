#include <stdlib.h>
#include <stdio.h>
struct stack
{
	int data;
	struct stack *next;
};
typedef struct stack st;
st *head;

void createEmptyStack()
{
	head = NULL; //一開始讓head指向歸零 
}

int isEmpty()
{
	if(head == NULL)
	return 1;
	else
	return 0;
}
// 如果用list 實作stack 則沒有FULL的問題 

void push(int newitem)
{
	st *new_node = (st*)malloc(sizeof(st));
	new_node->data = newitem;
	new_node->next = NULL;
	
	if(isEmpty() == 1)
		head = new_node;//目前head 只向現在這個node 
	else
	{
		new_node->next = head;//因為在前一個node已經將位址給head了，讓這個new_node知道前面還有一個node 
		head = new_node;//再將現在自己new_node assign 給head 
	}				
}	
int pop()
{
	if(isEmpty()== 1)
		printf("Stack is empty!\n");
	else
	{
		st *temp = head;
		head = head->next;
		return temp->data;
	}
}
void printStack(st *s)
{
	if(isEmpty() == 1)
		return;
	else
	{ 
	st *current = head ;
	while(current != NULL)
	{
		printf("%d ",current->data);
		current = current->next;
	}
	} 
	printf("\n");
}
int main()
{
	st *s = (st *)malloc(sizeof(st));
	createEmptyStack();
	push(1);
	push(2);
	push(3);
	push(4);
	printStack(s);
	
	pop();
	pop();
	printStack(s);
	return 0;
}
