#include<stdio.h>
#include<stdlib.h>
# define MAX 50
struct Matrix{
    int n;
    int m;
    int ar[MAX][MAX];
    int sp[MAX][3];
};
int Read(struct Matrix *M)
{
    int count=0;
    printf("\n Enter the elements :\n");
    for(int i=0;i<M->n;i++)
    {
        for(int j=0;j<M->m;j++)
        {
            scanf("%d",&M->ar[i][j]);
            if(M->ar[i][j]!=0)
               count++;

            
        }
    }
    return count;
}
void Sparse(struct Matrix *M,int count)
{
    int k=1;
    M->sp[0][0]=M->n;
    M->sp[0][1]=M->m;
    M->sp[0][2]=count;
    for(int i=0;i<M->n;i++)
    for (int j=0;j<M->m;j++)
    {
        if(M->ar[i][j]!=0)
        {
            M->sp[k][0]=i;
            M->sp[k][1]=j;
            M->sp[k][2]=M->ar[i][j];
            k++;
        }
    }
}
void display(struct Matrix M)
{
    printf("\n The 3 tuple matrix is :\n");
    for(int i=0;i<M.sp[0][2]+1;i++)
    {
    for(int j=0;j<3;j++)
    {
        printf("%d ",M.sp[i][j]);
    }
    printf("\n");
    }
    

}

void sum(struct Matrix M1,struct Matrix M2,int S[MAX][3])
{
    int i=1,j=1,k=1;
    if(M1.sp[0][0]!=M2.sp[0][1]||M1.sp[0][0]!=M2.sp[0][1])
    {
        printf("Matrices of different size!!!!cannot be added");
        exit(0);
    }

    while(i<=M1.sp[0][2]&&j<=M2.sp[0][2])
    {
        if(M1.sp[i][0]==M2.sp[j][0]&&M1.sp[i][1]==M2.sp[j][1])
        {
        
            
                S[k][0]=M1.sp[i][0];
                S[k][1]=M1.sp[i][1];
                S[k][2]=M1.sp[i][2]+M2.sp[j][2];
                i++,j++,k++;
        }    
            else if(M1.sp[i][0]==M2.sp[j][0]&&M1.sp[i][1]>M2.sp[j][1])
            {
                S[k][0]=M2.sp[j][0];
                S[k][1]=M2.sp[j][1];
                S[k][2]=M2.sp[j][2];
                j++,k++;
            }
            else if(M1.sp[i][0]==M2.sp[j][0]&&M1.sp[i][1]<M2.sp[j][1])
            {
                S[k][0]=M1.sp[i][0];
                S[k][1]=M1.sp[i][1];
                S[k][2]=M1.sp[i][2];
                i++,k++;
            }  
      else if(M1.sp[i][0]>M2.sp[j][0])
      {
                S[k][0]=M2.sp[j][0];
                S[k][1]=M2.sp[j][1];
                S[k][2]=M2.sp[j][2];
                j++,k++;
      }  
      else
      {
                S[k][0]=M1.sp[i][0];
                S[k][1]=M1.sp[i][1];
                S[k][2]=M1.sp[i][2];
                i++,k++; 
      } 
    }
    while(i<=M1.sp[0][2])
    {
                S[k][0]=M1.sp[i][0];
                S[k][1]=M1.sp[i][1];
                S[k][2]=M1.sp[i][2];
                i++,k++; 
    }
    while(i<=M2.sp[0][2])
    {
                S[k][0]=M2.sp[j][0];
                S[k][1]=M2.sp[j][1];
                S[k][2]=M2.sp[j][2];
                j++,k++;
    }
      S[0][0]=M1.sp[0][0];
      S[0][1]=M1.sp[0][1];
      S[0][2]=k-1;

}
void main()
{
     struct Matrix M1;
    int KEY;
    printf("Enter the number of rows and columns of first matrix :");
    scanf("%d%d",&M1.n,&M1.m);
    KEY=Read(&M1);
    Sparse(&M1,KEY);
    struct Matrix M2;
    printf("Enter the number of rows and columns of second matrix :");
    scanf("%d%d",&M2.n,&M2.m);
    KEY=Read(&M2);
    Sparse(&M2,KEY);
    display(M1);
    display(M2);
    int S[MAX][3];
    sum(M1,M2,S);
    printf("\n The 3 tuple matrix is :\n");
    for(int i=0;i<=S[0][2];i++)
    {
    for(int j=0;j<3;j++)
    {
        printf("%d ",S[i][j]);
    }
    printf("\n");
    }
    

    
}