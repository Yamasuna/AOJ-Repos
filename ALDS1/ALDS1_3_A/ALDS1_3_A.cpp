#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top, stack[1000];

void push(int x)
{
	top++;
	stack[top] = x;
}

int pop()
{
	top--;
	return stack[top + 1];
}

int main(void)
{
	int a, b;
	char operand[100];

	top = 0;

	while ( scanf("%s", operand) != EOF )
	{
		if ( operand[0] == '+' )
		{
			a = pop();
			b = pop();
			push(a + b);
		}
		else if ( operand[0] == '-' )
		{
			b = pop();
			a = pop();
			push(a - b);
		}
		else if ( operand[0] == '*')
		{
			a = pop();
			b = pop();
			push(a * b);
		}
		else
		{
			push(atoi(operand));
		}
	}
	printf("%d\n", pop() );
	return 0;
}