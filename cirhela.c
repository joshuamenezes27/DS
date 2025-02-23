#include<stdio.h>
#include<stdlib.h>
int N,cnt;
struct Node {
	int data;
	struct Node *next;
}*tail=NULL,*newNode;

int get_length();
void create(int x)
{
	newNode=(struct Node *)malloc(sizeof(struct Node));
	newNode->data=x;
	newNode->next=NULL;

}

void beg_insert(int x)
{
	int co=get_length();
	if(co==N)
	{
		printf("List is FULL!!");
	}
	else
	{
		create(x);
		if(tail==NULL)
		{
			tail=newNode;
			newNode->next=newNode;
		}
		else
		{		
			newNode->next=tail->next;
			tail->next=newNode;

		}	
	}

}
void mid_insert(int x,int pos)
{
	int co=get_length();
	if(co==N)
	{
		printf("List is FULL!");
		return;
	}
	create(x);
	
	int count=1;
	if(tail==NULL)
	{
		tail=newNode;
		newNode->next=newNode;
		return;
	}
	struct Node *temp=tail->next;
	while(temp!=tail)
	{
		if(count==pos-1)
		{
			newNode->next=temp->next;
			temp->next=newNode;
			return;
		}
		count++;
		temp=temp->next;
			
	}
	printf("Position Out of Bound");
}

void end_insert(int x)
{
	int co=get_length();
	if(co==N)
	{
		printf("List is FULL!");
		return;
	}
	create(x);
	if(tail==NULL)
	{
		tail=newNode;
		newNode->next=newNode;
	}
	else
	{
		newNode->next=tail->next;
		tail->next=newNode;
		tail=newNode;
	}

}
int get_length()
{
	
	int count=1;
	if(tail==NULL)
	{
		return 0;
	}
	struct Node *temp=tail->next;
	do
	{
		count++;
		temp=temp->next;
			
	}while(temp!=tail);
	return count;
}



void display()
{
	
	if(tail==NULL)
	{
		printf("No Elements in the List");
		return;
	}
	struct Node *temp=tail->next;
	while(temp!=tail)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
}
void search(int ele)
{
	int count=1;
	if(tail==NULL)
	{
		printf("No element is present in the List");
		return;
	}
	struct Node *temp=tail->next;	
	do
	{
		if(ele==temp->data)
		{
			printf("Element Found at location %d",count);
			return;
		}
		count++;
		temp=temp->next;
	}while(temp!=tail->next);
	printf("Element is not present in the list");
}

void beg_del()
{
	if(tail==NULL)
	{
		printf("List is Empty");
		return;
	}
	struct Node *temp=tail->next;
	if(temp==tail)
	{
		tail=NULL;
		free(temp);
	}
	else
	{
		tail->next=temp->next;
		free(temp);
	}
	

}
void mid_del(int pos)
{
	int count=1;
	if(tail==NULL)
	{
		printf("List is Empty");
		return;
	}
	struct Node *temp=tail->next;
	struct Node *prev;
	while(temp!=tail)
	{
		if(pos==count)
		{
			prev->next=temp->next;
			free(temp);
			return;
		}

		count++;
		prev=temp;
		temp=temp->next;
	}
	printf("Element out of Bound");

}
void end_del()
{
	if(tail==NULL)
	{
		printf("No Element in the List");
		return;
	}
	struct Node *temp=tail->next;
	if(temp==tail)
	{
		beg_del();
		return;
	}
	while(temp!=tail)
	{
		if(temp->next==tail)
		{
			temp->next=tail->next;
			free(tail);
			tail=temp;
			return;

		}
		temp=temp->next;
	}

}
void main()
{
	int ch,ele,pos;
	printf("Enter the Number of Nodes to be created in a List");
	scanf("%d",&N);
	while(1)
	{
		printf("\nMenu:\n0.Get Length\n1.Insert at Beginning\n2.Insert at Middle\n3.Insert at the End\n4.Display\n5.Search\n6.Delete at the beginning\n7.Delete at Middle\n8.Delete at End\n9.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				int c=get_length();
				printf("%d",c);
				break;

			case 1:
				printf("Enter the Element in a List:");
				scanf("%d",&ele);
				beg_insert(ele);
				break;
			
			case 2:
				printf("Enter the Element and Position:");
				scanf("%d %d",&ele,&pos);
				mid_insert(ele,pos);
				break;

			case 3:
				printf("Enter the Element:");
				scanf("%d",&ele);
				end_insert(ele);
				break;
			case 4:
				display();
				break;
			case 5:
				printf("Enter the Search Element:");
				scanf("%d",&ele);
				search(ele);
				break;
			case 6:
				beg_del();
				break;
			case 7:
				printf("Enter the Position to Delete:");
				scanf("%d",&pos);
				mid_del(pos);
				break;
			case 8:
				end_del();
				break;

			case 9:
				exit(0);

			default:
				printf("Invalid Choice:");
				break;

		}
	}
}
