#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int Data;
    struct Node *Link;
}*HEADER;
int SUM=0;
void DISPLAY_LINKEDLIST()
{
 if(HEADER->Link==NULL)//empty list
 {
     printf("\nSorry!!cannot Display the List, no element in LinkedList!");
     return;
 }
 struct Node *PTR;
 PTR=HEADER->Link;
 printf("\nCurrent List :\n");
 while (PTR->Link!=NULL)
 {
     printf("%d ",PTR->Data);
     PTR=PTR->Link;
 }
    printf("%d",PTR->Data);
}
void INSERT_FRONT()
{
    struct Node *NEW;
   NEW=(struct Node*)malloc(sizeof(struct Node)); 
   if(NEW==NULL)// No available space in free pool of memory 
   {
       printf("\nSorry!!!Cannot insert to LinkedList, no suited memory");
       return;
   }
   int ITEM;
   printf("\nEnter the element to be inserted :");
   scanf("%d",&ITEM);
   NEW->Link=HEADER->Link;
   NEW->Data=ITEM;
   SUM+=NEW->Data;
   HEADER->Link=NEW;
   printf("\nDone!!!");
   printf("\nSUM :%d",SUM);
   DISPLAY_LINKEDLIST();
}
void INSERT_END()
{
 struct Node *NEW,*PTR;
 NEW=(struct Node*)malloc(sizeof(struct Node)); 
 if(NEW==NULL)//No available space is free pool of memory
 {
    printf("\nSorry!!!Cannot insert to LinkedList, no suited memory");
       return; 
 }
 PTR=HEADER;
 int ITEM;
 printf("\nEnter the element to be inserted :");
 scanf("%d",&ITEM);
 while (PTR->Link!=NULL)
 {
     PTR=PTR->Link;
 }
 PTR->Link=NEW;
 NEW->Data=ITEM;
 SUM+=NEW->Data;
 NEW->Link=NULL;
 printf("\nDone!!!");
 printf("\nSUM :%d",SUM);
 DISPLAY_LINKEDLIST();

}
void INSERT_POSITION()
{
  struct Node *NEW,*PTR;
 NEW=(struct Node*)malloc(sizeof(struct Node));
 if(NEW==NULL)//No available space in free pool of memory
 {
    printf("\nSorry!!!Cannot insert to LinkedList, no suited memory");
       return; 
 }
 PTR=HEADER;
 int KEY;
 printf("\nEnter the data part of the node after which you want to perform insertion :");
 scanf("%d",&KEY);
 PTR=HEADER;
 while (PTR->Data!=KEY&&PTR->Link!=NULL)
 {
     PTR=PTR->Link;
 }
 if (PTR->Data==KEY)
 {
     int ITEM;
     printf("\nEnter the element to be inserted :");
     scanf("%d",&ITEM);
     NEW->Link=PTR->Link;
     NEW->Data=ITEM;
     SUM+=NEW->Data;
     PTR->Link=NEW;
     printf("\nDone!!!");
     printf("\nSUM :%d",SUM);
     DISPLAY_LINKEDLIST();
 }
else
 {
    printf("\nThe node with given KEY does not exist!!");//No such data element as user entered
 }
 
}
void DELETE_FRONT()
{
 if(HEADER->Link==NULL)//list is empty
 {
     printf("\nSorry!!cannot perform Deletion, no element in LinkedList!");
     return;
 }
 struct Node *PTR;
 PTR=HEADER->Link;
 HEADER->Link=PTR->Link;
 printf("\n%d deleted!!!",PTR->Data);
 SUM-=PTR->Data;
 free(PTR);
 printf("\nSUM :%d",SUM);
 DISPLAY_LINKEDLIST();
}
void DELETE_END()
{
 if(HEADER->Link==NULL)//empty list
 {
     printf("\nSorry!!cannot perform Deletion, no element in LinkedList!");
     return;
 }
 struct Node *PTR,*PTR1;
 PTR=HEADER;
 while (PTR->Link!=NULL)
 {
   PTR1=PTR;
   PTR=PTR->Link;
 }
 PTR1->Link=NULL;
 printf("\n%d deleted!!!",PTR->Data);
 SUM-=PTR->Data;
 free(PTR);
 printf("\nSUM :%d",SUM);
 DISPLAY_LINKEDLIST();
}
void DELETE_POSITION()
{
    if(HEADER->Link==NULL)//empty list
 {
     printf("\nSorry!!cannot perform Deletion, no element in LinkedList!");
     return;
 }
 int ITEM;
 printf("\nEnter the element to be deleted :");
 scanf("%d",&ITEM);
 struct Node *PTR,*PTR1;
 PTR=HEADER;
 while (PTR->Data!=ITEM&&PTR->Link!=NULL)
 {
     PTR1=PTR;
     PTR=PTR->Link;
 }
 if (PTR->Data==ITEM)
 {
     PTR1->Link=PTR->Link;
     printf("\n%d deleted!!!");
     SUM-=PTR->Data;
     free(PTR);
     printf("\nSUM :%d",SUM);
     DISPLAY_LINKEDLIST();
 }
 else
 {
    printf("\nThe node with given KEY does not exist!!");//Key not found
 }
}
void main()
{
   HEADER=(struct Node*)malloc(sizeof(struct Node)); 
   HEADER->Link=NULL;
    int ch;
    printf("Hey there! You have a linked list to manipulate!!!");
    printf("\n1. INSERT_FRONT(Insert at Beggining)");
    printf("\n2. INSERT_END(Insert at End)");
    printf("\n3. INSERT_POSITION(Insert at any position)");
    printf("\n4. DELETE_FRONT(Delete from Beggining)");
    printf("\n5. DELETE_END(Delete from End)");
    printf("\n6. DELETE_POSITION(delete from any position of Linked List)");
    printf("\n7. DISPLAY_LINKEDLIST(Display the list) ");
    printf("\n0. QUIT");
    printf("\n Enter your choice :");
    scanf("%d",&ch);
    while(ch!=0)
    {
        switch (ch)

        {
        case 1:INSERT_FRONT();
        break;
        case 2:INSERT_END();
        break;
        case 3:INSERT_POSITION();
        break;
        case 4:DELETE_FRONT();
        break;
        case 5:DELETE_END();
        break;
        case 6:DELETE_POSITION();
        break;
        case 7:DISPLAY_LINKEDLIST();
        break;
        default:
        {
            printf("Hey there! You have a linked list to manipulate!!!");
    printf("\n1. INSERT_FRONT");
    printf("\n2. INSERT_END");
    printf("\n3. INSERT_POSITION");
    printf("\n4. DELETE_FRONT");
    printf("\n5. DELETE_END");
    printf("\n6. DELETE_POSITION");
    printf("\n7. DISPLAY_LINKEDLIST");
    printf("\n0. QUIT");
    printf("\n Enter any valid choice :");
        }
        break;
        }
    printf("\nEnter the corresponding choice as per your requirement :");
    scanf("%d",&ch);
    }
    printf("\nSuccessfully exited from program!!!");

}