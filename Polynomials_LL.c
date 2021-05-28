#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int exp;
    int coeff;
    struct Node *Link;
}*PHEADER,*QHEADER,*RHEADER,*SHEADER;
void read(struct Node *HEADER)
{
   struct Node*PTR,*NEW;
   PTR=HEADER;
   int ch=1;
   printf("\nEnter as per your wish when need to exit press 0");
   while(ch!=0)
   {
       NEW=(struct Node*)malloc(sizeof(struct Node));
       if(NEW==NULL)//no avaialable space in free pool of memory
       {
           printf("\nOperation Not Possible!!");
           return;
       }
       printf("\nExp   Coeff\n");
       scanf("%d%d",&NEW->exp,&NEW->coeff);
       PTR->Link=NEW;
       NEW->Link=NULL;
       PTR=NEW;
       printf("\nPress 1 or 0 :");
       scanf("%d",&ch);
   }
   
}
void Add()
{
  struct Node*PPTR,*QPTR,*RPTR;
  PPTR=PHEADER->Link;
  QPTR=QHEADER->Link;
  RPTR=RHEADER;
  while(PPTR!=NULL&&QPTR!=NULL)//untill any of one becomes null, the loop  runs
  {
      if(QPTR->exp==PPTR->exp)
      {
          struct Node*NEW=(struct Node*)malloc(sizeof(struct Node));
          RPTR->Link=NEW;
          RPTR=NEW;
          RPTR->coeff=PPTR->coeff+QPTR->coeff;
          RPTR->exp=QPTR->exp;
          RPTR->Link=NULL;
          PPTR=PPTR->Link;
          QPTR=QPTR->Link;
      }else if(PPTR->exp>QPTR->exp)
      {
          struct Node*NEW=(struct Node*)malloc(sizeof(struct Node));
          RPTR->Link=NEW;
          RPTR=NEW;
          RPTR->coeff=PPTR->coeff;
          RPTR->exp=PPTR->exp;
          RPTR->Link=NULL;
          PPTR=PPTR->Link;
      }else if(PPTR->exp<QPTR->exp)
      {
        struct Node*NEW=(struct Node*)malloc(sizeof(struct Node));
          RPTR->Link=NEW;
          RPTR=NEW;
          RPTR->coeff=QPTR->coeff;
          RPTR->exp=QPTR->exp;
          RPTR->Link=NULL;
          QPTR=QPTR->Link;
      }

  }
  if(PPTR!=NULL&&QPTR==NULL)
  {
      while(PPTR!=NULL){//loop runs untill PPTR becomes null
      struct Node*NEW=(struct Node*)malloc(sizeof(struct Node));
          RPTR->Link=NEW;
          RPTR=NEW;
          RPTR->coeff=PPTR->coeff;
          RPTR->exp=PPTR->exp;
          RPTR->Link=NULL;
          PPTR=PPTR->Link;
      }
  }
  else if(QPTR!=NULL&&PPTR==NULL)
  {  while(QPTR!=NULL){//Loop runs untill QPTR becomes null
      struct Node*NEW=(struct Node*)malloc(sizeof(struct Node));
          RPTR->Link=NEW;
          RPTR=NEW;
          RPTR->coeff=QPTR->coeff;
          RPTR->exp=QPTR->exp;
          RPTR->Link=NULL;
          QPTR=QPTR->Link;
  }
  }
}
 void Multiply()
 {int C,X;
 struct Node *PPTR,*QPTR,*SPTR,*SPTR1;
 PPTR=PHEADER;
 QPTR=QHEADER;
 if(PHEADER==NULL&&QHEADER==NULL)//if any of them is null,multiplication is not possible
 {
     printf("\nCannot perform operation!!");
     exit(0);
 }
 PPTR=PHEADER->Link;
 SPTR=SHEADER;
 int FLAG;
 while (PPTR!=NULL)
 {QPTR=QHEADER->Link;
     while (QPTR!=NULL)
     {
         C=PPTR->coeff*QPTR->coeff;
         X=PPTR->exp+QPTR->exp;
         FLAG=0;
         SPTR1=SHEADER->Link;
         while(SPTR1!=NULL)
         {if(SPTR1->exp==X)//if more than one terms have same exponent
         {
             SPTR1->coeff=SPTR1->coeff+C;
             FLAG=1;
         }
         SPTR1=SPTR1->Link;
         }
         if(FLAG==0){
         struct Node *NEW;
             NEW=(struct Node*)malloc(sizeof(struct Node));
             NEW->coeff=C;
             NEW->exp=X;
             SPTR->Link=NEW;
             NEW->Link=NULL;
             SPTR=NEW;
             }
         QPTR=QPTR->Link;
    }
     PPTR=PPTR->Link;
    }
}
 
 void Display(struct Node*HEADER)
{
   struct Node*PTR;
   if(HEADER==NULL)//if the list is null
   {
       printf("Cannot Perform Operation!!");
       return;
   }PTR=HEADER->Link;
   printf("Exp   coeff\n");
   while(PTR->Link!=NULL)
   {
     printf("%d    %d\n",PTR->exp,PTR->coeff);
     PTR=PTR->Link;
   } printf("%d    %d",PTR->exp,PTR->coeff);
   PTR=HEADER->Link;
   printf("\n");
   while(PTR->Link!=NULL)
   {
     printf("%dx^%d+",PTR->coeff,PTR->exp);
     PTR=PTR->Link;
   }printf("%dx^%d",PTR->coeff,PTR->exp);
}
void main()
{
    PHEADER=(struct Node*)malloc(sizeof(struct Node));
    QHEADER=(struct Node*)malloc(sizeof(struct Node));
    RHEADER=(struct Node*)malloc(sizeof(struct Node));
    SHEADER=(struct Node*)malloc(sizeof(struct Node));
    PHEADER->Link=NULL;
    QHEADER->Link=NULL;
    RHEADER->Link=NULL;
    SHEADER->Link=NULL;
    printf("Enter the details of First Polynomial ");
    read(PHEADER);
    printf("\nEnter the details of second Polynomial");
    read(QHEADER);
    printf("\n The polynomials are :");
    printf("\n----------------P---------------\n");
    Display(PHEADER);
    printf("\n----------------Q----------------\n");
    Display(QHEADER);
    printf("\nFinding the sum :");
    Add();
    printf("\n----------------Sum--------------\n");
    Display(RHEADER);
    printf("\nFinding product :");
     Multiply();
    printf("\n----------Product----------------\n");
    Display(SHEADER);
}
