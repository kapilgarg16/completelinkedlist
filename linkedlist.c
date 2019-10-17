#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*start=NULL,*start1=NULL,*start2=NULL;

void createlinkedlist(struct node **start)
{
	struct node *newnode, *current;
	
	while(1)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(*start==NULL)
		{
		*start=newnode;	
		current=newnode;
		}
		else
		{
		current->next=newnode;
		current=newnode;
		}
		int ch;
		printf("enter choice ");
		ch=getche();
		if(ch=='n')
		break;
	}
	printf("\n");
}
void displaylinkedlist(struct node*start)
{
	struct node* ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}		
	printf("\n");
}
void deletelinkedlist()
{
	struct node* ptr;
	ptr=start;
	while(start!=NULL)
	{
		start=start->next;
		ptr->next=NULL;
		free(ptr);
	}
}
void insertatfirst()
{
	struct node* newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("memory error\n");
		return;
	}
	printf("enter data want to insert\n");
	scanf("%d",&newnode->data);
	newnode->next=start;
	start=newnode;
}
void insertatlast()
{
	struct node *newnode,*ptr;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("memory error\n");
		return;
	}
	printf("enter data want to insert at last\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(start==NULL)
	{
		start=newnode;
		return;
	}
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;	
	}
	ptr->next=newnode;
}
void delete_at_first()
{
	if(start==NULL)
	{
	printf("deletion not possibe\n"); 
	return;
	}
	struct node* ptr;
	ptr=start;
	start=start->next;
	ptr->next=NULL;
	free(ptr);
}
void delete_at_last()
{
	struct node *ptr,*prev;
	if(start==NULL)
	{
	printf("deletion not possibe\n");
	return;
	}
	if(start->next==NULL)
	{
	free(start);
	return;
	}
	ptr=start;
	while(ptr->next!=NULL)
	{
		prev=ptr;
		ptr=ptr->next;	
	}
	free(ptr);
	prev->next=NULL;
	
}
void search_a_element()
{
	struct node *ptr;
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	printf("enter elemnt want to search\n");
	int num;
	scanf("%d",&num);
	ptr=start;
	while(ptr!=NULL&&ptr->data!=num)
	{
	ptr=ptr->next;
	}
	if(ptr==NULL)
	printf("element not found\n");
	else
	printf("element found\n");
}
void delete_given_node()
{
	struct node *ptr,*prev;
	if(start==NULL)
	{
	printf("deletion not possibe\n");
	return;
	}
	printf("enter data want to delete\n");
	int e;
	scanf("%d",&e);
	ptr=start;
	if(start->data==e)
	{
		start=start->next;
		ptr->next=NULL;
		free(ptr);
		return;
	}
	while(ptr->data!=e&&ptr!=NULL)
	{
	prev=ptr;
	ptr=ptr->next;
	}
	if(ptr==NULL)
	{
		printf("element not found\n");
		return;
	}
	prev->next=ptr->next;
	ptr->next=NULL;
	free(ptr);
}
void linkedlistbubblesort()
{
	printf("after bubble sort\n");
	struct node *ptr,*lptr;
	int f,t;
	lptr=NULL;
	do
	{
		f=0;
		ptr=start;
	while(ptr->next!=lptr)
	{
		if(ptr->data>ptr->next->data)
		{
		t=ptr->data;
		ptr->data=ptr->next->data;
		ptr->next->data=t;
		f=1;
		}
		ptr=ptr->next;
	}	
	lptr=ptr;
	}while(f);	
}
void print_data_in_reverse(struct node* ptr)
{
	if(ptr==NULL)
	return;
	print_data_in_reverse(ptr->next);
	printf("%d\t",ptr->data);
}
void remove_duplicate_element()
{
	struct node *dup,*ptr,*ptr1;
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr1=ptr;
		while(ptr1->next!=NULL)
		{
			if(ptr->data==ptr1->next->data)
			{
			dup=ptr1->next;
			ptr1->next=dup->next;
			dup->next=NULL;
			free(dup);
			}
			else
			{
			ptr1=ptr1->next;
			}
		} 
		ptr=ptr->next;
	}
}
void swap_alternate_element()
{
	printf("swapping alternate elememt\n");
	struct node* ptr;
	ptr=start;
	int t;
	while(ptr&&ptr->next)
	{
		t=ptr->data;
		ptr->data=ptr->next->data;
		ptr->next->data=t;
		
		ptr=ptr->next->next;
	}
}
struct node* middle_node(struct node*start_node,struct node* end_node)
{
	if(start==NULL)
		return;
	struct node *slow_node,*fast_node;
	slow_node=start_node;
	fast_node=start_node->next;
	while(fast_node!=end_node)
	{
		fast_node=fast_node->next;
		if(fast_node!=end_node)
		{
			slow_node=slow_node->next;
			fast_node=fast_node->next;
		}
	}
	return slow_node;
}
void binary_search()
{
	struct node *start_node=start,*end_node=NULL,*mid;
	printf("enter data want binary search\n");
	int e;
	scanf("%d",&e);
	while(end_node==NULL||start_node!=end_node->next)	//doubt only this condition**
	{
		mid=middle_node(start_node,end_node);
		if(mid->data==e)
		{
			printf("element found\n");
			return;
		}
		else if(e>mid->data)
		{
			start_node=mid->next;
		}
		else if(e<mid->data)
		{
			end_node=mid;
		}
	}
	printf("element not found\n");
}
void insert_after_given_node()
{
	int d,e;
	printf("given node data\n");
	scanf("%d",&d);
	struct node* newnode,*ptr;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("insert item want insert\n");
	scanf("%d",&e);
	newnode->data=e;
	newnode->next=NULL;
	ptr=start;
	while(ptr->next!=NULL)
	{
		if(ptr->data==d)
		{
		newnode->next=ptr->next;
		ptr->next=newnode;
		return;
		}
		ptr=ptr->next;
	}
	if(ptr->data==d)
	ptr->next=newnode;
}
void insert_before_given_node()
{
	int d,e;
	printf("given node data\n");
	scanf("%d",&d);
	struct node* newnode,*ptr;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("insert item want insert\n");
	scanf("%d",&e);
	newnode->data=e;
	newnode->next=NULL;
	
	if(start->data==d)
	{
		newnode->next=start;
		start=newnode;
		return;
	}
	ptr=start;
	while(ptr->next!=NULL)
	{
		if(ptr->next->data==d)
		{
			newnode->next=ptr->next;
			ptr->next=newnode;
			return;
		}
		ptr=ptr->next;
	}
}
void reverselinkedlist()
{
	struct node *curr,*fast,*prev;
	curr=NULL;
	prev=NULL;
	fast=start;
	while(fast!=NULL)
	{
		prev=curr;
		curr=fast;
		fast=fast->next;
		curr->next=prev;	
	}
	start=curr;
}
void palindromelinkedlist()
{
	struct node* ptr,*curr,*fast,*prev,*ptr1;
	ptr=middle_node(start,NULL);
	printf("%d\n",ptr->data);
	curr=NULL;
	prev=NULL;
	fast=ptr;
	while(fast!=NULL)
	{
		prev=curr;
		curr=fast;
		fast=fast->next;
		curr->next=prev;	
	}
	start1=curr;
	//displaylinkedlist(start);
	//displaylinkedlist(start1);
	ptr1=start1;
	ptr=start;
	int f=0;
	while(ptr!=NULL&&ptr1!=NULL)
	{
		if(ptr->data!=ptr1->data)
		{
			f=1;
			break;
		}
		ptr=ptr->next;
		ptr1=ptr1->next;
	}
	if(f)
	printf("linked list is not palinrome\n\n");
	else
	printf("linked list is palinrome\n\n");
}
struct node* newnode(int data)
{
	struct node* node;
	node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->next=NULL;
	return node;
}
void merge_linked_list()
{
	printf("input 1st linked list\n");
	createlinkedlist(&start);
	printf("\ninput 2nd linked list\n");
	createlinkedlist(&start1);
	printf("display 1st\n");
	displaylinkedlist(start);
	printf("display 2nd\n");
	displaylinkedlist(start1);
	
	printf(" After merging of two linked list\n\n");
	
	struct node *ptr1,*ptr2,*ptr3,*node;
	ptr1=start;
	ptr2=start1;                            
	ptr3=start2;
	while(ptr1!=NULL&&ptr2!=NULL)
	{
		if(ptr1->data<ptr2->data)
		{
			node=newnode(ptr1->data);
			if(start2==NULL)
			start2=node;
			
			else
			ptr3->next=node;

			ptr1=ptr1->next;
		}
		else
		{
			node=newnode(ptr2->data);
			if(start2==NULL)
			start2=node;
			
			else
			ptr3->next=node;
			
			ptr2=ptr2->next;
		}
		ptr3=node;
	}
	while(ptr1!=NULL)
	{
		node=newnode(ptr1->data);
		ptr3->next=node;
		ptr1=ptr1->next;
		ptr3=node;
	}
	while(ptr2!=NULL)
	{
		node=newnode(ptr2->data);
		ptr3->next=node;
		ptr2=ptr2->next;
		ptr3=node;
	}
	displaylinkedlist(start2);
}
int main()
{
printf("1.create linkedlist\n2.displaylinklist\n3.insertatfirst\n4.insertatlast\n5.deleteatfirst\n6.deleteatlast\n7.searching a element\
\n8.delete a node from given position\n9.linkedlistbubblesort\n10.print_data_in_reverse\n11.remove_duplicate_element\n\
12.swap_alternate_element\n13.find middle node of a linkedlist\n14.binary_search\n15.insert_after_given_node\n16.insert_before_given_node\n17.reversedlinkedlist\n\
18.palindromelinkedlist\n19.delete linked lise\n20.merge_two_linkedlist\n21.exit\n\n");

while(1)
{
	int ch;
	struct node* ptr;
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("CREATE LINKEDLIST...\n\n"); 
			printf("enter data\n"); 
			 createlinkedlist(&start);
				break;
		case 2: printf("Display Linkedlist...\n\n"); 
			displaylinkedlist(start);
				break;
		case 3: printf("Insert at 1st position\n\n"); 
			insertatfirst();
				break;
		case 4:	 printf("Insert at last position...\n\n");
			insertatlast();
				break;
		case 5: printf("Delete at 1st position...\n\n"); 
			delete_at_first();
				break;
		case 6: printf("Delete at last position...\n\n"); 
			delete_at_last();
				break;
		case 7: printf("Search a element...\n\n"); 
			search_a_element();
				break;
		case 8: printf("Delete a given node...\n\n");
			delete_given_node();
				break;
		case 9:  printf("Bubble Sort...\n\n");
			linkedlistbubblesort();
				break;
		case 10: printf("print element Reverse...\n\n");
			print_data_in_reverse(start);
				break;
		case 11:printf("Remove Duplicate Element...\n"); 
			remove_duplicate_element();
				break;
		case 12:printf("Swap Alternate Element...\n"); 
			swap_alternate_element();
				break;
		case 13: ptr=middle_node(start,NULL);
		    		printf("Middle element of linkedlist is =%d \n",ptr->data);
				break;
		case 14:printf("Binary search in a linked list...\n\n"); 
			binary_search();
				break;
		case 15:printf("Insert after a  given node...\n\n");
			 insert_after_given_node();
				break;
		case 16: printf("Insert before given NODE...\n\n");
			 insert_before_given_node();
				break;
		case 17: printf("Reverse a Linkedlist...\n\n");
			reverselinkedlist();
				break;
		case 18:printf("Search linked list is PALINDROME or not.....\n");
			 palindromelinkedlist();
				break;
		case 19: printf("Delete a Total linked list...\n\n");
			deletelinkedlist();
				break;
		case 20: printf("Merge two linked list...\n\n");
			merge_linked_list();
				break; 		
		case 21: exit;
				break;
		default: printf("enter right key");
	}
}
}
