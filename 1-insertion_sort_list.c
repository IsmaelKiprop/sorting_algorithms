#include "sort.h"

/**
* insertion_sort_list - sort insertion sort algorithm
* @list: doubly linked list sorting
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *val;

	if ((list == NULL) || (*list == NULL) || ((*list)->next == NULL))
		return;

	tmp = *list;
	while (tmp)
	{
		if ((tmp->next != NULL) && (tmp->n > tmp->next->n))
		{
			swap(&tmp);
			val = tmp->prev;
			while (val != NULL && (val->prev != NULL) && (val->prev->n > val->n))
			{
				swap_back(&val);
			}
		}
		else
			tmp = tmp->next;
	}
	while ((*list)->prev != NULL)
		*list = (*list)->prev;
}

/**
* swap - swap nod list forward
* @top: ptr nod to swap
*/

void swap(listint_t **top)
{
	listint_t *tmp, *val;

	if (*top == NULL || top == NULL)
		return;

	tmp = *top;
	val = tmp->next;
	if (*top != NULL)
	{
		if (tmp->prev != NULL)
		{
			val->prev = tmp->prev;
			tmp->prev->next = val;
		}
		else
			val->prev = NULL;
		tmp->prev = val;
		if (val->next == NULL)
			tmp->next = NULL;
		else
		{
			tmp->next = val->next;
			val->next->prev = tmp;
		}
		val->next = tmp;
	}
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	print_list(tmp);
}

/**
* swap_back - swap nod list backward
* @top: ptr to nod swap
*/

void swap_back(listint_t **top)
{
	listint_t *tmp, *val;

	if (*top == NULL || top == NULL)
		return;
	tmp = *top;
	val = tmp->prev;
	if (val != NULL)
	{
		if (tmp->next != NULL)
		{
			val->next = tmp->next;
			tmp->next->prev = val;
		}
		else
			val->next = NULL;
		tmp->next = val;
		if (val->prev == NULL)
			tmp->prev = NULL;
		else
		{
			tmp->prev = val->prev;
			val->prev->next = tmp;
		}
		val->prev = tmp;
	}
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	print_list(tmp);
}
