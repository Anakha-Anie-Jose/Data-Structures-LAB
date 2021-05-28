#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 100
struct Queue{
int REAR;
int FRONT;
int ar[CAPACITY];
};
void ENQUEUE(struct Queue *q){
  if(q->REAR==CAPACITY-1)
    {
     printf("Queue is full!cannot insert untill you delete all items");
     exit;
    }
    int ITEM;
    printf("Enter item to be inserted :");
    scanf("%d",&ITEM);
    if(q->FRONT==-1)
    {
      q->FRONT=0;
    }
      q->REAR++;
    q->ar[q->REAR]=ITEM;
    printf("Done");

}
void DEQUEUE(struct Queue *q)
{
    int ITEM;
    if(q->FRONT==-1)
    {
        printf("Queue is Empty!Insert before Deletion");
        exit;
    }
    else
    {
      ITEM=q->ar[q->FRONT];
      if(q->FRONT==q->REAR)
      {
        q->REAR=-1;
        q->FRONT=-1;
      }
      else
      {
        q->FRONT++;
      }
    }
    printf("ITEM %d is deleted",ITEM);
    
}
void DISPLAY(struct Queue q)
{
    if(q.FRONT==-1)
    {
        printf("Queue is Empty!Insert before Display");
    }
    else
    {
      int i=q.FRONT+1;
      printf("FRONT->%d",q.ar[q.FRONT]);
      while(i<=q.REAR)
      {
          printf("\n%d",q.ar[i]);
          i++;
      }
      printf("<-REAR");
    }
    
}
void main()
{
    struct Queue Q;
    Q.FRONT=-1;
    Q.REAR=-1;
    int ch;
  printf("Hey!You are having a queue of CAPACITY %d",CAPACITY);
  printf("\n You can perform the following operations in the Queue :");
  printf("\n1. ENQUEUE(Insert to the queue)\n2. DEQUEUE(Delete From the Queue)\n3. DISPLAY");
  printf("\nPress the specified buttons to perform the operations");
  printf("\nPress 0 to quit");
  printf("\n So what's your choice? :");
  scanf("%d",&ch);
  while(ch!=0)
  {
    switch (ch)
     {
      case 1:ENQUEUE(&Q);
      break;
      case 2:DEQUEUE(&Q);
      break;
      case 3:DISPLAY(Q);
      break;
      default:printf("\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n Enter any valid choice");
      break;
     }
    printf("\nEnter the corresponding button as per your requirement :");
    scanf("%d",&ch);
  }
  printf("\nExiting from program!!!!!!!");
}
