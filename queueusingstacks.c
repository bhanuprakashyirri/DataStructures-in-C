#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int rear=-1;
int front=-1;
void enqueue();
void dequeue();
void show();
int queue[SIZE];
int main()
{
    int ch;
    
    while(1)
    {
     printf("---Queue implementation---");
     printf("\n1. Enqueue\n2. Dequeue\n3. Show\n4. Exit");
     printf("\nEnter you choice(1-4) : ");
     scanf("%d",&ch);
     
     switch(ch)
     {
        case 1  : enqueue();
                  break; 
        case 2  : dequeue();
                  break; 
        case 3  : show();
                  break; 
        case 4  : exit(0);
        default : printf("\nInvalid Choice!!");
     }
    }
    return 0;
}

void enqueue()
{
    int x;
    if(rear==SIZE-1)
      printf("\nQueue is Overflow!!");
    else
    {  
        if(front==-1)
        {
            front=0;
        }
      printf("\nEnter the Element to enqueue : ");
      scanf("%d",&x);
      rear=rear+1;
      queue[rear] = x;
    }
}

void dequeue()
{
    if(front==-1)
      printf("\nQueue is Overflow!!");
    else
    {  
      printf("\nDeleted element is %d",queue[front]);
      front++;
    }
}

void show()
{
    int i;
    
    if(front==-1)
    { 
      printf("\nQueue is underflow!!");
      return;
    }  
      printf("\nThe Queue is : ");
      for(i=front;i<=rear;i++)
        printf("%d-->",queue[i]);
}
