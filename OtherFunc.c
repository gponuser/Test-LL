#include<stdlib.h>
#include<stdio.h>

void insertHead(int val);
void insertNode(int val);
void displayList();
void addHead(int val);
void addTail(int val);
void addAfterNode(int after, int val);
void deleteHead();
void deleteTail();
void deleteNode(int val);

struct node
{
	int data;
	struct node* next;
};

struct node *head;

int getSortTypeOption()
{
	int res;
	printf("\n Do you wish to operate on sorted Link List??? (0-No 1-Yes)");
	scanf("%d",&res);
	return res;
}
int getMenuOption()
{
	int ch;
	printf("\n\n\n");
	printf("\n 1- Create List");
	printf("\n 2- Add Node at Head");
	printf("\n 3- Add Node at Tail");
	printf("\n 4- Add Node after a Node");
	printf("\n 5- Delete Node from Head");
	printf("\n 6- Delete Node from Tail");
	printf("\n 7- Delete Node from between");
	printf("\n 8- Destroy List");
	printf("\n 9- Display List");
	printf("\n 10- Exit");
	printf("\n Enter Your choice - ");
	scanf("%d",&ch);
	return ch;
	
}

int getSortedMenuOperation()
{
        int ch;
        printf("\n\n\n");
        printf("\n 1- Create Sorted List");
        printf("\n 2- Add Node");
        printf("\n 3- Delete Node from Head");
        printf("\n 4- Delete Node from Tail");
        printf("\n 5- Delete Node from between");
        printf("\n 6- Destroy List");
        printf("\n 7- Display List");
        printf("\n 8- Exit");
        printf("\n Enter Your choice - ");
        scanf("%d",&ch);
        return ch;
        
}

void performOperation(int Option)
{
	int val, after; 
	switch(Option)
		{
			case 1:
				printf("\n Create List - \n");
				printf("\n Enter the value - ");
        			scanf("%d",&val);
			        if(val != -1)
        			{
                			insertHead(val);
		                	while(1)	
		        	        {
        		        	        printf("\n Enter the value - ");
                		        	scanf("%d",&val);
	                		        if(val == -1)
        	                		        break;
		                	        else
        		                	        insertNode(val);
	        		        }
        	        		displayList();
			    	}
				break;
	
			case 2:
				printf("\n Add Node at Head");
				printf("\n Enter the value- ");
				scanf("%d",&val);
				addHead(val);
				printf("\n Node added at Head");
				break;

			case 3:
				printf("\n Add Node at Tail");
				printf("\n Enter the value- ");
				scanf("%d",&val);
				addTail(val);
				printf("\n Node added at Tail");
				break;

			case 4:
				printf("\n Add Node after a node");
				printf("\n Enter the value to add- ");
				scanf("%d",&val);
				printf("\n Enter the value of node after which the value is to be added- ");
				scanf("%d",&after);
				addAfterNode(after,val);
				printf("\n Node added after a Node");
				break;
				
			case 5:
				printf("\n Delete Node from Head");
				deleteHead();
				printf("\n Node deleted from Head");
				break;
	
			case 6:			
				printf("\n Delete Node from Tail");
				deleteTail();
				printf("\n Node deleted from Tail");
				break;
	
			case 7:
				printf("\n Delete Node from between");
				printf("\n Enter the value of node to be deleted- ");
				scanf("%d",&val);
				deleteNode(val);
				printf("\n Node deleted");
				break;
			case 8:	
				printf("\nDestroy list");
				break;
		
			case 9:
				printf("\n Display List");
				displayList();
				break;
			
			case 10:
				printf("\n Exit\n");
				return(0);
					
		}
}

int performSortedOperation(int Option)
{
	int val,after;
	switch(Option)
		{
			case 1:
				printf("\n Create List - \n");
				printf("\n Enter the value - ");
        			scanf("%d",&val);
			        if(val != -1)
        			{
                			insertHead(val);
		                	while(1)	
		        	        {
        		        	        printf("\n Enter the value - ");
                		        	scanf("%d",&val);
	                		        if(val == -1)
        	                		        break;
		                	        else
        		                	        insertNode(val);
	        		        }
        	        		displayList();
			    	}
				break;
	
			case 2:
				printf("\n Add Node at Head");
				printf("\n Enter the value- ");
				scanf("%d",&val);
				addHead(val);
				printf("\n Node added at Head");
				break;

			case 3:
				printf("\n Add Node at Tail");
				printf("\n Enter the value- ");
				scanf("%d",&val);
				addTail(val);
				printf("\n Node added at Tail");
				break;

			case 4:
				printf("\n Add Node after a node");
				printf("\n Enter the value to add- ");
				scanf("%d",&val);
				printf("\n Enter the value of node after which the value is to be added- ");
				scanf("%d",&after);
				addAfterNode(after,val);
				printf("\n Node added after a Node");
				break;
				
			case 5:
				printf("\n Delete Node from Head");
				deleteHead();
				printf("\n Node deleted from Head");
				break;
	
			case 6:			
				printf("\n Delete Node from Tail");
				deleteTail();
				printf("\n Node deleted from Tail");
				break;
	
			case 7:
				printf("\n Delete Node from between");
				printf("\n Enter the value of node to be deleted- ");
				scanf("%d",&val);
				deleteNode(val);
				printf("\n Node deleted");
				break;
			case 8:	
				printf("\nDestroy list");
				destroyList();
				break;
		
			case 9:
				printf("\n Display List");
				displayList();
				break;
			
			case 10:
				printf("\n Exit\n");
				return(0);
					
		}
}

void insertHead(int val)
{
	head = (struct node*)malloc(sizeof(struct node));
	head->data = val;
	head->next = NULL;
}

void insertNode(int val)
{
	struct node *temp;
	temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	
	temp->next = (struct node*)malloc(sizeof(struct node));
	temp = temp->next;
	temp->data = val;
	temp->next = NULL;
}

void displayList()
{
	struct node *temp;
	temp = head;
	while(temp != NULL)
	{
		printf("\n %d",temp->data);
		temp = temp->next;
	}
}

void addHead(int val)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = val;
	temp->next = head;
	head = temp;
}

void addTail(int val)
{
	struct node *temp, *ptr;
	ptr = head;
	while(ptr->next != NULL)
		ptr = ptr->next;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = val;
	temp->next = NULL;
	ptr->next = temp;
}

void addAfterNode(int after, int val)
{
	struct node *temp, *ptr;
	ptr = head;
	while(ptr->data != after)
		ptr = ptr->next;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = val;
	temp->next = ptr->next;
	ptr->next = temp;
}

void deleteHead()
{
	struct node *temp;
	temp = head;
	head = head->next;
	free(temp);
}

void deleteTail()
{
	struct node *temp, *ptr;
	ptr = head;
	temp = head;
	while(temp->next != NULL)
	{
		ptr = temp;
		temp = temp->next;
	}
	ptr->next = NULL;
	free(temp);
}

void deleteNode(int val)
{
	struct node *temp, *ptr;
	ptr = head;
	temp = head;
	while(temp->data != val)
	{
		ptr = temp;
		temp = temp->next;
	}
	ptr->next = temp->next;
	free(temp);
}

void destroyList(struct node *ptr)
{
	while(head != NULL)
	{
		deleteHead(ptr);
	}
		
	
}
