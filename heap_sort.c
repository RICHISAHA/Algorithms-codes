#include <stdio.h>
#include <stdlib.h>
#define max 10
int sortedarray(int heap[],int n)
{
    int i;
    for(i=n;i>=2;i--)
    {
        swap(heap[1],heap[i]);
        n--;
        heapify(heap,i);
    }
}
int heapify(int heap[],int n)
{
    int l,r,i=0,largest;
    l=2i+1;
    r=2i+2;
    largest=i;
    if(heap[l]>heap[largest] && (l<n))
    {
        largest=l;
    }
    if(heap[r]>heap[largest] && (r<n))
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(&heap[i],&heap[largest]);
    }
    heapify(heap,largest);
}
void swap(int *a,int *b)
{
    int c=*a;
    *a=*b;

    *b=c;

}
int main()
{
    int i,heap[max],n;
    printf("\n Enter the number of numbers.");
    scanf("%d",&n);
    printf("\n Enter the elements.");
    for(i=0;i<n;i++)
    {
        scanf("%d",&heap[i]);
    }
    heapify(heap,n);
    printf("\n Max heap is ");
    for(i=0;i<n;i++)
    {
        printf(" %d",heap[i]);

    }
    sortedarray(heap,n);
    printf("\n Sorted array is ");
    for(i=0;i<n;i++)
    {
        printf(" %d",heap[i]);

    }
}
