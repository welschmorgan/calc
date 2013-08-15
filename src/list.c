#include "list.h"
#include <stdlib.h>
#include <stdio.h>

#define abs(x) ((x<0)?-x:x)
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

void list_print(t_list*n, int debug)
{
	t_node*c;
	if(!n)return;
	c=n->tail;
	while(c)
	{
		node_print(c, 1, debug);
		c=c->next;
	}
}

void node_print(t_node*n, int sub_level, int debug)
{
	if(!n) return;
	char subs[20];
	int i=0;
	for( i=0; i<min(abs(sub_level),20);i++ )
		subs[i] = '\t';
	subs[i] = '\0';
	if( !debug )
		printf("%s%i%c (priority: %i)\n",
				sub_level?"\t":"",
				n->op,
				n->value,
				n->level);
	else
		printf("%s%i%c (priority: %i) prev:0x%x next:0x%x\n",
				sub_level?"\t":"",
				n->op,
				n->value,
				n->level,
				n->prev,
				n->next);
}

t_list* list_alloc()
{
	t_list* l = (t_list*)malloc(sizeof(t_list));
	list_init(l);
	return l;
}
void list_free(t_list*l)
{
	if(!l) return;
	list_clear(l);
	free(l);
}

void list_init(t_list*l)
{
	if(!l) return;
	l->tail=l->head=NULL;
	l->level=0;
}
void list_clear(t_list*l)
{
	t_node * n, * c;
	if(!l||!l->tail)
		return;
	c=l->tail;
	while(c)
	{
		n=c->next;
		free (c);
		c=n;
	}
	l->tail=l->head=NULL;
}
void list_push(t_list*l,t_node*n)
{
	t_node * oldHead;
	if(!l) return;
	if(!l->head)
	{
		l->head=n;
	}
	else
	{
		oldHead=l->head;
		oldHead->next=n;
		n->prev = oldHead;
		l->head = n;
	}
}
void list_pop(t_list*l)
{
	if(!l||!l->head) return;
	node_free(l->head);
}

t_node* node_alloc(int lvl, char op, int value)
{
	t_node * n=(t_node*)malloc(sizeof(t_node));
	node_init(n,lvl,op,value);
	return n;
}

void node_init(t_node*n, int lvl, char op, int value)
{
	if(!n) return;
	n->level=lvl;
	n->op=op;
	n->value=value;
	n->next=n->prev=NULL;
}

void node_free( t_node*n ){
	if(!n) return;
	if(n->prev)
		n->prev->next = n->next;
	free(n);
}
