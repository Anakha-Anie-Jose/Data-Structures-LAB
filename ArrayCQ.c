/*Implementation of circular queue*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define CAPACITY 50
struct CQ
{
    int ar[CAPACITY];
    int FRONT;
    int REAR;
};
int size;
void ENQUEUE_CQ(struct CQ *q)
{
   if(q->FRONT==(q->REAR+1)%size)//full condition
   {
    printf("Queue is full!!Delete Before Insertion!");
    return;
   }
   int ITEM;
   printf("Enter the item to be inserted :");
   scanf("%d",&ITEM);
   if(q->FRONT==-1)//no elements
    {
        q->FRONT=0;
        q->REAR=0;
    }
    else//there are elements
    {
        
            q->REAR=(q->REAR+1)%size;
        
    }
    q->ar[q->REAR]=ITEM;
    printf("\nDone");
    

}
void DEQUEUE_CQ(struct CQ *q)
{
   if((q->FRONT==-1)&&(q->REAR==-1))//empty condition
   {
       printf("\nThe Circular Queue is Empty!!Insert before deletion!");
       return;
   }
   int ITEM=q->ar[q->FRONT];
   if(q->FRONT==q->REAR)//front=rear
   {
       q->FRONT=-1;
       q->REAR=-1;
   }
   else
   {
       q->FRONT=(q->FRONT+1)%size;
   }
   printf("\n %d successfully deleted!!",ITEM);
}
void DISPLAY_CQ(struct CQ q)
{
  if(q.FRONT==-1)//empty condition
   {
       printf("\nThe Circular Queue is Empty!!Insert before Display!");
       return;
   }
   printf("\nThe queue is :\n");
   int i=q.FRONT;
   if(i<=q.REAR)
   {
       while(i<=q.REAR)
       {
           printf("%d\n",q.ar[i]);
           i++;
       }
   }
   else
   {
       while(i!=q.REAR)
       {
           printf("%d\n",q.ar[i]);
           i=(i+1)%size;;
       }
       printf("%d",q.ar[i]);
   }

   
  
}
void main()
{
    clrscr();
    struct CQ Q;
    Q.FRONT=-1;
    Q.REAR=-1;
    int ch;
    printf("Enter the size of Circular queue :");
    scanf("%d",&size);
    printf("\n You have a Circular Queue of Capacity %d ",size);
    printf("\n1. ENQUEUE_CQ(Enter elements to Queue)\n2. DEQUEUE_CQ(Delete elements from Queue)\n3. DISPLAY_CQ(Display elements)\n0. To Quit");
    printf("\n So what's your choice? :");
    scanf("%d",&ch);
    while(ch!=0)
    {
        switch(ch)
        {
            case 1:{ENQUEUE_CQ(&Q);
             DISPLAY_CQ(Q);}
            break;
            case 2:{DEQUEUE_CQ(&Q);
            DISPLAY_CQ(Q);}
            break;
            case 3:DISPLAY_CQ(Q);
            break;
            default:printf("\n1. ENQUEUE_CQ\n2. DEQUEUE_CQ\n3. DISPLAY_CQ\n0. To Quit\nEnter any valid choice");
        }
        printf("\n Enter the corresponding choice as per your requirements :");
        scanf("%d",&ch);
    }
    printf("\n Successfully Exited from Program!!!");

}
