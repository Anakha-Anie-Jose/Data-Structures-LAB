#include <stdio.h>
  
  
  void HeapMax(int A[],int n,int i) {
    int j = i;
    int LC = 2*i+1;
    int RC = 2*i+2;
  
    if(LC<n&&A[LC]>A[j])
      j=LC;
  
    if(RC<n&&A[RC]>A[j])
      j=RC;
  
    if(j!=i) 
      {
          int temp=A[i];
          A[i]=A[j];
          A[j]=temp;
      HeapMax(A,n,j);
    }
  }
  
  void heapSort(int A[],int n) 
  {
    for(int i=n/2-1;i>=0;i--)
      HeapMax(A,n,i);
  
    for(int i=n-1;i>=0;i--) {
      
          int temp=A[0];
          A[0]=A[i];
          A[i]=temp;
      
  
      HeapMax(A,i,0);
    }
  }
  
  
  void main() {
    int no;
    printf("Enter the number of elements in array: ");
    scanf("%d",&no);
    int A[no];
    int B[no];
    printf("\nEnter the set of numbers to be sorted: ");
    for(int i=0;i<no;i++)
      scanf("%d",&A[i]);
    heapSort(A,no);
  
    printf("\n***************SORTED ARRAY**************\n");
    for(int i=0;i<no;i++)
         printf("%d\t",A[i]);
  }
