#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
};
struct Node *new,*head=NULL,*tail=NULL;

void create(int x)
{
	new=(struct Node*)malloc(sizeof(struct Node));
	new->data=x;
	new->prev=NULL;
	new->next=NULL;
}
void beg_insert(int x)
{
	create(x);
	if(head==NULL)
	{
		head=tail=new;

	}
	else
	{
		new->next=head;
		head->prev=new;
		head=new;	
	}
}

void mid_insert(int ele,int pos)
{
	create(ele);
	int count=1;
	struct Node *temp;
	temp=head;
	if(head==NULL)
	{
		head=tail=new;
	}
	else
	{
		while(temp->next!=NULL)
		{
			if(count==pos-1)
			{
				temp->next->prev=new;
				new->next=temp->next;
				new->prev=temp;
				temp->next=new;
				return;
	
			}	
			count++;
			temp=temp->next;
		}
		printf("Position out of Bound");
	}
}

void end_insert(int ele)
{
	create(ele);
	if(head==NULL)
	{
		head=tail=new;
	}
	else
	{
		tail->next=new;
		new->prev=tail;
		tail=new;
	}


}
void beg_del()
{
	struct Node *temp=head;
	if(head==NULL)
	{
		printf("No Data in the List");
		return;
	}
	else
	{
		head=head->next;
		if(head!=NULL)
		{
			head->prev=NULL;
		}
		free(temp);
		
	}

}
void end_del()
{
	struct Node *temp=tail;
	if(tail==NULL)
	{
		printf("List is Empty");
		return;
	}
	else
	{
		if(head==tail)
		{
			head=tail=NULL;
		}
		else
		{
			tail=tail->prev;
			tail->next=NULL;
			free(temp);

		}
	}

}
void mid_del(int pos)
{	
	int count=1;
	struct Node *temp=head;
	if(head==NULL)
	{
		printf("List is Empty");
		return;
	}
	if(pos==1)
	{
		beg_del();
	}
	else
	{
		while(temp->next!=NULL)
		{
			if(count==pos)
			{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				free(temp);
				return;
			}
			count++;
			temp=temp->next;
		}
		printf("Position out of Bounds");
	}
}
void display()
{
	struct Node *temp=head;
	if(head==NULL)
	{
		printf("List is Empty");
		return;
	}
	else
	{
		while(temp->next!=tail->next)
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
	struct Node *temp=head;
	if(head==NULL)
	{
		printf("List is Empty");
		return;
	}
	else
	{
		while(temp!=tail->next)
		{
			if(temp->data==ele)
			{
				printf("Element found at %d",count);
				return;
			}
			count++;
			temp=temp->next;
		}
		printf("Element not found");

	}


}
int main()
{
	int ch,ele,pos;
	printf("Menu:1.Insert at Beginning\n2.Display\n3.Exit\n4.Insert at the Middle\n5.Insert at the End\n6.Delete from the Beginning\n7.Search\n8.Delete from the End\n9.Delete at the Middle");
	while(1)
	{
		printf("\nEnter your choice:");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("Enter the Data:");
				scanf("%d",&ele);
				beg_insert(ele);
				break;

			case 2:
				display();
				break;

			case 3:
				exit(0);
				break;
			case 4:
				printf("Enter the Data and Position:");
				scanf("%d %d",&ele,&pos);
				mid_insert(ele,pos);
				break;
			case 5:
				printf("Enter the Data:");
				scanf("%d",&ele);
				end_insert(ele);
				break;

			case 6:
				beg_del();
				break;
			case 7:
				printf("Enter the Search Element:");
				scanf("%d",&ele);
				search(ele);
				break;
			case 8:
				end_del();
				break;
			case 9:
				printf("Enter the Position to Delete:");
				scanf("%d",&pos);
				mid_del(pos);
				break;
			default:
				printf("Invalid Choice");
				break;
		}
	}

}
