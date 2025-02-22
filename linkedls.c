#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node
{
	int data;
	struct Node *next;
}*temp,*head=NULL,*newNode;

void create(int x)
{
	newNode=(struct Node *)malloc(sizeof(struct Node));
	newNode->data=x;
	newNode->next=NULL;

}

void beginsert(int x)
{
	create(x);
	if(head==NULL)
	{
		head=newNode;
	}
	else
	{
		newNode->next=head;
		head=newNode;
	}
}
void endinsert(int x)
{
	create(x);
	if(head==NULL)
	{
		head=newNode;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newNode;
	}

}
void midinsert(int pos,int x)
{
	int count=1;
	create(x);
	if(head==NULL)
	{
		head=newNode;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
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
		printf("Insert at the correct Position");

		
	}
}

void begdel()	
{
	if(head==NULL)
	{
		printf("Underflow");
	}
	else
	{
		temp=head;
		head=temp->next;
		free(temp);
	}

}

void enddel()
{
	struct Node *prev;
	temp=head;
	if(head==NULL)
	{
		printf("Underflow");
	}
	else if(temp->next==NULL)
	{
		free(head);
		head=NULL;
		return;
	}
	else
	{
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
			
		}
		prev->next=NULL;
		free(temp);
			
	}

}

void middel(int pos)
{
	int count=1;
	struct Node *prev;
	temp=head;
	if(head==NULL)
	{
		printf("Underflow");
	}
	else if(temp->next==NULL)
	{
		free(head);
		head=NULL;
		return;
	}
	else
	{
		while(temp->next!=NULL)
		{
			if(count==pos)
			{
				prev->next=temp->next;
				free(temp);
				return;
			}
			prev=temp;
			temp=temp->next;
			count++;
		}
		printf("You can delete only from the middle");
		return;
	}

}

void display()
{
	if(head==NULL)
	{
		printf("Underflow");
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}
		printf("%d",temp->data);
		
	}

}
void search(int ele)
{
	int count=1;
	if(head==NULL)
	{
		printf("Empty");
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			if(temp->data==ele)
			{
				printf("Element is found at %d",count);
				return;
			}
			temp=temp->next;
			count++;
		}
		
		printf("Element Not Found");
		
	}
}



void main()
{
	int ch,data,num,pos;
	printf("Menu:\n1.Insert at Beginning\n2.Display\n3.Search\n4.Exit\n5.Insert at End\n6.Insert in the Middle\n7.Delete in the Beginning");
	printf("\n8.Delete at the End\n9.Delete from the Middle");
	while(true)
	{
		printf("\nEnter you choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("Enter the data:");
				scanf("%d",&data);
				beginsert(data);
				break;
			case 2:
				display();
				break;
			case 3:
				printf("Enter the Search Element:");
				scanf("%d",&num);
				search(num);
				break;

			case 4:
				exit(0);
			case 5:
				printf("Enter the data:");
				scanf("%d",&data);
				endinsert(data);
				break;
			case 6:
				printf("Enter the position and Data:");
				scanf("%d %d",&pos,&data);
				midinsert(pos,data);
				break;
			case 7:
				begdel();
				break;
			case 8:
				enddel();
				break;
			case 9:
				printf("Enter the Position you want to delete");
				scanf("%d",&data);
				middel(data);
				break;

			default:
				printf("Invalid Choice");
				break;
		}

	}
}
