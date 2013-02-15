#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "nodeOperations.h"


//User IO
void mainMenu();
Node* createNode(int id, char *name);

int main(int args, char* argv[])
{
	mainMenu();

	return(0);
}

/*
 * The main menu system for the list operations.
 */
void mainMenu()
{
	int selection = 0;
	int count = 1;
	int id;
   char *name; 
	Node *base, *top, *tmp;
	
	base = top = tmp = NULL;

	while(selection >= 0 && selection < 8)
	{
		printf("+-----------------------------------------------+\n");
		printf("|            List and user management           |\n");
		printf("+-----------------------------------------------+\n");
		printf("| 1: Display List                               |\n");
		printf("| 2: New Entry                                  |\n");
		printf("| 3: Edit Entry                                 |\n");
		printf("| 4: Delete Entry                               |\n");
		printf("| 5: Delete Last Entry                          |\n");
		printf("| 6: Search For Entry                           |\n");
		printf("| 7: Exit                                       |\n");
		printf("+-----------------------------------------------+\n");
		printf("| Choose Menu Option> ");

		scanf("%d", &selection);
		printf("\n\n\n\n");
		switch(selection)
		{
		case 1: //Print List
			printList(&base);
			break;
		case 2: //Make a new entry
				{
					name = (char*)malloc(102); 
					printf("+-----------------------------------------------+\n");
					printf("|                  Add New Item                 |\n");
					printf("+-----------------------------------------------+\n");
					printf("| Enter Name> ");
					scanf("%100s", name);
					tmp = createNode(count, name);
					pushNode(&base, &top, &tmp);
					count++;
					printf("\n\n**Name added!**\n\n\n\n");
				}
			break;
		case 3:
			printf("+-----------------------------------------------+\n");
			printf("|                   Edit a Node                 |\n");
			printf("+-----------------------------------------------+\n");
			printf("| Enter ID> ");
			scanf("%d", &id);
			printf("\n\n");
			tmp = searchList(&base, id);
			if(tmp == NULL)
			{
				printf("**List is empty**\n\n\n\n");
			}
			else
			{
            name = (char*)malloc(102); 
				printf("**%d: %s**\n\n", tmp->id, tmp->name);
            printf("Enter new name> ");
            scanf("%100s", name);
            free(tmp->name);
            tmp->name = name;
            printf("\n\n**Name edited!**\n\n\n\n");
			}
			break;
		case 4:
			printf("+-----------------------------------------------+\n");
			printf("|                 Delete a Node                 |\n");
			printf("+-----------------------------------------------+\n");
			printf("| Enter ID> ");
			scanf("%d", &id);
			printf("\n\n");
			DeleteNode(&base, &top, id);
			break;
		case 5:
			printf("+-----------------------------------------------+\n");
			printf("|               Deleting Last Node              |\n");
			printf("+-----------------------------------------------+\n");
			popNode(&base, &top);
			break;
		case 6:
			printf("+-----------------------------------------------+\n");
			printf("|                Search for Node                |\n");
			printf("+-----------------------------------------------+\n");
			printf("| Enter ID> ");
			scanf("%d", &id);
			printf("\n\n");
			tmp = searchList(&base, id);
			if(tmp == NULL)
			{
				printf("**List is empty**\n\n\n\n");
			}
			else
			{
				printf("**%d: %s**\n\n\n\n", tmp->id, tmp->name);
			}
			break;
		case 7:
			return;
		default:
			selection = -1;
		}
	}
}

/*
 * Stage a node for insertion
 */
Node* createNode(int id, char *name)
{
	Node *tmp;
	tmp = (Node*)malloc(sizeof(Node));
	tmp->id = id;
	tmp->name = name;
	tmp->next = NULL;
	tmp->prev = NULL;
	return(tmp);
}
