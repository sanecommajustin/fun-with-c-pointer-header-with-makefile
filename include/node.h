/*
 * Global node for use by all source code.
 * 
 * Author: Justin Walrath <walrathjaw@gmail.com>
 * Since: 2/15/2013
 */

#ifndef __NODE_H
#define __NODE_H

typedef struct node
{
	struct node* next;
	struct node* prev;
	int id;
	char* name;
} Node;

#endif
