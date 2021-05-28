/*implementation of Binary Search Tree*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*LC;
    struct Node*RC;
}*ROOT;
int count;
void INSERT_BST(struct Node*PTR)
{
    int Flag=0;
    int ITEM;
    printf("\nEnter Item to be inserted: ");
    scanf("%d",&ITEM);
    struct Node*PTR1=NULL;
    while (PTR!=NULL)
    {
        PTR1=PTR;
    if(ITEM<PTR->data)
    {
        PTR=PTR->LC;
    }
    else if(ITEM>PTR->data)
    {
        PTR=PTR->RC;
    }
    else if(ITEM==PTR->data)
    {
        printf("Sorry! given Item already exits!!");
        return;
    }
    }
    struct Node*New=(struct Node*)malloc(sizeof(struct Node));
        New->data=ITEM;
        New->LC=NULL;
        New->RC=NULL;
    if(PTR1==NULL)
    {
        PTR1=New;
    }
    
    else if(PTR1->data>ITEM)
    {
       PTR1->LC=New;
    }
     else if(PTR1->data<ITEM)
     {
         PTR1->RC=New;
     }
     printf("Done");
    
      
      

}
int DELETE_BST(struct Node*PTR,int ITEM)
{
  int Flag=0;
  struct Node*parent;
  if(ROOT->data==ITEM)//when the data content is in root
    {
       // parent=ROOT;
        //Flag=1;
        //PTR=ROOT;
        if(ROOT->LC==NULL&&ROOT->RC==NULL)
  {
     ROOT=NULL;
      
  }
  else if(ROOT->LC!=NULL&&ROOT->RC!=NULL)
  {
      struct Node*PTR1;
      PTR1=ROOT->RC;
      if(PTR1!=NULL)
       {
           while (PTR1->LC!=NULL)
           {
               PTR1=PTR1->LC;
           }
           
       }
       int item=PTR1->data;
       DELETE_BST(ROOT,item);
       (ROOT)->data=item;
  }
  else
  {
         if(ROOT->LC==NULL)
            ROOT=ROOT->RC;
         if(ROOT->RC==NULL)
            ROOT=ROOT->LC;
                 
   }
   //printf("/nDone!!!!");
    } 
    else{
  while((PTR!=NULL)&&(Flag==0))
  {
      if(ITEM<PTR->data)
      {
          parent=PTR;
          PTR=PTR->LC;
      }
      else if(ITEM>PTR->data)
      {
          parent=PTR;
          PTR=PTR->RC;
      }
      else if(ITEM==PTR->data)
         Flag=1;
  }
    
    
  if(Flag==0)
  {
    printf("\nSorry!Item does not exist, no deletion!!");
    return 0;
  }
  if(PTR->LC==NULL&&PTR->RC==NULL)
  {
      if(parent->LC==PTR)
      {
         parent->LC=NULL;
      }
      else
      {
          parent->RC=NULL;
      }
      
  }
  else if(PTR->LC!=NULL&&PTR->RC!=NULL)
  {
      struct Node*PTR1;
      PTR1=PTR->RC;
      if(PTR1!=NULL)
       {
           while (PTR1->LC!=NULL)
           {
               PTR1=PTR1->LC;
           }
           
       }
       int item=PTR1->data;
       DELETE_BST(ROOT,item);
       (PTR)->data=item;
  }
  else
  {
      if(parent->LC==PTR)
         if(PTR->LC==NULL)
            parent->LC=PTR->RC;
          else
            parent->LC=PTR->LC;
       else if(parent->RC==PTR)
         if(PTR->LC==NULL)
            parent->RC=PTR->RC;
          else
            parent->RC=PTR->LC;
                 
   }
    }
    
  return 1;
}
void COUNT_LEAFNODE(struct Node*PTR)
{

        if(PTR->LC==NULL&&PTR->RC==NULL)
         count+=1;
        else
        {
            if(PTR->LC!=NULL) 
               COUNT_LEAFNODE(PTR->LC);
            if(PTR->RC!=NULL)
               COUNT_LEAFNODE(PTR->RC);
        }       

    
}
void PRE_ORDER_TRAVERSAL(struct Node*PTR)
{
    if(PTR!=NULL)
    {
        printf("%d ",PTR->data);
        PRE_ORDER_TRAVERSAL(PTR->LC);
        PRE_ORDER_TRAVERSAL(PTR->RC);
    }

    
    

}
void IN_ORDER_TRAVERSAL(struct Node*PTR)
{

        if(PTR!=NULL)
        {
        IN_ORDER_TRAVERSAL(PTR->LC);
        printf("%d ",PTR->data);
        IN_ORDER_TRAVERSAL(PTR->RC);
        }

    
}
void POST_ORDER_TRAVERSAL(struct Node*PTR)
   {
        if(PTR!=NULL)
        { 
        POST_ORDER_TRAVERSAL(PTR->LC);
        POST_ORDER_TRAVERSAL(PTR->RC);
        printf("%d ",PTR->data);
        }

    
   }
    void main()
     {
         ROOT=NULL;
          int ch;
          count=0;
 printf("Hey there!You have a Binary tree to manipulate.\nYou are allowed to perform the following");
 printf("\n0. QUIT");
 printf("\n1. INSERTION");
 printf("\n2. PRE ORDER TRAVERSAL");
 printf("\n3. IN ORDER TREE");
 printf("\n4. POST ORDER TRAVERSAL");
 printf("\n5. DELETION");
 printf("\n6. COUNT LEAF NODE");
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
                 INSERT_BST(ROOT);
        printf("\n*********************************************");
        
        break;
        }
        case 2:
        {
            if(ROOT==NULL)
            {
                printf("\nSorry!Tree is empty");
            }
            else{
                printf("\n--------PREORDER TRAVERSAL---------\n");
            PRE_ORDER_TRAVERSAL(ROOT);
            }
        printf("\n*********************************************");
        break;
        }
        case 3:
        {
            if(ROOT==NULL)
            {
                printf("\nSorry!Tree is empty");
            }
            else
            {
                printf("\n-------------INODER TRAVERSAL------------\n");
                IN_ORDER_TRAVERSAL(ROOT);}
        printf("\n*********************************************");
        break;
        }
        case 4:
        {
            if(ROOT==NULL)
            {
                printf("\nSorry!Tree is empty");
            }
            else
            {
            printf("\n----------POSTORDER TRAVERSAL------------\n");
            POST_ORDER_TRAVERSAL(ROOT);
            }
        printf("\n*********************************************");
        break;
        }
        case 5:
        {
            int ITEM;
            if(ROOT==NULL)
               {
               printf("\nSorry!Deletion not possible.Tree is empty");
   
                }
                else
                {
            printf("\nEnter item to be deleted: ");
            scanf("%d",&ITEM);
            int re= DELETE_BST(ROOT,ITEM);
            if(re==1)
            {
                printf("\nDone!!!");
            }
             
                }
        printf("\n*********************************************");
        break;
        }
        case 6:
        {
            if (ROOT==NULL)
            {
                printf("\nSorry!!Tree is empty!!");
            }
            else
            {
            COUNT_LEAFNODE(ROOT);
            printf("\nNo of leaf Nodes :%d",count);
            count=0;
            }
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
 printf("\n6.  COUNT LEAF NODES");
 printf("\nEnter the choice according to your requirement:");
 scanf("%d",&ch);
 }
     }
