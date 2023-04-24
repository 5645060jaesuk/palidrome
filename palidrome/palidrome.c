#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_STACK_SIZE 100



typedef char element;


typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;


void init_stack(StackType* s)
{
	s->top = -1;
}


int is_empty(StackType* s)
{
	return(s->top == -1);
}


int is_full(StackType* s)
{
	return(s->top == (MAX_STACK_SIZE - 1));
}



void push(StackType* s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}


element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		return;
	}
	else return s->data[(s->top)--];


}


int checking(char in[])
{
	StackType s;
	init_stack(&s);

	for (int i = 0; in[i] != NULL; i++)
	{
		if (in[i] >= 'A' && in[i] <= 'Z')
		{
			in[i] = in[i] + 32;
			push(&s, in[i]);
		}
		else if (in[i] >= 'a' && in[i] <= 'z')
		{
			push(&s, in[i]);
		}
	}
	for (int i = 0; in[i] != NULL; i++)
	{
		if (pop(&s) == in[i])
		{
			return 1;
		}
		else return 0;

	}

}



int main()
{
	StackType* s;


	while (1)
	{
		char str[100];
		char check[3];
		printf("문자열을 입력하세요 :");
		gets(str);
		if (checking(str))
		{
			printf("회문입니다\n");
		}
		else
		{
			printf("회문이 아닙니다\n");
		}


		printf("계속 입력하시겠습니까?(Yes/No) : ");
		gets(check);

		if (!strcmp(check, "No"))
		{
			exit(1);
		}

	}




}
