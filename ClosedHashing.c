/*implemnetation of closed hashinh*/
#include<stdio.h>
#include<stdlib.h>
void display(int hashtable[],int n)
{
    printf("\n");
    for(int i=0;i<n;i++)
       printf("%d\n",hashtable[i]);
}
void insert(int hashtable[],int n)
{
    int key;
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&key);
    int h=key%n;
    if(hashtable[h]==0)
    {
        hashtable[h]=key;
        display(hashtable,0);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if(hashtable[i]==0)
            {
                hashtable[i]=key;
                display(hashtable,n);
                return;
            }
        }
        for (int i = 0; i <h; i++)
        {
            if (hashtable[i]==0)
            {
                hashtable[i]=key;
                display(hashtable,0);
                return;
            }
            printf("\nHashTable is full!!!");
            
        }
        
        
    }
    
}
void main()
{
    int n,ch;
    printf("\nEnter size of hashtable: ");
    scanf("%d",&n);
    int *hash=calloc(n,sizeof(int));
    printf("\n0. To quit\n2. Insert an element\n3. Display the table");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    while (ch!=0)
    {
        switch (ch)
        {
            case 1:insert(hash,n);
                   break;
            case 2:display(hash,n);
                   break;       
            default:printf("\nEnter any valid choice!!!");
                   break;
        }
        printf("\n0. To quit\n2. Insert an element\n3. Display the table");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
    }
    printf("\nSuccessfully exited from program!!!!");
    

}

