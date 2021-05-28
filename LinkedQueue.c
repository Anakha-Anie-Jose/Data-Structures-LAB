#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int Data;
    struct Node *Link;
}*FRONT,*REAR;
void DISPLAY_QUEUE()
{ if(FRONT==NULL)//queue is empty
   {
       printf("\nSorry!Queue is empty,insert before Display!!");
       return;
   }
  struct Node *PTR;//queue is not empty
  PTR=FRONT;
  printf("\n Current queue :");
  while(PTR->Link!=NULL)
  {
      printf("%d ",PTR->Data);
      PTR=PTR->Link;
  }
  printf("%d",PTR->Data);
}
int SUM=0;
void INSERT_QUEUE()
{
  struct Node *NEW;
  NEW=(struct Node*)malloc(sizeof(struct Node));
  if(NEW==NULL)//No available space in free pool of memory
  {
      printf("\nSorry!Cannot Insert element,No suited space!!");
      return;
  }
  int ITEM;
  printf("\nEnter element to be inserted :");
  scanf("%d",&ITEM);
  NEW->Data=ITEM;
  NEW->Link=NULL;
  if(FRONT==NULL)//When the queue is empty
  {
      FRONT=NEW;
      REAR=NEW;
  }
  else//normal condition
  {
      REAR->Link=NEW;
      REAR=NEW;
  }
  printf("\nDone!!"); 
  SUM+=NEW->Data;
  printf("\nSUM :%d",SUM); 
  DISPLAY_QUEUE();
  }
void DELETE_QUEUE()
{if(FRONT==NULL)//when queue is empty
   {
       printf("\nSorry!Queue is empty,insert before insertion!!");
       return;
   }
   struct Node *PTR;//queue not empty
   PTR=FRONT;
   FRONT=FRONT->Link;
   SUM-=PTR->Data;
   printf("\n%d successfully deleted!!",PTR->Data);
   free(PTR);
   printf("\nSUM :%d",SUM);
   DISPLAY_QUEUE();
}
void main()//main function
{
    FRONT=NULL;
    REAR=NULL;
    int ch;
    printf("\nYou have a Queue to manipulate");
    printf("\n1. INSERT_QUEUE(Insert elements to Queue)");
    printf("\n2. DELETE_QUEUE(Delete elements from Queue)");
    printf("\n3. DISPLAY_QUEUE(Display elements from Queue)");
    printf("\n0. TO QUIT");
    printf("\n Enter Your choice :");
    scanf("%d",&ch);
    while (ch!=0)
    {
        switch(ch)
        {
             case 1:INSERT_QUEUE();
                break;
             case 2:DELETE_QUEUE();
                break;
            case 3:DISPLAY_QUEUE();
                break;
            default:printf("\n Enter any valid choice :");
                break;
        }
        printf("\nEnter the corresponding choice as per your requirements :");
        scanf("%d",&ch);
    }
    printf("\n Successfully exited from program!!!");
}