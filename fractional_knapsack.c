#include <stdio.h>
#include <stdlib.h>
void swap(float *v,int i,int j)
{
    float t;
    t=v[i];
    v[i]=v[j];
    v[j]=t;
}
int main()
{
    float pr[10],wt[10];
    int W,i,j,n;
    float r[10];
    printf("\n Enter the maximum weight of the knapsack.");
    scanf("%d",&W);
    printf("\n Enter the number of objects.");
    scanf("%d",&n);
    printf("\n Enter the profits for %d items.",n);
    for(i=0;i<n;i++)
    {
        scanf("%f",&pr[i]);
    }
    printf("\n Enter the weights for %d items.",n);
    for(i=0;i<n;i++)
    {
        scanf("%f",&wt[i]);
    }
    printf("\n Ratio: value/weight");
    for(i=0;i<n;i++)
    {
        r[i]=pr[i]/wt[i];
        printf(" %f",r[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(r[i]<r[j])
            {
                swap(r,i,j);
                swap(pr,i,j);
                swap(wt,i,j);
            }
        }
    }
    /*printf("\n");
    for(i=0;i<n;i++)
    {
        printf(" %f",r[i]);
        printf(" %f",pr[i]);
        printf(" %f",wt[i]);
    }*/
    float tpr=0.0;
    for(i=0;i<n;i++)
    {
        printf("\n %f",wt[i]);
        if(wt[i]<=W)
        {
            tpr+=pr[i];
            W-=wt[i];
            printf("%f",tpr);
            printf("%f",W);
        }
        else
        {
            tpr+=(W/wt[i])*pr[i];
            printf("%f",tpr);
            printf("%f",W);
            break;
        }
    }
    printf("\n Total profit is %f",tpr);
}
