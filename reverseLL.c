#include <stdio.h>


struct LL_node
{
	struct LL_node * next;
	int val;
};

typedef struct LL_node node;

void createLL(node *);
void displayLL(node * head);
node * reverseLL(node * head);
node * diffLL(node * head1, node * head2);

int main()
{
	node * head1, * head2, * head3;
	head1 = (node*)malloc(sizeof(node));
	head2 = (node*)malloc(sizeof(node));
	printf("\n Enter elements of list1 - \n");
	createLL(head1);
	printf("\n The linked list entered is - ");
	displayLL(head1);
	printf("\n Enter elements of list2 - \n");
	createLL(head2);
	printf("\n The linked list entered is - ");
	displayLL(head2);
	
	
	head1 = reverseLL(head1);
	head2 = reverseLL(head2);
	
	head3 = diffLL(head1, head2);
	reverseLL(head3);
	
	printf("\n The difference linked list is - ");
	displayLL(head3);
	return 0;
}

void createLL(node * head)
{
	int v;
	node * ptr;
	ptr = head;
	scanf("%d",&v);
	if(v != -1)
	{
		ptr->val = v;
		scanf("%d",&v);
	}
	while(v != -1)
	{
		ptr->next = (node*)malloc(sizeof(node));
		ptr = ptr->next;
		ptr->val = v;
		scanf("%d", &v);
	}
	ptr = NULL;
}

void displayLL(node * head)
{
	node * ptr = head;
	while(ptr != NULL)
	{
		printf("[%d]->", ptr->val);
		ptr = ptr->next;
	}
	printf("NULL");
}

node * reverseLL(node * head)
{
	node * p, * q, * r;
	p = head;
	q = p->next;
	p->next = NULL;
	while(q != NULL)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	head = p;
	return head;
}


node * diffLL(node * head1, node * head2)
{
	node * head3,* ptr1, * ptr2, * ptr3;
	int carry;
	head3 = (node *)malloc(sizeof(node));
	ptr1 = head1;
	ptr2 = head2;
	ptr3 = head3;
	while(ptr2->next != NULL || ptr1->next != NULL)
	{
		if(ptr1->val < ptr2->val)
		{
			ptr1->next->val = ptr1->next->val - 1;
			ptr1->val = ptr1->val + 10;
		}
		ptr3->val = ptr1->val - ptr2->val;
		ptr3->next = (node *)malloc(sizeof(node));
		ptr3 = ptr3->next;
		
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	ptr3->val = ptr1->val - ptr2->val;
	ptr3->next = NULL;
	return(head3);
}
