#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node 
{
	struct node* prev;
	int data;
	struct node* next;
}*start=NULL;
void create_linkedlist()
{
	char ch;
	printf("enter data\n");
	struct node* newnode,*curr;
	while(1)
	{
		printf("enter choice  ");
		ch=getche();
		if(ch=='n')
		break;
		int data;
		newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&data);
		newnode->data=data;
		newnode->next=NULL;
		newnode->prev=NULL;
		if(start==NULL)
		{
			start=newnode;
			curr=newnode;
		}
		else
		{
			curr->next=newnode;
			newnode->prev=curr;
			curr=newnode;
		}
	} 
	
}
void display()
{
	struct node *ptr=start;
	if(start==NULL)
	{
	printf("list is empty\n");
	return;
	}
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
}
void reversed_linkedlist(struct node*ptr)
{
	ptr=start;
	while(ptr->next!=NULL)
	{
	ptr=ptr->next;
	}
	printf("%d\t",ptr->data);
	while(ptr->prev!=NULL)
	{
		printf("%d\t",ptr->prev->data);
		ptr=ptr->prev;
	}
}

void insertion_atfirst()
{
	struct node *newnode;
	newnode =(struct node*)malloc(sizeof(struct node));
	printf("enter data \n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	
	if(start==NULL)
	{
	start=newnode;
	}
	else
	{
		newnode->next=start;
		start->prev=newnode;
		start=newnode;
	}
}
void insertion_atlast()
{
	struct node*newnode,*ptr;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&(*newnode).data);
	newnode->next=NULL;
	newnode->prev=NULL;
	if(start==NULL)
	{
	start=newnode;
	return;
	}
	
	ptr=start;
	while(ptr->next)
	ptr=ptr->next;
	newnode->prev=ptr;
	ptr->next=newnode;
	
}
void insertion_after_given_node(int x,int y)
{
	struct node* ptr=start;
	while(ptr!=NULL&&ptr->data!=x)
	ptr=ptr->next;
	if(ptr==NULL)
	{
		printf("insertion is not possible\n");
		return;
	}
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=y;
	if(ptr->next==NULL)
	{
		ptr->next=newnode;
		newnode->prev=ptr;
		return;
	}
	newnode->next=ptr->next;                      
 	 newnode->prev=ptr;					
	newnode->next->prev=newnode;
	ptr->next=newnode;
}
void insertion_before_given_node(int x,int y)
{
	struct node* ptr=start;
	while(ptr!=NULL&&ptr->data!=x)
	ptr=ptr->next;
	if(ptr==NULL)
	{
		printf("insertion is not possible\n");
		return;
	}
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->prev=NULL;
	newnode->next=NULL;
	newnode->data=y;
	if(start->data==x)
	{
		newnode->next=start;
		start->prev=newnode;
		start=newnode;
		return;
	}
	newnode->next=ptr;
	newnode->prev=ptr->prev;
	ptr->prev->next=newnode;
	ptr->prev=newnode;
}
void deletion_atfirst()
{
	struct node* ptr;
	ptr=start;
	if(start==NULL)
	{
	printf("deletion not possible\n");
	return;
	}
	start=start->next;
	start->prev=NULL;
	ptr->next=NULL;
	free(ptr);
}
void deletion_atlast()
{
	struct node* ptr;
	ptr=start;
	if(start==NULL)
	{
	printf("deletion not possible\n");
	return;
	}
	while(ptr->next)
	ptr=ptr->next;
	
	ptr->prev->next=NULL;
	ptr->prev=NULL;
	free(ptr);
}
int main()
{
	while(1)
	{
		int ch,x,y;
		scanf("%d",&ch);
	switch(ch)
		{
			case 1: printf("Create Linkedlist\n");
				create_linkedlist();
					break;
			case 2: printf("Display linked list\n");
				display();
					break;
			case 3: printf("Reverses Linkedlist\n");
				reversed_linkedlist(start);
					break;
			case 4: printf("Insertion at first position\n");
				insertion_atfirst();
					break;
			case 5: printf("insert at last position\n");
				insertion_atlast();
					break;
			case 6: printf("insertion after given node\n\n");
				printf("enter given node= ");  scanf("%d",&x);
				printf("enter number want to be insert= "); scanf("%d",&y);
				insertion_after_given_node(x,y);
					break;
			case 7: printf("insertion before given node\n\n");
				printf("enter given node= ");  scanf("%d",&x);
				printf("enter number want to be insert= "); scanf("%d",&y);
				insertion_before_given_node(x,y);
					break;
			case 8: printf("Deletion at first\n");
				deletion_atfirst();
					break;
			case 9: printf("deletion at last\n");
				deletion_atlast();
				break;
					
		}
	}
}
