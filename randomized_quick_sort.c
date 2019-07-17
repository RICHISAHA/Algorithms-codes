#include <stdio.h>
#include <stdlib.h>
int count=0,compare=0;
void quicksort(int a[],int p,int r)
{
    int q;
    if(p<r)
    {
        compare++;
        q=partition(a,p,r);
        quicksort(a,q+1,r);
        quicksort(a,p,q-1);
    }
}
int partition(int a[],int beg,int end)
{
    int pivot_index=beg+rand()%(end-beg+1);
    int pivot=a[pivot_index];
    int temp;
    temp=a[end];
    a[end]=a[pivot_index];
    a[pivot_index]=temp;
    int i=beg-1,j;
    for(j=beg;j<=end-1;j++)
    {
        compare++;
        if(a[j]<pivot)
        {
            compare++;
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    i++;
    temp=a[i];
    a[i]=a[end];
    a[end]=temp;
    return i;
}
void swap(int *v,int i,int j)
{
    int t;
    t=v[i];
    v[i]=v[j];
    v[j]=t;
}
void perm(int v[],int n,int i)
{
    int j;
    if(i==n)
    {
        count++;
        FILE *fp=fopen("quickran.txt","a");
        for(j=0;j<n;j++)
            fprintf(fp,"%d",v[j]);
        fprintf(fp,"\n");
    }
    else
    {
        for(j=i;j<n;j++)
        {
            swap(v,i,j);
            perm(v,n,i+1);
            swap(v,i,j);
        }
    }
}
int main()
{
    srand(time(NULL));
    int n;
    printf("\n Enter the number of elements.");
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    FILE *fp=fopen("quickran.txt","w");
    fclose(fp);
    int i,j,k;
    for(i=0;i<n;i++)
    {
        a[i]=i++;
    }

    perm(a,n,0);
    //printf("\n Number of permutations=%d\n\n",count);
    fp=fopen("quickran.txt","r");
    for(i=1;i<3628800;i++)
    {
        for(j=0;j<n;j++)
        {
            fscanf(fp,"%d",&a[j]);
        }
        quicksort(a,0,n-1);
        printf("\n");
        //printf("The sorted array for this combination is :\n");
        //for(k=0;k<n;k++)
        //{
          //  printf("%d ",a[k]);
        //}
        printf("\n The number of comparisons are =%d",compare);
        compare=0;
    //}
}
