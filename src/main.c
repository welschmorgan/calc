#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

int main (int argc, char *argv[])
{
	(void)argc,(void)argv;
	t_list * l = list_alloc();
	list_push(l, node_alloc(0, '/', 10));
	list_push(l, node_alloc(0, '*', 10));
	list_push(l, node_alloc(0, '+', 10));
	list_push(l, node_alloc(0, '-', 10));
	list_print(l,1);
	list_free(l);
	return 0;
}
