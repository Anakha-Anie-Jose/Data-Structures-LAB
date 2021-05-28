/*Implementation of Double Linked List*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct Node{
    char Data;
    struct Node *LLink;
    struct Node *RLink;
}*HEADER;
void insert_rear(char ITEM)//store word
{
    struct Node *NEW,*PTR;
    NEW=(struct Node*)malloc(sizeof(struct Node));
    PTR=HEADER;
    while(PTR->RLink!=NULL)
    {
        PTR=PTR->RLink;
    }
    if(NEW!=NULL){
    NEW->LLink=PTR;
    NEW->Data=ITEM;
    NEW->RLink=NULL;
    PTR->RLink=NEW;
    };

}
void check_palindrome(int l)
{
  struct Node *PTR1,*PTR2;
  PTR1=HEADER->RLink;
  while(PTR1->RLink!=NULL)//making PTR1 point to last node
  {
      PTR1=PTR1->RLink;
  }
  PTR2=HEADER->RLink;//PTR2 points to first node
  int flag=0;
  while(PTR2!=NULL&&PTR1!=HEADER)
  {
     if(PTR1->Data==PTR2->Data)//checking each node for equality
      {
          PTR1=PTR1->LLink;
          PTR2=PTR2->RLink;
          flag++;//if yes, increase flag
      } 
      else
      {
          break;//else break
      }
  }
  if(flag==l)//if flag is equal to length of word, the word and its reverse is same
  {
      printf("\nThe word is palindrome!!");
  }
  else
  {
      printf("\nThe word is not Palindrome!!!");
  }
  
}
void main()
{
    int ch;
    HEADER=(struct Node*)malloc(sizeof(struct Node));
    do
    {
    HEADER->LLink=NULL;
    HEADER->RLink=NULL;
    char word[50];
    printf("Enter the word which you want to check as palindrome :");
    scanf("%s",&word);
    int i;
    int l=strlen(word);
    for(i=0;i<l;i++)
    {
       insert_rear(toupper(word[i]));//making it case insensitive
    }
    check_palindrome(l);
    printf("\nPress 0 to exit or any other digit to continue :");
    scanf("%d",&ch);
    }while(ch!=0);
}
