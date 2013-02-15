/*
 * Header file prototyping the list operations for the Linked List
 *
 * Author: Justin Walrath
 * Since: 2/14/2013
 */

#ifndef __NODEOPERATIONS_H
#define __NODEOPERATIONS_H

#include "node.h"

//Performs operations on the lists
void pushNode(Node **base, Node **top, Node **newNode);
void popNode(Node **base, Node **top);
void basePopNode(Node **base, Node **top);
void printList(Node **base);
void DeleteNode(Node **base, Node **top, int id);
Node* searchList(Node **base, int id);

#endif
