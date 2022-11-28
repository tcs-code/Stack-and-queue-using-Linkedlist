#include<stdio.h>
#include<stdlib.h>

void push(int a);
int pop();
void enq(int b);
int deq();
void displayst();
void displayq();
struct Node
{	int data ;
	struct Node *next;
};
struct Node *top=NULL, *front=NULL, *rear=NULL;
void main()
{	int op,ch1,ch2,num1,num2,c;
	while(op!=3)
	{	printf("\nChoose option\n1-Stack\n2-Queue\n3-Exit\n");
		scanf("%d",&op);
		switch(op)
		{	case 1: while(ch1!=4)
				{	printf("\nChoose operation\n1-Push\n2-Pop\n3-Display\n4-Exit\n");
					scanf("%d",&ch1);
					if(ch1==1)
					{	printf("Enter the number to push:");
						scanf("%d",&num1);
						push(num1);
					}
					else if(ch1==2)
					{	c=pop();
						if(c==89123)
						{	printf("Stack underflow\n");
						}
						else
						{	printf("The popped element is :%d",c);
						}
					}
					else if(ch1==3)
					{	displayst();
					}
					else if(ch1==4)
					{	continue;
					}
					else
					{	printf("Invalid Choice");
					}
				}break;
			case 2: while(ch2!=4)
				{	printf("\nChoose operation\n1-Enqueue\n2-Dequeue\n3-Display\n4-Exit\n");
					scanf("%d",&ch2);
					if(ch2==1)
					{	printf("Enter the number to enqueue:");
						scanf("%d",&num2);
						enq(num2);
					}
					else if(ch2==2)
					{	c=deq();
						if(c==89123)
						{	printf("Queue underflow\n");
						}
						else
						{	printf("The dequeued element is :%d\n",c);
						}
					}
					else if(ch2==3)
					{	displayq();
					}
					else if(ch2==4)
					{	continue;
					}
					else
					{	printf("Invalid Choice");
					}
				}break;
			case 3: break;
			default: printf("Invalid choice");break;
		}
	}
}

void push(int a)
{	struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data=a;
	newnode->next=top;
	top=newnode;
}

int pop()
{	if(top==NULL)
	{	return 89123;
	}
	else
	{	struct Node *ptr=top;
		top=top->next;
		int x=ptr->data;
		free(ptr);
		return x;
	}
}
void displayst()
{	if(top==NULL)
	{	printf("Stack is empty");
	}
	else
	{	struct Node *ptr=top;
		while(ptr!=NULL)
		{	printf("%d ",ptr->data);
			ptr=ptr->next;
		}
	}
}

void enq(int b)
{	struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data=b;
	newnode->next=NULL;
	if(front==NULL)
	{	front=newnode;
		rear=newnode;
	}
	else
	{	rear->next=newnode;
		rear=newnode;
	}
}

int deq()
{	if(front==NULL)
	{	return 89123;
	}
	else
	{	int x=front->data;
		struct Node *ptr = front;
		front=front->next;
		free(ptr);
		if(front==NULL)
		{	rear=NULL;
		}
		return x;
	}
}

void displayq()
{	if(front==NULL)
	{	printf("Empty queue");
	}
	else
	{	struct Node *ptr=front;
		while(ptr!=NULL)
		{	printf("%d",ptr->data);
			ptr=ptr->next;
		}
	}
}
