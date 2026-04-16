#include <stdio.h>  
#include <stdlib.h>
#define MAX 5
int deque[MAX];
int front=-1, rear=-1;

int isFull()
{
    return (front==(rear + 1)%MAX);
}

int isEmpty()
{
    return (front==-1);
}

void insertfront(int);
void insertrear(int);
void deletefront();
void deleterear();
void display();

int main()
{
    int ch, val;
    
    while(1)
    {
        printf("\n---DOUBLE ENDED QUEUES---");
        printf("\n1.Insert at Front\n2.Insert at Rear\n3.Delete at Front\n4.Delete at Rear\n5.display\n6.exit");
        printf("\nEnter your choice (1-4) : ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1 : printf("\nEnter the value : ");
                     scanf("%d",&val);
                     insertfront(val); 
                     break;
            case 2 : printf("\nEnter the value : ");
                     scanf("%d",&val);
                     insertrear(val); 
                     break;        
            case 3 : deletefront(); 
                     break;
            case 4 : deleterear(); 
                     break;
            case 5 : display(); 
                     break;
            case 6 : exit(0); 
            default: printf("\nInvalid choice!!");
        }
    }
    return 0;
}

void insertfront(int val)
{
    if(isFull())
    {
        printf("\nOverflow!!");
        return;
    }
    
    if(isEmpty())
    {
        front=rear=0;
    }
    else
    {
        front=(front-1+MAX)%MAX;
    }
    
    deque[front]=val;
    printf("\nInserted at Front : %d",val);
}

void insertrear(int val)
{
    if(isFull())
    {
        printf("\nOverflow!!");
        return;
    }
    
    if(isEmpty())
    {
        front=rear=0;
    }
    else
    {
        rear=(rear-1+MAX)%MAX;
    }
    
    deque[rear]=val;
    printf("\nInserted at Rear : %d",val);
}

void deletefront()
{
    if(isEmpty())
    {
        printf("\nUnderflow!!");
        return;
    }
    
    printf("\nDeleted Element is %d",deque[front]);

    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%MAX;
    }
}
 
void deleterear()
{
    if(isEmpty())
    {
        printf("\nUnderflow!!");
        return;
    }
    
    printf("\nDeleted Element is %d",deque[rear]);

    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        rear=(rear-1)%MAX;
    }
}

void display()
{
    if(isEmpty())
    {
       printf("\nDeque is empty!!");
       return;
    }
    
    printf("\nQueue Elements : ");

    for(int i = front ;; i= (i+1)%MAX)
    {
        printf("%d->",deque[i]);
        if(i==rear)
          break;
    }
    printf("\n");
}
