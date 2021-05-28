/*Depth First and Breadth First traversal using array*/
#include<stdio.h>
int stack[100];//to store DFS traversal intermediate result
int Queue[100];//to store BFS traversal intermediate result
int Front,Rear;
int top;
int N,n;
struct Graph
{
    int label;
    int visited;//to check if the vertices are visited or not
}matrix[10][10],vertex[10];//matrix for storing adjacency and vertex for storing vetices
void Insert_Graph()
{
    int l;//no of adjacent vertices
     N=N+1;
    printf("\nEnter the number of adjacent vertices of vertex %d: ",N+1);
    scanf("%d",&l);
    int X[l];//array to store the adjacent vertices
    int v=N;
    printf("\nEnter the adjacent vertex/vertices :");
    for(int i=0;i<l;i++)
     scanf("%d",&X[i]);
    for (int i = 0; i <l; i++)
    {
        int j=X[i]-1;
        if(j>=n)
        {
          printf("Vertex labelled %d does not exist. edge from V to %d is not established",j,j);
          continue;
        }
        matrix[v][j].label=1;
        matrix[j][v].label=1;


    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",matrix[i][j].label);
        }
        printf("\n");
    }
    
    

    
}
void PUSH(int item)//push function definition
  {
      
          top++;
          stack[top]=item;
          
  }
  int POP()//pop function definition
  { 
      int u;
      u=stack[top];
          top--;
          return u;
          
  }
void DFS()
{
    for(int i=0;i<n;i++)
    {
        vertex[i].visited=0;
    }
    int V,u;
    printf("Enter the starting vertex as per your requirement:");
    scanf("%d",&V);
    if (V>n)
    {
        printf("\nVertex out of range!!!!Exiting");
        return;
    }
    
    u=V;
    printf("\n**********DEPTH FIRST TRAVERSAL*************\n");
    PUSH(V);
    while (top!=-1)
    {
       u=POP();

       if(vertex[u-1].visited==0)
         {
             vertex[u-1].visited=1;
             printf("%d\t",vertex[u-1].label);
             for (int i = 0; i < n; i++)
             {
                 if(matrix[u-1][i].label==1)
                  PUSH(i+1);
             }
             
         } 
    }
    


}
void ENQUEUE(int item){//inserting into queue
    if(Front==-1)
    {
      Front=0;
    }
      Rear++;
    Queue[Rear]=item;

}
int DEQUEUE()//deleting into queue
{
    
      int u=Queue[Front];
      if(Front==Rear)
      {
        Rear=-1;
        Front=-1;
      }
      else
      {
        Front++;
      }
    
  return u;  
}
void BFS()
{
    for(int i=0;i<n;i++)
    {
        vertex[i].visited=0;
    }
    int V,u;
    printf("Enter the starting vertex as per your requirement:");
    scanf("%d",&V);
    if (V>n)
    {
        printf("\nVertex out of range!!!!Exiting");
        return;
    }
    printf("\n************BREADTH FIRST TRAVERSAL***********\n");
    u=V;
    ENQUEUE(u);
    while (Front!=-1)
    {
        u=DEQUEUE();
        if(vertex[u-1].visited==0)
        {
           vertex[u-1].visited=1;
           printf("%d\t",vertex[u-1].label);
           for (int i = 0; i < n; i++)
           {
               if(matrix[u-1][i].label==1)
               {
                   ENQUEUE(i+1);
               }
           }
            
        }
    }
    
}
void main()
{
    N=-1;
    top=-1,Front=-1,Rear=-1;
    int ch;
    printf("You are dealing with graph");
    printf("\nEnter no of vertices  of the graph: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        vertex[i].label=i+1;
        for (int j= 0; j < n; j++)
        {
            matrix[i][j].label=0;
        }
        }
    printf("\nOPERATIONS ");
    printf("\n0.To quit");
    printf("\n1. Insert a vertex");
    printf("\n2. DFS Traversal");
    printf("\n3. BFS Traversal");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
   while(ch!=0)
   {
       switch(ch)
       {

    case 1:{
    if(N>=n-1)
     printf("Out of bound!!");
    else
    Insert_Graph();
    }

   break;
   case 2:DFS();
   break;
   case 3:BFS();
   break;
   }
   printf("\n0.To quit");
    printf("\n1. Insert a vertex");
    printf("\n2. DFS Traversal");
    printf("\n3. BFS Traversal");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    }
printf("\nSuccessfully Exited from program!!!!!!");

}
