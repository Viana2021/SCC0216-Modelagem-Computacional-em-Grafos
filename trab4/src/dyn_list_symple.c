#include <stdio.h>
#include <stdlib.h>
#include <dyn_list_simple.h>
#include <defines.h>

DYN_LIST_SIMPLE *dyn_list_simple_create()
{
	DYN_LIST_SIMPLE *list;
	list = (DYN_LIST_SIMPLE *) calloc(1, sizeof(DYN_LIST_SIMPLE));
	return list;
}

int dyn_list_simple_insert(DYN_LIST_SIMPLE *list, int destination, int time, int price)
{
	if(!list) return ERROR;
	int exists = FALSE;

	DYN_LIST_SIMPLE_ELEM *new = (DYN_LIST_SIMPLE_ELEM *) calloc(1, sizeof(DYN_LIST_SIMPLE_ELEM));
	new->value = destination;
	new->time = time;
	new->price = price;
	if(!list->first && !list->last) list->first = list->last = new;
	else
	{
		DYN_LIST_SIMPLE_ELEM *p = list->first;
		while(!exists && p)
		{
			if(p->value == destination) exists = TRUE;
			else p = p->next;
		}
		if(!exists)
		{
			list->last->next = new;
			list->last = new;
			list->n_elem++;
		}
	}
	return SUCCESS;
}

int dyn_list_simple_remove(DYN_LIST_SIMPLE *list, int vertex)
{
	if(!list) return ERROR;

	int isThere = FALSE;

	DYN_LIST_SIMPLE_ELEM *p = list->first;
	if(list->first->value == vertex)
	{
		list->first = list->first->next;
		isThere = TRUE;
	}
	else
	{
		DYN_LIST_SIMPLE_ELEM *prev;
		while(p->next && !isThere)
		{
			if(p->next->value == vertex)
			{
				prev = p;
				p = p->next;
				if(p->next) prev->next = p->next;
				else {list->last = prev; prev->next = NULL;}
				isThere = TRUE;
			}
			else p = p->next;
		}
	}

	if(isThere)
	{
		p = NULL;
		free(p);
		list->n_elem--;
	}
	else return ERROR;

	return SUCCESS;
}

int dyn_list_simple_print(DYN_LIST_SIMPLE *list)
{
	if(!list) return ERROR;

	DYN_LIST_SIMPLE_ELEM *p = list->first;
	while(p)
	{
		printf("%d ", p->value);
		p = p->next;
	}
	return SUCCESS;
}

int dyn_list_simple_delete(DYN_LIST_SIMPLE *list)
{
	if(!list) return ERROR;
	int i;

	for(i = 0; i < list->n_elem; i++) dyn_list_simple_remove(list, i);
	free(list);

	return SUCCESS;
}

int dyn_list_simple_remove_first(DYN_LIST_SIMPLE *list)
{
	int value = list->first->value;
	dyn_list_simple_remove(list, value);
	return value;
}

