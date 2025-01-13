#include<stdio.h>
int n,v[20],a[20][20],source;
void main()
{
    printf("Enter the numbr of edges :");
    scanf("%d",&n);

    printf("Enter the adjacency matrix :");
    for(int i=0;i<n;i++)
    {   v[i]=0;
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the source node :");;
    scanf("%d",&source);
    dijikstra(source);
}
void dijikstra()
{
    
}