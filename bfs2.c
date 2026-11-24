#include<stdio.h>
void BFS(int n, int graph [n][n],int visited[], int source)
{
    int queue[n];
    int front=0,rear=0;
    visited[source]=1;
    queue[rear++]=source;
    while(front<rear)
    {
        int current=queue[front++];
        printf("%d->",current);
        for(int i=0;i<n;i++)
        {
         if(graph[current][i]==1 && !visited[i])
         {
            visited[i]=1;
            queue[rear++]=i;
         }
        }
    }
}
int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    int visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    int graph[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            graph[i][j]=0;
        }
    }
    printf("Enter the -1 to exit");
    int v1,v2;
    while(1)
    {
        printf("Enter the 1st edge: ");
        scanf("%d",&v1);
        if(v1==-1)
        {
            break;
        }
        printf("Enter the 2nd edge");
        scanf("%d",&v2);
        if(v1>=n || v2>=n || v2<0 || v1<0)
        {
            printf("Enter valid edge between 0 and %d",n-1);
        }
        else
        {
            graph[v1][v2]=1;
            graph[v2][v1]=1;
        }
    }
    int source;
    printf("Entere the source: ");
    scanf("%d",&source);
    if(source<0 || source>=n)
    {
        printf("Enter valid source");
        return 1;
    }
    printf("BFS->");
    BFS(n,graph,visited,source);
    return 0;
}
