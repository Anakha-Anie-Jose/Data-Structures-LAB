#include<stdio.h>
# define CAPACITY 50
int size;
struct Deque
{
    int ar[CAPACITY];
    int FRONT;
    int REAR;
};

void INSERT_FRONT(struct Deque *q)
{
 if(q->FRONT==0)//FRONT-1=-1
 {
     printf("Insertion not possible!Delete from front before insertion!");
     return;
 }
 int ITEM;
 printf("\n Insert Element to be inserted :");
 scanf("%d",&ITEM);
 if(q->FRONT==-1)//no element
 {
   q->FRONT=0;
   q->REAR=0;
 }
 else//there are elements
 {
     q->FRONT=q->FRONT-1;
 }
 q->ar[q->FRONT]=ITEM;
  printf("Done\n");


   

}
void INSERT_REAR(struct Deque *q)
{
if(q->REAR==size-1)//size-1+1=size-array out of bound
    {
     printf("Cannot Insert elemensts!cannot insert untill you delete items");
     return;
    }
    int ITEM;
    printf("Enter item to be inserted :");
    scanf("%d",&ITEM);
    if(q->FRONT==-1)//no elements
    {
      q->FRONT=0;
      q->REAR=0;
    }
    else//there are some elements
      q->REAR++;
    q->ar[q->REAR]=ITEM;
    printf("Done\n");

}
void DELETE_FRONT(struct Deque *q)
{
int ITEM;
    if((q->FRONT==-1&&q->REAR==-1)||(q->FRONT==0&&q->REAR==-1))//empty condition
    {
        q->FRONT=-1;
        printf("Queue is Empty!Insert before Deletion");
        return;
    }
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
      printf("%d successfully deleted!!",ITEM);
 
}
void DELETE_REAR(struct Deque *q)
{
 if(q->FRONT==-1)//queue is empty
 {
     printf("\n Queue is empty!!Insert before deletion!");
     return;
 }
 int ITEM=q->ar[q->REAR];
 if(q->REAR==q->FRONT)
 {
   q->REAR=-1;
   q->FRONT=-1;
 }
 else
 {
     q->REAR=q->REAR-1;
 }
 printf("%d successfully deleted!!",ITEM);
 
}
void DISPLAY_Deque(struct Deque q)
{
    if(q.FRONT==-1)//empty
   {
       printf("\nThe Double Ended Queue is Empty!!Insert before Display!");
       return;
   }
 
   int i=q.FRONT+1;
   printf("\nFRONT->%d",q.ar[q.FRONT]);
   while(i<=q.REAR)
   {
       printf("\n%d",q.ar[i]);
       i++;
   }
   printf("<-REAR");
    
  
  
}

void main()
{
    struct Deque Q;
    Q.FRONT=-1;
    Q.REAR=-1;
    int ch;
    printf("Enter the size of Double Ended Queue :");
    scanf("%d",&size);
    printf("\n You have a Double Ended Queue of Capacity %d ",size);
    printf("\n1. INSERT_FRONT(Insert at front of Queue)\n2. INSERT_REAR(Insert at the rear of the Queue)");
   printf("\n3. DELETE_FRONT(Delete from front of Queue)\n4. DELETE_REAR(delete from rear of Queue)\n5. DISPLAY_Deque(Display elements)\n0. To Quit");
    printf("\n So what's your choice? :");
    scanf("%d",&ch);
    while(ch!=0)
    {
        switch(ch)
        {
            case 1:{INSERT_FRONT(&Q);
            DISPLAY_Deque(Q);}
            break;
            case 2:{INSERT_REAR(&Q);
            DISPLAY_Deque(Q);}
            break;
            case 3:{DELETE_FRONT(&Q);
            DISPLAY_Deque(Q);}
            break;
            case 4:{DELETE_REAR(&Q);
            DISPLAY_Deque(Q);}
            break;
            case 5:DISPLAY_Deque(Q);
            break;
            default:printf("\n1. ENQUEUE_CQ\n2. DEQUEUE_CQ\n3. DISPLAY_CQ\n0. To Quit\nEnter any valid choice");
        }
        printf("\n Enter the corresponding choice as per your requirements :");
        scanf("%d",&ch);
    }
    printf("\n Successfully Exited from Program!!!");

}
