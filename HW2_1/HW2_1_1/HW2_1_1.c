#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 3

typedef int element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType *s)
{
	s->top = -1;
}

int is_empty(StackType *s)
{
	return (s->top == -1);
}

int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE-1));
}

void push(StackType *s, element item)
{ 
    if( is_full(s) ) { 
		fprintf(stderr,"���� ��ȭ ����\n");
		return; 		 
	} 
	else 
		s->stack[++(s->top)] = item; 
}


element pop(StackType *s) 
{ 
   	if( is_empty(s) ) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1); 		
	}
	else 
		return s->stack[(s->top)--]; 
} 

element peek(StackType *s) 
{ 
   	if( is_empty(s) ) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1); 		
	}
	else 
		return s->stack[s->top]; 
}

void stack_print(StackType *s)
{
	int i;
	if( is_empty(s) ) {
		printf("<empty>\n--\n");
		return;
	}
	else {
		printf("%d <- top\n", s->stack[s->top]);
		for(i = s->top-1; i >= 0; i--)
			printf("%d\n", s->stack[i]);
		printf("--\n");
	}
}

void main(void)
{
	StackType s;

	init(&s);
	stack_print(&s);

	push(&s, 10);
	stack_print(&s);
	push(&s, 20);
	stack_print(&s);
	push(&s, 30);
	stack_print(&s);

	push(&s, 40);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	push(&s, 50);
	stack_print(&s);
	
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
}
