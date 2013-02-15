/*
 * List of operations defined 
 */
#include<stdio.h>
#include<stdlib.h>
#include "nodeOperations.h"

/*
 * Pushes a new value on top of the linked list.
 */
void pushNode(Node **base, Node **top, Node **newNode)
{
	if((*top) == NULL)
	{
		(*top) = (*newNode);
		(*base) = (*top);
	}
	else if((*top)->prev == NULL)
	{
		(*top)->next = (*newNode);
		(*top)->next->prev = (*top);
		(*top) = (*top)->next;
		(*base) = (*top)->prev;
	}
	else
	{
	   (*top)->next = (*newNode);
		(*top)->next->prev = (*top);
		(*top) = (*top)->next;
	}
}

/*
 * Pops the top of the linked list.
 */
void popNode(Node **base, Node **top)
{
	if((*top) == NULL)
	{
		printf("**List is empty**\n\n\n\n");
		return;
	}
	else if((*top) == (*base))
	{
		free((*top));
		(*top) = (*base) = NULL;
		printf("**Deleted Node, No More Nodes Left**\n\n\n\n");
	}
	else
	{
		(*top) = (*top)->prev;
		free((*top)->next);
		(*top)->next = NULL;
		printf("**Deleted Top Node**\n\n\n\n");
	}
}

/*
 * Pops the base of the linked list.
 */
void basePopNode(Node **base, Node **top)
{
	if((*base) == NULL)
	{
		printf("**List is empty**\n\n\n\n");
		return;
	}
	else if((*top) == (*base))
	{
		free((*base));
		(*top) = (*base) = NULL;
		printf("**Deleted Node, No More Nodes Left**\n\n\n\n");
	}
	else
	{
		(*base) = (*base)->next;
		free((*base)->prev);
		(*base)->prev = NULL;
		printf("**Deleted Bottom Node**\n\n\n\n");
	}
}

/*
 * Displays all of the Nodes from the base to the top.
 */
void printList(Node **base)
{
	printf("+-----------------------------------------------+\n");
	printf("|                  List Printing                |\n");
	printf("+-----------------------------------------------+\n");
	if((*base) == NULL)
	{
		printf("**List is empty**\n\n\n\n");
	}
	else
	{
		Node *iterator;
		iterator = (*base);
		while(iterator != NULL)
		{
			printf("%d: %s\n", iterator->id, iterator->name);
			iterator = iterator->next;
		}
		printf("**End of list**\n\n\n\n");
	}
}

/*
 * Pops the the identified node of the linked list.
 */
void DeleteNode(Node **base, Node **top, int id)
{
	if((*base) != NULL)
	{
		Node *tmp;
		tmp = searchList(&(*base), id);
		if(tmp == NULL)
		{
			printf("**Id not found**\n\n\n\n");
			return; //Just in case. Covers a one node left situation.
		}
		else if(tmp == (*base))
		{
			basePopNode(&(*base), &(*top));
			return;	//Just in case. Covers a one node left situation.
		}
		else if(tmp == (*top))
		{
			popNode(&(*base), &(*top));
		}
		else
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			tmp->next = NULL;
			tmp->prev = NULL;
			free(tmp);
		}
	}
	else
	{
		printf("**List is empty**\n\n\n\n");
		return;
	}
}

/*
 * Searches the list and returns a pointer to a Node that has the ID searched for.
 * Returns NULL if there is no match found.
 */
Node* searchList(Node **base, int id)
{
	Node *tmp;
	tmp = (*base);

	while(tmp != NULL)
	{
		if(tmp->id == id)
			return(tmp);
		tmp = tmp->next;
	}
	return(tmp);
}
#pragma endregion
