#include <stdio.h>
#define STACK_SIZE 100
int contents[STACK_SIZE];
int top=0;
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
int evaluate_RPN_expression(const char * expression)
void main()
{
	char input;
	int i;
	printf("Enter an RPN expression:");
	for(;;)
	{
		scanf(" %c",&input);
		if(input>='0'&&input<='9')
		{
			switch(input)
			{
			case '0': i=0;break;
			case '1': i=1;break;
			case '2': i=2;break;
			case '3': i=3;break;
			case '4': i=4;break;
			case '5': i=5;break;
			case '6': i=6;break;
			case '7': i=7;break;
			case '8': i=8;break;
			case '9': i=9;break;
			}
			push(i);
		}
		else if(input=='+')
			push(pop()+pop());
		else if(input=='*')
			push(pop()*pop());
		else if(input=='-')
			push(-pop()+pop());
		else if(input=='/')
			push((int)(1/((double)pop()/(double)pop())));
		else if(input=='=')
		{
			printf("%d\n",pop());
			printf("Enter an RPN expression:");
			make_empty();
		}
		else  return;

	}
}
void make_empty(void)
{
	top=0;
}
bool is_empty(void)
{
	return top==0;
}
bool is_full(void)
{
	return top==STACK_SIZE;
}
void push(int i)
{
	if(is_full())
		printf("Expression is too complex\n");
	else 
		contents[top++]=i;
}
int pop(void)
{
	if(is_empty())
		printf("Not enough operands in the expression\n");
	else 
		return contents[--top];
}