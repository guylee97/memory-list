#include <stdio.h.>
#include <stdlib.h>
#include <string.h>

struct node
{
	char *value;
	struct node *next;
};
typedef struct node node;
typedef node *pnode;


pnode create_node(char *val, int len);
pnode Insert_node(pnode new_node, pnode HEAD, pnode next_node);
pnode delete_node(pnode HEAD, pnode next_node);
void printnode(pnode HEAD, pnode next_node);
void middleprintnode(pnode HEAD, pnode next_node, int count);
void revprintnode(pnode HEAD, pnode next_node, int count);




int main()
{
	pnode HEAD = NULL;
	pnode next_node = NULL;
	int count;
	char tempval[4]="lame";
	count = 0;
	printf("ctrl+z : exit\n");
	while (gets(tempval))
	{
	    if (HEAD == NULL)
		{
			HEAD = Insert_node(create_node(tempval, strlen(tempval)), HEAD, next_node);
			next_node = HEAD;
		}
		else
		{
			next_node = Insert_node(create_node(tempval, strlen(tempval)), HEAD, next_node);
		}
		count++;
	}

	
	printf("µµÂø\n");
	printnode(HEAD, next_node);
	printf("ÀÚ·á°¹¼ö : %d \n",count);
	middleprintnode(HEAD, next_node, count);
	revprintnode(HEAD, next_node, count);
	HEAD = delete_node(HEAD, next_node);
	printnode(HEAD, next_node);
	
	system("pause");
	return 0;
}

pnode create_node(char *val,int len)
{
	pnode new_node = (pnode)malloc(sizeof(node));
	new_node->value = (char*)malloc(sizeof(char)*len);
	strcpy_s(new_node->value, sizeof(val),val);
	new_node->next = NULL;

	return new_node;
}

pnode Insert_node(pnode new_node, pnode HEAD, pnode next_node)
{
	if (HEAD == NULL)
	{
		HEAD = new_node;
		return HEAD;
	}

	else
	{
		while (next_node->next != NULL)
		{
			next_node = next_node->next;
		}
		next_node->next = new_node;
		return next_node;
	}
}

pnode delete_node(pnode HEAD, pnode next_node)
{
	pnode del;
	HEAD = HEAD->next;
	next_node = HEAD;
		while (next_node != NULL)
		{
			del = next_node->next;
			next_node->next = next_node->next->next;
			next_node = next_node->next;
			free(del);
		}
		
		
		return HEAD;
}

void printnode(pnode HEAD, pnode next_node)
{
	next_node = HEAD;
	while (next_node != NULL)
	{
		printf("%s ", next_node->value);
		next_node = next_node->next;
	}
	printf("\n");
}

void revprintnode(pnode HEAD, pnode next_node, int count)
{
	next_node = HEAD;
	int i;
	while (count!=0)
	{
		next_node = HEAD;
		for (i = 1; i < count; i++)
		{
			next_node = next_node->next;
		}
		printf("%s ", next_node->value);
		count--;
	}
	printf("\n");
}

void middleprintnode(pnode HEAD, pnode next_node, int count)
{
	next_node = HEAD;
	int i;
	count = count / 2 + 1;	
		for (i = 1; i < count; i++)
		{
			next_node = next_node->next;
		}
		printf("%s ", next_node->value);
		printf("\n");
}