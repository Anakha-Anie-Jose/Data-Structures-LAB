#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define Max 50
struct  postfix
{
    int ar[Max];//stack is stored here
    int top;//top of stack
};
void push(struct postfix *p,int ch)//pushing to stack
{
    p->top++;
    p->ar[p->top]=(int)(ch-48);//character converted to integer
}
void pop(struct postfix *p)//popping from stack
{
    p->top--;
}
void main()
{
    struct postfix P;
    P.top=-1;//initially top=-1
    char E[Max];
    printf("Enter the PostFix Expression :");
    scanf("%s",&E);
    int i=0;
    int val;
    while (i<strlen(E))
    {
        if(isdigit(E[i]))//pushing digits to stack
        { 
          push(&P,E[i]);
        }
        else if(E[i]=='+'||E[i]=='-'||E[i]=='*'||E[i]=='/'||E[i]=='^')//if operatoris encountered
        {  /*last two elements in the stack is popped and evaluated*/
            int num1=P.ar[P.top];//accessing the top from stack
            pop(&P);//popping out top from stack
            int num2=P.ar[P.top];//accessing the top from stack
            pop(&P);//popping out top from stack
            switch(E[i])
            {
            case '+':val=num1+num2;
                     break;
            case '-':val=num2-num1;
                     break;
            case '*':val=num1*num2;
                     break;
            case '/':val=num2/num1;
                     break;
            case '^':val=num2^num1;
                     break;                                    

            }
            P.ar[++P.top]=val;//pushing the result back to stack 
        }
        i++;
    }
    int result=P.ar[P.top];//final one element in stack
    pop(&P);//poping the final element
    if(P.top==-1)//-1 => no element in stack, evaluation successful
     printf("The result after Evaluation :%d",result);
    else//elements are still present, Invalid expression
     printf("Invalid Expression");
          
}
