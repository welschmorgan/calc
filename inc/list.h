#ifndef __LIST__H
#define __LIST__H

struct s_list;

typedef struct  s_node
{
	struct s_node * next;
	struct s_node * prev;
	int level;
	int value;
	char op;
}				t_node;

typedef struct  s_list
{
	struct s_node * tail;
	struct s_node * head;
	int level;
}				t_list;

t_list* list_alloc();
void list_free(t_list*);
void list_init(t_list*l);
void list_clear(t_list*l);
void list_push(t_list*l,t_node*n);
void list_pop(t_list*l);
void list_print(t_list*l, int debug);

t_node* node_alloc(int lvl, char op, int value);
void node_init(t_node*n, int lvl, char op, int value);
void node_free(t_node*n);
void node_print(t_node*n, int sub_level, int debug);

#endif
