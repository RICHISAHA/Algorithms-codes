#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int size, ind=0;
int h_size=0;
int a[50];
void enqueue(int);
void dequeue();
void maxheapify(int);
void display();
int main()
{
    int ch,x;
    printf("\n Enter size of queue.");
    scanf(" %d",&size);
    while(1)
    {
        printf("\n 1.Enqueue 2.Dequeue 3.Display 4. Exit.");
        printf("\n Enter choice.");
        scanf(" %d",&ch);
        switch(ch)
        {
            case 1: printf("\n Enter an element.\n");
            scanf(" %d",&x);
            enqueue(x);
            break;
            case 2:
                dequeue();
                break;
                case 3:
                    display();
                    break;
                case 4:
                    exit(0);
        }
    }

}
void enqueue(int x)
{
    if(h_size>=size)
        printf("\n Overflow.");
    else
    {
        h_size++;
        ind=h_size-1;
        int temp;
        a[ind]=x;
        int parent=(int)(floor((ind-1)/2.0));
        while((a[parent]<a[ind]) && (ind>0))
        {
            temp=a[parent];
            a[parent]=a[ind];
            a[ind]=temp;
            ind=parent;
            parent=(int)(floor((ind-1)/2.0));
        }
    }
}
void dequeue()
{
    ind=h_size-1;int temp;
    if(h_size==0)
    printf("\n Underflow.");
    else{
        printf("Dequeued item is %d ",a[0]);
        temp=a[0];
        a[0]=a[ind];
        a[ind]=temp;
        h_size-=1;
        maxheapify(0);
    }
}
void display()
{
    int p=16,j,k,i;
    if(h_size==0)
        printf("\n Nothing to display.");
    for(i=0;i<h_size;i=2*i+1)
    {
        for(k=0;k<p;k++)
        {
            printf(" ");
        }
        p-=2;
        for(j=i;((j<=2*i)&&(j<h_size));j++)
            printf(" %d",a[j]);
        printf("\n");
    }

}
void maxheapify(int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int largest,temp;
    if(l<h_size && a[l]>a[i])
        largest=l;
    else
        largest=i;
    if(r<h_size && a[r]>a[largest])
        largest=r;
    if(largest!=i)
    {
        temp=a[largest];
        a[largest]=a[i];
        a[i]=temp;
        maxheapify(largest);
    }
}
