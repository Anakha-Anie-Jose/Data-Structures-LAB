#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 50
struct  Infix{
    int top;//referring to top of stack
    char ar[MAX];//stack is stored here

} ;
int In_stack_priority(char ch)//predicting instack priority
{
    switch (ch)
    {
    case '+':return 2;
             break;
    case '-':return 2;
             break;
    case '*':return 4;
             break;
    case '/':return 4;
             break;
    case '^':return 5;
            break;  
    case '(':return 0;
            break;                       

    }
}
  int In_coming_priority(char ch)//predicting Incoming stack priority
  {
      switch (ch)
      {
    case  '+':return 1;
             break;
    case '-':return 1;
             break;
    case '*':return 3;
              break;
    case '/':return 3;
             break;
    case '^':return 7;
            break; 
    case ')':return 0;
             break;                
      }
    
}
void push(struct Infix *s,char ch)//push function definition
  {
          s->top++;
          s->ar[s->top]=ch;
  }
  void pop(struct Infix *s)//pop function definition
  {
          s->top--;
      
  }

void main()
{ 
    struct Infix I;
    I.top=-1;
    char Expression[MAX];
    char E[MAX];
    char Y[MAX];
    printf("Enter the Infix expression :");
    scanf("%s",&Expression);
    int ELE=1;
    E[0]='(';
    for(int i=0;i<strlen(Expression);i++)//copying expression to E to sdd '(' and ')'
     {
       E[ELE]=Expression[i];
       ELE++;
     }
     E[ELE]=')';
    int i=0;
    int k=0;
    int ISP,ICP;
    int l=strlen(E);
    while(i<l)
    {
        if(isalnum(E[i]))//operand
        {
           Y[k]=E[i];//adding to output
           k++;
        }
        else if(E[i]=='(')
        {
          push(&I,E[i]);//pushing to stack
        }
        else if(E[i]==')')  
        {
        int j=I.top;
        while(I.ar[j]!='(')
        {
            Y[k]=I.ar[j];//adding to output
            k++;
          pop(&I);//popping from stack
          j--;
        }
         pop(&I);//popping '(' out
        }
        else{//operator
          ISP=In_stack_priority(I.ar[I.top]);
          ICP=In_coming_priority(E[i]);
          if(ISP>=ICP)//checking priorities of operators
          {
              while (ISP>=ICP)
              {
                  Y[k++]=I.ar[I.top];
                  //printf("%c",I.ar[I.top]);

                  pop(&I);//popping out operator
                  ISP=In_stack_priority(I.ar[I.top]);
              }
              push(&I,E[i]);//pushing operator to stack
          }
         else if(ISP<ICP)
          {
              push(&I,E[i]);//pushing operatorto stack
          }
        }
        i++;

          
    }
    if(I.top==-1)//stack is empty=>valid expression
    {
        printf("The PostFix Expression is :");
        for(int j=0;j<k;j++)
         printf("%c",Y[j]);
    
    }
    else{
    
        
        printf("Invalid Expression");
    }
    
    
    

}