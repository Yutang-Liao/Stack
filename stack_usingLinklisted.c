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
	head = NULL; //�@�}�l��head���V�k�s 
}

int isEmpty()
{
	if(head == NULL)
	return 1;
	else
	return 0;
}
// �p�G��list ��@stack �h�S��FULL�����D 

void push(int newitem)
{
	st *new_node = (st*)malloc(sizeof(st));
	new_node->data = newitem;
	new_node->next = NULL;
	
	if(isEmpty() == 1)
		head = new_node;//�ثehead �u�V�{�b�o��node 
	else
	{
		new_node->next = head;//�]���b�e�@��node�w�g�N��}��head�F�A���o��new_node���D�e���٦��@��node 
		head = new_node;//�A�N�{�b�ۤvnew_node assign ��head 
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
