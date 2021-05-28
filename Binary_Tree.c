/*implementation of binary Tree*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*LC;
    struct Node*RC;
}*ROOT,*stack[100],*stack1[100];
int TOP,TOP1;
void push(struct Node*ptr)
{
   TOP++;
   stack[TOP]=ptr;
}
void push1(struct Node*ptr)
{
    TOP1++;
    stack1[TOP1]=ptr;
}
struct Node* pop()
{
    struct Node*ptr=stack[TOP];
    TOP--;
    return ptr;
}
struct Node* pop1()
{
    struct Node*ptr=stack1[TOP1];
    TOP1--;
    return ptr;
}
void IN_ORDER_TRAVERSAL()
{
    TOP=-1;
    struct Node*ptr=ROOT;
    int Flag=1;
    while(Flag)
    {
        while(ptr!=NULL)
        {
            push(ptr);
            ptr=ptr->LC;
        }
        if(TOP==-1)
         break;
        ptr=pop();
        printf("%d ",ptr->data);
        ptr=ptr->RC; 
    }
}
void PRE_ORDER_TRAVERSAL()
{
    TOP=-1;
    struct Node*ptr=ROOT;
    push(ROOT);
    while(TOP!=-1)
    {
        ptr=pop();
        if(ptr!=NULL)
        printf("%d ",ptr->data);
        if(ptr->RC!=NULL)
        push(ptr->RC);
        if(ptr->LC!=NULL)
        push(ptr->LC);
        
    }
}
void POST_ORDER_TRAVERSAL()
{
    TOP=-1;
    TOP1=-1;
    struct Node*ptr=ROOT;
    push(ptr);
    while(TOP!=-1)
    {
        ptr=pop();
        push1(ptr);
        if(ptr->LC!=NULL)
         push(ptr->LC);
        if(ptr->RC!=NULL)
         push(ptr->RC); 
    }
    while(TOP1!=-1)
    {
        ptr=pop1();
        printf("%d ",ptr->data);
    }
}
struct Node* SEARCH_BT(struct Node*PTR,int KEY)
{
  struct Node*PTR0=PTR;
  if(PTR0->data!=KEY)
  {
      struct Node*PTR1=NULL;
    if(PTR0->LC!=NULL)
      PTR1=SEARCH_BT(PTR0->LC,KEY);

    if((PTR1==NULL)&&(PTR0->RC!=NULL))
      PTR1=SEARCH_BT(PTR0->RC,KEY);
    return PTR1;   
  }
  else
  
      return PTR0;
  
  
           
}
void INSERT_BT()
{
    int item,key;
    printf("\nEnter data to be inserted :");
    scanf("%d",&item);
     printf("\nEnter the data content of node after new node is to be inserted: ");
     scanf("%d",&key);
     struct Node*ptr0;
     ptr0=SEARCH_BT(ROOT,key);
     if(ptr0==NULL)
     {
         printf("\nSearch is unsuccessful:Insertion not possible");
         return;
     }
     else
     {
        if(ptr0->LC==NULL||ptr0->RC==NULL)
        {
            int choice;
            printf("Insert as Left(1) or Right(2) child?: ");
            scanf("%d",&choice);
            if(choice==1)
            {
                if(ptr0->LC==NULL)
                {
                    struct Node*NEW=(struct Node*)malloc(sizeof(struct Node));
                    NEW->data=item;
                    NEW->LC=NULL;
                    NEW->RC=NULL;
                    ptr0->LC=NEW;
                    printf("\nDone!!!!");
                }
                else
                {
                    printf("\nSorry!Insertion not possible as left child");
                }
                
            }
            else if(choice==2)
            {
                if (ptr0->RC==NULL)
                {
                    struct Node*NEW=(struct Node*)malloc(sizeof(struct Node));
                    NEW->data=item;
                    NEW->LC=NULL;
                    NEW->RC=NULL;
                    ptr0->RC=NEW;
                    printf("\nDone!!!!");
                }
                else
                {
                    printf("\nSorry!Insertion not possible as right child");
                }
                
                
            }
        } 
     }
     
 
 
}
/*void PRE_ORDER_TRAVERSAL(struct Node*PTR)
{
    if(PTR!=NULL)
    {
        printf("%d ",PTR->data);
        PRE_ORDER_TRAVERSAL(PTR->LC);
        PRE_ORDER_TRAVERSAL(PTR->RC);

    }
    

}*/
/*void IN_ORDER_TRAVERSAL(struct Node*PTR)
{
if(PTR!=NULL)
    {
        
        IN_ORDER_TRAVERSAL(PTR->LC);
        printf("%d ",PTR->data);
        IN_ORDER_TRAVERSAL(PTR->RC);

    }
}*/
/*void POST_ORDER_TRAVERSAL(struct Node*PTR)
{
if(PTR!=NULL)
    {
        
        POST_ORDER_TRAVERSAL(PTR->LC);
        POST_ORDER_TRAVERSAL(PTR->RC);
        printf("%d ",PTR->data);

    }
}*/
struct Node* SEARCH_PARENT(struct Node*PTR,struct Node*parent,int ITEM)
{
    struct Node*PTR0=PTR;
    if(PTR0->data!=ITEM)
    {
       struct Node*parent0=NULL;
        if(PTR0->LC!=NULL)
            parent0=SEARCH_PARENT(PTR0->LC,PTR0,ITEM);
         
        if((parent0==NULL)&&(PTR0->RC!=NULL))
            parent0= SEARCH_PARENT(PTR0->RC,PTR0,ITEM);
        return parent0; 
          
    }
    else if(PTR0==ROOT)
    return ROOT;
    else//printf("\nDone");
      return parent;

}
void DELETE()
{
  struct Node*PTR=ROOT;
  if (PTR==NULL)
  {
      printf("Sorry!Deletion not possible, Tree is empty");
      return;
  }
  int ITEM;
  printf("Enter the data content of node to be deleted :");
  scanf("%d",&ITEM);
 if (ROOT->data==ITEM)
      {
          if (ROOT->LC==NULL&&ROOT->RC==NULL)
          {
              ROOT=NULL;
              //free(parent);
              printf("\nSucccessfully deleted the node!!!");
          }
          else
          {
              printf("\nSorry!!!Node with %d data content is not a leaf node!!!",ITEM);
          }
          
          return;
      }
   struct Node*parent=SEARCH_PARENT(ROOT,ROOT,ITEM);
   if(parent==NULL)
  {
      printf("\nSorry!!!Node with %d data content does not exist",ITEM);
      return;
  }
      struct Node*ptr1,*ptr2;
      ptr1=parent->LC;
      ptr2=parent->RC; 
      if(ROOT->data==ITEM)
      {
         if(ROOT->LC==NULL&&ROOT->RC==NULL)
          {
              printf("\nparent:%d",parent->data);
            ROOT=NULL;
            free(ROOT);
            printf("\nSuccessfully deleted the Node");
          }
          else
          {
            printf("\nSorry!!!Node with %d data content is not a leaf node!!!",ITEM);
          }
          return;
      }
      
     if(ptr1->data==ITEM)
      {
          if(ptr1->LC==NULL&&ptr1->RC==NULL)
          {
              printf("\nparent:%d",parent->data);
            parent->LC=NULL;
            free(ptr1);
            printf("\nSuccessfully deleted the Node");
          }
          else
          {
            printf("\nSorry!!!Node with %d data content is not a leaf node!!!",ITEM);
            
          }
          return;
      }
     else if(ptr2->data==ITEM)
      {
          if(ptr2->LC==NULL&&ptr2->RC==NULL)
          {
              printf("\nparent:%d",parent->data);
           parent->RC=NULL;
           free(ptr2);
           printf("\nSuccessfully deleted the Node");
          }
          else
          {
         printf("\nSorry!!!Node with %d data content is not a leaf node!!!",ITEM);
        
          }
          return;
           
      }
  

  
}
void main()
{
    ROOT=NULL;
    int ch;
 printf("Hey there!You have a Binary tree to manipulate.\nYou are allowed to perform the following");
 printf("\n0. QUIT");
 printf("\n1. INSERTION");
 printf("\n2. PRE ORDER TRAVERSAL");
 printf("\n3. IN ORDER TREE");
 printf("\n4. POST ORDER TRAVERSAL");
 printf("\n5. DELETION");
 printf("\nEnter the choice according to your requirement:");
 scanf("%d",&ch);
 while(ch!=0)
 {
     switch (ch)
     {
        case 1:
        {
            if(ROOT==NULL)
            {   
                  int item;
                  ROOT=(struct Node*)malloc(sizeof(struct Node));
                  printf("\nEnter data to be inserted :");
                  scanf("%d",&item);      
                  ROOT->data=item;
                  ROOT->LC=NULL;
                  ROOT->RC=NULL;
                  printf("\nDone!!");
            }
            else
                 INSERT_BT();
        printf("\n*********************************************");
        
        break;
        }
        case 2:
        {
            if (ROOT==NULL)
            {
                printf("\nSorry!Tree is empty!");
            }
            else{
                printf("\n---------PREORDER TRAVERSAL---------\n");
                //TOP=NULL;
            PRE_ORDER_TRAVERSAL();
            }
        printf("\n*********************************************");
        break;
        }
        case 3:
        {
            if (ROOT==NULL)
            {
                printf("\nSorry!Tree is empty!");
            }
            else
            {  printf("\n--------INORDER TRAVERSAL------------\n");
            //TOP=(struct stack*)malloc(sizeof(struct stack*));
            //TOP=NULL;
                IN_ORDER_TRAVERSAL();
            }
        printf("\n*********************************************");
        break;
        }
        case 4:
        {
            if (ROOT==NULL)
            {
                printf("\nSorry!Tree is empty!");
            }
            else{
                printf("\n------------POSTORDER TRAVERSAL----------\n");
                POST_ORDER_TRAVERSAL();
            }
        printf("\n*********************************************");
        break;
        }
        case 5:
        {
        DELETE();
        printf("\n*********************************************");
        break;
        }
     
     default:printf("\nEnter any valid choice:");
         break;
     }
     printf("\n0. QUIT");
 printf("\n1. INSERTION");
 printf("\n2. PRE ORDER TRAVERSAL");
 printf("\n3. IN ORDER TREE");
 printf("\n4. POST ORDER TRAVERSAL");
 printf("\n5. DELETION");
 printf("\nEnter the choice according to your requirement:");
 scanf("%d",&ch);
 }
}

