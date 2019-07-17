#include <stdio.h>
#include <stdlib.h>
int s[20],top=-1;
int visited[20];
void push(int s[],int i)
{
    s[++top]=i;
}
void pop()
{
    top--;
}
struct node
{
        int d;
        struct node *next;
};
struct node *b[20];
struct node *insert_node(struct node *head,int i)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->d=i;
    ptr->next=NULL;
    if(head==NULL)
        head=ptr;
    else
    {
        struct node *a=head;
        while(a->next!=NULL)
            a=a->next;
        a->next=ptr;
    }
    return head;
};
void printlist(struct node *a,int i)
{
    if(a==NULL)
        printf("\n%d",i);
    else
    {
        printf("\n%d",i);
        struct node *ptr=a;
        while(ptr!=NULL)
        {
            printf("->%d",ptr->d);
            ptr=ptr->next;
        }
    }
}
void dfs(int i)
{
    if(visited[i]==0)
    {
        visited[i]=1;
        struct node *ptr=b[i];
        while(ptr!=NULL)
        {
            dfs(ptr->d);
            ptr=ptr->next;
        }
        push(s,i);
    }
}
void dfs1(int i)
{
    //printf("-%d",i);
    if(visited[i]==0)
    {
        printf("-%d",i);
        visited[i]=1;

        struct node *ptr=b[i];

      // pop();
        while(ptr!=NULL)
        {
            /*if(visited[ptr->d]==0)
            printf("-%d",ptr->d);*/
            dfs1(ptr->d);
            ptr=ptr->next;


        }
        //printf("-%d",i);
        //pop();
        //push(s,i);
    }
}
int main()
{
    int n,i,j;
    printf("\n Enter the number of vertices.");
    scanf(" %d",&n);
    int a[n][n],r[n][n];
    printf("n Enter the adjacency matrix.");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            r[i][j]=a[i][j];
        }
    }
    for(i=0;i<n;i++)
        b[i]=NULL;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1)
                b[i]=insert_node(b[i],j);
        }
    }
    printf("\ Adjacency list");
    for(i=0;i<n;i++)
    printlist(b[i],i);
    for(i=0;i<n;i++)
        visited[i]=0;
    for(i=0;i<n;i++)
        dfs(i);
   for(i=top;i>=0;i--)
        printf("\n%d",s[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=r[j][i];
            printf("\t%d",a[i][j]);
        }
        printf("\n");
    }

        for(i=0;i<n;i++)
        b[i]=NULL;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1)
                b[i]=insert_node(b[i],j);
        }
    }
    for(i=0;i<n;i++)
    printlist(b[i],i);
    for(i=0;i<n;i++)
        visited[i]=0;
    for(i=top;i>=0;i--)
    {
        printf("\n");
        dfs1(s[i]);
        pop();
    }
}
