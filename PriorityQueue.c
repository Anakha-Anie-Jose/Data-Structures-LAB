#include<stdio.h>
#define CAPACITY 50
struct PriorityQueue
{
    int ar[CAPACITY];
    int REAR;
    int FRONT;
};
int size;
void ENQUEUE(struct PriorityQueue *q ) {//When a larger element is encountered,smaaller ones are pushed to front
        // Check if the queue is full
        if (q->REAR == size-1) {
                printf("\n Queue is full!Delete before Insertion!!");
                return;
        }
        int ITEM;
        printf("\n Enter item to be inserted :");
        scanf("%d",&ITEM);
        if(q->FRONT==-1)
         q->FRONT=0;
        q->REAR++;
        
         


        int i = q->REAR;
        while (i >= 0 && ITEM< q->ar[i]) {
                q->ar[i + 1] = q->ar[i];
                i--;
        }
        q->ar[i + 1] = ITEM;
        printf("\nDone!");
}
        

// deleting the front element in the queue
void DEQUEUE(struct PriorityQueue *q) {
        if(q->FRONT==-1)
        {
            printf("\n Queue is empty!Insert before Deletion!!");
            return;
        }
        int ITEM=q->ar[q->FRONT];
        if(q->FRONT==q->REAR)
          {
              q->REAR=-1;
              q->FRONT=-1;
          }
          else
          {
              q->FRONT++;
          }
          printf("\n%d successfully deleted!!",ITEM);
          
}
void DISPLAY(struct PriorityQueue q)
{
    if(q.FRONT==-1)//empty condition
    {
        printf("Queue is Empty!Insert before Display");
    }
    else
    {
      int i=q.FRONT+1;
      printf("\nFRONT->%d",q.ar[q.FRONT]);
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
    struct PriorityQueue Q;
    Q.FRONT=-1;
    Q.REAR=-1;
    printf("Enter the size of array :");
    scanf("%d",&size);

    int ch;
  printf("\nHey!You are having a  Priority queue of CAPACITY %d",size);
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
      case 1:
      {ENQUEUE(&Q);
      DISPLAY(Q);}
      break;
      case 2:{DEQUEUE(&Q);
      DISPLAY(Q);}
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
